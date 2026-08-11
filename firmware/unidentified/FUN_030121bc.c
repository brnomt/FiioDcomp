/**
 * FUN_030121bc @ 0x030121bc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030121bc(uint param_1)

{
  byte *pbVar1;
  uint uVar2;
  
  uVar2 = (uint)*DAT_03012214;
  pbVar1 = DAT_03012214;
  if (uVar2 == 6) {
    return;
  }
  do {
    if (uVar2 == param_1) {
      return;
    }
    pbVar1 = pbVar1 + 8;
    uVar2 = (uint)*pbVar1;
  } while (uVar2 != 6);
  return;
}


