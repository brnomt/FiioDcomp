/**
 * FUN_0301f616 @ 0x0301f616
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0301f616(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = bitreader_peek(param_1,0xb);
  iVar1 = DAT_0301f8a4;
  iVar3 = 0xb;
  do {
    if (iVar2 == 1) {
      bitreader_refill(param_1,iVar3);
      return iVar3 + 1;
    }
    iVar2 = iVar2 >> 1;
    iVar3 = iVar3 + -1;
  } while (3 < iVar3);
  bitreader_refill(param_1,*(undefined1 *)(DAT_0301f8a4 + iVar2 * 2 + 1));
  return (uint)*(byte *)(iVar1 + iVar2 * 2);
}


