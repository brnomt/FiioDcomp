/**
 * FUN_0300d5ae @ 0x0300d5ae
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0300d5ae(uint param_1,uint param_2,short *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = DAT_0300d7ac;
  if (param_1 < DAT_0300d7ac) {
    *param_3 = (short)(param_1 / 10000) + 0x30;
  }
  else {
    *param_3 = 0x4d;
  }
  uVar2 = DAT_0300d7a8;
  param_3[1] = (short)(param_1 / 1000) +
               (short)(uint)((ulonglong)DAT_0300d7a8 * (ulonglong)(param_1 / 1000) >> 0x23) * -10 +
               0x30;
  param_3[2] = (short)((param_1 % 1000) * 0x29 >> 0xc) + 0x30;
  uVar1 = DAT_0300d7a4;
  param_3[3] = (short)(uint)((ulonglong)uVar2 *
                             (ulonglong)
                             (param_1 +
                             (uint)((ulonglong)DAT_0300d7a4 * (ulonglong)param_1 >> 0x25) * -100) >>
                            0x23) + 0x30;
  param_3[4] = (short)param_1 + (short)(uint)((ulonglong)uVar2 * (ulonglong)param_1 >> 0x23) * -10 +
               0x30;
  param_3[5] = 0x2f;
  if (param_2 < uVar3) {
    param_3[6] = (short)(param_2 / 10000) + 0x30;
  }
  else {
    param_3[6] = 0x4d;
  }
  param_3[7] = (short)(param_2 / 1000) +
               (short)(uint)((ulonglong)uVar2 * (ulonglong)(param_2 / 1000) >> 0x23) * -10 + 0x30;
  param_3[8] = (short)((param_2 % 1000) * 0x29 >> 0xc) + 0x30;
  param_3[9] = (short)(uint)((ulonglong)uVar2 *
                             (ulonglong)
                             (param_2 + (uint)((ulonglong)uVar1 * (ulonglong)param_2 >> 0x25) * -100
                             ) >> 0x23) + 0x30;
  param_3[10] = (short)param_2 + (short)(uint)((ulonglong)uVar2 * (ulonglong)param_2 >> 0x23) * -10
                + 0x30;
  param_3[0xb] = 0;
  return 0xb;
}


