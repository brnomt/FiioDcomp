/**
 * FUN_030228aa @ 0x030228aa
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_030228aa(char param_1)

{
  short sVar1;
  char *pcVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_78 [64];
  ushort local_38 [2];
  ushort local_34 [2];
  int local_30;
  undefined *local_2c;
  
  puVar3 = DAT_03022afc;
  local_30 = 0;
  *DAT_03022afc = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0;
  puVar3[4] = 0;
  *(undefined2 *)puVar3 = 0xffe1;
  *(undefined2 *)((int)puVar3 + 2) = 0;
  FUN_02ff8972(puVar3 + 1,DAT_03022b00,4);
  *(undefined2 *)(puVar3 + 3) = 0x4d4d;
  *(undefined2 *)((int)puVar3 + 0xe) = 0x2a;
  puVar3[4] = 8;
  iVar7 = (int)param_1;
  local_2c = &DAT_03022b08;
  uVar4 = FUN_02ffc9d6(local_38,2,iVar7);
  pcVar2 = DAT_03022af8;
  iVar8 = -1;
  if (1 < uVar4) {
    if (DAT_03022af8[1] != '\0') {
      local_38[0] = local_38[0] << 8 | local_38[0] >> 8;
    }
    if ((local_38[0] == 0xffd8) && (uVar4 = FUN_02ffc9d6(local_38,2,iVar7), 1 < uVar4)) {
      if (pcVar2[1] != '\0') {
        local_38[0] = local_38[0] << 8 | local_38[0] >> 8;
      }
      if (local_38[0] != 0xffdb) {
        while (iVar5 = FUN_02ffce8c(iVar7), local_38[0] - 0xffe0 < 0x10) {
          uVar4 = FUN_02ffc9d6(local_34,2,iVar7);
          if (uVar4 < 2) goto LAB_03022a38;
          if (pcVar2[1] != '\0') {
            local_34[0] = local_34[0] << 8 | local_34[0] >> 8;
          }
          if (local_38[0] == 0xffe1) {
            uVar4 = FUN_02ffc9d6(auStack_78,5,iVar7);
            if (4 < uVar4) {
              iVar6 = FUN_02ff89b4(auStack_78,local_2c,5);
              if (iVar6 == 0) {
                iVar8 = iVar5 + -2;
              }
              else {
                iVar5 = FUN_02ffcece(iVar5,0,iVar7);
                if (iVar5 == 0) {
                  iVar5 = FUN_02ffcece(local_34[0],1,iVar7);
                  goto joined_r0x03022a0a;
                }
LAB_03022a0c:
                iVar8 = -2;
              }
            }
            goto LAB_03022a38;
          }
          iVar5 = FUN_02ffcece(local_34[0] - 2,1);
joined_r0x03022a0a:
          if (iVar5 != 0) goto LAB_03022a0c;
          uVar4 = FUN_02ffc9d6(local_38,2,iVar7);
          if (uVar4 < 2) goto LAB_03022a38;
          if (pcVar2[1] != '\0') {
            local_38[0] = local_38[0] << 8 | local_38[0] >> 8;
          }
        }
        if ((local_38[0] == 0xffdb) && (&stack0x00000000 != &Reserved5)) {
          local_30 = iVar5 + -2;
        }
      }
    }
  }
LAB_03022a38:
  if (iVar8 < 0) {
    return iVar8;
  }
  *(int *)(pcVar2 + 4) = iVar8;
  *(int *)(pcVar2 + 8) = local_30;
  iVar8 = FUN_02ffcece(iVar8,0,iVar7);
  if ((((iVar8 == 0) && (uVar4 = FUN_02ffc9d6(DAT_03022afc,0x14,iVar7), 0x13 < uVar4)) &&
      (iVar8 = FUN_02ffcece(*(int *)(pcVar2 + 4) + 10,0,iVar7), iVar8 == 0)) &&
     (uVar4 = FUN_02ffc9d6(puVar3 + 3,8,iVar7), 7 < uVar4)) {
    if (pcVar2[1] != '\0') {
      *(ushort *)((int)puVar3 + 2) =
           *(ushort *)((int)puVar3 + 2) << 8 | *(ushort *)((int)puVar3 + 2) >> 8;
    }
    sVar1 = *(short *)(puVar3 + 3);
    if (sVar1 == 0x4d4d || sVar1 == 0x4949) {
      if (sVar1 == 0x4949) {
        *pcVar2 = '\x01';
      }
      else {
        *pcVar2 = '\0';
        *(ushort *)((int)puVar3 + 0xe) =
             *(ushort *)((int)puVar3 + 0xe) << 8 | *(ushort *)((int)puVar3 + 0xe) >> 8;
      }
      if (*(short *)((int)puVar3 + 0xe) == 0x2a) {
        if (*pcVar2 != '\x01') {
          uVar4 = puVar3[4];
          puVar3[4] = uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                      uVar4 >> 0x18;
        }
        return 1;
      }
    }
  }
  return 3;
}


