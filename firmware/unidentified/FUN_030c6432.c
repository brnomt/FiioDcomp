/**
 * FUN_030c6432 @ 0x030c6432
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c6432(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  param_1[2] = param_1[2] + 1;
  iVar1 = DAT_030c66e8;
  iVar4 = *param_1;
  if (iVar4 == 0) {
    iVar4 = DAT_030c66ec + *(int *)(DAT_030c66e8 + 4) * 0x40c;
    memset_byte(iVar4,0,0x40c);
    iVar2 = *(int *)(iVar1 + 4) + 1;
    *(int *)(iVar1 + 4) = iVar2;
    if (0x31 < iVar2) {
      iVar4 = 0;
      goto LAB_030c6490;
    }
  }
  else {
    *param_1 = *(int *)(iVar4 + 0x408);
    if (param_2 < *(int *)(iVar4 + 0x400)) {
      param_2 = *(int *)(iVar4 + 0x400);
    }
  }
  *(int **)(iVar4 + 0x408) = param_1;
  *(int *)(iVar4 + 0x400) = param_2;
  *(undefined4 *)(iVar4 + 0x404) = 1;
LAB_030c6490:
  piVar3 = (int *)FUN_030c63f0(param_1);
  if (iVar4 != 0 && piVar3 != (int *)0x0) {
    *piVar3 = iVar4;
  }
  return;
}


