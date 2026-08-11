/**
 * FUN_030ae774 @ 0x030ae774
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ae774(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    return;
  }
  if (*(int *)(iVar1 + 0x204) != 0) {
    (*(code *)*DAT_030ae948)();
    *(undefined4 *)(iVar1 + 0x204) = 0;
  }
  *(undefined2 *)(iVar1 + 0x200) = 0;
  *(undefined2 *)(iVar1 + 0x202) = 0;
  return;
}


