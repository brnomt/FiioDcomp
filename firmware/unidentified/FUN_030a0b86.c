/**
 * FUN_030a0b86 @ 0x030a0b86
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030a0b86(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (0x532a < param_1) {
    return 0x7fffffff;
  }
  if (-0x532b < param_1) {
    iVar2 = (param_1 * 0x5c55 + 0x2000) * 4;
    iVar1 = iVar2 >> 0x1b;
    if (0xe < iVar1) {
      return 0x7fffffff;
    }
    if (-0x10 < iVar1) {
      iVar2 = (int)(short)(((short)((uint)iVar2 >> 0x10) - (short)(iVar1 << 0xb)) * 8);
      uVar3 = iVar1 + 2;
      iVar1 = (int)(short)((short)((uint)((short)((short)((uint)(iVar2 * ((iVar2 * 0x515 >> 0xe) +
                                                                         0xe8e) * 4) >> 0x10) +
                                                 0x2c5c) * iVar2 * 4) >> 0x10) + 0x4000);
      if (uVar3 == 0 || (int)-uVar3 < 0) {
        iVar1 = iVar1 << (uVar3 & 0xff);
      }
      else {
        iVar1 = iVar1 >> (-uVar3 & 0xff);
      }
      return iVar1;
    }
  }
  return 0;
}


