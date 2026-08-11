/**
 * FUN_030c7a34 @ 0x030c7a34
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030c7a34(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_30;
  
  local_30 = 0;
  iVar1 = FUN_030c0fba(param_2);
  iVar5 = 0;
  if (0 < param_1[2]) {
    do {
      iVar4 = 0;
      iVar6 = 1;
      iVar7 = *(int *)(*param_1 + iVar5 * 4);
      if (1 < iVar1 + 1) {
        do {
          iVar2 = FUN_030c0f4a(*(undefined1 *)(iVar7 + iVar4));
          iVar3 = FUN_030c0f4a(*(undefined1 *)(param_2 + iVar4));
          if (iVar2 != iVar3) goto LAB_030c7aa2;
          iVar4 = iVar4 + 1;
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar1 + 1);
      }
      if (*(char *)(*(int *)(*param_1 + iVar5 * 4) + iVar1) != '=') {
        local_30 = local_30 + 1;
      }
LAB_030c7aa2:
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_1[2]);
  }
  return local_30;
}


