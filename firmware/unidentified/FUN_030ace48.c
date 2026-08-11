/**
 * FUN_030ace48 @ 0x030ace48
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030ace48(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  longlong lVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint extraout_r1;
  uint uVar12;
  undefined4 uVar13;
  uint extraout_r2;
  uint uVar14;
  bool bVar15;
  bool bVar16;
  char local_30;
  char local_2f;
  char local_2e;
  byte local_2c;
  byte local_2a;
  byte local_29;
  byte local_28;
  byte local_27;
  
  piVar6 = (int *)FUN_030ad68c();
  puVar5 = DAT_030ad2c0;
  puVar4 = DAT_030ad2bc;
  iVar8 = DAT_030ad278;
  iVar10 = DAT_030ad274;
  puVar2 = DAT_030ad26c;
  switch(param_1) {
  case 3:
    if (DAT_030ad26c[6] == 1) {
      uVar9 = *DAT_030ad2c8 - DAT_030ad26c[0xb];
      *DAT_030ad2c8 = uVar9;
      uVar14 = *(uint *)(iVar10 + 0xa4);
      lVar1 = (ulonglong)uVar14 * (ulonglong)uVar9;
      uVar12 = (uint)lVar1;
      iVar10 = FUN_030ac84e(uVar12 << 3,
                            (uVar14 * ((int)uVar9 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 8 |
                            uVar12 >> 0x1d,*(undefined4 *)(iVar10 + 0xac),0);
    }
    else {
      iVar10 = piVar6[8] * 1000;
    }
    *param_2 = iVar10;
    if (iVar10 % 1000 < 500) {
      return 1;
    }
    iVar10 = iVar10 + 500;
    break;
  case 4:
    if (DAT_030ad26c[6] == 1) {
      iVar10 = *(int *)(DAT_030ad274 + 200);
    }
    else {
      iVar10 = *piVar6;
    }
    break;
  case 5:
    if (DAT_030ad26c[6] == 1) {
      iVar10 = (int)*(short *)(DAT_030ad274 + 0xc4);
    }
    else {
      iVar10 = piVar6[1];
    }
    break;
  case 6:
    if (DAT_030ad26c[6] == 1) {
      lVar1 = (ulonglong)*(uint *)(DAT_030ad274 + 0xac) * 1000;
      iVar10 = FUN_030ac84e((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),
                            *(undefined4 *)(DAT_030ad274 + 0xa4),0);
    }
    else {
      iVar10 = piVar6[7];
    }
    break;
  case 7:
    if (DAT_030ad26c[6] == 0) {
      iVar10 = FUN_030ad63e();
    }
    else {
      iVar10 = FUN_030b146a();
    }
    break;
  case 8:
    uVar13 = *DAT_030ad2bc;
    DAT_030ad26c[10] = 0;
    puVar2[0xb] = 0;
    *puVar2 = uVar13;
    (*(code *)*puVar5)(0,0);
    (*(code *)*DAT_030ad2b4)(&local_30,0x14,*puVar2);
    (*(code *)*puVar5)(0,0,*puVar2);
    bVar15 = local_30 == 'I';
    if (bVar15) {
      local_30 = local_2f;
    }
    bVar16 = bVar15 && local_30 == 'D';
    if (bVar15 && local_30 == 'D') {
      bVar16 = local_2e == '3';
    }
    if (bVar16) {
      uVar9 = (uint)local_2c;
      bVar15 = 0xfe < uVar9;
      if (uVar9 != 0xff) {
        uVar9 = (uint)local_2a;
        bVar15 = 0x7f < uVar9;
      }
      if (!bVar15) {
        bVar15 = local_29 < 0x80;
        uVar14 = extraout_r2;
        if (bVar15) {
          uVar14 = (uint)local_28;
        }
        uVar12 = extraout_r1;
        if (bVar15 && uVar14 < 0x80) {
          uVar12 = (uint)local_27;
        }
        if (((bVar15 && uVar14 < 0x80) && uVar12 < 0x80) &&
           (uVar9 = uVar12 | uVar9 << 0x15 | (uint)local_29 << 0xe | uVar14 << 7, uVar9 != 0)) {
          puVar2[6] = 0;
          iVar10 = uVar9 + 10;
          puVar2[9] = 0;
          (*(code *)*puVar5)(iVar10,0,*puVar2);
          goto LAB_030ad036;
        }
      }
    }
    iVar10 = 0;
    uVar13 = FUN_030b12f6(&local_30);
    puVar2[6] = uVar13;
    puVar2[9] = uVar13;
LAB_030ad036:
    if (puVar2[6] == 0) {
      iVar8 = (*(code *)*DAT_030ad2c4)(*puVar4);
      iVar8 = FUN_030ad494(*puVar2,iVar8 - iVar10,iVar10);
      if (iVar8 != -3) {
        FUN_030ad8aa();
        iVar8 = thunk_FUN_030b1778();
        puVar2[8] = iVar8;
        if (iVar8 != 0) {
          (*(code *)*puVar5)(iVar10,0,*puVar2);
          puVar2[0xc] = 0;
          puVar2[0xd] = 0;
          puVar2[5] = 0;
          return 1;
        }
      }
      return -1;
    }
    iVar10 = (*(code *)*DAT_030ad2c4)();
    puVar2[7] = iVar10;
    (*(code *)*puVar5)(iVar10 + -1,0,*puVar4);
    FUN_030b0a8a();
    iVar8 = FUN_030b0b22(*puVar2);
    iVar10 = DAT_030ad274;
    if (iVar8 != 0) {
      FUN_030b0e4c();
      return -100;
    }
    iVar8 = FwCheck(DAT_030ad274 + 0x2e0);
    if (iVar8 != 0) {
      FUN_030b0e4c();
      return iVar8;
    }
    buffered_fseek(iVar10 + 0x2e0,0);
    FUN_030ad8aa();
    iVar8 = thunk_FUN_030b1778();
    puVar2[8] = iVar8;
    iVar10 = DAT_030ad270;
    if (iVar8 != 0) {
      puVar2[2] = DAT_030ad270;
      puVar2[3] = iVar10;
      puVar2[1] = 0;
      puVar2[0xc] = 0;
      puVar2[0xd] = 0;
      puVar2[4] = 0x800;
      puVar2[5] = 0;
      return 1;
    }
    return -0x14;
  default:
    return 0;
  case 10:
    iVar10 = *(int *)(DAT_030ad278 + -0x1c);
    *param_2 = *(int *)(DAT_030ad278 + iVar10 * 4) + *DAT_030ad27c * 2;
    *param_3 = 0x400;
    *(int *)(iVar8 + -0x1c) = (iVar10 + 1) % 2;
    return 1;
  case 0xc:
    if (DAT_030ad26c[6] == 0) {
      iVar8 = (*(code *)*DAT_030ad2b4)(DAT_030ad26c[3],DAT_030ad26c[4],*DAT_030ad26c);
      iVar10 = DAT_030ad270;
      iVar7 = puVar2[1];
      puVar2[1] = iVar7 + iVar8;
      puVar2[2] = iVar10;
      if (iVar7 + iVar8 == 0) {
        return 0;
      }
      iVar8 = FUN_030ada46(puVar2[8],DAT_030ad2b8 + 4,DAT_030ad2b8,
                           *(int *)(DAT_030ad278 + puVar2[5] * 4) + *DAT_030ad27c * 2);
      if (iVar8 == 0) {
        FUN_030ac8a8(DAT_030ad270,puVar2[2],puVar2[1]);
        puVar2[3] = puVar2[1] + iVar10;
        puVar2[4] = 0x800 - puVar2[1];
        return 1;
      }
      return 0;
    }
    iVar7 = FUN_030b1394(DAT_030ad26c[2],DAT_030ad26c[4],1);
    iVar10 = DAT_030ad270;
    iVar11 = puVar2[1];
    puVar2[3] = DAT_030ad270;
    puVar2[1] = iVar11 + iVar7;
    piVar6 = DAT_030ad27c;
    iVar8 = DAT_030ad278;
    if (iVar11 + iVar7 == 0) {
      return 0;
    }
    iVar7 = DAT_030ad278 + -0x2c;
    *(int *)(DAT_030ad274 + 0x70) = *(int *)(DAT_030ad274 + 0x70) + 1;
    iVar7 = FUN_030ada46(puVar2[8],iVar8 + -0x24,iVar7,*(int *)(iVar8 + puVar2[5] * 4) + *piVar6 * 2
                        );
    piVar3 = DAT_030ad280;
    if (iVar7 != 0) {
      puVar2[1] = 0x800 - *DAT_030ad280;
      FUN_030ac8f6(*(int *)(iVar8 + puVar2[5] * 4) + *piVar6 * 2,0x1000);
      FUN_030ac8a8(DAT_030ad270,*piVar3 + puVar2[3],puVar2[1]);
      puVar2[4] = 0x800 - puVar2[1];
      puVar2[2] = puVar2[1] + iVar10;
      iVar10 = puVar2[10];
      puVar2[10] = iVar10 + 1;
      if (iVar10 + 1 < 0xc9) {
        return 1;
      }
      hifi_debug_printf_ovl(&DAT_030ad284);
      hifi_debug_printf_ovl(s______err____d_dec_err_count__d_030ad294,iVar7,puVar2[10]);
      return 0;
    }
    puVar2[10] = 0;
    FUN_030ac8a8(DAT_030ad270,puVar2[3],puVar2[1]);
    puVar2[4] = 0x800 - puVar2[1];
    puVar2[2] = puVar2[1] + iVar10;
    return 1;
  case 0xe:
    if (DAT_030ad26c[6] != 0) {
      FUN_030b145a(param_2);
      iVar10 = DAT_030ad270;
      puVar2[1] = 0;
      puVar2[2] = iVar10;
      puVar2[3] = iVar10;
      puVar2[4] = 0x800;
      puVar2[5] = 0;
      return 1;
    }
    FUN_030ad9f2(DAT_030ad26c[8]);
    aac_aac_dec(param_2,puVar2[8],*puVar2);
    iVar10 = DAT_030ad270;
    puVar2[1] = 0;
    puVar2[2] = iVar10;
    puVar2[3] = iVar10;
    puVar2[4] = 0x800;
    puVar2[5] = 0;
    return 1;
  case 0xf:
    if (DAT_030ad26c[6] == 1) {
      FUN_030b0e4c();
    }
    FUN_030ad9f2(puVar2[8]);
    FUN_030ad8be(puVar2[8]);
    puVar2[6] = 0;
    return 1;
  case 0x11:
    iVar10 = 0x10;
  }
  *param_2 = iVar10;
  return 1;
}


