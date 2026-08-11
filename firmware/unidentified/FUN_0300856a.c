/**
 * FUN_0300856a @ 0x0300856a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300856a(int param_1,uint param_2,undefined2 *param_3)

{
  longlong lVar1;
  short sVar2;
  short sVar3;
  
  *param_3 = 0x43;
  sVar2 = (short)(uint)((ulonglong)DAT_03008970 * (ulonglong)(param_1 + 1U) >> 0x23);
  param_3[1] = 0x48;
  param_3[2] = sVar2 + 0x30;
  param_3[3] = (short)(param_1 + 1U) + sVar2 * -10 + 0x30;
  param_3[4] = 0x3a;
  param_3[5] = 0x20;
  param_3[8] = 0x2e;
  param_3[10] = 0x4d;
  param_3[0xb] = 0x48;
  param_3[0xc] = 0x7a;
  param_3[0xd] = 0;
  if (param_2 == 0) {
    param_3[6] = 0x45;
    param_3[7] = 0x6d;
    param_3[8] = 0x70;
    param_3[9] = 0x74;
    param_3[10] = 0x79;
    param_3[0xb] = 0;
    return;
  }
  sVar2 = (short)(param_2 / 10000);
  param_3[5] = sVar2;
  if (param_2 / 10000 == 0) {
    sVar3 = 0x20;
  }
  else {
    sVar3 = 0x30;
  }
  param_3[5] = sVar3 + sVar2;
  param_3[6] = (short)((param_2 % 10000) / 1000) + 0x30;
  param_3[7] = (short)((param_2 % 1000) * 0x29 >> 0xc) + 0x30;
  lVar1 = (longlong)DAT_03008978 *
          (longlong)
          (int)(param_2 + (uint)((ulonglong)DAT_03008974 * (ulonglong)param_2 >> 0x25) * -100);
  param_3[9] = ((short)(int)(lVar1 >> 0x22) - (short)(lVar1 >> 0x3f)) + 0x30;
  return;
}


