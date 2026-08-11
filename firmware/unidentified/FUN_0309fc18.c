/**
 * FUN_0309fc18 @ 0x0309fc18
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0309fc18(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_0309fffc;
  DAT_0309fffc[5] = 0;
  iVar2 = DAT_030a0000;
  puVar1[6] = 0;
  puVar1[4] = 0;
  *(undefined1 *)(iVar2 + 1) = 1;
  uVar3 = FUN_0309d924(*puVar1,puVar1[3],param_1);
  puVar1[puVar1[6] + 9] = uVar3;
  puVar1[7] = 1;
  puVar1[10] = 0;
  FUN_030a3900(0xf2);
  return;
}


