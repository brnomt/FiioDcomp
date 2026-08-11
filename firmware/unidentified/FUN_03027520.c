/**
 * FUN_03027520 @ 0x03027520
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03027520(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = DAT_03027874;
  puVar1 = (undefined4 *)(DAT_03027874 + 0x50);
  *(undefined4 *)(DAT_03027874 + 0x5c) = *puVar1;
  iVar4 = FUN_03026bae(*puVar1,0x1000);
  if (iVar4 < 0x1000) {
    puVar3 = (undefined2 *)(iVar4 + *(int *)(iVar2 + 0x50));
    for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar3 = 0xd9ff;
      puVar3 = puVar3 + 1;
    }
    return;
  }
  return;
}


