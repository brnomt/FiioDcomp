/**
 * FUN_0300584c @ 0x0300584c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300584c(uint param_1,uint param_2,uint param_3,int param_4)

{
  longlong lVar1;
  short sVar2;
  uint uVar3;
  short sVar4;
  uint uVar5;
  short local_40 [4];
  short local_38;
  undefined2 local_36;
  short local_34;
  short local_32;
  undefined2 local_30;
  
  uVar5 = param_1 * 0xcccd >> 0x13;
  uVar5 = uVar5 + (uint)((ulonglong)DAT_03005a38 * (ulonglong)uVar5 >> 0x23) * -10 + 0x30;
  local_40[0] = (short)uVar5;
  local_40[1] = (short)param_1 +
                (short)(uint)((ulonglong)DAT_03005a38 * (ulonglong)param_1 >> 0x23) * -10 + 0x30;
  local_40[2] = 0x3b;
  local_40[3] = (ushort)(param_2 * 0xcccd >> 0x13) +
                (short)(uint)((ulonglong)DAT_03005a38 * (ulonglong)(param_2 * 0xcccd >> 0x13) >>
                             0x23) * -10 + 0x30;
  local_38 = (short)param_2 +
             (short)(uint)((ulonglong)DAT_03005a38 * (ulonglong)param_2 >> 0x23) * -10 + 0x30;
  lVar1 = (ulonglong)DAT_03005a38 * (ulonglong)(param_3 * 0xcccd >> 0x13);
  local_34 = (ushort)(param_3 * 0xcccd >> 0x13) + (short)(uint)((ulonglong)lVar1 >> 0x23) * -10 +
             0x30;
  local_32 = (short)param_3 +
             (short)(uint)((ulonglong)DAT_03005a38 * (ulonglong)param_3 >> 0x23) * -10 + 0x30;
  local_30 = 0;
  local_36 = 0x3b;
  FUN_02fee568(1,(int)((ulonglong)DAT_03005a38 * (ulonglong)param_3),param_3,(int)lVar1);
  if (param_4 == 0) {
    sVar4 = 0x14;
  }
  else {
    sVar4 = 0x106;
  }
  uVar3 = 0;
  sVar2 = 0;
  if ((uVar5 & 0xffff) != 0) {
    do {
      FUN_02fef2b2(local_40[uVar3] + 0x80,(int)(short)(((short)uVar3 * 7 + sVar4) - sVar2),0x9e);
      if (local_40[uVar3] == 0x3b) {
        sVar2 = sVar2 + 4;
      }
      uVar3 = uVar3 + 1 & 0xffff;
    } while (local_40[uVar3] != 0);
    return;
  }
  return;
}


