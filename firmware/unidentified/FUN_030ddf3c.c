/**
 * FUN_030ddf3c @ 0x030ddf3c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ddf3c(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_030de328;
  DAT_030de328[5] = 0;
  iVar2 = DAT_030de32c;
  puVar1[6] = 0;
  puVar1[4] = 0;
  *(undefined1 *)(iVar2 + 1) = 1;
  uVar3 = FUN_030dbed4(*puVar1,puVar1[3],param_1);
  puVar1[puVar1[6] + 8] = uVar3;
  puVar1[7] = 1;
  puVar1[9] = 0;
  FUN_030e0430(0x102);
  return;
}


