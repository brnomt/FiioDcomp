/**
 * FUN_030177ea @ 0x030177ea
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030177ea(short *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = DAT_03017b14;
  uVar2 = *param_2;
  uVar4 = uVar2 >> 0x14;
  if (99 < uVar4) {
    uVar3 = (uint)((ulonglong)DAT_03017b18 * (ulonglong)uVar4 >> 0x25);
    *param_1 = (short)uVar3 +
               (short)(uint)((ulonglong)DAT_03017b14 * (ulonglong)uVar3 >> 0x23) * -10 + 0x30;
  }
  uVar3 = (uint)(99 < uVar4);
  if (9 < uVar4) {
    uVar5 = (uint)((ulonglong)uVar1 * (ulonglong)uVar4 >> 0x23);
    param_1[uVar3] =
         (short)uVar5 + (short)(uint)((ulonglong)uVar1 * (ulonglong)uVar5 >> 0x23) * -10 + 0x30;
    uVar3 = uVar3 + 1;
  }
  if (uVar4 == 0) {
    param_1[uVar3] = 0x30;
  }
  else {
    param_1[uVar3] =
         (ushort)(uVar2 >> 0x14) + (short)(uint)((ulonglong)uVar1 * (ulonglong)uVar4 >> 0x23) * -10
         + 0x30;
  }
  param_1[uVar3 + 1] = 0x2e;
  uVar4 = (uVar2 >> 10 & 0x3ff) * 1000;
  uVar2 = uVar4 / 0x19000;
  param_1[uVar3 + 2] =
       (short)uVar2 + (short)(uint)((ulonglong)uVar1 * (ulonglong)uVar2 >> 0x23) * -10 + 0x30;
  uVar4 = uVar4 / 0x2800;
  param_1[uVar3 + 3] =
       (short)uVar4 + (short)(uint)((ulonglong)uVar1 * (ulonglong)uVar4 >> 0x23) * -10 + 0x30;
  return uVar3 + 4;
}


