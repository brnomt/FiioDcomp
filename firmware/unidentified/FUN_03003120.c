/**
 * FUN_03003120 @ 0x03003120
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03003120(undefined4 param_1,int param_2,int param_3,int param_4)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  short sVar7;
  short sVar8;
  undefined2 uVar9;
  ushort uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  undefined2 unaff_r4;
  ushort uVar15;
  undefined4 uVar16;
  undefined2 unaff_r7;
  uint unaff_r11;
  undefined1 auStack_26c [512];
  short local_6c;
  undefined2 local_6a;
  undefined2 local_68;
  undefined2 local_66;
  undefined2 local_64;
  
  *(undefined2 *)(param_4 + param_2) = unaff_r4;
  *(undefined2 *)(param_2 * 2) = unaff_r7;
  puVar3 = DAT_03003564;
  puVar2 = DAT_03003560;
  puVar1 = DAT_03003558;
  if (*DAT_03003558 == 8 || *DAT_03003558 == 9) {
    iVar11 = func_0x02fdf14c(*DAT_0300355c,DAT_03003568,param_3 + -0x55);
    if (iVar11 == 1) {
      if ((puVar2[0x79] == *puVar1) && (puVar3[puVar3[5] + 6] == puVar2[1])) goto LAB_03003214;
      goto LAB_03003204;
    }
LAB_0300318a:
    *(undefined1 *)(DAT_0300356c + 0x6c) = 0;
  }
  else {
    iVar11 = func_0x02fdf14c(*DAT_0300355c,DAT_03003568,param_3 + -0x55);
    if (iVar11 != 1) goto LAB_0300318a;
    if ((((puVar2[0x79] == *puVar1) &&
         (uVar12 = (uint)puVar3[5], (uint)puVar3[uVar12 + 6] == puVar2[1] - 1)) &&
        (puVar3[uVar12 + 1] == puVar2[uVar12 + 0x88])) &&
       (uVar12 == *(ushort *)(DAT_0300356c + 0x54))) {
LAB_03003214:
      local_6a = *DAT_03003574;
      FUN_02ff02ea(3,&local_6c);
      return 1;
    }
LAB_03003204:
    func_0x02fdf0a4(DAT_0300355c,DAT_03003568);
    *(undefined1 *)(DAT_0300356c + 0x6c) = 0;
  }
  puVar4 = DAT_03003570;
  uVar10 = *DAT_03003558;
  if (uVar10 != 5) {
    if (uVar10 < 6) {
      if (uVar10 != 1) {
        if (uVar10 == 2) {
          uVar10 = FUN_02ff560c(DAT_0300357c,puVar3[puVar3[5] + 6],auStack_26c);
          unaff_r11 = (uint)uVar10;
          uVar14 = *(undefined4 *)(DAT_03003580 + 0x298);
          *(undefined4 *)(puVar2 + 0x1a) = *(undefined4 *)(DAT_03003580 + 0x294);
          *(undefined4 *)(puVar2 + 0x1c) = uVar14;
        }
        else if (uVar10 == 3 || uVar10 == 4) goto LAB_03003242;
LAB_030034ca:
        if (unaff_r11 != 0) {
          local_6c = 0x38;
          local_6a = 0x46;
          local_68 = 3;
          local_64 = 1;
          local_66 = 0;
          func_0x02fdefbc(DAT_0300358c,DAT_03003588,&local_6c);
          FUN_02ff00c0(0x179);
          return 0;
        }
        goto LAB_0300354a;
      }
    }
    else {
      if (uVar10 == 8) {
        uVar15 = 0;
        uVar10 = puVar3[puVar3[5] + 6];
        *(undefined4 *)(puVar2 + 0x1a) = *DAT_03003578;
        puVar2[0x1c] = 0;
        puVar2[0x1d] = 0;
        *(uint *)(puVar2 + 0x1e) = (uint)*puVar3;
        do {
          FUN_02fe2a5c(puVar2 + 10,puVar2 + 0x1a,DAT_03003590,2);
          uVar15 = uVar15 + 1;
        } while (uVar15 <= uVar10);
        goto LAB_0300354a;
      }
      if (uVar10 == 9) {
        uVar10 = puVar3[puVar3[5] + 6];
        *(undefined4 *)(puVar2 + 0x1a) = *DAT_03003578;
        *(uint *)(puVar2 + 0x1c) = uVar10 + 1;
        *(uint *)(puVar2 + 0x1e) = (uint)*puVar3;
        goto LAB_0300354a;
      }
      if (uVar10 != 100) goto LAB_030034ca;
    }
  }
LAB_03003242:
  uVar12 = (uint)puVar3[5];
  sVar7 = *(short *)((int)DAT_03003570 + uVar12 * 2 + 4);
  if (sVar7 == 0x600) {
    if (uVar12 != 0) {
      uVar15 = 0;
      uVar12 = 0;
      uVar10 = 0;
      if (0 < (int)(*puVar3 - 1)) {
        do {
          sVar7 = FUN_03001f5c(puVar4[puVar3[5] + 4],puVar3[puVar3[5] + 1] + uVar12,2);
          uVar15 = (sVar7 + uVar10) - 1;
          uVar12 = uVar12 + 1 & 0xffff;
          uVar10 = uVar15;
        } while ((int)uVar12 < (int)(*puVar3 - 1));
      }
      uVar10 = FUN_03001f5c(puVar4[puVar3[5] + 4],puVar3[puVar3[5] + 1],1);
      FUN_02ff5648(DAT_0300357c,*puVar4,puVar4[3],uVar10);
      uVar14 = *(undefined4 *)(DAT_03003580 + 0x298);
      *(undefined4 *)(puVar2 + 0x1a) = *(undefined4 *)(DAT_03003580 + 0x294);
      *(undefined4 *)(puVar2 + 0x1c) = uVar14;
      iVar11 = DAT_0300357c;
      *(undefined4 *)(puVar2 + 0x22) = *(undefined4 *)(DAT_0300357c + 0x10);
      *(undefined4 *)(puVar2 + 0x24) = *(undefined4 *)(iVar11 + 0x14);
      *(undefined4 *)(puVar2 + 0x26) = *(undefined4 *)(iVar11 + 0x18);
      *puVar3 = uVar15;
      puVar3[puVar3[5] + 1] = uVar10;
      goto LAB_0300354a;
    }
  }
  else if (sVar7 == 0x500 && uVar12 == 1) {
    iVar11 = *puVar3 - 1;
    uVar15 = 0;
    DAT_03003564[7] = 0;
    puVar3[0xb] = 0;
    uVar12 = 0;
    uVar10 = 0;
    if (0 < iVar11) {
      do {
        uVar15 = puVar3[5];
        puVar3[5] = uVar15 + 1;
        puVar3[(ushort)(uVar15 + 1) + 6] = 0;
        puVar3[0xb] = 0;
        FUN_03001d8e();
        FUN_02fe93c8();
        sVar7 = 0;
        uVar13 = 0;
        if (0 < (int)(*puVar3 - 1)) {
          do {
            sVar8 = FUN_03001f5c(puVar4[puVar3[5] + 4],puVar3[puVar3[5] + 1] + uVar13,2);
            sVar7 = sVar8 + sVar7 + -1;
            uVar13 = uVar13 + 1 & 0xffff;
          } while ((int)uVar13 < (int)(*puVar3 - 1));
        }
        if (uVar12 == 0) {
          uVar9 = FUN_03001f5c(puVar4[puVar3[5] + 4],puVar3[puVar3[5] + 1],1);
          FUN_02ff5648(DAT_0300357c,*puVar4,puVar4[3],uVar9);
        }
        FUN_02fe93c8();
        uVar15 = uVar10 + sVar7;
        uVar10 = puVar3[5];
        puVar3[5] = uVar10 - 1;
        uVar10 = puVar3[(ushort)(uVar10 - 1) + 6];
        if (4 < uVar10) {
          uVar10 = 5;
        }
        puVar3[0xb] = uVar10;
        FUN_03001d8e();
        puVar3[0xc] = puVar3[0xb];
        if ((int)(uint)puVar3[puVar3[5] + 6] < (int)(*puVar3 - 1)) {
          puVar3[puVar3[5] + 6] = puVar3[puVar3[5] + 6] + 1;
          if (puVar3[0xb] < 5) {
            puVar3[0xb] = puVar3[0xb] + 1;
            FUN_02ff00c0(0x174);
          }
          else {
            FUN_030017e8(2);
          }
        }
        uVar12 = uVar12 + 1 & 0xffff;
        uVar10 = uVar15;
      } while ((int)uVar12 < iVar11);
    }
    puVar3[puVar3[5] + 6] = 0;
    uVar10 = puVar3[5];
    puVar3[5] = uVar10 + 1;
    puVar3[(ushort)(uVar10 + 1) + 6] = 0;
    puVar3[0xb] = 0;
    FUN_03001d8e();
    uVar10 = FUN_03001f5c(puVar4[puVar3[5] + 4],puVar3[puVar3[5] + 1],1);
    FUN_02ff5648(DAT_0300357c,*puVar4,puVar4[3],uVar10);
    FUN_02ff0102(0x1dc);
    uVar14 = *(undefined4 *)(DAT_03003580 + 0x298);
    *(undefined4 *)(puVar2 + 0x1a) = *(undefined4 *)(DAT_03003580 + 0x294);
    *(undefined4 *)(puVar2 + 0x1c) = uVar14;
    iVar11 = DAT_0300357c;
    *(undefined4 *)(puVar2 + 0x22) = *(undefined4 *)(DAT_0300357c + 0x10);
    *(undefined4 *)(puVar2 + 0x24) = *(undefined4 *)(iVar11 + 0x14);
    *(undefined4 *)(puVar2 + 0x26) = *(undefined4 *)(iVar11 + 0x18);
    *puVar3 = uVar15;
    puVar3[puVar3[5] + 1] = uVar10;
    puVar3[0xb] = 0;
    puVar3[puVar3[5] + 6] = 0;
    iVar11 = DAT_03003584;
    *(uint *)(DAT_03003584 + 4) = (uint)puVar3[0xb];
    *(undefined4 *)(iVar11 + 8) = 0;
    FUN_02ff00c0(0x12a);
    goto LAB_0300354a;
  }
  FUN_02ff5648(DAT_0300357c,*DAT_03003570,DAT_03003570[3],
               (uint)puVar3[uVar12 + 6] + (uint)puVar3[uVar12 + 1]);
  uVar14 = *(undefined4 *)(DAT_03003580 + 0x298);
  *(undefined4 *)(puVar2 + 0x1a) = *(undefined4 *)(DAT_03003580 + 0x294);
  *(undefined4 *)(puVar2 + 0x1c) = uVar14;
  iVar11 = DAT_0300357c;
  *(undefined4 *)(puVar2 + 0x22) = *(undefined4 *)(DAT_0300357c + 0x10);
  *(undefined4 *)(puVar2 + 0x24) = *(undefined4 *)(iVar11 + 0x14);
  *(undefined4 *)(puVar2 + 0x26) = *(undefined4 *)(iVar11 + 0x18);
LAB_0300354a:
  puVar2[0x79] = *DAT_03003558;
  uVar14 = *puVar4;
  *(undefined4 *)(puVar2 + 0x7c) = uVar14;
  uVar16 = puVar4[3];
  *(undefined4 *)(puVar2 + 0x7e) = uVar16;
  uVar10 = puVar3[5];
  uVar12 = 0;
  do {
    puVar2[uVar12 + 0x80] = puVar3[uVar12 + 6];
    uVar13 = uVar12 + 1 & 0xffff;
    puVar2[uVar12 + 0x88] = puVar3[uVar12 + 1];
    uVar12 = uVar13;
  } while (uVar13 <= uVar10);
  puVar2[0x7a] = uVar10;
  *puVar2 = *puVar3;
  puVar6 = DAT_03003678;
  uVar5 = DAT_03003674;
  uVar10 = puVar3[uVar10 + 6];
  puVar2[1] = uVar10 + 1;
  *(undefined4 *)(puVar2 + 8) = uVar5;
  puVar2[3] = uVar10 + 1;
  FUN_03001e98(DAT_0300367c,uVar14,*(undefined4 *)(puVar6 + 10),*(undefined4 *)(puVar6 + 0xc),uVar16
               ,*(undefined4 *)(puVar6 + 0x10),*(undefined4 *)(puVar6 + 0x12),
               *(undefined4 *)(puVar6 + 0x14),(uint)puVar3[6] + (uint)puVar3[1],0x80,0,0);
  iVar11 = DAT_03003680;
  local_6c = puVar3[puVar3[5] + 6] + 1;
  *(ushort *)(DAT_03003680 + 0x54) = puVar3[5];
  *(ushort *)(iVar11 + 0x56) = puVar3[6];
  *(ushort *)(iVar11 + 0x4c) = puVar3[1];
  *(ushort *)(iVar11 + 0x58) = puVar3[7];
  *(ushort *)(iVar11 + 0x4e) = puVar3[2];
  *(ushort *)(iVar11 + 0x5a) = puVar3[8];
  *(ushort *)(iVar11 + 0x50) = puVar3[3];
  *(ushort *)(iVar11 + 0x5c) = puVar3[9];
  *(ushort *)(iVar11 + 0x52) = puVar3[4];
  FUN_02ff0102(0x18b);
  local_6a = *puVar6;
  FUN_02ff02ea(3,&local_6c);
  return 1;
}


