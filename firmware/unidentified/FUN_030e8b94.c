/**
 * FUN_030e8b94 @ 0x030e8b94
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030e8b94(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_030e8f78;
  DAT_030e8f78[5] = 0;
  iVar2 = DAT_030e8f7c;
  puVar1[6] = 0;
  puVar1[4] = 0;
  *(undefined1 *)(iVar2 + 1) = 1;
  uVar3 = FUN_030e3e7c(*puVar1,puVar1[3],param_1);
  puVar1[puVar1[6] + 9] = uVar3;
  puVar1[7] = 1;
  puVar1[10] = 0;
  FUN_030e9468(0xf2);
  return;
}


