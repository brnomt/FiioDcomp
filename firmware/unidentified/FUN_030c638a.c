/**
 * FUN_030c638a @ 0x030c638a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030c638a(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  param_1[2] = param_1[2] + 1;
  iVar1 = DAT_030c66e8;
  iVar3 = *param_1;
  if (iVar3 == 0) {
    iVar3 = DAT_030c66ec + *(int *)(DAT_030c66e8 + 4) * 0x40c;
    memset_byte(iVar3,0,0x40c);
    iVar2 = *(int *)(iVar1 + 4) + 1;
    *(int *)(iVar1 + 4) = iVar2;
    if (0x31 < iVar2) {
      return 0;
    }
  }
  else {
    *param_1 = *(int *)(iVar3 + 0x408);
    if (param_2 < *(int *)(iVar3 + 0x400)) {
      param_2 = *(int *)(iVar3 + 0x400);
    }
  }
  *(int **)(iVar3 + 0x408) = param_1;
  *(int *)(iVar3 + 0x400) = param_2;
  *(undefined4 *)(iVar3 + 0x404) = 1;
  return iVar3;
}


