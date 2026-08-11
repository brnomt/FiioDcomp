/**
 * FUN_03001f28 @ 0x03001f28
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_03001f28(int param_1,int param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  uint unaff_r4;
  uint uVar3;
  
  FUN_02ff0378(DAT_03001f84,param_1 * 0x200 + param_2 * 8,8,DAT_03001f88);
  if (param_3 == 0) {
    unaff_r4 = (uint)*DAT_03001f88;
  }
  else if (param_3 == 1) {
    unaff_r4 = (uint)DAT_03001f88[1];
  }
  else if (param_3 == 2) {
    uVar3 = (uint)DAT_03001f88[2];
    uVar2 = (uint)*(ushort *)(DAT_03001f8c + 10);
    sVar1 = *(short *)(DAT_03001f90 + uVar2 * 2 + 4);
    if (sVar1 == 0x600) {
      if (uVar2 == 0) {
        return uVar3;
      }
    }
    else if (sVar1 != 0x500 || uVar2 != 1) {
      return uVar3;
    }
    unaff_r4 = uVar3 + 1 & 0xffff;
  }
  else if (param_3 == 4) {
    unaff_r4 = (uint)DAT_03001f88[3];
  }
  return unaff_r4;
}


