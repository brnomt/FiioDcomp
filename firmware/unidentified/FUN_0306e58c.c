/**
 * FUN_0306e58c @ 0x0306e58c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0306e58c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_0306e898;
  *DAT_0306e8a8 = *(undefined4 *)(DAT_0306e898 + 0xc);
  if (param_1 == 1) {
    uVar2 = *(undefined4 *)(iVar1 + 8);
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 4);
  }
  *(undefined4 *)(iVar1 + 0xc) = uVar2;
  FUN_03070abe(*(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(iVar1 + 0x1c));
  *DAT_0306e8ac = 0;
  return;
}


