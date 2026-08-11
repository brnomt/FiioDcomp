/**
 * FUN_030e7f44 @ 0x030e7f44
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030e7f44(int param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_030e8344;
  uVar2 = *DAT_030e8344;
  *DAT_030e8344 = uVar2 + param_1;
  if (0x183ff < uVar2 + param_1) {
    hifi_debug_printf_sync_ovl_0e45(DAT_030e8348);
  }
  return (*puVar1 - param_1) + DAT_030e834c;
}


