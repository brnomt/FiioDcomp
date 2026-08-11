/**
 * FUN_0300634c @ 0x0300634c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300634c(void)

{
  short sVar1;
  char *pcVar2;
  ushort *puVar3;
  ushort *puVar4;
  int *piVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  uint *puVar8;
  short *psVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  ushort *puVar13;
  ushort uVar14;
  ushort uVar15;
  int iVar16;
  uint uVar17;
  undefined4 uVar18;
  undefined4 *puVar19;
  int iVar20;
  uint uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  uint extraout_r3;
  uint unaff_r8;
  bool bVar24;
  short local_50;
  short local_4e;
  short local_4c;
  short local_4a;
  ushort local_48 [2];
  undefined4 local_44;
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  undefined4 local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  puVar3 = DAT_0300674c;
  local_30 = (uint)*DAT_0300674c;
  local_34 = (uint)DAT_0300674c[1];
  local_38 = FUN_02fee568(1);
  local_44 = FUN_02fee544(2);
  puVar4 = DAT_03006750;
  *puVar3 = 0xffff;
  puVar3[1] = *puVar4;
  iVar16 = FUN_02ff2e44(0x26);
  pcVar2 = DAT_03006758;
  puVar4 = DAT_03006754;
  if (((iVar16 != 0) || (iVar16 = FUN_02ff2e00(0x39), iVar16 != 0)) ||
     (iVar16 = FUN_02ff2e00(0x2f), iVar16 != 0)) {
    FUN_02feee16(0x145);
    *DAT_0300675c = 0;
    FUN_02ff2de4(0x3b);
    FUN_02ff2de4(0x52);
    FUN_02ff2de4(0x43);
    FUN_02ff2de4(0x44);
    FUN_02ff2de4(0x45);
    FUN_02ff2de4(0x1a9);
    FUN_02ff2de4(0x3a);
    FUN_02ff2de4(0x46);
    FUN_02ff2e26(0xae);
    FUN_02ff2e26(0xaf);
    FUN_02ff2e26(0xb0);
    *DAT_03006760 = 0xffffffff;
    pcVar2[2] = '\0';
    if (*puVar4 == 3) {
      pcVar2[6] = '\0';
      pcVar2[7] = '\0';
    }
    else {
      pcVar2[6] = '\x03';
      pcVar2[7] = '\0';
    }
    pcVar2[0x10] = '\0';
    pcVar2[0x11] = '\0';
    pcVar2[0x12] = '\0';
    pcVar2[0x13] = '\0';
    FUN_02fee90a(1);
    piVar5 = DAT_03006764;
    if (*DAT_03006764 != -1) {
      FUN_02fe3c0c((int)(char)*DAT_03006764);
      *piVar5 = -1;
    }
  }
  iVar16 = FUN_02ff2e00(0x3a);
  if (iVar16 != 0) {
    FUN_02ff2de4(0x42);
    FUN_02ff2de4(0x4b);
    FUN_02ff2de4(0x46);
    FUN_02ff2de4(0x4c);
    FUN_02ff2de4(0x3f);
    FUN_02ff2de4(0x40);
    FUN_02ff2de4(0x48);
    FUN_02ff2de4(0x49);
    FUN_02ff2de4(0x4e);
    FUN_02ff2de4(0x3b);
    FUN_02ff2e26(0x4a);
    FUN_02ff2de4(0x21);
    FUN_02ff2e26(0xae);
    FUN_02ff2e26(0xaf);
    FUN_02ff2e26(0xb0);
  }
  iVar16 = FUN_02ff2e00(0x4e);
  puVar6 = DAT_03006768;
  if (iVar16 == 1) {
    iVar16 = FUN_03004710(DAT_0300676c);
    if (iVar16 == 0) {
      if (puVar6[1] != *(short *)(DAT_03006770 + 2)) {
        *(undefined2 *)(DAT_03006770 + 2) = puVar6[1];
        FUN_02ff2e26(0xae);
        FUN_02ff2e26(0xaf);
        FUN_02ff2e26(0xb0);
        func_0x02fde8f6(DAT_03006774,0,0x100);
        func_0x02fde8f6(DAT_03006778,0,0x100);
        func_0x02fde8f6(DAT_0300677c,0,0x100);
      }
      FUN_0300490a();
      if ((*DAT_03006780 == 0) && (*(int *)(puVar6 + 0x22) != 1)) {
        *pcVar2 = '\x01';
        FUN_02ff2de4(0x4f);
        iVar16 = func_0x02fde968(DAT_03006778,DAT_03006774,0x100);
        if (iVar16 == 0) {
          *DAT_03006774 = 0;
        }
        FUN_02ff2e26(0x46);
        goto LAB_03006528;
      }
    }
    FUN_02ff2de4(0x1b0);
    *pcVar2 = '\0';
  }
LAB_03006528:
  iVar16 = FUN_02ff2e00(0x48);
  if (iVar16 == 1) {
    FUN_03004f16(puVar6[1],*puVar6);
  }
  FUN_02ff2e00(0x41);
  iVar16 = FUN_02ff2e00(0x42);
  if (iVar16 == 1) {
    if (*puVar4 == 0) {
      uVar23 = 0x53;
    }
    else {
      uVar23 = 0x52;
    }
    FUN_02fef2b2(uVar23,5,0x98);
  }
  uVar17 = FUN_02ff2e00(0x1b0);
  bVar24 = uVar17 == 1;
  if (bVar24) {
    uVar17 = (uint)*puVar4;
  }
  if (bVar24 && uVar17 == 0) {
    *(int *)(pcVar2 + 0x10) = *(int *)(pcVar2 + 0x10) + 1;
  }
  iVar16 = FUN_02ff2e00(0x46);
  piVar5 = DAT_03006784;
  if (iVar16 == 1) {
    FUN_02ff2de4(0x43);
    *puVar3 = 0xffff;
    FUN_03005bd2();
    uVar23 = 1;
    iVar16 = *piVar5;
    if (*DAT_03006788 < 8) {
      uVar23 = *(undefined4 *)(iVar16 + 0x9c);
      uVar22 = *(undefined4 *)(iVar16 + 8);
      uVar18 = *(undefined4 *)(iVar16 + 0xc);
    }
    else {
      uVar22 = *(undefined4 *)(iVar16 + 8);
      uVar18 = *(undefined4 *)(iVar16 + 0xc);
    }
    FUN_03005e54(uVar18,uVar22,uVar23);
  }
  iVar16 = FUN_02ff2e00(0x45);
  if (iVar16 == 1) {
    FUN_02fef2b2(*(byte *)(*piVar5 + 0x28) + 0xbc,0xf0,3);
    FUN_02fef2b2(*(byte *)(DAT_0300678c + 0x358) + 0x102,0x88,4);
  }
  iVar16 = FUN_02ff2e00(0x48);
  if (iVar16 == 1) {
    *puVar3 = *DAT_03006790;
  }
  iVar16 = FUN_02ff2e00(0x4c);
  if (iVar16 == 1) {
    puVar19 = (undefined4 *)*piVar5;
    if (*(int *)(puVar6 + 0x22) == 1) {
      if ((uint)puVar19[1] < *(uint *)(puVar6 + 0x24)) {
        puVar19[1] = *(uint *)(puVar6 + 0x24);
      }
      uVar17 = (uint)((puVar19[1] - *(int *)(puVar6 + 0x24)) * 0x121) /
               (uint)(*(int *)(puVar6 + 0x26) - *(int *)(puVar6 + 0x24));
    }
    else {
      uVar17 = func_0x02fdfb60((int)((ulonglong)(uint)puVar19[1] * 0x121),
                               (int)((ulonglong)(uint)puVar19[1] * 0x121 >> 0x20),*puVar19,0);
    }
    *(uint *)(pcVar2 + 8) = uVar17;
    *(uint *)(pcVar2 + 0xc) = uVar17;
    if (uVar17 < 0x123) {
      FUN_03005b44((ushort)DAT_03006794[2] + 0x13,(ushort)DAT_03006794[3] + 0x98,
                   (ushort)DAT_03006794[2] + 0x136,(ushort)DAT_03006794[3] + 0x9c);
      puVar7 = DAT_03006794;
      local_48[0] = 0;
      if (*(int *)(pcVar2 + 8) != 0) {
        do {
          FUN_02feeb60(puVar7[2] + local_48[0] + 0x14,puVar7[3] + 0x99,*puVar7,puVar7[1],0x10,
                       DAT_03006798);
          local_48[0] = local_48[0] + 1;
        } while ((uint)local_48[0] < *(uint *)(pcVar2 + 8));
      }
      uVar23 = DAT_0300679c;
      local_2c = (uint)local_48[0];
      if (local_2c < 0x122) {
        do {
          FUN_02feeb60(DAT_03006794[2] + local_48[0] + 0x14,DAT_03006794[3] + 0x99,*DAT_03006794,
                       DAT_03006794[1],0x10,uVar23);
          local_48[0] = local_48[0] + 1;
        } while (local_48[0] < 0x122);
      }
      FUN_02fef2b2(0xf6,(int)(short)((short)local_2c + 0x13 + DAT_03006794[2]),
                   (int)(short)(DAT_03006794[3] + 0x98));
    }
  }
  iVar16 = FUN_02ff2e00(0x40);
  if (iVar16 == 1) {
    if (*(int *)(puVar6 + 0x22) == 1) {
      uVar17 = *(int *)(puVar6 + 0x26) - *(int *)(puVar6 + 0x24);
    }
    else {
      uVar17 = *(uint *)*piVar5;
    }
    unaff_r8 = uVar17 / 1000;
    FUN_02fe1968(unaff_r8,local_48,local_40,local_3c);
    FUN_0300584c(local_48[0],local_40[0],local_3c[0],1);
  }
  iVar16 = FUN_02ff2e00(0x3f);
  puVar8 = DAT_03006c1c;
  if (iVar16 == 1) {
    if (*(uint *)(*piVar5 + 4) != unaff_r8) {
      unaff_r8 = *(uint *)(*piVar5 + 4);
    }
    uVar17 = unaff_r8 / 1000;
    if (uVar17 != *DAT_03006c1c) {
      FUN_02ff2de4(0x4c);
      if (*(int *)(puVar6 + 0x22) == 1) {
        uVar21 = *(uint *)(puVar6 + 0x24) / 1000;
        if (uVar17 < uVar21) {
          uVar17 = uVar21;
        }
        uVar17 = uVar17 - uVar21;
      }
      *puVar8 = uVar17;
      FUN_02fe1968(uVar17,local_48,local_40,local_3c);
      FUN_0300584c(local_48[0],local_40[0],local_3c[0],0);
    }
  }
  iVar20 = FUN_02ff2e00(0x49);
  psVar9 = DAT_03006c28;
  iVar16 = DAT_03006c24;
  puVar4 = DAT_03006c20;
  if (iVar20 == 1) {
    local_48[0] = 0;
    do {
      uVar17 = (uint)local_48[0];
      psVar9[uVar17] = *(short *)(iVar16 + uVar17 * 2 + 0x60);
      iVar20 = DAT_03006c2c;
      local_48[0] = (ushort)(uVar17 + 1);
    } while ((uVar17 + 1 & 0xffff) < 0x80);
    if (*psVar9 == 0) {
      local_48[0] = 0;
      do {
        uVar17 = (uint)local_48[0];
        sVar1 = *(short *)(iVar20 + uVar17 * 2);
        if (sVar1 == 0) {
          psVar9[local_48[0]] = 0;
          if (psVar9[uVar17 - 4] == 0x2e) {
            psVar9[uVar17 - 4] = 0;
          }
          if (psVar9[uVar17 - 5] == 0x2e) {
            psVar9[uVar17 - 5] = 0;
          }
          break;
        }
        psVar9[uVar17] = sVar1;
        local_48[0] = (ushort)(uVar17 + 1);
      } while ((uVar17 + 1 & 0xffff) < 0x80);
    }
    local_4c = 0x140;
    local_50 = 0xa2;
    local_4a = 0x2b;
    local_4e = 0x1c;
    FUN_02fef2b2(0x148);
    uVar17 = FUN_02fed6a6(DAT_03006c28);
    if (uVar17 < ((int)local_4c - (int)local_50) - 0x10U) {
      FUN_02ff2e26(0x4a);
    }
    else {
      FUN_02fee2a8(&local_50,CONCAT22(local_4e,local_50),0x100000,extraout_r3 & 0xffff0000 | 0x148,
                   DAT_03006c28,0x1e);
      FUN_02ff2de4(0x4a);
    }
    *puVar3 = *puVar4;
    FUN_02feda18(&local_50,&local_50,DAT_03006c28,2);
    *puVar3 = 0xffff;
  }
  if (*pcVar2 == '\x01') {
    FUN_030041b4(0);
    iVar16 = FUN_02ff2e00(0x4f);
    if (iVar16 == 1) {
      FUN_02fef2b2(0x146,0xa1,0x32);
      FUN_02fee544(1);
      uVar14 = FUN_02fed6a6(DAT_03006c30);
      if (uVar14 < 0x9b) {
        local_50 = 0xa5;
        local_4e = 0x40;
        local_4c = 0x13f;
        local_4a = 0x56;
      }
      else {
        local_4e = 0x37;
        local_4a = 0x4d;
        if (uVar14 < 0x135) {
          uVar17 = (uVar14 >> 1) + 0xc;
          if (0x9a < uVar17) {
            uVar17 = 0x9a;
          }
          local_50 = (short)((int)(0x9b - uVar17) / 2) + 0xa5;
          local_4c = (short)uVar17 + local_50;
        }
        else {
          local_50 = 0xa5;
          local_4c = 0x13f;
        }
      }
      if (*(char *)(DAT_03006c34 + 0x34f) == '\x01') {
        uVar14 = 0x94b2;
      }
      else {
        uVar14 = 0x528a;
      }
      *puVar3 = uVar14;
      FUN_02feda18(&local_50,&local_50,DAT_03006c30,2);
      uVar14 = FUN_02fed6a6(DAT_03006c38);
      local_4e = 0x50;
      local_4a = 0x71;
      if (uVar14 < 0x1ce) {
        if (uVar14 < 0x134) {
          if (uVar14 < 0x9b) {
            local_50 = 0xa5;
            local_4c = 0x140;
            uVar14 = 1;
          }
          else {
            uVar17 = (uVar14 >> 1) + 0xc;
            uVar14 = 2;
            if (0x9a < uVar17) {
              uVar17 = 0x9a;
            }
            local_50 = (short)((int)(0x9b - uVar17) / 2) + 0xa5;
            local_4c = (short)uVar17 + local_50;
          }
        }
        else {
          uVar14 = 3;
          local_50 = 0xa5;
          local_4c = 0x140;
        }
      }
      else {
        local_4c = 0x140;
        uVar14 = 4;
        local_50 = 0xa5;
        local_4a = 0x8a;
      }
      if (*(char *)(DAT_03006c34 + 0x34f) == '\x04') {
        *puVar3 = 0xffff;
      }
      else if (*(char *)(DAT_03006c34 + 0x34f) == '\x03') {
        *puVar3 = 0;
      }
      else {
        *puVar3 = *puVar4;
      }
      FUN_02feda18(&local_50,&local_50,DAT_03006c38,2);
      func_0x02fde8f6(DAT_03006c30,DAT_03006c38,0x100);
      *DAT_03006c40 = *DAT_03006c3c;
      *DAT_03006c48 = *DAT_03006c44;
      FUN_030041b4();
      FUN_02ff2e00(0x4f);
      *DAT_03006c3c = *DAT_03006c40;
      *DAT_03006c44 = *DAT_03006c48;
      func_0x02fde8f6(DAT_03006c4c,DAT_03006c38,0x100);
      func_0x02fde8f6(DAT_03006c38,DAT_03006c30,0x100);
      if (*(char *)(DAT_03006c34 + 0x34f) == '\x01') {
        uVar15 = 0x94b2;
      }
      else {
        uVar15 = 0x528a;
      }
      *puVar3 = uVar15;
      if (uVar14 < 4) {
        local_4e = uVar14 * 0xc + 0x52;
      }
      else {
        local_4e = 0x76;
      }
      local_4a = local_4e + 0x16;
      uVar15 = FUN_02fed6a6(DAT_03006c4c);
      if ((uVar15 < 0x134) && (0x9a < uVar15)) {
        uVar17 = (uVar15 >> 1) + 0xc;
        if (0x9a < uVar17) {
          uVar17 = 0x9a;
        }
        local_50 = (short)((int)(0x9b - uVar17) / 2) + 0xa5;
        local_4c = (short)uVar17 + local_50;
      }
      else {
        local_50 = 0xa5;
        local_4c = 0x140;
      }
      if (uVar14 < 4) {
        FUN_02feda18(&local_50,&local_50,DAT_03006c4c,2);
      }
      FUN_02fee544(2);
      iVar16 = FUN_02ff2e44(1);
      if (iVar16 != 0) {
        FUN_02ff2de4(0x33);
      }
    }
  }
  iVar16 = FUN_02ff2e00(0x3b);
  piVar11 = DAT_03006c58;
  piVar10 = DAT_03006c54;
  piVar5 = DAT_03006c50;
  if (iVar16 == 0) {
LAB_03006bc8:
    piVar12 = DAT_03006c5c;
    iVar16 = *piVar5;
    bVar24 = iVar16 != 1;
    if (!bVar24) {
      iVar16 = *piVar10;
    }
    if (bVar24 || iVar16 != 0) goto LAB_03006cd2;
    if (*piVar11 == 0) {
      if (*DAT_03006c5c == 0) {
        iVar16 = 0xff;
      }
      else {
        iVar16 = FUN_0300b832();
        FUN_02ff2de4(0x11c);
      }
      iVar20 = *piVar12 + 1;
      *piVar12 = iVar20;
      if (iVar20 == 1) {
        FUN_02fef2b2(0x15c,0x11,0x16);
      }
      FUN_02fefb54();
      if (iVar16 != 0) goto LAB_03006cd2;
    }
  }
  else {
    *DAT_03006c5c = 0;
    *piVar5 = 0;
    *piVar10 = 0;
    *piVar11 = 0;
    FUN_02ff2e26(0x11c);
    if (*(int *)(puVar6 + 0x22) != 0) {
      *piVar5 = 0;
LAB_03006bc2:
      FUN_02ff2de4(0x43);
      goto LAB_03006bc8;
    }
    FUN_03005968();
    if (*piVar5 != 1) goto LAB_03006bc2;
    if (*piVar10 == 1) goto LAB_03006cd2;
    if (*piVar10 != 0) goto LAB_03006bc2;
    if (*piVar11 == 0) {
      FUN_02ff2c88(0x1a);
      goto LAB_03006bc8;
    }
  }
  FUN_02ff2cd4(0x1a);
  pcVar2 = DAT_03007074;
  FUN_02fe3c0c((int)*DAT_03007074);
  pcVar2[0] = -1;
  puVar13 = DAT_03007078;
  pcVar2[1] = -1;
  pcVar2[2] = -1;
  pcVar2[3] = -1;
  func_0x02fde8f6(DAT_0300707c + (uint)*DAT_03007078 * 0x15e00,DAT_0300707c,0x15e00);
  func_0x02fde8f6(DAT_03007080 + (uint)*puVar13 * 0x4b00,DAT_03007080,0x4b00);
  *piVar10 = 1;
  *piVar11 = 1;
  FUN_02ff2e26(0x11c);
  *DAT_03007084 = 0;
LAB_03006cd2:
  iVar16 = FUN_02ff2e44(0x4a);
  if (iVar16 == 1) {
    local_44 = FUN_02fee544(2);
    *puVar3 = *puVar4;
    FUN_02fee180(DAT_03007088);
    *puVar3 = 0xffff;
  }
  iVar16 = FUN_02ff2e44(0xae);
  if (iVar16 == 1) {
    local_44 = FUN_02fee544();
    *puVar3 = *puVar4;
    FUN_02fedc4e(DAT_0300708c,0);
    *puVar3 = 0xffff;
  }
  iVar16 = FUN_02ff2e44(0xaf);
  if (iVar16 == 1) {
    local_44 = FUN_02fee544();
    *puVar3 = *puVar4;
    FUN_02fedd96(DAT_03007090,0);
    *puVar3 = 0xffff;
  }
  iVar16 = FUN_02ff2e44(0xb0);
  if (iVar16 == 1) {
    local_44 = FUN_02fee544();
    *puVar3 = *puVar4;
    FUN_02fedede(DAT_03007094,0);
    *puVar3 = 0xffff;
  }
  FUN_02fee568(local_38);
  puVar3[1] = (ushort)local_34;
  *puVar3 = (ushort)local_30;
  FUN_02fee544(local_44);
  return;
}


