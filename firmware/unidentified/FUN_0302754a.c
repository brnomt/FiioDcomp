/**
 * FUN_0302754a @ 0x0302754a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined1 FUN_0302754a(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar2 = DAT_03027874;
  if (*(int *)(DAT_03027874 + 0x5c) == *(int *)(DAT_03027874 + 0x50) + 0x1000) {
    FUN_03027520();
  }
  puVar3 = *(undefined1 **)(iVar2 + 0x5c);
  uVar1 = *puVar3;
  *(undefined1 **)(iVar2 + 0x5c) = puVar3 + 1;
  return uVar1;
}


