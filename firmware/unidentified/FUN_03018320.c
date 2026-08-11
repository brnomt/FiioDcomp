/**
 * FUN_03018320 @ 0x03018320
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03018320(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  short local_28;
  short local_26;
  short local_24;
  short local_22;
  undefined2 local_20;
  
  sVar3 = (short)param_2 + (short)(uint)((ulonglong)DAT_030184a4 * (ulonglong)param_2 >> 0x23) * -10
          + 0x30;
  uVar1 = (ushort)(param_2 * 0xcccd >> 0x10);
  if (param_2 < 100) {
    uVar2 = uVar1 >> 3;
    local_24 = 0;
    local_26 = sVar3;
  }
  else {
    uVar2 = (short)(param_2 / 1000) +
            (short)(uint)((ulonglong)DAT_030184a4 * (ulonglong)(param_2 / 1000) >> 0x23) * -10;
    uVar4 = param_2 * 0xa3d7 + 0xa3d7;
    local_26 = (ushort)(uVar4 >> 0x16) +
               (short)(uint)((ulonglong)DAT_030184a4 * (ulonglong)(uVar4 >> 0x16) >> 0x23) * -10 +
               0x30;
    local_24 = (uVar1 >> 3) +
               (short)(uint)((ulonglong)DAT_030184a4 * (ulonglong)(param_2 * 0xcccd >> 0x13) >> 0x23
                            ) * -10 + 0x30;
    local_20 = 0;
    local_22 = sVar3;
  }
  local_28 = uVar2 + 0x30;
  *DAT_030184a8 = 0xffff;
  FUN_02ffe2cc(param_4,param_5,&local_28);
  return;
}


