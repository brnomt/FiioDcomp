/**
 * FUN_0302b278 @ 0x0302b278
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0302b278(int param_1)

{
  byte *pbVar1;
  short *psVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  bool bVar8;
  
  psVar2 = DAT_0302b534;
  pbVar1 = DAT_0302b528;
  iVar7 = 200;
  if ((*DAT_0302b534 == 0) && (param_1 != 0)) {
    pbVar1[0x24] = 0;
    pbVar1[0x25] = 0;
    pbVar1[0x26] = 0;
    pbVar1[0x27] = 0;
    iVar4 = FUN_0300c714(0x13);
    if (iVar4 == 0) {
      FUN_03005604(0);
    }
    FUN_03005604(0);
  }
  *psVar2 = 4;
  iVar4 = rom_buffer_ready(5);
  while (iVar4 == 1) {
    dac_gain_curve_apply(1);
    iVar7 = iVar7 + -1;
    if (iVar7 == 0) break;
    iVar4 = rom_buffer_ready(5);
  }
  rom_dac_unmute(1,4);
  rom_dma_config(4,1);
  *DAT_0302b548 = 0;
  *DAT_0302b538 = 0;
  uVar5 = FUN_0300c714(0x18);
  bVar8 = uVar5 == 0;
  if (bVar8) {
    uVar5 = (uint)*pbVar1;
  }
  if (bVar8 && uVar5 == 1) {
    piVar6 = *(int **)(pbVar1 + 0xc);
    if (((uint)(*piVar6 - piVar6[1]) < 0x3e9) && (*DAT_0302b558 == 0)) {
      piVar6[1] = *piVar6;
    }
  }
  iVar7 = FUN_0300c714(0x58);
  if (iVar7 != 0) {
    shared_mid_entry_c6f6(0x58);
  }
  if (*(int *)(*(int *)(pbVar1 + 0xc) + 8) != 0x2ee00) {
    iVar4 = *DAT_0302b55c;
    bVar8 = SBORROW4(iVar4,8);
    iVar7 = iVar4 + -8;
    if (iVar4 < 8) {
      iVar7 = *(int *)(*(int *)(pbVar1 + 0xc) + 0x9c);
      bVar8 = SBORROW4(iVar7,0x18);
      iVar7 = iVar7 + -0x18;
    }
    if (iVar7 < 0 != bVar8) {
      FUN_0302ccf8();
    }
  }
  FUN_0300cd00(0x22,7);
  *DAT_0302b560 = 0;
  shared_mid_entry_c6f6(0x4c);
  shared_mid_entry_c6f6(0x3f);
  shared_mid_entry_c6f6(0xf8);
  shared_mid_entry_c6f6(0x4a);
  thunk_FUN_0302ca22();
  FUN_0302ab46();
  FUN_0302db40();
  pcVar3 = DAT_0302b568;
  piVar6 = DAT_0302b564;
  if (*DAT_0302b564 != 0) {
    FUN_02ffd4dc((int)*DAT_0302b568);
    *pcVar3 = -1;
    *piVar6 = 0;
  }
  FUN_03000eb6(&DAT_0302b578,s_PICTURE_OGG_0302b56c);
  FUN_02ffb33c(0xe);
  rom_usb_disconnect(0xe);
  FUN_0300b9b0(0xe);
  FUN_0302dbb8();
  iVar7 = DAT_0302b57c;
  if (*(char *)(DAT_0302b57c + 0xe) == '\x04') {
    uVar5 = FUN_02ff7890();
    bVar8 = uVar5 == 0;
    if (bVar8) {
      uVar5 = (uint)*pbVar1;
    }
    if (bVar8 && uVar5 == 0) {
      shared_frame_epilogue_c6b4(0x53);
      *(undefined1 *)(iVar7 + 0xe) = 2;
      FUN_02ffbf72();
      FUN_0300ac16();
    }
  }
  shared_mid_entry_c6f6(0x1d5);
  shared_mid_entry_c6f6(0x1d4);
  if (param_1 != 0) {
    return 1;
  }
  pbVar1[8] = 0;
  pbVar1[9] = 0;
  pbVar1[10] = 0;
  pbVar1[0xb] = 0;
  iVar7 = FUN_0300c714(0x1db);
  if (iVar7 == 0) {
    *DAT_0302b580 = 1;
  }
  else {
    *DAT_0302b580 = 0xffffffff;
  }
  FUN_0302a74e();
  shared_frame_epilogue_c6b4(0x110);
  return 0;
}


