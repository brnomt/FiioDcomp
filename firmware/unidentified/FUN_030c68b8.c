/**
 * FUN_030c68b8 @ 0x030c68b8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c68b8(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 < *(int *)(param_1 + 0x10)) {
    return;
  }
  do {
    iVar2 = *(int *)(param_1 + 0xc) + *(int *)(*(int *)(param_1 + 4) + 8);
    *(int *)(param_1 + 0xc) = iVar2;
    piVar1 = *(int **)(*(int *)(param_1 + 4) + 0xc);
    *(int **)(param_1 + 4) = piVar1;
    iVar2 = iVar2 + piVar1[2];
    *(int *)(param_1 + 0x10) = iVar2;
    *(int *)(param_1 + 8) = piVar1[1] + *piVar1;
  } while (iVar2 <= param_2);
  return;
}


