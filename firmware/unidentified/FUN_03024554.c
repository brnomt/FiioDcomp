/**
 * FUN_03024554 @ 0x03024554
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03024554(undefined4 param_1)

{
  int iVar1;
  undefined4 local_10;
  
  local_10 = 0xffffffff;
  iVar1 = VorbisOGG_Parser(param_1,&local_10);
  if (iVar1 == 0) {
    return;
  }
  FUN_030241f8(param_1,local_10);
  return;
}


