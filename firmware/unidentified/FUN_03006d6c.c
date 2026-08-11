/**
 * FUN_03006d6c @ 0x03006d6c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03006d6c(void)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  ushort *puVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  int *piVar7;
  undefined2 *puVar8;
  uint *puVar9;
  short *psVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  uint extraout_r3;
  uint extraout_r3_00;
  uint unaff_r7;
  bool bVar19;
  undefined4 local_50;
  ushort local_4c [2];
  short sStack_48;
  undefined2 uStack_46;
  short sStack_44;
  undefined2 uStack_42;
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  undefined4 local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  puVar4 = DAT_03007098;
  local_30 = (uint)*DAT_03007098;
  local_34 = (uint)DAT_03007098[1];
  local_38 = FUN_02fee568(1);
  local_50 = FUN_02fee544(2);
  puVar5 = DAT_0300709c;
  *puVar4 = 0xffff;
  puVar4[1] = *puVar5;
  iVar11 = FUN_02ff2e44(0x26);
  pcVar3 = DAT_030070a4;
  puVar5 = DAT_030070a0;
  if (((iVar11 != 0) || (iVar11 = FUN_02ff2e00(0x39), iVar11 != 0)) ||
     (iVar11 = FUN_02ff2e00(0x2f), iVar11 != 0)) {
    FUN_02feee16(0x4f);
    *DAT_03007084 = 0;
    FUN_02ff2de4(0x3b);
    FUN_02ff2de4(0x52);
    FUN_02ff2de4(0x43);
    FUN_02ff2de4(0x44);
    FUN_02ff2de4(0x45);
    FUN_02ff2de4(0x1a9);
    FUN_02ff2de4(0x3a);
    FUN_02ff2de4(0x46);
    *DAT_030070a8 = 0xffffffff;
    pcVar3[2] = '\0';
    if (*puVar5 == 3) {
      pcVar3[6] = '\0';
      pcVar3[7] = '\0';
    }
    else {
      pcVar3[6] = '\x03';
      pcVar3[7] = '\0';
    }
    pcVar3[0x10] = '\0';
    pcVar3[0x11] = '\0';
    pcVar3[0x12] = '\0';
    pcVar3[0x13] = '\0';
    FUN_02fee90a(1);
  }
  iVar11 = FUN_02ff2e00(0x3a);
  if (iVar11 != 0) {
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
  }
  iVar11 = FUN_02ff2e00(0x4e);
  puVar6 = DAT_030070ac;
  if (iVar11 == 1) {
    iVar11 = FUN_03004710(DAT_030070b0);
    if (((iVar11 == 0) && (FUN_0300490a(), *DAT_030070b4 == 0)) && (*(int *)(puVar6 + 0x22) != 1)) {
      *pcVar3 = '\x01';
      FUN_02ff2de4(0x4f);
      FUN_02ff2de4(0x46);
    }
    else {
      FUN_02ff2de4(0x1b0);
      *pcVar3 = '\0';
    }
  }
  FUN_02ff2e00(0x41);
  iVar11 = FUN_02ff2e00(0x42);
  if (iVar11 == 1) {
    if (*puVar5 == 0) {
      uVar18 = 0x53;
    }
    else {
      uVar18 = 0x52;
    }
    FUN_02fef2b2(uVar18,5,0x98);
  }
  uVar12 = FUN_02ff2e00(0x1b0);
  uVar16 = DAT_030070bc;
  iVar11 = DAT_030070b8;
  bVar19 = uVar12 == 1;
  if (bVar19) {
    uVar12 = (uint)*puVar5;
  }
  if (bVar19 && uVar12 == 0) {
    uVar12 = *(int *)(pcVar3 + 0x10) + 1;
    *(uint *)(pcVar3 + 0x10) = uVar12;
    cVar1 = *(char *)(iVar11 + 0x34f);
    if (cVar1 == '\x04') {
      FUN_02fef2b2(((uint)((ulonglong)uVar16 * (ulonglong)uVar12 >> 0x23) * 0xc - uVar12) + 0xd1,0,
                   0x35);
    }
    else if (cVar1 == '\x02') {
      FUN_02fef2b2(uVar12 + (uint)((ulonglong)uVar16 * (ulonglong)uVar12 >> 0x23) * -0xc + 0xc6,0,
                   0x35);
    }
    else {
      iVar13 = uVar12 + (uint)((ulonglong)uVar16 * (ulonglong)uVar12 >> 0x23) * -0xc + 0xc6;
      if (cVar1 == '\x03') {
        FUN_02fef2b2(iVar13,0,0x36);
      }
      else {
        FUN_02fef2b2(iVar13,0,0x37);
      }
    }
  }
  iVar13 = FUN_02ff2e00(0x46);
  piVar7 = DAT_030070c0;
  if (iVar13 == 1) {
    FUN_02ff2de4(0x43);
    *puVar4 = 0xffff;
    FUN_030055c6();
    uVar18 = 1;
    iVar13 = *piVar7;
    if (*DAT_030070c4 < 8) {
      uVar18 = *(undefined4 *)(iVar13 + 0x9c);
      uVar17 = *(undefined4 *)(iVar13 + 8);
      uVar14 = *(undefined4 *)(iVar13 + 0xc);
    }
    else {
      uVar17 = *(undefined4 *)(iVar13 + 8);
      uVar14 = *(undefined4 *)(iVar13 + 0xc);
    }
    FUN_0300512a(uVar14,uVar17,uVar18);
    FUN_03004f16(puVar6[1],*puVar6);
  }
  iVar13 = FUN_02ff2e00(0x45);
  if (iVar13 == 1) {
    FUN_02fef2b2(*(byte *)(*piVar7 + 0x28) + 0xbc,0xf0,3);
    FUN_02fef2b2(*(byte *)(iVar11 + 0x358) + 0x102,0x88,4);
  }
  iVar11 = FUN_02ff2e00(0x48);
  if (iVar11 == 1) {
    *puVar4 = *DAT_030070c8;
  }
  iVar11 = FUN_02ff2e00(0x4c);
  if (iVar11 == 1) {
    puVar15 = (undefined4 *)*piVar7;
    if (*(int *)(puVar6 + 0x22) == 1) {
      if ((uint)puVar15[1] < *(uint *)(puVar6 + 0x24)) {
        puVar15[1] = *(uint *)(puVar6 + 0x24);
      }
      uVar12 = (uint)((puVar15[1] - *(int *)(puVar6 + 0x24)) * 0x121) /
               (uint)(*(int *)(puVar6 + 0x26) - *(int *)(puVar6 + 0x24));
    }
    else {
      uVar12 = func_0x02fdfb60((int)((ulonglong)(uint)puVar15[1] * 0x121),
                               (int)((ulonglong)(uint)puVar15[1] * 0x121 >> 0x20),*puVar15,0);
    }
    *(uint *)(pcVar3 + 8) = uVar12;
    *(uint *)(pcVar3 + 0xc) = uVar12;
    if (uVar12 < 0x123) {
      FUN_03005b44((ushort)DAT_030070cc[2] + 0x13,(ushort)DAT_030070cc[3] + 0x98,
                   (ushort)DAT_030070cc[2] + 0x136);
      puVar8 = DAT_030070cc;
      local_4c[0] = 0;
      if (*(int *)(pcVar3 + 8) != 0) {
        do {
          FUN_02feeb60(puVar8[2] + local_4c[0] + 0x14,puVar8[3] + 0x99,*puVar8,puVar8[1],0x10,
                       DAT_030070d0);
          local_4c[0] = local_4c[0] + 1;
        } while ((uint)local_4c[0] < *(uint *)(pcVar3 + 8));
      }
      uVar18 = DAT_03007500;
      local_2c = (uint)local_4c[0];
      if (local_2c < 0x122) {
        do {
          FUN_02feeb60(DAT_03007504[2] + local_4c[0] + 0x14,DAT_03007504[3] + 0x99,*DAT_03007504,
                       DAT_03007504[1],0x10,uVar18);
          local_4c[0] = local_4c[0] + 1;
        } while (local_4c[0] < 0x122);
      }
      FUN_02fef2b2(0xf6,(int)(short)((short)local_2c + 0x13 + DAT_03007504[2]),
                   (int)(short)(DAT_03007504[3] + 0x98));
    }
  }
  iVar11 = FUN_02ff2e00(0x40);
  if (iVar11 == 1) {
    if (*(int *)(puVar6 + 0x22) == 1) {
      uVar12 = *(int *)(puVar6 + 0x26) - *(int *)(puVar6 + 0x24);
    }
    else {
      uVar12 = *(uint *)*piVar7;
    }
    unaff_r7 = uVar12 / 1000;
    FUN_02fe1968(unaff_r7,local_4c,auStack_40,auStack_3c);
    FUN_0300584c(local_4c[0],auStack_40[0],auStack_3c[0],1);
  }
  iVar11 = FUN_02ff2e00(0x3f);
  puVar9 = DAT_03007508;
  if (iVar11 == 1) {
    if (*(uint *)(*piVar7 + 4) != unaff_r7) {
      unaff_r7 = *(uint *)(*piVar7 + 4);
    }
    uVar12 = unaff_r7 / 1000;
    if (uVar12 != *DAT_03007508) {
      FUN_02ff2de4(0x4c);
      if (*(int *)(puVar6 + 0x22) == 1) {
        uVar16 = *(uint *)(puVar6 + 0x24) / 1000;
        if (uVar12 < uVar16) {
          uVar12 = uVar16;
        }
        uVar12 = uVar12 - uVar16;
      }
      *puVar9 = uVar12;
      FUN_02fe1968(uVar12,local_4c,auStack_40,auStack_3c);
      FUN_0300584c(local_4c[0],auStack_40[0],auStack_3c[0],0);
    }
  }
  iVar13 = FUN_02ff2e00(0x49);
  psVar10 = DAT_03007514;
  iVar11 = DAT_03007510;
  puVar5 = DAT_0300750c;
  if (iVar13 == 1) {
    if (*pcVar3 != '\x01') {
      sStack_44 = 0x122;
      sStack_48 = 0x1e;
      uStack_46 = 0x21;
      uStack_42 = 0x30;
      local_4c[0] = 0;
      do {
        uVar12 = (uint)local_4c[0];
        psVar10[uVar12] = *(short *)(iVar11 + uVar12 * 2 + 0x60);
        iVar13 = DAT_03007518;
        local_4c[0] = (ushort)(uVar12 + 1);
      } while ((uVar12 + 1 & 0xffff) < 0x80);
      if (*psVar10 == 0) {
        local_4c[0] = 0;
        do {
          uVar12 = (uint)local_4c[0];
          sVar2 = *(short *)(iVar13 + uVar12 * 2);
          if (sVar2 == 0) {
            psVar10[local_4c[0]] = 0;
            if (psVar10[uVar12 - 4] == 0x2e) {
              psVar10[uVar12 - 4] = 0;
            }
            if (psVar10[uVar12 - 5] == 0x2e) {
              psVar10[uVar12 - 5] = 0;
            }
            break;
          }
          psVar10[uVar12] = sVar2;
          local_4c[0] = (ushort)(uVar12 + 1);
        } while ((uVar12 + 1 & 0xffff) < 0x80);
      }
      FUN_02fef2b2(0x50);
      uVar12 = FUN_02fed6a6(DAT_03007514);
      if ((uint)((int)sStack_44 - (int)sStack_48) < uVar12) {
        FUN_02fee2a8(&sStack_48,CONCAT22(uStack_46,sStack_48),0x100000,
                     extraout_r3 & 0xffff0000 | 0x50,DAT_03007514,0x1e);
        FUN_02ff2de4(0x4a);
      }
      else {
        FUN_02ff2e26(0x4a);
      }
      *puVar4 = *puVar5;
      FUN_02feda18(&sStack_48,&sStack_48,DAT_03007514,2);
      *puVar4 = 0xffff;
      goto LAB_0300733c;
    }
  }
  else {
LAB_0300733c:
    if (*pcVar3 != '\x01') goto LAB_030073e8;
  }
  FUN_030041b4(0);
  iVar11 = FUN_02ff2e00(0x4f);
  if (iVar11 == 1) {
    sStack_44 = 0x122;
    sStack_48 = 0x1e;
    uStack_42 = 0x30;
    uStack_46 = 0x21;
    FUN_02fef2b2(0x50);
    uVar12 = FUN_02fed6a6(DAT_0300751c);
    if ((uint)((int)sStack_44 - (int)sStack_48) < uVar12) {
      FUN_02fee2a8(&sStack_48,CONCAT22(uStack_46,sStack_48),0x100000,
                   extraout_r3_00 & 0xffff0000 | 0x50,DAT_0300751c,0x1e);
      FUN_02ff2de4(0x4a);
    }
    else {
      FUN_02ff2e26(0x4a);
    }
    *puVar4 = *puVar5;
    FUN_02feda18(&sStack_48,&sStack_48,DAT_0300751c,2);
    iVar11 = FUN_02ff2e44(1);
    if (iVar11 != 0) {
      FUN_02ff2de4(0x33);
    }
  }
LAB_030073e8:
  iVar11 = FUN_02ff2e44(0x4a);
  if (iVar11 == 1) {
    if (*pcVar3 == '\x01') {
      local_50 = FUN_02fee544(2);
      *puVar4 = *puVar5;
      FUN_02fee180(DAT_0300751c);
      *puVar4 = 0xffff;
    }
    else {
      local_50 = FUN_02fee544(2);
      *puVar4 = *puVar5;
      FUN_02fee180(DAT_03007514);
      *puVar4 = 0xffff;
    }
  }
  iVar11 = FUN_02ff2e44(0xae);
  if (iVar11 == 1) {
    local_50 = FUN_02fee544();
    *puVar4 = *puVar5;
    FUN_02fedc4e(DAT_03007520,1);
    *puVar4 = 0xffff;
  }
  iVar11 = FUN_02ff2e44(0xaf);
  if (iVar11 == 1) {
    local_50 = FUN_02fee544();
    *puVar4 = *puVar5;
    FUN_02fedd96(DAT_03007524,1);
    *puVar4 = 0xffff;
  }
  iVar11 = FUN_02ff2e44(0xb0);
  if (iVar11 == 1) {
    local_50 = FUN_02fee544();
    *puVar4 = *puVar5;
    FUN_02fedede(DAT_03007528,1);
    *puVar4 = 0xffff;
  }
  FUN_02fee568(local_38);
  puVar4[1] = (ushort)local_34;
  *puVar4 = (ushort)local_30;
  FUN_02fee544(local_50);
  return;
}


