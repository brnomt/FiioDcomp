/**
 * FUN_030b0e4c @ 0x030b0e4c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030b0e4c(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  
  puVar2 = DAT_030b111c;
  iVar4 = DAT_030b1118;
  if (*(int *)(DAT_030b1118 + 0x204) != 0) {
    (*(code *)*DAT_030b111c)();
    *(undefined4 *)(iVar4 + 0x204) = 0;
  }
  iVar1 = DAT_030b1104;
  *(undefined2 *)(iVar4 + 0x200) = 0;
  *(undefined2 *)(iVar4 + 0x202) = 0;
  piVar3 = *(int **)(iVar1 + 0x2c);
  if (piVar3 != (int *)0x0) {
    iVar4 = *piVar3;
  }
  if (piVar3 != (int *)0x0 && iVar4 != 0) {
    if (*(int *)(iVar4 + 0x204) != 0) {
      (*(code *)*puVar2)();
      *(undefined4 *)(iVar4 + 0x204) = 0;
    }
    *(undefined2 *)(iVar4 + 0x200) = 0;
    *(undefined2 *)(iVar4 + 0x202) = 0;
  }
  piVar3 = *(int **)(iVar1 + 0x3c);
  if (piVar3 != (int *)0x0) {
    iVar4 = *piVar3;
  }
  if (piVar3 != (int *)0x0 && iVar4 != 0) {
    if (*(int *)(iVar4 + 0x204) != 0) {
      (*(code *)*puVar2)();
      *(undefined4 *)(iVar4 + 0x204) = 0;
    }
    *(undefined2 *)(iVar4 + 0x200) = 0;
    *(undefined2 *)(iVar4 + 0x202) = 0;
    return;
  }
  return;
}


