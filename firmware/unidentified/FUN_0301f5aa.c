/**
 * FUN_0301f5aa @ 0x0301f5aa
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined1 FUN_0301f5aa(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = bitreader_peek(param_1,9);
  iVar1 = DAT_0301f89c;
  bitreader_refill(param_1,*(undefined1 *)(DAT_0301f89c + (uVar2 >> 3) * 2 + 1));
  return *(undefined1 *)(iVar1 + (uVar2 >> 3) * 2);
}


