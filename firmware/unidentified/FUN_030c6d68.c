/**
 * FUN_030c6d68 @ 0x030c6d68
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c6d68(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 == (int *)0x0) {
    return 0xfffffff2;
  }
  if (param_2 <= (*(int *)(*piVar1 + 0x400) - piVar1[2]) - piVar1[1]) {
    piVar1[2] = piVar1[2] + param_2;
    *(int *)(param_1 + 0xc) = param_2 + *(int *)(param_1 + 0xc);
    return 0;
  }
  return 0xfffffff2;
}


