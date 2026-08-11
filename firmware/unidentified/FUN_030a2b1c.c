/**
 * FUN_030a2b1c @ 0x030a2b1c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030a2b1c(uint param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  
  uVar2 = (ushort)(DAT_030a2e58 >> 0x10);
  if ((int)param_1 < 0x8000) {
    iVar3 = (int)(short)param_1;
    return ((short)((uVar2 >> 1) +
                   (short)(iVar3 * (short)((short)(iVar3 * (short)((short)DAT_030a2e58 +
                                                                  (short)(iVar3 * 0x1348 + 0x4000 >>
                                                                         0xf)) + 0x4000 >> 0xf) +
                                          -0x15) + 0x4000 >> 0xf)) * iVar3 + 0x4000) * 2 >> 0x11;
  }
  cVar5 = '\0';
  uVar4 = param_1;
  if (0xffff < param_1) {
    uVar4 = param_1 >> 0x10;
    cVar5 = '\x10';
  }
  if (0xff < uVar4) {
    uVar4 = uVar4 >> 8;
    cVar5 = cVar5 + '\b';
  }
  if (0xf < uVar4) {
    uVar4 = uVar4 >> 4;
    cVar5 = cVar5 + '\x04';
  }
  if (3 < uVar4) {
    uVar4 = uVar4 >> 2;
    cVar5 = cVar5 + '\x02';
  }
  bVar1 = cVar5 + (1 < uVar4);
  if (bVar1 < 0x1d) {
    iVar3 = (int)(short)((int)((DAT_030a2e58 >> 0x11) << (uint)(byte)(0x1d - bVar1)) /
                        (int)(short)((int)param_1 >> (uint)(byte)(bVar1 - 0xe)));
    return (int)(short)(0x6488 - (short)(((short)((uVar2 >> 1) +
                                                 (short)(iVar3 * (short)((short)(iVar3 * (short)((
                                                  short)DAT_030a2e58 +
                                                  (short)(iVar3 * 0x1348 + 0x4000 >> 0xf)) + 0x4000
                                                  >> 0xf) + -0x15) + 0x4000 >> 0xf)) * iVar3 +
                                         0x4000) * 2 >> 0x11));
  }
  return 0x6488;
}


