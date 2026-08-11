/**
 * FUN_030b1740 @ 0x030b1740
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030b1740(undefined1 *param_1,uint param_2)

{
  undefined1 *puVar1;
  int iVar2;
  
  if ((int)param_2 < 1) {
    return;
  }
  puVar1 = param_1 + -1;
  if ((param_2 & 1) != 0) {
    *param_1 = 0;
    puVar1 = param_1;
  }
  iVar2 = (int)param_2 >> 1;
  if (iVar2 == 0) {
    return;
  }
  do {
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


