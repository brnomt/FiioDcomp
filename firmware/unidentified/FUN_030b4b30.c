/**
 * FUN_030b4b30 @ 0x030b4b30
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030b4b30(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_030b4f1c;
  DAT_030b4f1c[5] = 0;
  iVar2 = DAT_030b4f20;
  puVar1[6] = 0;
  puVar1[4] = 0;
  *(undefined1 *)(iVar2 + 1) = 1;
  uVar3 = FUN_030ab020(*puVar1,puVar1[3],param_1);
  puVar1[puVar1[6] + 8] = uVar3;
  puVar1[7] = 1;
  puVar1[9] = 0;
  FUN_030b5418(0x102);
  return;
}


