/**
 * FUN_03013a86 @ 0x03013a86
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_03013a86(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  short local_268 [256];
  char local_68 [11];
  byte local_5d;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  
  iVar5 = 0;
  uVar7 = *(undefined4 *)(param_1 + 8);
  iVar3 = 0;
  if (param_2 == 0) {
    uVar6 = 6;
  }
  else {
    uVar6 = *(undefined1 *)(param_1 + 0x4e);
  }
  if (*DAT_03013b00 == '\x03') {
    local_48 = *(undefined4 *)(param_1 + 0x24);
    uStack_44 = *(undefined4 *)(param_1 + 0x28);
    uStack_40 = *(undefined4 *)(param_1 + 0x2c);
    uStack_3c = *(undefined4 *)(param_1 + 0x30);
    local_38 = *(undefined4 *)(param_1 + 0x34);
    uStack_34 = *(undefined4 *)(param_1 + 0x38);
    uStack_30 = *(undefined4 *)(param_1 + 0x3c);
    uStack_2c = *(undefined4 *)(param_1 + 0x40);
    local_28 = *(undefined4 *)(param_1 + 0x44);
    uStack_24 = *(undefined4 *)(param_1 + 0x48);
    local_20 = *(undefined4 *)(param_1 + 0x4c);
    do {
      do {
        do {
          iVar4 = iVar3;
          iVar3 = iVar4 + 1;
          sVar1 = FUN_02ff0d7e(local_68,&local_48,iVar4);
          if (sVar1 != 0) {
            return iVar5;
          }
          if (local_68[0] == '\0') {
            return iVar5;
          }
        } while ((local_68[0] != -0x7b) || ((local_68[4] & 2U) != 0 || (local_68[4] & 0x10U) != 0));
        iVar4 = FUN_02ff30c4(&local_48,iVar4,3,local_268);
        FUN_02ff5638(local_68,local_268);
        iVar2 = FUN_030121da(local_68,uVar6);
      } while (iVar2 == 0);
      iVar2 = 0;
      iVar5 = (int)(short)((short)iVar5 + 1);
      if (0 < iVar4) {
        do {
          if (*(short *)(param_1 + iVar2 * 2 + 0x70) != local_268[iVar2]) break;
          iVar2 = (int)(short)((short)iVar2 + 1);
        } while (iVar2 < iVar4);
      }
    } while (iVar4 != iVar2);
  }
  else {
    do {
      do {
        do {
          iVar4 = iVar3 + 1;
          iVar3 = FUN_02ff0ec6(local_68,uVar7,iVar3);
          if (iVar3 != 0) {
            return iVar5;
          }
          if (local_68[0] == '\0') {
            return iVar5;
          }
          iVar3 = iVar4;
        } while (local_68[0] == -0x1b);
        while (local_5d == 0xf) {
          FUN_02ff0ec6(local_68,uVar7,iVar3);
          iVar3 = iVar3 + 1;
        }
      } while ((((local_5d & 8) != 0 || (local_5d & 2) != 0) || (local_5d & 0x10) != 0) ||
              (iVar4 = FUN_030121da(local_68,uVar6), iVar4 == 0));
      iVar5 = (int)(short)((short)iVar5 + 1);
      iVar4 = 0;
      do {
        if (*(char *)(param_1 + iVar4 + 0x4f) != local_68[iVar4]) break;
        iVar4 = (int)(short)((short)iVar4 + 1);
      } while (iVar4 < 0xb);
    } while (iVar4 != 0xb);
  }
  return iVar5;
}


