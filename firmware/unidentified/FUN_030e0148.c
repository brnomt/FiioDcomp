/**
 * FUN_030e0148 @ 0x030e0148
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e0148(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  
  puVar3 = param_1 + 8;
  iVar1 = FUN_030dfd86(puVar3,&local_38,0);
  if (iVar1 < 0) {
    return 0xffffffff;
  }
  param_1[1] = local_34;
  param_1[0x10] = local_28;
  if (local_30 == 0) {
    local_30 = param_1[2];
  }
  param_1[2] = local_30;
  if (local_30 < 0x11) {
    iVar1 = 0x10 - local_30;
  }
  else {
    iVar1 = 0x20 - local_30;
  }
  param_1[0xe] = iVar1;
  param_1[3] = 0x1200;
  param_1[0xf] = (uint)(0x10 < local_30);
  if (local_2c < 0x1201) {
    param_1[0xc] = local_2c;
    *param_1 = local_38;
    iVar1 = 0;
    if (0 < (int)param_1[1]) {
      do {
        iVar2 = FUN_030dfb90(param_1,iVar1);
        if (iVar2 < 0) {
          return 0xffffffff;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)param_1[1]);
    }
    FUN_030dd8a8(puVar3);
    hifi_flac_helper(param_1 + 8,0x10);
    FUN_030dd7a6(puVar3,0x10);
    return 0;
  }
  hifi_debug_printf_ovl_0dc5(DAT_030e03ec,local_2c);
  return 0xffffffff;
}


