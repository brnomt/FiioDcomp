/**
 * FUN_030c6344 @ 0x030c6344
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c6344(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  param_1[3] = 1;
  iVar3 = param_1[1];
  iVar1 = *param_1;
  while (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x408);
    memset_byte(iVar1,0,0x400);
    iVar1 = iVar2;
  }
  *param_1 = 0;
  for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xc)) {
  }
  param_1[1] = 0;
  if (param_1[2] == 0) {
    memset_byte(DAT_030c66e4,0,0x10);
    return;
  }
  return;
}


