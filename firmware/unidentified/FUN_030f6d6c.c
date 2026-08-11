/**
 * FUN_030f6d6c @ 0x030f6d6c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030f6d6c(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_030f7150;
  DAT_030f7150[5] = 0;
  iVar2 = DAT_030f7154;
  puVar1[6] = 0;
  puVar1[4] = 0;
  *(undefined1 *)(iVar2 + 1) = 1;
  uVar3 = FUN_030f49d4(*puVar1,puVar1[3],param_1);
  puVar1[puVar1[6] + 9] = uVar3;
  puVar1[7] = 1;
  puVar1[10] = 0;
  FUN_030f81dc(0xf2);
  return;
}


