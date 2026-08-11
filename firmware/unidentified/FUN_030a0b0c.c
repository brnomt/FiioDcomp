/**
 * FUN_030a0b0c @ 0x030a0b0c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030a0b0c(uint param_1)

{
  uint uVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  sVar3 = 0;
  uVar1 = param_1;
  if (0xffff < param_1) {
    uVar1 = param_1 >> 0x10;
    sVar3 = 8;
  }
  if (0xff < uVar1) {
    uVar1 = uVar1 >> 8;
    sVar3 = sVar3 + 4;
  }
  if (0xf < uVar1) {
    uVar1 = uVar1 >> 4;
    sVar3 = sVar3 + 2;
  }
  iVar4 = (int)(short)(sVar3 + (ushort)(3 < uVar1));
  iVar2 = iVar4 + -6;
  iVar5 = iVar4 * 2 + -0xc;
  if (iVar4 != 6 && -1 < iVar5) {
    param_1 = (int)param_1 >> (iVar2 * 2 & 0xffU);
  }
  if (iVar5 < 1) {
    param_1 = param_1 << (iVar2 * -2 & 0xffU);
  }
  iVar5 = (int)(short)param_1;
  iVar5 = (int)(short)((short)((uint)((short)((short)((uint)(iVar5 * (short)((short)(iVar5 * 0x106c
                                                                                    >> 0xe) +
                                                                            -0x3153) * 4) >> 0x10) +
                                             0x52b5) * iVar5 * 4) >> 0x10) + 0xe32);
  if ((int)(7U - iVar2) < 1) {
    sVar3 = (short)(iVar5 << (iVar4 - 0xdU & 0xff));
  }
  else {
    sVar3 = (short)(iVar5 >> (7U - iVar2 & 0xff));
  }
  return (int)sVar3;
}


