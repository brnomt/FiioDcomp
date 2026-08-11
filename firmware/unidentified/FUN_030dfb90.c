/**
 * FUN_030dfb90 @ 0x030dfb90
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030dfb90(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  *(int *)(param_1 + 0x34) = *(int *)(param_1 + 8);
  iVar5 = *(int *)(param_1 + 0x40);
  if (param_2 == 0) {
    if (iVar5 != 9) goto LAB_030dfbb8;
  }
  else if (iVar5 != 8 && iVar5 != 10) goto LAB_030dfbb8;
  *(int *)(param_1 + 0x34) = *(int *)(param_1 + 8) + 1;
LAB_030dfbb8:
  hifi_flac_helper(param_1 + 0x20,0x40);
  iVar5 = FUN_030dd7ae(param_1 + 0x20);
  if (iVar5 != 0) {
    hifi_debug_printf_ovl_0dc5(s_invalid_subframe_padding_030dfe98);
    return 0xffffffff;
  }
  uVar2 = flac_bitstream_getbits_u(param_1 + 0x20,6);
  iVar5 = FUN_030dd7ae(param_1 + 0x20);
  uVar7 = (uint)(iVar5 != 0);
  if (iVar5 != 0) {
    while (iVar5 = FUN_030dd7ae(param_1 + 0x20), iVar5 == 0) {
      uVar7 = uVar7 + 1;
    }
    *(uint *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) - uVar7;
  }
  if (0x20 < *(int *)(param_1 + 0x34)) {
    hifi_debug_printf_ovl_0dc5(s_s_>curr_bps_>_32_030dfeb4);
    return 0xffffffff;
  }
  iVar5 = param_1 + param_2 * 0x4800;
  if (uVar2 == 0) {
    uVar3 = FUN_030dd842(param_1 + 0x20);
    uVar2 = *(uint *)(param_1 + 0x30);
    if (0 < (int)uVar2) {
      uVar2 = uVar2 & 1;
      uVar4 = (uint)(uVar2 != 0);
      if (uVar2 != 0) {
        *(undefined4 *)(iVar5 + 0x48) = uVar3;
      }
      if ((int)uVar2 < *(int *)(param_1 + 0x30)) {
        do {
          iVar6 = uVar4 + 1;
          *(undefined4 *)(iVar5 + uVar4 * 4 + 0x48) = uVar3;
          uVar4 = uVar4 + 2;
          *(undefined4 *)(iVar5 + iVar6 * 4 + 0x48) = uVar3;
          uVar2 = uVar2 + 2;
        } while ((int)uVar2 < *(int *)(param_1 + 0x30));
      }
    }
  }
  else if (uVar2 == 1) {
    uVar2 = *(uint *)(param_1 + 0x30);
    iVar6 = 0;
    if (0 < (int)uVar2) {
      do {
        hifi_flac_helper(param_1 + 0x20,0x40);
        uVar3 = FUN_030dd842(param_1 + 0x20,*(undefined4 *)(param_1 + 0x34));
        iVar1 = iVar6 * 4;
        iVar6 = iVar6 + 1;
        *(undefined4 *)(iVar5 + iVar1 + 0x48) = uVar3;
        uVar2 = *(uint *)(param_1 + 0x30);
      } while (iVar6 < (int)uVar2);
    }
  }
  else if (uVar2 - 8 < 5) {
    uVar2 = FUN_030df840(param_1,param_2,uVar2 & 0xfffffff7);
    if ((int)uVar2 < 0) {
      hifi_debug_printf_ovl_0dc5(s___decode_subframe_fixed_fail_030dfec8);
      return 0xffffffff;
    }
  }
  else {
    if ((int)uVar2 < 0x20) {
      hifi_debug_printf_ovl_0dc5(s_invalid_coding_type_030dff04);
      return 0xffffffff;
    }
    uVar2 = FUN_030df9fa(param_1,param_2,(uVar2 & 0xffffffdf) + 1);
    if ((int)uVar2 < 0) {
      hifi_debug_printf_ovl_0dc5(s___decode_subframe_lpc_fail_030dfee8);
      return 0xffffffff;
    }
  }
  uVar4 = 0;
  if (uVar7 != 0) {
    uVar4 = *(uint *)(param_1 + 0x30);
    uVar2 = uVar4;
  }
  if ((uVar7 != 0 && uVar2 != 0) && -1 < (int)uVar4) {
    uVar2 = uVar2 & 1;
    if (uVar2 != 0) {
      *(int *)(iVar5 + 0x48) = *(int *)(iVar5 + 0x48) << (uVar7 & 0xff);
    }
    uVar4 = (uint)(uVar2 != 0);
    if ((int)uVar2 < *(int *)(param_1 + 0x30)) {
      do {
        iVar6 = iVar5 + uVar4 * 4;
        *(int *)(iVar6 + 0x48) = *(int *)(iVar6 + 0x48) << (uVar7 & 0xff);
        iVar6 = iVar5 + (uVar4 + 1) * 4;
        *(int *)(iVar6 + 0x48) = *(int *)(iVar6 + 0x48) << (uVar7 & 0xff);
        uVar4 = uVar4 + 2;
        uVar2 = uVar2 + 2;
      } while ((int)uVar2 < *(int *)(param_1 + 0x30));
    }
  }
  return 0;
}


