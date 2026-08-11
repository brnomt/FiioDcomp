/**
 * FUN_030099e4 @ 0x030099e4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


bool FUN_030099e4(void)

{
  ushort uVar1;
  byte bVar2;
  char cVar3;
  int *piVar4;
  ushort *puVar5;
  ushort *puVar6;
  undefined2 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  undefined2 *puVar13;
  bool bVar14;
  undefined1 local_48;
  undefined1 uStack_47;
  undefined1 uStack_46;
  undefined1 uStack_45;
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined2 uStack_42;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  iVar8 = FUN_02ff7414(0x9e);
  if (iVar8 != 0) {
    *DAT_03009ce8 = 0;
    local_48 = 2;
    uStack_47 = 0;
    FUN_02ff75de(10,&local_48);
    return true;
  }
  iVar8 = FUN_02ff73d0(0x9d);
  if (iVar8 != 1) goto LAB_03009a4c;
  local_48 = 1;
  uStack_47 = 0x38;
  uStack_46 = 0;
  uVar1 = *DAT_03009ce4;
  if (uVar1 == 1) {
    uStack_45 = 0x28;
LAB_03009a58:
    uStack_44 = 0;
  }
  else {
    if (uVar1 == 0) {
      uStack_45 = 0x29;
      goto LAB_03009a58;
    }
    if (1 < uVar1) goto LAB_03009a4c;
  }
  FUN_02fe62b0(DAT_03009cf0,DAT_03009cec,&local_48);
LAB_03009a4c:
  iVar8 = FUN_02ff73d0(0x9c);
  if (iVar8 == 1) {
    FUN_02fe62b0(DAT_03009cf0,DAT_03009cf4,0);
  }
  iVar8 = FUN_03009920();
  if (iVar8 == 1) {
    FUN_02fe62b0(DAT_03009cf0,DAT_03009cf4,0);
  }
  iVar8 = FUN_02ff7414(0xaf);
  piVar4 = DAT_03009cd8;
  if ((iVar8 == 1) && (iVar8 = FUN_02ff7414(0x82), puVar5 = DAT_03009cf8, iVar8 == 0)) {
    puVar13 = (undefined2 *)*piVar4;
    puVar13[5] = 1;
    *puVar13 = 1;
    puVar13[9] = 0;
    puVar13[0x2a] = 0;
    *(uint *)(puVar13 + 6) = (uint)*puVar5;
    uVar9 = 0;
    do {
      uVar10 = uVar9 + 1 & 0xff;
      puVar13[uVar9 + 10] = 0;
      uVar9 = uVar10;
    } while (uVar10 < 0x1e);
    FUN_02ff73b4(0x92);
    iVar8 = FUN_02ff73d0(0xaf);
    if (iVar8 == 1) {
      FUN_02ff7258(0x1d);
      FUN_03021672(0xaf,1);
      FUN_02ff73b4(0x87);
      FUN_02ff73b4(0x8b);
      FUN_030098d8();
      FUN_02ff73b4(0x88);
      FUN_02ff72a4(0x1d);
    }
  }
  iVar8 = FUN_02ff73d0(0xa1);
  uVar12 = DAT_03009cfc;
  if (iVar8 == 1) {
    *(undefined4 *)(DAT_03009cdc + 8) = 0;
    FUN_02fe62b0(DAT_03009cf0,uVar12,0);
  }
  iVar8 = FUN_02ff73d0(0x93);
  uVar12 = DAT_03009d04;
  bVar14 = iVar8 == 1;
  if (bVar14) {
    *DAT_03009d00 = 0;
    FUN_02fe6398(DAT_03009d08,uVar12);
    local_48 = 7;
    FUN_02ff75de(0,&local_48);
  }
  iVar11 = FUN_02ff7414(0xa3);
  iVar8 = DAT_03009cd4;
  if (iVar11 == 1) {
    FUN_02ff73f6(0xa3);
    *DAT_03009d0c = *(undefined4 *)(*piVar4 + 0xc);
    *DAT_03009d10 = 1;
    FUN_02ff73f6(0x21);
    FUN_02ff73b4(0xaa);
    puVar6 = DAT_03009d18;
    puVar5 = DAT_03009d14;
    bVar2 = *(byte *)(iVar8 + 0x219);
    uVar1 = *DAT_03009d14;
    bVar14 = *(byte *)(iVar8 + 0x21a) == uVar1;
    if (bVar14) {
      uVar1 = *DAT_03009d18;
    }
    if (!bVar14 || bVar2 != uVar1) {
      *DAT_03009d14 = (ushort)*(byte *)(iVar8 + 0x21a);
      *puVar6 = (ushort)bVar2;
      FUN_02ff04aa();
      FUN_03020ff0(*puVar6,*puVar5);
      FUN_03021220(*DAT_03009d1c);
    }
    cVar3 = *(char *)(iVar8 + 0x219);
    if (cVar3 == '\0') {
      local_38 = 0xf;
      local_34 = 0;
      local_40 = 32000;
    }
    else if (cVar3 == '\x01') {
      local_38 = 0xf;
      local_34 = 0;
      local_40 = 0xac44;
    }
    else if (cVar3 == '\x02') {
      local_40 = 32000;
      local_38 = 0x17;
      local_34 = 2;
    }
    else if (cVar3 == '\x03') {
      local_40 = 0xac44;
      local_38 = 0x17;
      local_34 = 2;
    }
    else {
      local_40 = 48000;
      local_38 = 0x17;
      local_34 = 2;
    }
    uStack_45 = 0;
    uStack_46 = 0;
    uStack_47 = 0;
    local_48 = 5;
    local_30 = 1;
    local_3c = 2;
    uStack_44 = 1;
    uStack_43 = 0;
    uStack_42 = 0;
    FUN_02ff75de(7,&local_48);
    bVar14 = true;
  }
  iVar11 = FUN_02ff7414(0xa4);
  if (iVar11 == 1) {
    FUN_02ff73f6(0xa4);
    uVar12 = FUN_02fe7990(s_U__RECORD_03009d20);
    iVar11 = FUN_02fe9e42(uVar12,DAT_03009d30,3);
    if (iVar11 == 0) {
      local_48 = 0x38;
      uStack_47 = 0;
      uStack_46 = 0x47;
      uStack_45 = 0;
      uStack_44 = 2;
      uStack_43 = 0;
      uStack_42 = 0;
      local_40 = CONCAT22(local_40._2_2_,1);
      FUN_02fe62b0(DAT_03009cf0,DAT_03009d34,&local_48);
    }
    else {
      FUN_02ff73b4(0x1cd);
      *(undefined1 *)(iVar8 + 0x6d) = 0;
      local_48 = 5;
      uVar12 = FUN_02fe7990(s_U__RECORD_03009d20);
      uVar7 = FUN_02fe9e42(uVar12,DAT_03009d30,3);
      uStack_47 = (undefined1)uVar7;
      uStack_46 = (undefined1)((ushort)uVar7 >> 8);
      uVar12 = FUN_02fe7990(s_U__RECORD_03009d20);
      uVar7 = FUN_02fea610(CONCAT11(uStack_46,uStack_47),uVar12,DAT_03009d30,3);
      uStack_47 = (undefined1)uVar7;
      uStack_46 = (undefined1)((ushort)uVar7 >> 8);
      FUN_02ff75de(9,&local_48);
      bVar14 = true;
    }
  }
  iVar8 = FUN_02ff73d0(0xa6);
  if (iVar8 == 1) {
    local_48 = 0x38;
    uStack_47 = 0;
    uStack_46 = 0x37;
    uStack_45 = 0;
    uStack_44 = 3;
    uStack_43 = 0;
    uStack_42 = 0;
    local_40 = CONCAT22(local_40._2_2_,1);
    FUN_02fe62b0(DAT_03009cf0,DAT_03009d34,&local_48);
  }
  iVar8 = FUN_02ff73d0(0xe3);
  if (iVar8 == 1) {
    FUN_02ff73b4(0xa1);
  }
  if (*(short *)(DAT_0300a12c + 4) == 2) {
    *(undefined2 *)(DAT_0300a12c + 4) = 0;
    FUN_02ff73b4(0x91);
  }
  return bVar14;
}


