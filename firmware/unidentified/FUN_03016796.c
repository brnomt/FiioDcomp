/**
 * FUN_03016796 @ 0x03016796
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03016796(void)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  bool bVar7;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  uVar6 = 0;
  iVar4 = ui_refresh_and_redraw(0xc9);
  if ((iVar4 != 0) && (100 < (uint)(*DAT_03016afc - *DAT_03016b00))) {
    func_0x030037a8(199);
    ui_post_redraw(0xc9);
  }
  iVar5 = func_0x030037c4(0x6a);
  iVar4 = DAT_03016b04;
  if (iVar5 != 0) {
    func_0x030037a8(0x1cc);
    local_40 = CONCAT31(local_40._1_3_,5);
    *(undefined1 *)(iVar4 + 0x6d) = 0;
    uVar6 = FUN_02ff3d84(s_U__RECORD_03016b08);
    uVar3 = FUN_02ff6236(uVar6,DAT_03016b18,3);
    local_40._0_3_ = CONCAT21(uVar3,(undefined1)local_40);
    uVar6 = FUN_02ff3d84(s_U__RECORD_03016b08);
    uVar3 = FUN_02ff6a04(local_40._1_2_,uVar6,DAT_03016b18,3);
    local_40._0_3_ = CONCAT21(uVar3,(undefined1)local_40);
    FUN_030039d2(9,&local_40);
    return 0xffff;
  }
  iVar5 = func_0x030037c4(0x7d);
  puVar1 = DAT_03016b1c;
  if (iVar5 != 0) {
    iVar5 = FUN_02ff2834(*DAT_03016b1c,DAT_03016b20);
    if ((iVar5 == 1) && (FUN_02ff278c(puVar1,DAT_03016b20), *DAT_03016b24 != '\0')) {
      *(undefined1 *)(iVar4 + 0x6c) = 1;
    }
    local_38 = (uint)*(byte *)(iVar4 + 0x219);
    if (local_38 == 0) {
      local_30 = 0xf;
      local_2c = 0;
      local_38 = 32000;
      uStack_34 = 1;
    }
    else if (local_38 == 1) {
      local_30 = 0xf;
      local_2c = 0;
      local_38 = 0xac44;
      uStack_34 = 1;
    }
    else if (local_38 == 2) {
      local_38 = 32000;
      uStack_34 = 2;
      local_30 = 0x17;
      local_2c = 2;
    }
    else {
      bVar7 = local_38 != 3;
      if (bVar7) {
        local_38 = 48000;
      }
      local_30 = 0x17;
      if (!bVar7) {
        local_38 = 0xac44;
      }
      uStack_34 = 2;
      local_2c = 2;
    }
    local_28 = 0;
    local_40 = 0;
    local_3c = 3;
    FUN_030039d2(7,&local_40);
    return 1;
  }
  iVar5 = ui_refresh_and_redraw(200);
  if (iVar5 != 0) {
    local_40 = CONCAT22(local_40._2_2_,*(undefined2 *)(iVar4 + 0x21d));
    FUN_030039d2(8,&local_40);
    return 1;
  }
  iVar5 = func_0x030037c4(0xdf);
  if (iVar5 != 0) {
    iVar5 = func_0x030037c4(0xbe);
    if (iVar5 != 0) {
      local_40 = 0x3f0038;
      local_3c = 10;
      local_38 = CONCAT22(local_38._2_2_,1);
      FUN_02ff26a4(DAT_03016b2c,DAT_03016b28,&local_40);
      func_0x030037a8(0xc0);
    }
    iVar5 = func_0x030037c4(0xc1);
    if (iVar5 != 0) {
      CP932toUnicode();
      iVar5 = FUN_02ff2834(*puVar1,DAT_03016b20);
      if (iVar5 == 1) {
        FUN_02ff278c(DAT_03016b1c,DAT_03016b20);
      }
      *(undefined1 *)(iVar4 + 0x34a) = 0;
      *(undefined1 *)(iVar4 + 0x34b) = 0;
      FUN_02fed9e4(2,7,0);
      FUN_02ff17e4(2,7,1);
      FUN_02ff181e(2,7,0);
      FUN_02fed9e4(2,0x11,0);
      FUN_02ff17e4(2,0x11,1);
      FUN_02ff181e(2,0x11,0);
      FUN_02fed9e4(2,0x10,0);
      FUN_02ff17e4(2,0x10,1);
      FUN_02ff181e(2,0x10,0);
      FUN_03019218();
      FUN_0301921a();
      FUN_0301921c();
      FUN_03008eec(1);
      func_0x030037a8(199);
      FUN_02fef650();
      *(undefined1 *)(iVar4 + 0x357) = 0x55;
      FUN_03008eec(1);
      local_40 = CONCAT22(local_40._2_2_,9);
      FUN_030039d2(10,&local_40);
      uVar6 = 1;
    }
    iVar5 = ui_refresh_and_redraw(0xd3);
    puVar1 = DAT_03016b30;
    if (iVar5 != 0) {
      func_0x030037a8(199);
      FUN_0301672a();
      local_40 = 0x430038;
      local_3c = 1;
      local_38 = CONCAT22(local_38._2_2_,1);
      *puVar1 = DAT_03016b34;
      FUN_02ff26a4(DAT_03016b2c,DAT_03016b28,&local_40);
      *(undefined2 *)(iVar4 + 0x42) = 1;
      FUN_03008eec(1);
    }
    iVar5 = func_0x030037c4(0xd4);
    if (iVar5 != 0) {
      func_0x030037a8(199);
      FUN_0301672a();
      local_40 = 0x430038;
      local_3c = 1;
      local_38 = CONCAT22(local_38._2_2_,1);
      *puVar1 = DAT_03016b38;
      *(undefined2 *)(iVar4 + 0x42) = 1;
      FUN_03008eec(1);
      FUN_02ff26a4(DAT_03016b2c,DAT_03016b28,&local_40);
    }
  }
  iVar5 = func_0x030037c4(0xe0);
  if (iVar5 != 0) {
    uVar6 = 0;
    ui_post_redraw(0xd3);
    ui_post_redraw(0xd4);
    func_0x030037c4(0xbe);
    func_0x030037c4(0xc1);
    func_0x030037a8(199);
    ui_post_redraw(0x154);
  }
  iVar5 = func_0x030037c4(0xe3);
  if (iVar5 != 0) {
    func_0x030037c4(0xc0);
    func_0x030037a8(199);
    iVar5 = func_0x030037c4(0xd3);
    if (iVar5 != 0) {
      *(undefined2 *)(iVar4 + 0x42) = 1;
      *(undefined1 *)(iVar4 + 0x6c) = 0;
      local_40 = local_40 & 0xffff0000;
      FUN_030039d2(0xd,&local_40);
      uVar6 = 1;
    }
    func_0x030037c4(0xc0);
    func_0x030037a8(199);
  }
  iVar5 = ui_refresh_and_redraw(0xae);
  iVar4 = DAT_03016b3c;
  if ((iVar5 == 1) && (iVar5 = FUN_03002c9a(), 0x1e < (uint)(iVar5 - *(int *)(iVar4 + 0x18)))) {
    *(int *)(iVar4 + 0x18) = iVar5;
    bVar2 = *(char *)(iVar4 + 1) + 1;
    *(byte *)(iVar4 + 1) = bVar2;
    if (0xe < bVar2) {
      *(undefined1 *)(iVar4 + 1) = 0;
    }
    func_0x030037a8(0x1b0);
  }
  iVar5 = ui_refresh_and_redraw(0xaf);
  if ((iVar5 == 1) && (iVar5 = FUN_03002c9a(), 0x1e < (uint)(iVar5 - *(int *)(iVar4 + 0x18)))) {
    *(int *)(iVar4 + 0x18) = iVar5;
    bVar2 = *(char *)(iVar4 + 1) + 1;
    *(byte *)(iVar4 + 1) = bVar2;
    if (0xe < bVar2) {
      *(undefined1 *)(iVar4 + 1) = 0;
    }
    func_0x030037a8(0xac);
  }
  return uVar6;
}


