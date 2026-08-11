/**
 * FUN_030b46c6 @ 0x030b46c6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030b46c6(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = ((int)((-3 - param_1) + ((uint)(-3 - param_1 >> 0x1f) >> 0x1e)) >> 2) * -4;
  if (iVar2 < 1) {
    return;
  }
  puVar1 = (undefined4 *)(param_2 + -4);
  iVar2 = iVar2 >> 1;
  do {
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


