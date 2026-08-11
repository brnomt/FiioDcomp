/**
 * FUN_03004f16 @ 0x03004f16
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03004f16(uint param_1,uint param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short local_88 [52];
  
  iVar2 = 0;
  if (param_2 < param_1) {
    param_1 = param_2;
  }
  uVar5 = param_1 % 1000;
  if (999 < param_1) {
    sVar1 = (short)(param_1 / 1000) +
            (short)(uint)((ulonglong)DAT_03005048 * (ulonglong)(param_1 / 1000) >> 0x23) * -10;
    if (param_1 < 10000) {
      local_88[0] = sVar1 + 0x30;
    }
    else {
      local_88[0] = sVar1 + 0x39;
    }
    iVar2 = 1;
  }
  if (99 < param_1) {
    uVar4 = uVar5 * 0xa3d7 + 0xa3d7;
    local_88[iVar2] =
         (ushort)(uVar4 >> 0x16) +
         (short)(uint)((ulonglong)DAT_03005048 * (ulonglong)(uVar4 >> 0x16) >> 0x23) * -10 + 0x30;
    iVar2 = iVar2 + 1;
  }
  uVar5 = uVar5 + (uint)((ulonglong)DAT_0300504c * (ulonglong)uVar5 >> 0x25) * -100;
  uVar4 = uVar5 & 0xffff;
  if (9 < param_1) {
    local_88[iVar2] = (short)(uVar4 / 10) + 0x30;
    iVar2 = iVar2 + 1;
  }
  local_88[iVar2] =
       (short)uVar5 + (short)(uint)((ulonglong)DAT_03005048 * (ulonglong)uVar4 >> 0x23) * -10 + 0x30
  ;
  local_88[iVar2 + 1] = 0x3a;
  iVar3 = iVar2 + 2;
  if (999 < param_2) {
    sVar1 = (short)(param_2 / 1000) +
            (short)(uint)((ulonglong)DAT_03005048 * (ulonglong)(param_2 / 1000) >> 0x23) * -10;
    if (param_2 < 10000) {
      sVar1 = sVar1 + 0x30;
    }
    else {
      sVar1 = sVar1 + 0x39;
    }
    local_88[iVar3] = sVar1;
    iVar3 = iVar2 + 3;
  }
  uVar5 = param_2 % 1000;
  if (99 < param_2) {
    local_88[iVar3] = (ushort)(uVar5 * 0xa3d7 + 0xa3d7 >> 0x16) + 0x30;
    iVar3 = iVar3 + 1;
  }
  uVar5 = uVar5 + (uint)((ulonglong)DAT_0300504c * (ulonglong)uVar5 >> 0x25) * -100;
  uVar4 = uVar5 & 0xffff;
  if (9 < param_2) {
    local_88[iVar3] = (short)(uVar4 / 10) + 0x30;
    iVar3 = iVar3 + 1;
  }
  local_88[iVar3] =
       (short)uVar5 + (short)(uint)((ulonglong)DAT_03005048 * (ulonglong)uVar4 >> 0x23) * -10 + 0x30
  ;
  local_88[iVar3 + 1] = 0;
  uVar5 = 0;
  sVar1 = 0;
  if (local_88[0] == 0) {
    return;
  }
  do {
    iVar2 = (int)(short)(((short)(uVar5 << 3) + 0x42) - sVar1);
    if (local_88[uVar5] == 0x3a) {
      FUN_02fef2b2(0x12a,iVar2,6);
      sVar1 = 2;
    }
    else {
      FUN_02fef2b2(local_88[uVar5] + 0xf0,iVar2,4);
    }
    uVar5 = uVar5 + 1 & 0xff;
  } while (local_88[uVar5] != 0);
  return;
}


