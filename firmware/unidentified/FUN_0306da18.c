/**
 * FUN_0306da18 @ 0x0306da18
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0306da18(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_0306de04;
  DAT_0306de04[5] = 0;
  iVar2 = DAT_0306de08;
  puVar1[6] = 0;
  puVar1[4] = 0;
  *(undefined1 *)(iVar2 + 1) = 1;
  uVar3 = HifiFileRead(*puVar1,puVar1[3],param_1);
  puVar1[puVar1[6] + 8] = uVar3;
  puVar1[7] = 1;
  puVar1[9] = 0;
  event_set(0x115);
  return;
}


