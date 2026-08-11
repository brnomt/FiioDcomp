/**
 * FUN_0301e7dc @ 0x0301e7dc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301e7dc(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    rom_dma_or_copy(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x10));
  }
  iVar1 = FUN_0301e3de(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x18),0x2000,param_1 + 0x20);
  do {
  } while (iVar1 == -1);
  uVar2 = iVar1 + *(int *)(param_1 + 0x18);
  *(uint *)(param_1 + 0x18) = uVar2;
  if (uVar2 < 4) {
    *(undefined4 *)(param_1 + 0x18) = 4;
  }
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x14);
  return;
}


