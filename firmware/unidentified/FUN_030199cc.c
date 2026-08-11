/**
 * FUN_030199cc @ 0x030199cc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030199cc(undefined4 param_1)

{
  int iVar1;
  undefined2 *puVar2;
  
  iVar1 = DAT_03019dcc;
  *DAT_03019dc8 = 0;
  puVar2 = DAT_03019dd0;
  *(undefined1 *)(iVar1 + 0x224) = 0;
  *puVar2 = 0;
  *DAT_03019dd8 = *DAT_03019dd4;
  FUN_03001f96();
  if (*(char *)(iVar1 + 0x224) != '\0') {
    FUN_03005ab2();
    FUN_03006a76();
  }
  FUN_03005abe();
  FUN_03019998(param_1);
  return;
}


