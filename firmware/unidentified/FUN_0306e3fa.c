/**
 * FUN_0306e3fa @ 0x0306e3fa
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0306e3fa(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  *DAT_0306e48c = 0x11;
  iVar2 = DAT_0306e490;
  *(undefined4 *)(DAT_0306e490 + 4) = _DAT_e000e100;
  puVar1 = DAT_0306e464;
  _DAT_e000e180 = 0xffffffff;
  *DAT_0306e464 = 0;
  if (puVar1[1] == 2) {
    puVar1[2] = 1;
  }
  else if (puVar1[1] == 4) {
    FUN_0306edd6();
    FUN_0306ef32();
    puVar1[3] = 1;
  }
  puVar1[1] = 5;
  _DAT_e000e100 = *(undefined4 *)(iVar2 + 4);
  return;
}


