/**
 * FUN_0301f5ca @ 0x0301f5ca
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0301f5ca(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = bitreader_peek(param_1,6);
  iVar1 = DAT_0301f8a0;
  bitreader_refill(param_1,*(undefined1 *)(DAT_0301f8a0 + iVar2 * 2 + 1));
  uVar3 = (uint)*(byte *)(iVar1 + iVar2 * 2);
  if (param_2 == 0) {
    uVar3 = 0xf - uVar3;
  }
  return uVar3;
}


