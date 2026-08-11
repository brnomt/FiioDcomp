/**
 * FUN_030122a2 @ 0x030122a2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_030122a2(undefined4 param_1,int param_2,ushort *param_3,uint param_4,int param_5)

{
  ushort uVar1;
  ushort uVar2;
  char *pcVar3;
  undefined1 uVar4;
  short sVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  ushort uVar10;
  short sVar11;
  undefined4 local_a0;
  int local_9c;
  uint local_98;
  undefined1 auStack_84 [44];
  undefined1 auStack_58 [11];
  byte bStack_4d;
  undefined4 local_34;
  int iStack_30;
  ushort *puStack_2c;
  uint uStack_28;
  
  uVar1 = param_3[2];
  uVar2 = (ushort)param_4;
  if (param_4 < uVar1) {
    iVar9 = (int)(short)(uVar1 - uVar2);
    if (iVar9 < 6) {
      sVar5 = 6 - (uVar1 - uVar2);
    }
    else {
      sVar5 = 0;
      iVar9 = 6;
    }
    sVar11 = 0;
    uVar10 = uVar2;
  }
  else {
    uVar10 = param_3[2];
    sVar5 = *param_3 - uVar2;
    iVar9 = 0;
    if (5 < sVar5) {
      sVar5 = 6;
    }
    sVar11 = uVar2 - uVar1;
  }
  iVar8 = param_2 + iVar9 * 0x270;
  local_34 = param_1;
  iStack_30 = param_2;
  puStack_2c = param_3;
  uStack_28 = param_4;
  FUN_02fede0e(auStack_84,param_3 + 6,0x2a);
  local_a0 = *(undefined4 *)(param_3 + 4);
  local_9c = 0;
  local_98 = (uint)*param_3;
  iVar6 = FUN_02ff3884(auStack_58,&local_a0,local_34,param_5);
  pcVar3 = DAT_03012614;
  if (iVar6 != 0) {
    return;
  }
  do {
    if ((bStack_4d & 2) == 0) {
      if ((bStack_4d & 0x10) == 0) {
        if (sVar5 != 0) {
          if (sVar11 == 0) {
            FUN_02fede0e(iVar8 + 0x4f,auStack_58,0x20);
            *(undefined4 *)(iVar8 + 8) = local_a0;
            FUN_02fede0e(iVar8 + 0x24,auStack_84,0x2a);
            *(int *)(iVar8 + 0xc) = local_9c + -1;
            if (*pcVar3 == '\x03') {
              FUN_02ff30c4(iVar8 + 0x24,local_9c + -1,param_5,iVar8 + 0x70);
            }
            else {
              FUN_02ff3f2c(local_a0,local_9c + -1,param_5,iVar8 + 0x70);
            }
            if (*pcVar3 == '\x03') {
              FUN_02ff5638(auStack_58,iVar8 + 0x70);
            }
            puVar7 = (undefined1 *)FUN_03012194(auStack_58);
            if (param_5 == 1) {
              uVar4 = 1;
            }
            else {
              uVar4 = *puVar7;
            }
            *(undefined1 *)(iVar8 + 0x4e) = uVar4;
            sVar5 = sVar5 + -1;
            iVar8 = *(int *)(iVar8 + 4);
          }
          else {
            sVar11 = sVar11 + -1;
          }
        }
      }
      else if (iVar9 != 0) {
        if (uVar10 == 0) {
          FUN_02fede0e(param_2 + 0x4f,auStack_58,0x20);
          *(undefined1 *)(param_2 + 0x4e) = 0;
          *(undefined4 *)(param_2 + 8) = local_a0;
          FUN_02fede0e(param_2 + 0x24,auStack_84,0x2a);
          *(int *)(param_2 + 0xc) = local_9c + -1;
          if (*pcVar3 == '\x03') {
            FUN_02ff30c4(param_2 + 0x24,local_9c + -1,param_5,param_2 + 0x70);
          }
          else {
            FUN_02ff3f2c(local_a0,local_9c + -1,param_5,param_2 + 0x70);
          }
          param_2 = *(int *)(param_2 + 4);
          iVar9 = (int)(short)((short)iVar9 + -1);
        }
        else {
          uVar10 = uVar10 - 1;
        }
      }
      if (iVar9 == 0 && sVar5 == 0) {
        return;
      }
    }
    iVar6 = FUN_02ff3858(auStack_58,&local_a0,local_34,param_5);
    if (iVar6 != 0) {
      return;
    }
  } while( true );
}


