/**
 * FUN_03100c78 @ 0x03100c78
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Type propagation algorithm not settling */

ulonglong FUN_03100c78(int param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 extraout_r1;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  undefined1 uVar14;
  char cVar15;
  undefined1 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  longlong lVar21;
  ulonglong uVar22;
  int iStack_6c;
  uint uStack_68;
  
  uVar5 = param_2 & 0x7fffffff;
  uVar2 = param_4 & 0x7fffffff;
  if (((uint)(param_1 != 0) + param_2 * 2 + DAT_03101098 < (uint)(DAT_03101098 >> 1)) ||
     ((uint)(param_3 != 0) + param_4 * 2 + DAT_03101098 < DAT_0310109c)) goto LAB_03100d08;
  if (uVar2 == 0 && param_3 == 0) {
    return 0;
  }
  if (param_2 == DAT_031010a0) {
    if (param_1 == 0) {
      return 0;
    }
LAB_03100ce4:
    iVar13 = 1;
  }
  else {
    if (param_1 != 0) goto LAB_03100ce4;
    iVar13 = 0;
  }
  if ((0xffe00000 < iVar13 + param_2 * 2) || (0xffe00000 < (uint)(param_3 != 0) + param_4 * 2)) {
LAB_03100d08:
    uVar2 = softfloat_dadd_b(param_1,param_2,param_3,param_4);
    return (ulonglong)uVar2;
  }
  iVar13 = 0;
  if ((int)param_2 < 0 && (int)uVar2 < (int)DAT_031010a4) {
    if ((int)uVar2 < DAT_031010a8) {
      if ((int)DAT_031010a0 <= (int)uVar2) {
        iVar9 = DAT_031010ac + ((int)uVar2 >> 0x14);
        if (iVar9 < 0x15) {
          if ((param_3 == 0) &&
             (uVar10 = uVar2 >> (0x14U - iVar9 & 0xff), uVar10 << (0x14U - iVar9 & 0xff) == uVar2))
          goto LAB_03100d6a;
        }
        else {
          uVar10 = param_3 >> (0x34U - iVar9 & 0xff);
          if (uVar10 << (0x34U - iVar9 & 0xff) == param_3) {
LAB_03100d6a:
            iVar13 = 2 - (uVar10 & 1);
          }
        }
      }
    }
    else {
      iVar13 = 2;
    }
  }
  if ((uVar5 == 0 && param_1 == 0) && ((int)param_4 < 0)) {
    if ((param_2 != 0 && iVar13 != 2) && (iVar13 == 1)) {
      FUN_031003b4(2);
      uVar2 = FUN_030fe4a6(0,DAT_031010a0,param_1,param_2);
      return (ulonglong)uVar2;
    }
    FUN_031003b4(2);
    uVar2 = FUN_030fe4a6(0,DAT_031010a0,0,0);
    return (ulonglong)uVar2;
  }
  if (param_3 == 0) {
    if (uVar2 == DAT_031010a4) {
      if (param_2 == 0xbff00000 && param_1 == 0) {
        return 0;
      }
      if ((int)uVar5 < (int)DAT_031010a0) {
        if ((int)param_4 < 0) {
          return 0;
        }
      }
      else if (-1 < (int)param_4) {
        return 0;
      }
      return *(ulonglong *)(DAT_031010b0 + 0x3100e08);
    }
    if (uVar2 == DAT_031010a0) {
      if (-1 < (int)param_4) {
LAB_03100e5c:
        return CONCAT44(param_2,param_1);
      }
      if (uVar5 != 0) {
        if (uVar5 == DAT_031010a4) {
          if (param_1 == 0) {
            return 0;
          }
        }
        else if ((int)uVar5 < (int)DAT_031010a4) {
          uVar2 = FUN_030fe4a6(0,DAT_031010a0,param_1,param_2);
          return (ulonglong)uVar2;
        }
        goto LAB_03100e5c;
      }
      if (param_1 == 0) {
        return 0;
      }
      goto LAB_031013e0;
    }
    if ((int)uVar5 < (int)DAT_031010a4) {
      if (param_4 == 0x40000000) {
        uVar2 = softfloat_dmul_b(param_1,param_2);
        return (ulonglong)uVar2;
      }
      if ((param_4 == 0x3fe00000) && (-1 < (int)param_2)) {
        uVar22 = FUN_030fe982();
        if (((int)(0x7ff00000 - ((uint)((int)uVar22 != 0) | (uint)(uVar22 >> 0x20) & 0x7fffffff)) <
             0) && (-1 < (int)(0x7ff00000 - ((uint)(param_1 != 0) | param_2 & 0x7fffffff)))) {
          FUN_031003b4(1);
        }
        return uVar22;
      }
    }
  }
  if (param_1 == 0) {
    if (uVar5 == 0) {
      if (iVar13 == 2 || param_2 == 0) {
        return 0;
      }
      if (iVar13 != 1) {
        return 0;
      }
      if (-1 < (int)param_2) {
        return 0;
      }
      return 0;
    }
    if (uVar5 == DAT_031010a4) {
      if ((0 < (int)param_2) && (-1 < (int)param_4)) {
        return 0;
      }
      if ((0 < (int)param_2) && ((int)param_4 < 0)) {
        return 0;
      }
      if (((int)param_2 < 0) && (-1 < (int)param_4)) {
        return 0;
      }
      if ((int)param_2 < 0 && (int)param_4 < 0) {
        if (iVar13 != 1) {
          return 0;
        }
        return 0;
      }
    }
  }
  if ((int)param_2 < 0 && iVar13 == 0) {
    FUN_031003b4(1);
    uVar2 = FUN_030fe4a6(0,0,0,0);
    return (ulonglong)uVar2;
  }
  if (DAT_031010b8 < (int)uVar2) {
    if (DAT_031010bc < (int)uVar2) {
      if (DAT_031010c0 < (int)uVar5) {
        if ((int)uVar5 < (int)DAT_031010a0) goto LAB_03100f66;
joined_r0x03100f62:
        if (0 < (int)param_4) goto LAB_03100f7a;
        goto LAB_03100f9c;
      }
    }
    else {
LAB_03100f66:
      if (DAT_031010c0 <= (int)uVar5) {
        if ((int)DAT_031010a0 < (int)uVar5) goto joined_r0x03100f62;
        uVar17 = FUN_030fe948(param_1,param_2,0);
        uVar4 = (undefined4)((ulonglong)uVar17 >> 0x20);
        uVar11 = (undefined4)uVar17;
        uVar17 = FUN_030fe954(uVar11,uVar4,0xfffffffe);
        uVar17 = FUN_030fe94e((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0x55555555,DAT_031010c4);
        uVar17 = softfloat_dmul_b((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar11,uVar4);
        uVar17 = FUN_030fe94e((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0,DAT_031010c8);
        uVar18 = softfloat_dmul_b(uVar11,uVar4);
        uVar17 = softfloat_dmul_b((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                                  (int)((ulonglong)uVar17 >> 0x20));
        uVar18 = softfloat_dmul_b(uVar11,uVar4,0x60000000,DAT_031010cc);
        uVar6 = (undefined4)((ulonglong)uVar18 >> 0x20);
        uVar17 = softfloat_dmul_b((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),DAT_031010d0,
                                  DAT_031010cc);
        uVar19 = softfloat_dmul_b(uVar11,uVar4,DAT_031010d4,DAT_031010d8);
        uVar17 = FUN_030fe948((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar17,
                              (int)((ulonglong)uVar17 >> 0x20));
        uVar11 = (undefined4)((ulonglong)uVar17 >> 0x20);
        softfloat_dadd_b((int)uVar17,uVar11,(int)uVar18,uVar6);
        uVar18 = FUN_030fe948(0,extraout_r1,(int)uVar18,uVar6);
        uVar17 = FUN_030fe94e((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,uVar11);
        uVar11 = extraout_r1;
        goto LAB_0310134e;
      }
    }
    if ((int)param_4 < 0) {
LAB_03100f7a:
      FUN_031003b4(2);
      uVar2 = FUN_030fe954(0,0x70000000,0x301);
      return (ulonglong)uVar2;
    }
LAB_03100f9c:
    FUN_031003b4(2);
    uVar2 = FUN_031003a4();
    return (ulonglong)uVar2;
  }
  iVar9 = 0;
  if (uVar5 < 0x100000) {
    uVar17 = FUN_030fe954(param_1,param_2 & 0x7fffffff,0x35);
    uVar5 = (uint)((ulonglong)uVar17 >> 0x20);
    param_1 = (int)uVar17;
    iVar9 = -0x35;
  }
  iVar9 = iVar9 + ((int)uVar5 >> 0x14);
  iStack_6c = iVar9 + -0x3ff;
  uVar5 = uVar5 & 0xfffff;
  uStack_68 = uVar5 | 0x3ff00000;
  if (DAT_031010dc < (int)uVar5) {
    if ((int)uVar5 < DAT_031014e4) {
      iVar12 = 1;
    }
    else {
      iVar12 = 0;
      iStack_6c = iVar9 + -0x3fe;
      uStack_68 = uStack_68 - 0x100000;
    }
  }
  else {
    iVar12 = 0;
  }
  puVar3 = (undefined4 *)(DAT_031014e8 + 0x310110e + iVar12 * 8);
  uVar17 = FUN_030fe948(param_1,uStack_68,*puVar3,puVar3[1]);
  uVar6 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar18 = softfloat_dadd_b(param_1,uStack_68,*puVar3,puVar3[1]);
  uVar18 = FUN_030fe4a6(0,DAT_031014ec,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
  uVar7 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = softfloat_dmul_b((int)uVar17,uVar6,(int)uVar18,uVar7);
  uVar8 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar11 = (undefined4)uVar19;
  uVar4 = *(undefined4 *)(DAT_031014f0 + 0x3101158);
  iVar9 = ((int)uStack_68 >> 1 | 0x20000000U) + iVar12 * 0x40000 + 0x80000;
  uVar19 = FUN_030fe948(uVar4,iVar9,*puVar3,puVar3[1]);
  uVar19 = FUN_030fe94e((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),param_1,uStack_68);
  uVar19 = softfloat_dmul_b((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0,uVar8);
  uVar20 = softfloat_dmul_b(0,uVar8,uVar4,iVar9);
  uVar17 = FUN_030fe94e((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar17,uVar6);
  uVar17 = FUN_030fe948((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar19,
                        (int)((ulonglong)uVar19 >> 0x20));
  uVar17 = softfloat_dmul_b((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar18,uVar7);
  uVar4 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar18 = softfloat_dmul_b(uVar11,uVar8);
  uVar6 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = FUN_031002fa(DAT_031014f4 + 0x31011d2,6,(int)uVar18,uVar6);
  uVar18 = softfloat_dmul_b((int)uVar18,uVar6);
  uVar18 = softfloat_dmul_b((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar19,
                            (int)((ulonglong)uVar19 >> 0x20));
  uVar19 = softfloat_dadd_b(0,uVar8,uVar11);
  uVar19 = softfloat_dmul_b((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar17,uVar4);
  uVar18 = softfloat_dadd_b((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,
                            (int)((ulonglong)uVar18 >> 0x20));
  uVar6 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = softfloat_dmul_b(0,uVar8);
  uVar7 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar20 = softfloat_dadd_b((int)uVar19,uVar7,0,DAT_031014f8);
  softfloat_dadd_b((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar18,uVar6);
  uVar20 = FUN_030fe948(0,extraout_r1_00,0,DAT_031014f8);
  uVar19 = FUN_030fe948((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar19,uVar7);
  uVar18 = FUN_030fe94e((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,uVar6);
  uVar19 = softfloat_dmul_b(0,uVar8,0,extraout_r1_00);
  uVar6 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar18 = softfloat_dmul_b((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar11,uVar8);
  uVar17 = softfloat_dmul_b((int)uVar17,uVar4,0,extraout_r1_00);
  uVar17 = softfloat_dadd_b((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar18,
                            (int)((ulonglong)uVar18 >> 0x20));
  uVar11 = (undefined4)((ulonglong)uVar17 >> 0x20);
  softfloat_dadd_b((int)uVar19,uVar6,(int)uVar17,uVar11);
  uVar18 = FUN_030fe948(0,extraout_r1_01,(int)uVar19,uVar6);
  uVar17 = FUN_030fe94e((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,uVar11);
  uVar18 = softfloat_dmul_b(0,extraout_r1_01,0xe0000000,DAT_031014fc);
  uVar11 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar17 = softfloat_dmul_b((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),DAT_03101500,DAT_031014fc);
  uVar19 = softfloat_dmul_b(0,extraout_r1_01,DAT_03101504,DAT_03101508);
  uVar17 = softfloat_dadd_b((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar17,
                            (int)((ulonglong)uVar17 >> 0x20));
  puVar3 = (undefined4 *)(DAT_0310150c + 0x31012ea + iVar12 * 8);
  uVar17 = softfloat_dadd_b((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),*puVar3,puVar3[1]);
  uVar4 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar19 = FUN_030fea24(iStack_6c);
  uVar6 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar20 = softfloat_dadd_b((int)uVar18,uVar11,(int)uVar17,uVar4);
  puVar3 = (undefined4 *)(DAT_03101510 + 0x3101314 + iVar12 * 8);
  uVar20 = softfloat_dadd_b((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),*puVar3,puVar3[1]);
  softfloat_dadd_b((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar19,uVar6);
  uVar19 = FUN_030fe948(0,extraout_r1_02,(int)uVar19,uVar6);
  uVar19 = FUN_030fe948((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),*puVar3,puVar3[1]);
  uVar18 = FUN_030fe948((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,uVar11);
  uVar17 = FUN_030fe94e((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,uVar4);
  uVar11 = extraout_r1_02;
LAB_0310134e:
  uVar4 = DAT_031014ec;
  if ((int)param_2 < 0 && iVar13 == 1) {
    uVar4 = DAT_03101514;
  }
  uVar17 = softfloat_dmul_b(param_3,param_4,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
  uVar18 = FUN_030fe948(param_3,param_4,0);
  uVar18 = softfloat_dmul_b((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),0,uVar11);
  uVar17 = softfloat_dadd_b((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                            (int)((ulonglong)uVar17 >> 0x20));
  uVar7 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar6 = (undefined4)uVar17;
  uVar17 = softfloat_dmul_b(0,param_4,0,uVar11);
  uVar8 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar11 = (undefined4)uVar17;
  lVar21 = softfloat_dadd_b(uVar11,uVar8,uVar6,uVar7);
  uVar2 = (uint)((ulonglong)lVar21 >> 0x20);
  iVar13 = (int)lVar21;
  cVar15 = DAT_03101518 <= uVar2;
  if ((int)DAT_03101518 <= (int)uVar2) {
    if (uVar2 == DAT_03101518 && iVar13 == 0) {
      uVar18 = FUN_030fe948(iVar13,uVar2,uVar11,uVar8);
      uVar19 = softfloat_dadd_b(uVar6,uVar7,DAT_0310151c,DAT_03101520);
      FUN_030feaa0((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,
                   (int)((ulonglong)uVar18 >> 0x20));
      if (cVar15 != '\0') goto LAB_03101442;
    }
LAB_031013e0:
    FUN_031003b4(2);
    uVar2 = FUN_030fe954(0,0x70000000,0x301);
    return (ulonglong)uVar2;
  }
  uVar16 = DAT_03101524 <= (uVar2 & 0x7fffffff);
  if ((bool)uVar16) {
    bVar1 = uVar2 + DAT_03101528 == 0;
    uVar14 = bVar1 && iVar13 == 0;
    if (bVar1 && iVar13 == 0) {
      uVar18 = FUN_030fe948(iVar13,uVar2,uVar11,uVar8);
      FUN_030feaa0((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar6,uVar7);
      if ((bool)uVar16 && !(bool)uVar14) goto LAB_03101442;
    }
    FUN_031003b4(2);
    uVar2 = FUN_031003a4();
    return (ulonglong)uVar2;
  }
LAB_03101442:
  uVar5 = 0;
  if (DAT_03101530 < (int)(uVar2 & 0x7fffffff)) {
    uVar2 = (0x100000U >> (DAT_0310152c + ((int)(uVar2 & 0x7fffffff) >> 0x14) + 1U & 0xff)) + uVar2;
    uVar10 = ((uVar2 & 0x7fffffff) >> 0x14) - 0x3ff;
    uVar5 = (uVar2 & 0xfffff | 0x100000) >> (0x14 - uVar10 & 0xff);
    if (lVar21 < 0) {
      uVar5 = -uVar5;
    }
    uVar17 = FUN_030fe948(uVar11,uVar8,*(undefined4 *)(DAT_03101534 + 0x3101470),
                          uVar2 & ~(DAT_03101538 >> (uVar10 & 0xff)));
  }
  uVar11 = (undefined4)((ulonglong)uVar17 >> 0x20);
  softfloat_dadd_b(uVar6,uVar7,(int)uVar17,uVar11);
  uVar18 = softfloat_dmul_b(0,extraout_r1_03,0,DAT_0310153c);
  uVar8 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = softfloat_dmul_b(0,extraout_r1_03,DAT_03101540,DAT_03101544);
  uVar17 = FUN_030fe948(0,extraout_r1_03,(int)uVar17,uVar11);
  uVar17 = FUN_030fe94e((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar6,uVar7);
  uVar17 = softfloat_dmul_b((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),DAT_03101648,DAT_0310164c);
  uVar17 = softfloat_dadd_b((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar19,
                            (int)((ulonglong)uVar19 >> 0x20));
  uVar6 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar19 = softfloat_dadd_b((int)uVar17,uVar6,(int)uVar18,uVar8);
  uVar7 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar11 = (undefined4)uVar19;
  uVar18 = FUN_030fe948(uVar11,uVar7,(int)uVar18,uVar8);
  uVar17 = FUN_030fe94e((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,uVar6);
  uVar6 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar18 = softfloat_dmul_b(uVar11,uVar7);
  uVar8 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = FUN_031002fa(DAT_03101650 + 0x3101598,5,(int)uVar18,uVar8);
  uVar18 = softfloat_dmul_b((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,uVar8);
  uVar18 = FUN_030fe94e((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar11,uVar7);
  uVar8 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = softfloat_dmul_b(uVar11,uVar7,(int)uVar17,uVar6);
  uVar17 = softfloat_dadd_b((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar17,uVar6);
  uVar19 = FUN_030fe948((int)uVar18,uVar8,0,0x40000000);
  uVar18 = softfloat_dmul_b(uVar11,uVar7,(int)uVar18,uVar8);
  uVar18 = FUN_030fe4a6((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar19,
                        (int)((ulonglong)uVar19 >> 0x20));
  uVar17 = FUN_030fe948((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                        (int)((ulonglong)uVar17 >> 0x20));
  uVar17 = FUN_030fe948((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar11,uVar7);
  uVar17 = FUN_030fe94e((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0,DAT_03101654);
  iVar13 = (int)((ulonglong)uVar17 >> 0x20);
  uVar11 = (undefined4)uVar17;
  iVar9 = iVar13 + uVar5 * 0x100000;
  uVar17 = CONCAT44(iVar9,uVar11);
  if (iVar9 >> 0x14 < 1) {
    FUN_030fe954(uVar11,iVar13,uVar5);
    iVar9 = FUN_031002d2();
    if (iVar9 == 4) {
      FUN_031003a4();
    }
    uVar17 = FUN_030fe954(uVar11,iVar13,uVar5);
  }
  uVar2 = softfloat_dmul_b(0,uVar4,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
  return (ulonglong)uVar2;
}


