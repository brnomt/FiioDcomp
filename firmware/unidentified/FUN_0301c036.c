/**
 * FUN_0301c036 @ 0x0301c036
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301c036(int param_1,char *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  char local_88 [16];
  int local_78;
  undefined1 auStack_68 [64];
  undefined4 local_28;
  undefined4 uStack_24;
  
  uVar5 = 0;
  local_28 = *(undefined4 *)(param_1 + 0x1c);
  uStack_24 = *(undefined4 *)(param_1 + 0x20);
  iVar1 = (int)((uint)(byte)param_2[0x18] << 0x18) >> 0x1f;
  if ((*param_2 == '\x03') && ((*(ushort *)(param_2 + 0x18) & 0x1000) != 0)) {
    uVar2 = 0x48;
  }
  else {
    uVar2 = 0x90;
  }
  while (iVar3 = FUN_0301c3de(param_1), iVar3 == 0) {
    FUN_02ff5d5a(auStack_68,param_1,0x40);
    FUN_02ff5d5a(local_88,param_2,0x20);
    iVar3 = FUN_0301be76(local_88,auStack_68);
    if (((iVar3 == 0) && (local_88[0] == *param_2)) && (local_78 == *(int *)(param_2 + 0x10))) {
      iVar3 = FUN_0301c85a(param_1 + 0x1c);
      iVar3 = iVar3 - *(int *)(param_1 + 0x14);
      if (*param_2 == '\x01') {
        uVar5 = (uint)((iVar3 + iVar1 * 4 + 4) * *(int *)(param_2 + 0x10)) / 48000;
      }
      else {
        uVar5 = (uint)(((ulonglong)(uint)((iVar3 + iVar1 + 1) * *(int *)(param_2 + 0x10)) /
                       (ulonglong)uVar2) / 1000);
      }
      if (7 < uVar5) break;
    }
    FUN_0301c868(param_1 + 0x1c,8);
  }
  *(undefined4 *)(param_1 + 0x1c) = local_28;
  *(undefined4 *)(param_1 + 0x20) = uStack_24;
  if ((uVar5 < 8) || ((*param_2 == '\x03' && (0x280 < uVar5)))) {
    *(undefined2 *)(param_1 + 0x3c) = 0x101;
    uVar4 = 0xffffffff;
  }
  else {
    *(uint *)(param_1 + 0x10) = uVar5 * 1000;
    uVar4 = 0;
  }
  return uVar4;
}


