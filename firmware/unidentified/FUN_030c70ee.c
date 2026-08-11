/**
 * FUN_030c70ee @ 0x030c70ee
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c70ee(int param_1,undefined4 param_2)

{
  int iVar1;
  
  while( true ) {
    iVar1 = FUN_030c6e3e(param_1,param_2);
    if (0 < iVar1) {
      return 1;
    }
    if (iVar1 == 0) break;
    if (*(int *)(param_1 + 0x10) == 0) {
      *(undefined4 *)(param_1 + 0x10) = 1;
      return 0xfffffff6;
    }
  }
  return 0;
}


