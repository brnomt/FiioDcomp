/**
 * FUN_0306e538 @ 0x0306e538
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0306e538(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0306e898;
  iVar2 = *DAT_0306e8a0 + *DAT_0306e8a4 * 2;
  if (iVar2 == *(int *)(DAT_0306e898 + 4)) {
    iVar2 = DAT_0306e8a0[1] + *DAT_0306e8a4 * 2;
    *(int *)(DAT_0306e898 + 4) = iVar2;
  }
  else {
    *(int *)(DAT_0306e898 + 4) = iVar2;
  }
  *(int *)(*(int *)(iVar1 + 0x1c) + 0x2c) = iVar2;
  return;
}


