/**
 * FUN_030e4fca @ 0x030e4fca
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030e4fca(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined1 uStack_21;
  undefined4 uStack_20;
  
  uVar2 = 0;
  uStack_20 = param_4;
  if (param_2 == 0) {
    return;
  }
  do {
    hifi_debug_printf_sync_ovl_0e45(&DAT_030e536c);
    do {
      if (((uVar2 & 3) == 0) && (uVar2 != 0)) {
        hifi_debug_printf_sync_ovl_0e45(&DAT_030e5370);
      }
      uStack_20 = *param_1;
      iVar1 = 4;
      do {
        hifi_debug_printf_sync_ovl_0e45(s__02x_030e5374,(&uStack_21)[iVar1]);
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      param_1 = param_1 + 1;
      uVar2 = uVar2 + 1;
      if (param_2 <= uVar2) {
        return;
      }
    } while (uVar2 != 0);
  } while( true );
}


