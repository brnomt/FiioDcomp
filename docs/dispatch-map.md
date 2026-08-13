# M0 — ROM Dispatch Map (Echo Mini / RKnanoC)

> Resultado de la fase M0: mapear con precisión cómo el ROM del RKnanoC
> arranca y despacha la app. Fuente: Ghidra (`FIIO-3.7.0-Decomp`,
> language `ARM:LE:32:v8-m`), desensamblado de bytes crudos del IMG stock
> v3.7.0, y el SDK RKnanoD integrado.

> ## ⚠️ CORRECCIÓN ARQUITECTURAL (posterior a M0)
> El Echo Mini corre **DOS firmwares** comunicados por mailbox, no uno — y
> **ambos tienen SDK source**:
> - **fw1 (AP) @ IMG `0x7B8–0x57820`** — ~356KB de código Thumb (~168 func),
>   header RKnanoFW #1 en `0x1F8` (SP=`0x03050000`). Es la **UI** (menús,
>   navegación, I2C, fuentes, file browser). Construido sobre el **SDK
>   RKnanoD** (build App/UI: `main.c` + `SDK_160_128/UI/` 45 `.c`; el
>   match de strings dio 223 RKnanoD_MP3 vs 32 rk3399-table).
> - **section_3 (BB) @ IMG `0x81A14–0x9BAA0E`** — header #3 (SP=`0x0301E794`).
>   Es el **audio/DSP** (codecs, EQ). Construido sobre el **SDK RKnanoD**.
>
> Esto invalida la conclusión previa "section_3 = toda la app": la **UI
> navegable vive en fw1 (AP)**, y por eso reemplazar section_3 dejaba la UI
> stock intacta (solo fallaba al interactuar, porque el AP llama al BB).
> Los nombres de section_3 (RKnanoD) **no se transfieren** a fw1 (RKnanoC);
> hay que mapear fw1 con los nombres del SDK RKnanoC.

> **Conclusión clave:** el ROM (máscara, invisible) *posee* el boot y el
> despacho por **offsets fijos**. La app (`section_3`) es un *plugin* que
> provee callbacks a esos offsets. No hay un "main" al que el ROM salte:
> el app main lo arrancamos **nosotros** tras `firmware_entry`.

---

## 1. Cadena de arranque

```
Mask ROM  (0x00000000–0x02FDFFFF, invisible)
   └─ carga sec2 bootloader (IMG 0x57820, corre ~0x0301e2c0)
        └─ valida fw1/fw2 mediante validadores ROM
           (imprime "fw1valid=%d fw2valid=%d", "fw2 error!")
           └─ carga section_3 a 0x03000000
              └─ salta a firmware_entry @ 0x03000010
                 (r0 = puntero a boot params; *r0 = modo de boot)
```

- **sec2 no referencia `"RKnanoFW"`** → el parseo del magic está en el ROM
  (invisible). sec2 solo llama validadores ROM y salta a `firmware_entry`.
- El ROM API (0x02FE0000–0x02FFFFFF) es una **librería HAL** que la app
  llama directamente (el código real está en la máscara; en Ghidra es un
  bloque stub `ROM_API` con los símbolos nombrados).

## 2. Header RKnanoFW (16 bytes @ 0x03000000)

```
[0:8]   "RKnanoFW"     magic
[8:12]  0x0301E794     SP inicial (base del stack principal, 16 KB)
[12:16] 0x00000052     count/flags  ← NO tocar (el ROM lo interpreta)
```

- No hay tabla de segmentos justo después del header: `firmware_entry`
  empieza **inmediatamente** en `0x03000010`.
- `count=0x52` (82) aún no está 100% decodificado; el ROM lo usa. Es
  **byte-exacto** en el stock y debe mantenerse idéntico.
- `0x03000200` en el stock es **código**, no tabla de vectores → el ROM
  del Echo Mini **no usa VTOR/vector table**; usa offsets fijos.

## 3. `firmware_entry` @ 0x03000010 (decompilado Ghidra)

```c
void firmware_entry(short *param) {
  boot_param_layout();                        /* modo -> layout LCD */
  if (rom_alloc(0x1dc) == 0) {
    rom_hw_init2(0x16f);
  } else {
    rom_hw_init(0x1dc);
    rom_hw_init(0x16f);
    rom_hw_init(0x16f);
    rom_hw_init2(0x171);
    rom_hw_init(0x170);
  }
  rom_early_init();
  if (*param != 0xb) rom_hw_init2(0x18f);    /* 399 = modo no-app (USB MSC) */
  else               rom_hw_init2(0x191);    /* modo app */
}
```

- Es un **callback de init de HW que RETORNA** (tail-call a `rom_hw_init2`,
  devolviendo el control al ROM). `r0` de salida = código de continuación
  (`0x18f`/`0x191`).
- `*param == 0xb` = "arrancar app"; cualquier otro valor = USB MSC/early.
- Esto es lo que V0.15 replicó; V0.1–V0.14 hacían `b rechord_app` (loop
  infinito) → el ROM nunca continuaba → timeout ~23 s → apagado.

### `boot_param_layout` @ 0x030000da

```c
void boot_param_layout(ushort *param) {
  /* acepta modos 0–5, 8, 10; descarta el resto */
  /* escribe struct de boot @ DAT_03000164 */
  /* math de columnas LCD: ((modo/6)*3 & 0x7f)*2  (mismo que main2_entry) */
}
```

- Configura el layout de columnas de texto del LCD según el modo de boot.
  No es despacho de app.

## 4. Tabla de despacho del ROM (offsets fijos)

El ROM llama estos offsets para eventos concretos. `entry_stubs.S` los
reserva con `.org` para que caigan en la dirección exacta.

| Offset | Dirección      | Rol (evidencia)                                            |
|--------|----------------|------------------------------------------------------------|
| 0x010  | `0x03000010`   | `firmware_entry` — boot/HW init, **retorna**               |
| 0x162  | `0x03000162`   | USB/MSC misc (stock = `bx lr`)                             |
| 0x16c  | `0x0300016c`   | `WriteData_To_Flash` — write USB MSC                        |
| 0x24e  | `0x0300024e`   | `MscTestUnitReady` — USB MSC                                |
| 0x296  | `0x03000296`   | (sin identificar)                                          |
| 0x4f4  | `0x030004f4`   | (sin identificar)                                          |
| 0x546  | `0x03000546`   | `RKDev_Close`                                              |
| 0xa72  | `0x03000a72`   | (sin identificar)                                          |
| 0xa74  | `0x03000a74`   | `DeleteDeviceListEmmcDataBase`                             |
| 0xaba  | `0x03000aba`   | `main2_entry` — **dispatcher USB Mass Storage** (`MscSendCSW`, `WriteData_To_Flash`, `GetFileType`) |
| 0x70fa | `0x0300710a`   | **UI draw callback** — dibuja texto en LCD (`FUN_02feda18`, `FUN_02fed6a6`). *Mislabeled* `application_start`. |

### Correcciones de etiquetas (importante para M1)

| Etiqueta antigua | Realidad verificada |
|------------------|---------------------|
| `application_start @ 0x0300710a` | Rutina de **dibujo de texto** del UI (no un main ni un shell). Sus callers tienen nombres auto-generados basura (`LunShellCreate`, `music_shell_help`, `dhcpd_add_option`, `I2sDevShell8987_Init`). |
| `main2_entry @ 0x03000aba` | **USB MSC dispatcher**, no el main. |
| `Http_Close @ 0x0304d006` | Bucle de **escaneo/indexado musical** (`MusicInit()` en loop). |

> ⚠️ Los nombres de función de Ghidra en este binario son en su mayoría
> **auto-generados y erróneos** (Ghidra matcheó firmas contra libc/red:
> `ed25519_test`, `dhcpd_add_option`, `Http_Close`, `LunShellCreate`...).
> Solo son fiables el **código** y los **xrefs**, no los nombres.

## 5. ROM API (HAL, 0x02FE0000–0x02FFFFFF)

Librería de bajo nivel que la app llama directamente:

| Símbolo | Dirección | Uso |
|---------|-----------|-----|
| `rom_alloc` | `0x02feeedc` | reservar buffer |
| `rom_hw_init` / `rom_hw_init2` | `0x02feeebe` / `0x02feee7c` | init HW / continuación |
| `rom_early_init` | `0x02fe860e` | init temprano |
| `rom_i2s_master_config` | `0x02ff5752` | I2S |
| `rom_audio_clock_setup` | `0x02ff5c30` | clock audio |
| `rom_dma_config` / `rom_i2s_dma_start` | `0x02ff6814` / `0x02ff68f0` | DMA |
| `rom_sample_rate_set` | `0x02ffa410` | sample rate |
| `rom_audio_path_route` / `_disable` | `0x02ffa6f0` / `0x02ffa72a` | ruta audio |
| `rom_dac_mute` / `rom_dac_unmute` | `0x02ff44ce` / `0x02ff4580` | DAC |
| `rom_memcpy` | `0x02ff952e` | memcpy |
| `rom_usb_connect` | `0x02ffb2e0` | USB |
| `FUN_02fee544` | `0x02fee544` | comando SPI |
| `FUN_02feda18` | `0x02feda18` | update LCD |
| `FUN_02fed6a6` | `0x02fed6a6` | medir ancho de string |

## 6. Modelo SDK vs ROM del Echo Mini

- **SDK RKnanoD genérico:** vector table (`bb_vect`) con reset = `Main2`
  (salto directo). `Main2` = `ScatterLoader2()` → `BSP_Init2()` →
  `RegHifiDecodeServer()` → `RegHifiFileServer()` → loop heartbeat.
- **Echo Mini (ROM custom):** header + `firmware_entry` (init y retorno).
  El app main (OS + UI + audio) **no está en la tabla de offsets fijos**:
  lo arranca el propio `firmware_entry` (stock) o lo arrancamos nosotros
  (from-source).

## 7. Implicación para M1 (from-source)

Dos arquitecturas viables:

**A. Retorno al ROM (espejo stock).** `firmware_entry` hace el init y
retorna; el ROM despacha los callbacks de la tabla (§4). Requiere
implementar/registrar todos los callbacks (USB MSC, UI draw, etc.).
Es el camino del stock; el ROM sigue siendo el "runtime".

**B. Auto-contenido (modelo SDK).** `firmware_entry` hace el init de HW
(rom_hw_init + rom_early_init) y **salta a nuestro propio `Main2`/main**
sin retornar. Nosotros manejamos el loop principal (NANO_OS + tareas UI y
audio) llamando al ROM API para LCD/USB/audio. Es lo que probó V0.17
(`firmware_entry` → `Main2`): arrancó el kernel BB (heartbeat visible)
pero sin UI (Main2 no tiene UI).

**Recomendación:** camino **B** para el objetivo from-source, pero
`firmware_entry` debe hacer el init completo (como el stock, §3) antes de
saltar a nuestro main — no saltar directo como V0.17, para no perder el
init de HW del ROM. El main propio debe arrancar NANO_OS, crear la tarea
UI (framebuffer + dibujo vía `FUN_02feda18`) y la tarea audio (codecs SDK
+ `rom_i2s_*`/`rom_dac_*`).
