/**
 * FUN_0301e8b2 @ 0x0301e8b2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301e8b2(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = bitreader_peek(param_1,1);
  bitreader_refill(param_1,1);
  return uVar1;
}


