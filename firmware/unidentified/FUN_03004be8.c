/**
 * FUN_03004be8 @ 0x03004be8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


bool FUN_03004be8(void)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  byte *pbVar4;
  ushort *puVar5;
  undefined4 *puVar6;
  short *psVar7;
  ushort *puVar8;
  int *piVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  undefined4 *puVar14;
  uint uVar15;
  bool bVar16;
  bool bVar17;
  undefined4 local_40;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined2 local_38;
  
  puVar14 = &local_40;
  iVar10 = FUN_02ff2e00(0x122);
  pbVar4 = DAT_03004ffc;
  puVar5 = DAT_03004ff8;
  if (iVar10 != 0) {
    if (*DAT_03005000 != 0) {
      *DAT_03005000 = 0;
      FUN_03011d76(0xfe,0);
      FUN_02ff2de4(0x41);
    }
    puVar6 = DAT_03005004;
    *puVar5 = 0;
    *puVar6 = 1;
    *DAT_03005008 = 1;
    pbVar4[8] = 0;
    pbVar4[9] = 0;
    pbVar4[10] = 0;
    pbVar4[0xb] = 0;
    DSP_GOODEF_Reload(0x110,1);
  }
  iVar10 = FUN_02ff2e00(0xf5);
  if (iVar10 == 1) {
    iVar10 = FUN_02ff2e44(0x159);
    if (iVar10 == 0) {
      FUN_02fe1dc8(DAT_03005010,DAT_0300500c);
      pbVar4[1] = 1;
      local_40 = 0x460038;
      local_3c = 3;
      local_3a = 0;
      local_38 = 1;
      FUN_02fe1ce0(DAT_03005018,DAT_03005014,&local_40);
    }
    else {
      FUN_02ff2de4(0x15a);
    }
  }
  iVar10 = FUN_02ff2e00(0x53);
  bVar16 = iVar10 == 1;
  if (bVar16) {
    FUN_02fe1dc8(DAT_03005010,DAT_0300500c);
    local_40 = local_40 & 0xffffff00;
    FUN_02ff300e(0,&local_40);
  }
  iVar10 = FUN_02ff2e00(0xf2);
  if (iVar10 != 0) {
    FUN_02fe1dc8(DAT_03005010,DAT_0300500c);
    FUN_02ff2de4(0x1ce);
  }
  iVar10 = FUN_02ff2e00(0x55);
  psVar7 = DAT_0300501c;
  if ((iVar10 == 1) || (iVar10 = FUN_02ff2e00(0xf2), iVar10 == 1)) {
    sVar1 = *psVar7;
    pbVar4[1] = 2;
    if (sVar1 == 0x61) {
      FUN_02ff2de4(0xe3);
    }
    else {
      local_40 = 0x440038;
      local_3c = 1;
      local_3a = 0;
      local_38 = 1;
      FUN_02fe1ce0(DAT_03005018,DAT_03005014,&local_40);
    }
    pbVar4[4] = 0;
    pbVar4[5] = 0;
  }
  iVar10 = FUN_02ff2e00(0xe4);
  if (iVar10 == 1) {
    FUN_02ff2de4(0x39);
  }
  iVar10 = FUN_02ff2e00(0xe3);
  piVar9 = DAT_03005028;
  puVar8 = DAT_03005020;
  if (iVar10 != 1) goto LAB_03004e5a;
  if (pbVar4[1] == 2) {
    uVar15 = *DAT_03005024;
    uVar2 = *puVar5;
    uVar3 = DAT_03005020[1];
    *puVar5 = uVar2 + 1;
    uVar12 = (uint)*puVar8;
    if ((((ushort)(uVar2 + 1) < uVar12) && (iVar10 = *(int *)(*piVar9 + 0x1c), iVar10 != 1)) &&
       (((iVar10 != 2 && iVar10 != 0 &&
         ((iVar10 != 6 && iVar10 != 4 && (iVar10 != 7 && iVar10 != 3)))) || (uVar15 < uVar12)))) {
      FUN_03011d76(0xf1,0);
      if (*DAT_0300503c == 1) goto LAB_03004e5a;
      uVar11 = 0x39;
      goto LAB_03004d38;
    }
    *puVar5 = 0;
    iVar10 = DAT_0300502c;
    uVar2 = puVar8[0x79];
    if (uVar2 == 99) {
      local_40 = 6;
LAB_03004e00:
      iVar13 = FUN_02ff2e44(0x159);
      if (iVar13 == 0) {
        uVar11 = 9;
      }
      else {
        FUN_02fe1dc8(DAT_03005010,DAT_0300500c);
        puVar14 = (undefined4 *)0x0;
        uVar11 = 0xf;
      }
      FUN_02ff300e(uVar11,puVar14);
    }
    else {
      if (uVar2 == 10) {
        if (5 < *(int *)(*piVar9 + 0x1c)) {
          uVar3 = uVar3 + *DAT_03005038;
        }
        local_40 = CONCAT13(1,CONCAT21(uVar3,1));
        goto LAB_03004e00;
      }
      iVar13 = DAT_0300502c + 0x4a;
      *DAT_03005030 = uVar2;
      sVar1 = *psVar7;
      local_40 = CONCAT22(sVar1,1);
      func_0x02fdfc5e(&local_3c,iVar13,0x1c);
      *DAT_03005034 = 0;
      if (sVar1 == 0x61) {
        FUN_03011d76(0xf1,0);
      }
      else {
        FUN_02ff300e(2,&local_40);
      }
    }
    *(undefined1 *)(iVar10 + 0x6c) = 0;
  }
  else {
    iVar10 = FUN_02ff2e44(0x159);
    if (iVar10 != 0) {
      uVar11 = 0x15a;
LAB_03004d38:
      FUN_02ff2de4(uVar11);
      goto LAB_03004e5a;
    }
    FUN_02fe1dc8(DAT_03005010,DAT_0300500c);
    local_40 = local_40 & 0xffffff00;
    FUN_02ff300e(0,&local_40);
  }
  bVar16 = true;
LAB_03004e5a:
  uVar12 = FUN_02ff2e00(0x110);
  bVar17 = uVar12 == 1;
  if (bVar17) {
    uVar12 = (uint)*pbVar4;
  }
  if (bVar17 && uVar12 == 1) {
    FUN_030046e0();
  }
  iVar10 = FUN_02ff2e00(0xf7);
  if (iVar10 == 1) {
    FUN_02ff2de4(0x39);
    FUN_02ff82c0();
    FUN_02ff2e26(0x82);
  }
  iVar10 = FUN_02ff2e00(0x112);
  if (iVar10 == 1) {
    FUN_02fe1dc8(DAT_03005010,DAT_0300500c);
    local_40 = local_40 & 0xffffff00;
    FUN_02ff300e(0,&local_40);
    bVar16 = true;
  }
  iVar10 = FUN_02fe1e70(*DAT_03005010,DAT_0300500c);
  if (iVar10 == 0) {
    FUN_02fe1dc8(DAT_03005010,DAT_0300500c);
    local_40 = local_40 & 0xffffff00;
    FUN_02ff300e(0,&local_40);
    bVar16 = true;
  }
  psVar7 = DAT_03005040;
  if (*DAT_03005040 == 0 || *DAT_03005040 == 3) {
    iVar10 = FUN_02ff22d6();
    if (0x28 < (uint)(iVar10 - *DAT_03005044)) {
      *DAT_03005044 = iVar10;
      FUN_02ff2de4(0x3f);
    }
    if ((*psVar7 == 0) &&
       (iVar10 = FUN_02ff22d6(), *(uint *)(pbVar4 + 0x1c) < (uint)(iVar10 - *(int *)(pbVar4 + 0x14))
       )) {
      pbVar4[0x1c] = 10;
      pbVar4[0x1d] = 0;
      pbVar4[0x1e] = 0;
      pbVar4[0x1f] = 0;
      *(int *)(pbVar4 + 0x14) = iVar10;
      FUN_02ff2de4(0x1b0);
    }
  }
  return bVar16;
}


