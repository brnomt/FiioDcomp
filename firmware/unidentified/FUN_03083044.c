/**
 * FUN_03083044 @ 0x03083044
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03083044(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_03083430;
  DAT_03083430[5] = 0;
  iVar2 = DAT_03083434;
  puVar1[6] = 0;
  puVar1[4] = 0;
  *(undefined1 *)(iVar2 + 1) = 1;
  uVar3 = HifiFileRead_ovl(*puVar1,puVar1[3],param_1);
  puVar1[puVar1[6] + 8] = uVar3;
  puVar1[7] = 1;
  puVar1[9] = 0;
  FUN_0308392c(0x102);
  return;
}


