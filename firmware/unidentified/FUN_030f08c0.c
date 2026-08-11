/**
 * FUN_030f08c0 @ 0x030f08c0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030f08c0(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_030f0cac;
  DAT_030f0cac[5] = 0;
  iVar2 = DAT_030f0cb0;
  puVar1[6] = 0;
  puVar1[4] = 0;
  *(undefined1 *)(iVar2 + 1) = 1;
  uVar3 = FUN_030ecd50(*puVar1,puVar1[3],param_1);
  puVar1[puVar1[6] + 8] = uVar3;
  puVar1[7] = 1;
  puVar1[9] = 0;
  FUN_030f11a8(0x115);
  return;
}


