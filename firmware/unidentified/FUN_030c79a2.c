/**
 * FUN_030c79a2 @ 0x030c79a2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030c79a2(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_38;
  
  local_38 = 0;
  iVar1 = FUN_030c0fba(param_2);
  iVar5 = 0;
  if (0 < param_1[2]) {
    iVar8 = iVar1 + 1;
    do {
      iVar4 = 0;
      iVar6 = 1;
      iVar7 = *(int *)(*param_1 + iVar5 * 4);
      if (1 < iVar8) {
        do {
          iVar2 = FUN_030c0f4a(*(undefined1 *)(iVar7 + iVar4));
          iVar3 = FUN_030c0f4a(*(undefined1 *)(param_2 + iVar4));
          if (iVar2 != iVar3) goto LAB_030c7a24;
          iVar4 = iVar4 + 1;
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar8);
      }
      if (*(char *)(*(int *)(*param_1 + iVar5 * 4) + iVar1) != '=') {
        if (param_3 == local_38) {
          return *(int *)(*param_1 + iVar5 * 4) + iVar8;
        }
        local_38 = local_38 + 1;
      }
LAB_030c7a24:
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_1[2]);
  }
  return 0;
}


