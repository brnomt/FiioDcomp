/**
 * FUN_0301a126 @ 0x0301a126
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301a126(void)

{
  char cVar1;
  char *pcVar2;
  short *psVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 local_48;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  
  *DAT_0301a47c = 1;
  uVar10 = 0;
  iVar7 = FUN_03008eb4(0x2a);
  pcVar4 = DAT_0301a488;
  psVar3 = DAT_0301a484;
  pcVar2 = DAT_0301a480;
  if ((iVar7 != 0) && (*DAT_0301a484 == 0)) {
    *DAT_0301a488 = '\b';
    FUN_03006134();
    func_0x03006b68();
    FUN_0301ab96(0x120,0);
    if (*pcVar2 == '\0') {
      uVar8 = 0x128;
    }
    else {
      uVar8 = 0x127;
    }
    FUN_03008e98(uVar8);
  }
  iVar7 = FUN_03008eb4(0x1b7);
  puVar5 = DAT_0301a48c;
  if (iVar7 == 0) goto LAB_0301a1bc;
  if (*psVar3 == 0) {
    *pcVar4 = '\b';
    FUN_03006134();
    func_0x03006b68();
    FUN_0301ab96(0x120,0);
    if (*pcVar2 != '\0') goto LAB_0301a252;
LAB_0301a258:
    uVar8 = 0x128;
  }
  else {
    if (*DAT_0301a490 != 3) goto LAB_0301a1bc;
    *pcVar4 = '\b';
    FUN_03006146();
    FUN_0300710a();
    *puVar5 = 0;
    FUN_0301ab96(0x121,0);
    if (*pcVar2 == '\0') goto LAB_0301a258;
LAB_0301a252:
    uVar8 = 0x127;
  }
  FUN_03008e98(uVar8);
LAB_0301a1bc:
  iVar7 = FUN_03008eb4(0x1b5);
  if (iVar7 != 0) {
    *DAT_0301a45c = '\x01';
    puVar6 = DAT_0301a494;
    *pcVar4 = '\b';
    *puVar6 = 1;
    *psVar3 = 0;
    *puVar5 = 0;
    FUN_0301ab96(0x122,1);
    FUN_03008e98(0x128);
  }
  iVar7 = FUN_03008eb4(0x1b6);
  if (iVar7 != 0) {
    *DAT_0301a45c = '\x01';
    puVar6 = DAT_0301a494;
    *pcVar4 = '\b';
    *puVar6 = 1;
    *psVar3 = 0;
    *puVar5 = 0;
    FUN_0301ab96(0x122,0xffffffff);
    FUN_03008e98(0x128);
  }
  iVar7 = FUN_03008eb4(0x131);
  if (iVar7 == 1) {
    FUN_02ff7e7c(DAT_0301a49c,DAT_0301a498);
    iVar7 = FUN_03008ef8(0x157);
    if (iVar7 == 0) {
      local_48._0_3_ = CONCAT21(*(undefined2 *)(DAT_0301a4a0 + 0x1b1),2);
    }
    else {
      local_48._0_3_ = 6;
    }
    local_48 = (uint)(uint3)local_48;
    FUN_030090c2(9,&local_48);
    uVar10 = 1;
  }
  iVar7 = FUN_03008eb4(0x12f);
  if (iVar7 == 1) {
    FUN_02ff7e7c(DAT_0301a49c,DAT_0301a498);
    FUN_030090c2(0,&local_48);
    uVar10 = 1;
  }
  iVar7 = FUN_03008eb4(0x126);
  if (iVar7 == 1) {
    FUN_02ff7e7c(DAT_0301a49c,DAT_0301a498);
    *DAT_0301a4a4 = 1;
    local_48 = 0x460038;
    local_44 = 3;
    local_42 = 0;
    local_40 = 1;
    FUN_03008e98(0x134);
    FUN_02ff7d94(DAT_0301a4ac,DAT_0301a4a8,&local_48);
  }
  iVar7 = FUN_03008eb4(0x130);
  if (iVar7 == 1) {
    *DAT_0301a4a4 = 2;
    local_48 = 0x440038;
    local_44 = 3;
    local_42 = 0;
    local_40 = 1;
    FUN_03008e98(0x134);
    FUN_02ff7d94(DAT_0301a4ac,DAT_0301a4a8,&local_48);
  }
  iVar7 = FUN_03008eb4(0xe3);
  if (iVar7 == 1) {
    uVar9 = *DAT_0301a464;
    *DAT_0301a464 = uVar9 + 1;
    if ((uint)*DAT_0301a4b0 == uVar9 + 1) {
      FUN_02ff7e7c(DAT_0301a49c,DAT_0301a498);
      iVar7 = FUN_03008ef8(0x157);
      if (iVar7 == 0) {
        local_48._0_3_ = CONCAT21(*(undefined2 *)(DAT_0301a4a0 + 0x1b1),2);
      }
      else {
        local_48._0_3_ = 6;
      }
      local_48 = (uint)(uint3)local_48;
      FUN_030090c2(9,&local_48);
      return 1;
    }
    cVar1 = *DAT_0301a45c;
    *pcVar4 = '\b';
    *pcVar2 = '\0';
    if (cVar1 == '\0') {
      FUN_0301ab96(0x122,1);
      FUN_03008e98(0x128);
    }
    else {
      FUN_0301ab96(0x122,0xffffffff);
      FUN_03008e98(0x128);
    }
  }
  if ((*psVar3 == 0) && (*pcVar4 != '\0')) {
    FUN_03008e98(0x12d);
    FUN_03008e98(0x12a);
    FUN_03008e98(0x127);
  }
  iVar7 = FUN_03008ef8(0x21);
  cVar1 = '\0';
  if (iVar7 != 0) {
    cVar1 = *pcVar4;
  }
  if (iVar7 != 0 && cVar1 != '\0') {
    FUN_03008e98(0x129);
  }
  return uVar10;
}


