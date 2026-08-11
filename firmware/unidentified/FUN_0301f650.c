/**
 * FUN_0301f650 @ 0x0301f650
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0301f650(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = bitreader_peek(param_1,0xc);
  uVar3 = 0xc;
  do {
    if (uVar1 == 1) {
      bitreader_refill(param_1,uVar3);
      return uVar3;
    }
    uVar1 = uVar1 >> 1;
    uVar3 = uVar3 - 1;
  } while (2 < uVar3);
  iVar2 = FUN_0301e89a(param_1,2);
  return 3 - iVar2;
}


