/**
 * FUN_03004338 @ 0x03004338
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03004338(void)

{
  ushort *puVar1;
  ushort uVar2;
  
  puVar1 = DAT_030046fc;
  uVar2 = DAT_030046fc[2];
  DAT_030046fc[2] = uVar2 + 1;
  if (puVar1[1] <= (ushort)(uVar2 + 1)) {
    if ((*puVar1 & 1) != 0) {
      return 0xffffffff;
    }
    uVar2 = FUN_02fe3d26(DAT_03004704,0x800,(int)*DAT_03004700);
    puVar1[1] = uVar2;
    if (uVar2 < 0x800) {
      *puVar1 = *puVar1 | 1;
    }
    puVar1[2] = 0;
  }
  return 0;
}


