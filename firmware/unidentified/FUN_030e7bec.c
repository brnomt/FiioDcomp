/**
 * FUN_030e7bec @ 0x030e7bec
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e7bec(uint param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint *puVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  bool bVar18;
  uint local_2c;
  uint local_28;
  
  iVar3 = DAT_030e7f40;
  iVar2 = DAT_030e7f10;
  uVar4 = (param_1 / 1000) * *(int *)(DAT_030e7f10 + 0xa0) +
          (*(int *)(DAT_030e7f10 + 0xa0) * (param_1 % 1000)) / 1000;
  sVar1 = *(short *)(DAT_030e7f10 + 0xcc);
  if (sVar1 == 2 || sVar1 == 4) {
    uVar5 = FUN_030e7e94(DAT_030e7f10 + 0x2dc,DAT_030e7f10,uVar4);
    iVar6 = *(int *)(iVar2 + 0x78);
    *(undefined4 *)(iVar2 + 0x30) = 0;
    *(uint *)(iVar2 + 0x68) = uVar5;
    if (iVar6 + 1U == uVar5) {
      *(undefined4 *)(iVar2 + 0x38) = 0;
      *(uint *)(iVar3 + 0x48) = param_1;
    }
    else {
      iVar17 = *(int *)(iVar2 + 0x70);
      bVar18 = iVar6 == iVar17;
      if (bVar18) {
        iVar6 = *(int *)(iVar2 + 0x8c);
      }
      if (bVar18 && iVar6 == 1) {
        iVar6 = 1;
      }
      else {
        puVar13 = *(uint **)(iVar3 + 0x28);
        uVar7 = 0;
        uVar9 = *puVar13;
        uVar10 = puVar13[1];
        uVar11 = 1;
        uVar9 = uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
                uVar9 >> 0x18;
        uVar10 = uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8 |
                 uVar10 >> 0x18;
        do {
          uVar16 = uVar10;
          if (uVar11 < *(uint *)(iVar2 + 0x8c)) {
            uVar11 = uVar11 + 1;
            uVar15 = puVar13[uVar11 * 3 + -3];
            uVar10 = puVar13[uVar11 * 3 + -2];
            uVar15 = uVar15 << 0x18 | (uVar15 >> 8 & 0xff) << 0x10 | (uVar15 >> 0x10 & 0xff) << 8 |
                     uVar15 >> 0x18;
            iVar6 = uVar15 - uVar9;
            uVar9 = uVar15;
            uVar10 = uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8 |
                     uVar10 >> 0x18;
          }
          else {
            uVar15 = iVar17 + 1;
            iVar6 = uVar15 - uVar9;
            uVar10 = uVar16;
          }
          uVar7 = uVar16 * iVar6 + uVar7;
        } while (uVar7 < uVar5);
        uVar7 = uVar7 - uVar5;
        uVar9 = uVar7 / uVar16;
        uVar5 = (uVar15 - uVar9) - 1;
        iVar6 = uVar16 - (uVar7 - uVar16 * uVar9);
      }
      uVar9 = FUN_030e6652(uVar5,*(undefined4 *)(iVar3 + 0x30));
      local_28 = uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
                 uVar9 >> 0x18;
      iVar14 = *(int *)(iVar2 + 0x70);
      iVar17 = *(int *)(iVar2 + 0x78);
      bVar18 = iVar17 == iVar14;
      if (bVar18) {
        iVar17 = *(int *)(iVar2 + 0x8c);
      }
      if (!bVar18 || iVar17 != 1) {
        puVar13 = *(uint **)(iVar3 + 0x28);
        iVar17 = 0;
        uVar9 = *puVar13;
        uVar10 = puVar13[1];
        uVar7 = 1;
        uVar9 = uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
                uVar9 >> 0x18;
        uVar10 = uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8 |
                 uVar10 >> 0x18;
        do {
          uVar11 = uVar10;
          if (uVar7 < *(uint *)(iVar2 + 0x8c)) {
            uVar7 = uVar7 + 1;
            uVar16 = puVar13[uVar7 * 3 + -3];
            uVar10 = puVar13[uVar7 * 3 + -2];
            uVar16 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
                     uVar16 >> 0x18;
            iVar8 = uVar16 - uVar9;
            uVar10 = uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8 |
                     uVar10 >> 0x18;
          }
          else {
            uVar16 = iVar14 + 1;
            iVar8 = uVar16 - uVar9;
            uVar10 = uVar11;
          }
          iVar17 = uVar11 * iVar8 + iVar17;
          uVar9 = uVar16;
        } while (uVar16 < uVar5);
        uVar5 = (uVar5 - uVar16) * uVar11 + iVar17 + 1;
      }
      uVar9 = (uVar5 + iVar6) - 2;
      iVar6 = 0;
      if (*(int *)(iVar2 + 0x80) == 0) {
        uVar10 = *(int *)(iVar3 + 4) + 1;
        bVar18 = uVar9 != uVar10;
        if (!bVar18) {
          uVar10 = *(uint *)(iVar3 + 8);
        }
        uVar7 = uVar5;
        if (bVar18 || uVar5 != uVar10) {
          for (; uVar7 <= uVar9; uVar7 = uVar7 + 1) {
            puVar12 = *(undefined4 **)(iVar3 + 0x20);
            buffered_fseek_ovl_0e64(*puVar12,(uVar7 - puVar12[2]) * 4 + -4,1);
            puVar12[2] = uVar7;
            buffered_fread_ovl_0e65(&local_2c,1,4,*puVar12);
            iVar6 = iVar6 + (local_2c << 0x18 | (local_2c >> 8 & 0xff) << 0x10 |
                             (local_2c >> 0x10 & 0xff) << 8 | local_2c >> 0x18);
          }
        }
        else {
          uVar10 = FUN_030e6652(uVar9,*(undefined4 *)(iVar3 + 0x20));
          iVar6 = *(int *)(iVar3 + 0xc) +
                  (uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8 |
                  uVar10 >> 0x18);
        }
      }
      else {
        iVar6 = ((uVar9 - uVar5) + 1) * *(int *)(iVar2 + 0x80);
      }
      *(uint *)(iVar3 + 4) = uVar9;
      *(uint *)(iVar3 + 8) = uVar5;
      *(int *)(iVar3 + 0xc) = iVar6;
      *(uint *)(iVar2 + 0x34) = local_28 + iVar6;
      uVar5 = *(uint *)(iVar2 + 0x80);
      if (uVar5 == 0) {
        uVar5 = FUN_030e6652(*(undefined4 *)(iVar2 + 0x68),*(undefined4 *)(iVar3 + 0x20));
        uVar5 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                uVar5 >> 0x18;
      }
      *(uint *)(iVar2 + 0x38) = uVar5;
      uVar5 = *(uint *)(iVar2 + 0xa0);
      *(uint *)(iVar3 + 0x48) =
           ((uVar4 - uVar5 * (uVar4 / uVar5)) * 1000) / uVar5 + (uVar4 / uVar5) * 1000;
    }
  }
  else if ((sVar1 == 1 || sVar1 == 3) &&
          (iVar6 = FUN_030e7e94(DAT_030e7f10 + 0x2dc,DAT_030e7f10,uVar4),
          *(int *)(iVar2 + 0x78) + 1 == iVar6)) {
    *(undefined4 *)(iVar2 + 0x30) = 0;
    *(undefined4 *)(iVar2 + 0x38) = 0;
    *(int *)(iVar2 + 0x68) = iVar6;
    *(undefined4 *)(iVar3 + 0x48) = 0;
  }
  return 0;
}


