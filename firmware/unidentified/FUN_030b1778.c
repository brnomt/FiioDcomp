/**
 * FUN_030b1778 @ 0x030b1778
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030b1778(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  
  piVar1 = DAT_030b17a0;
  puVar4 = (undefined1 *)((int)DAT_030b17a0 + -1);
  iVar3 = 0x30;
  do {
    puVar4[1] = 0;
    puVar4 = puVar4 + 2;
    *puVar4 = 0;
    iVar2 = DAT_030b17a4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *piVar1 = DAT_030b17a4;
  puVar4 = (undefined1 *)(iVar2 + -1);
  iVar3 = 0x2828;
  do {
    puVar4[1] = 0;
    puVar4 = puVar4 + 2;
    *puVar4 = 0;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


