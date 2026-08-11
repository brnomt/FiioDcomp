/**
 * FUN_03050a96 @ 0x03050a96
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03050a96(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_03050df0;
  uVar2 = *DAT_03050dec;
  *(uint *)(DAT_03050df0 + 0x4c) = uVar2;
  if (0x1ff < uVar2) {
    *(undefined4 *)(iVar1 + 0x5c) = 0xffffffff;
    if (*(int *)(iVar1 + 0x28) == 2) {
      uVar2 = uVar2 - 0x200;
    }
    else {
      uVar2 = uVar2 * 8 - 0x1000;
    }
    *(uint *)(iVar1 + 0x54) = uVar2 / *(uint *)(DAT_03050df0 + 0x1c);
    return 1;
  }
  FUN_0303a438(0x70);
  return 0;
}


