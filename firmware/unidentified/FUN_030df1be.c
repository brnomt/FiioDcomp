/**
 * FUN_030df1be @ 0x030df1be
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030df1be(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 extraout_r1;
  undefined1 auStack_18 [16];
  
  FUN_030dd888(auStack_18,param_2,0x110);
  FUN_030dd7a6(auStack_18,0x10);
  iVar2 = flac_bitstream_getbits_u(auStack_18,0x10);
  param_1[3] = iVar2;
  if (iVar2 < 0x11) {
    iVar2 = 0x10;
  }
  param_1[3] = iVar2;
  FUN_030dd7a6(auStack_18,0x18);
  uVar3 = FUN_030dd7fc(auStack_18,0x18);
  param_1[4] = uVar3;
  uVar3 = FUN_030dd7fc(auStack_18,0x14);
  *param_1 = uVar3;
  iVar2 = flac_bitstream_getbits_u(auStack_18,3);
  param_1[1] = iVar2 + 1;
  iVar2 = flac_bitstream_getbits_u(auStack_18,5);
  param_1[2] = iVar2 + 1;
  iVar2 = FUN_030dd7fc(auStack_18,0x20);
  param_1[6] = iVar2 << 4;
  param_1[7] = 0;
  uVar4 = flac_bitstream_getbits_u(auStack_18,4);
  param_1[6] = uVar4 | param_1[6];
  hifi_debug_printf_ovl_0dc5(DAT_030df584,param_1[3]);
  hifi_debug_printf_ovl_0dc5(DAT_030df588,param_1[4]);
  hifi_debug_printf_ovl_0dc5(DAT_030df58c,extraout_r1,param_1[6],param_1[7]);
  hifi_debug_printf_ovl_0dc5(DAT_030df590,*param_1);
  hifi_debug_printf_ovl_0dc5(DAT_030df594,param_1[1]);
  hifi_debug_printf_ovl_0dc5(DAT_030df598,param_1[2]);
  FUN_030dd6ee(auStack_18,0x40);
  FUN_030dd6ee(auStack_18,0x40);
  puVar1 = DAT_030df59c;
  DAT_030df59c[3] = param_1[3];
  *puVar1 = *param_1;
  puVar1[1] = param_1[1];
  puVar1[2] = param_1[2];
  uVar3 = param_1[7];
  puVar1[6] = param_1[6];
  puVar1[7] = uVar3;
  puVar1[4] = param_1[4];
  return;
}


