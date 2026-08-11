/**
 * FUN_030e65cc @ 0x030e65cc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e65cc(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_030e641a(0xc);
  *param_2 = iVar1;
  if (iVar1 != 0) {
    iVar1 = FUN_030e641a(0x208);
    *(int *)*param_2 = iVar1;
    if (iVar1 != 0 && param_1 != -1) {
      *(undefined2 *)(iVar1 + 0x200) = 0;
      *(undefined2 *)(iVar1 + 0x202) = 0;
      *(int *)(iVar1 + 0x204) = param_1;
      *(undefined4 *)(*param_2 + 4) = 0;
      *(undefined4 *)(*param_2 + 8) = 0;
      return 0;
    }
  }
  return 0xffffffff;
}


