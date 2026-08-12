Todo verificado. Reporte de aceptación:

## Resumen

**Entregado:**
- `tools/make_v019_dispatch_map.py` — herramienta que parchea offsets de section_3 del stock a `b .` (FE E7), con verificación de código-Thumb-plausible y verificación de diffs
- `build/ReChord_V0.19_map_USB.IMG` — hangs en {0x0300016c WriteData_To_Flash, 0x0300024e MscTestUnitReady, 0x03000aba main2_entry}
- `build/ReChord_V0.19_map_misc.IMG` — hangs en {0x03000296, 0x030004f4, 0x03000546, 0x03000a72, 0x03000a74}
- `build/ReChord_V0.19_map_appstart.IMG` — hang en {0x0300710a application_start}

**Verificación por IMG** (independiente del tool): cada uno difiere del stock SOLO en los pares FE E7 patcheados (6/10/2 bytes), trailer 0x1EA1C309 preservado. Todos los offsets verificados contenían código Thumb real antes del patch. El offset 0x03000162 (bx lr stock) se excluyó de los grupos como indica la tarea. El modo standalone (`-n/--offsets/-o`) funciona y rechaza offsets que apuntan a padding (byte 0x00).