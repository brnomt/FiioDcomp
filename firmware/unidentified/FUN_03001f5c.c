/**
 * FUN_03001f5c @ 0x03001f5c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_03001f5c(void)

{
  short sVar1;
  uint uVar2;
  uint unaff_r4;
  
  uVar2 = (uint)*(ushort *)(DAT_03001f8c + 10);
  sVar1 = *(short *)(DAT_03001f90 + uVar2 * 2 + 4);
  if (sVar1 == 0x600) {
    if (uVar2 == 0) {
      return unaff_r4;
    }
  }
  else if (sVar1 != 0x500 || uVar2 != 1) {
    return unaff_r4;
  }
  return unaff_r4 + 1 & 0xffff;
}


