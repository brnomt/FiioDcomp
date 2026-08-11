/**
 * FUN_030191e4 @ 0x030191e4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030191e4(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_02ff2834(*DAT_03019234,DAT_03019230);
  if (iVar2 == 1) {
    FUN_02ff278c(DAT_03019234,DAT_03019230);
  }
  iVar2 = DAT_03019238;
  uVar3 = 0;
  *(undefined1 *)(DAT_03019238 + 0x1c3) = 0;
  do {
    iVar1 = uVar3 * 2;
    uVar3 = uVar3 + 1;
    *(undefined2 *)(iVar2 + iVar1 + 0x1c6) = 0;
  } while (uVar3 < 0x28);
  return;
}


