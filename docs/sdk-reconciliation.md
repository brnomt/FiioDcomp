# SDK Reconciliación de headers (fw1/AP = RKnanoD_MP3_V1.3 completo)

> Estado: integración del **SDK RKnanoD_MP3_V1.3_20161102 completo** (UI +
> drivers + display + filesys) en `firmware/rockchip/`. Confirmado por match
> de strings (223/1747) y diff (BSP2.c/Win.c/Task.c 100% idénticos).

## El problema

`firmware/rockchip/` se montó **originalmente solo para el BB** (audio), con:

- **Headers auto-creados** en `include/` que *aproximan* los tipos del SDK
  (`SysConfig.h` con `MEMDEV_ID`, `MEMDEV_INFO`, `CODE_INFO_T`, ...).
- **`firmware/stubs.c`** con funciones/globales *placeholder*
  (`ValidSysDisk`, `MailBox*`, `Codec*`, ...).

Al copiar el **SDK real** (`driver/`, `display/`, `filesys/`, `ui/`...), esos
placeholders **chocan** con las definiciones reales: `conflicting types for X`,
`redefinition of X`, etc.

## La regla de la reconciliación

**El SDK real gana.** Todo lo que el SDK real ya define (tipos, globales,
funciones) se **elimina** de nuestros headers auto-creados y de `stubs.c`.
Solo se conserva:

1. `include/armcc_compat.h` — nuestro puente Keil→GCC (esencial).
2. Headers/funciones que el SDK **no** provee (la capa FiiO: windows UI,
   algunos drivers del Echo Mini).

## Progreso

| Hito | Estado |
|------|--------|
| Confirmar SDK exacto (`RKnanoD_MP3_V1.3`) | ✅ |
| Copiar SDK completo (196 `.c`) | ✅ |
| `display/stdint.h` (quitar typedefs duplicados) | ✅ |
| `MAX_VOLUME` default en armcc_compat.h | ✅ |
| `SysConfig.h`: quitar `MEMDEV_ID`/`MEMDEV_INFO`/`CODE_INFO_T` duplicados | ✅ |
| Reconciliar resto de `stubs.c` + headers auto-creados | ⬜ en curso (68/197 → objetivo 100%) |

## Conflictos conocidos (categorías)

1. **Globales duplicados** — `ValidSysDisk`, `DataDiskID`, etc. (stubs.c vs SDK).
2. **Tipos duplicados** — `MEMDEV_ID`, `MEMDEV_INFO`, `CODE_INFO_T`,
   `struct tagDMA_LLP`, `HDC`... (headers auto-creados vs SDK).
3. **Defines de config** — `KEY_VAL_*`, `MODULE_ID_*`, `SID_MANUAL`,
   `DMA_CTLL_SPI0_*`... (SysConfig.h de `SDK_160_128` no copiado aún).
4. **Keil-ismos** — `__asm`, `__irq`, `_ATTR_*` (armcc_compat.h).
5. **Tipos de la capa FiiO** — `PICTURE_INFO_STRUCT`, `FM_GLOBAL`, `HDC`
   (drivers específicos no en este SDK).

## Método

Iterar: compilar → ver el top error → eliminar el duplicado de nuestro lado
(stubs.c/headers auto-creados) o añadir el define/header real → recompilar.
