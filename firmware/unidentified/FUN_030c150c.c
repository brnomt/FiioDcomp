/**
 * FUN_030c150c @ 0x030c150c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c150c(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_030c18f8;
  DAT_030c18f8[5] = 0;
  iVar2 = DAT_030c18fc;
  puVar1[6] = 0;
  puVar1[4] = 0;
  *(undefined1 *)(iVar2 + 1) = 1;
  uVar3 = FUN_030bf680(*puVar1,puVar1[3],param_1);
  puVar1[puVar1[6] + 8] = uVar3;
  puVar1[7] = 1;
  puVar1[9] = 0;
  FUN_030cd468(0x115);
  return;
}


