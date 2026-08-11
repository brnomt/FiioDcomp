/**
 * FUN_030f90a0 @ 0x030f90a0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Type propagation algorithm not settling */

longlong FUN_030f90a0(int param_1,uint param_2,uint param_3,uint param_4)

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
  longlong lVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  int iStack_6c;
  uint uStack_68;
  
  uVar5 = param_2 & 0x7fffffff;
  uVar2 = param_4 & 0x7fffffff;
  if (((uint)(param_1 != 0) + param_2 * 2 + DAT_030f94c0 < (uint)(DAT_030f94c0 >> 1)) ||
     ((uint)(param_3 != 0) + param_4 * 2 + DAT_030f94c0 < DAT_030f94c4)) goto LAB_030f9130;
  if (uVar2 == 0 && param_3 == 0) {
LAB_030f90f8:
    return (ulonglong)DAT_030f94c8 << 0x20;
  }
  if (param_2 == DAT_030f94c8) {
    if (param_1 == 0) goto LAB_030f90f8;
LAB_030f910c:
    iVar13 = 1;
  }
  else {
    if (param_1 != 0) goto LAB_030f910c;
    iVar13 = 0;
  }
  if ((0xffe00000 < iVar13 + param_2 * 2) || (0xffe00000 < (uint)(param_3 != 0) + param_4 * 2)) {
LAB_030f9130:
    lVar17 = softfloat_dadd_a(param_1,param_2,param_3,param_4);
    return lVar17;
  }
  iVar13 = 0;
  if ((int)param_2 < 0 && (int)uVar2 < (int)DAT_030f94cc) {
    if ((int)uVar2 < DAT_030f94d0) {
      if ((int)DAT_030f94c8 <= (int)uVar2) {
        iVar9 = DAT_030f94d4 + ((int)uVar2 >> 0x14);
        if (iVar9 < 0x15) {
          if ((param_3 == 0) &&
             (uVar10 = uVar2 >> (0x14U - iVar9 & 0xff), uVar10 << (0x14U - iVar9 & 0xff) == uVar2))
          goto LAB_030f9192;
        }
        else {
          uVar10 = param_3 >> (0x34U - iVar9 & 0xff);
          if (uVar10 << (0x34U - iVar9 & 0xff) == param_3) {
LAB_030f9192:
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
      FUN_030f87dc(2);
      lVar17 = FUN_030f6706(0,DAT_030f94c8,param_1,param_2);
      return lVar17;
    }
    FUN_030f87dc(2);
    lVar17 = FUN_030f6706(0,DAT_030f94c8,0,0);
    return lVar17;
  }
  if (param_3 == 0) {
    if (uVar2 == DAT_030f94cc) {
      if (param_2 == 0xbff00000 && param_1 == 0) {
        return (ulonglong)DAT_030f94c8 << 0x20;
      }
      if ((int)uVar5 < (int)DAT_030f94c8) {
        if ((int)param_4 < 0) {
          return (ulonglong)(param_4 ^ 0x80000000) << 0x20;
        }
      }
      else if (-1 < (int)param_4) {
        return (ulonglong)param_4 << 0x20;
      }
      return *(longlong *)(DAT_030f94d8 + 0x30f9230);
    }
    if (uVar2 == DAT_030f94c8) {
      if (-1 < (int)param_4) {
LAB_030f9284:
        return CONCAT44(param_2,param_1);
      }
      if (uVar5 != 0) {
        if (uVar5 == DAT_030f94cc) {
          if (param_1 == 0) {
            return (ulonglong)(param_2 & 0x80000000) << 0x20;
          }
        }
        else if ((int)uVar5 < (int)DAT_030f94cc) {
          lVar17 = FUN_030f6706(0,DAT_030f94c8,param_1,param_2);
          return lVar17;
        }
        goto LAB_030f9284;
      }
      if (param_1 == 0) {
        return (ulonglong)(param_2 & 0x80000000 | DAT_030f94cc & 0x7fffffff) << 0x20;
      }
      goto LAB_030f9808;
    }
    if ((int)uVar5 < (int)DAT_030f94cc) {
      if (param_4 == 0x40000000) {
        lVar17 = softfloat_dmul_a(param_1,param_2);
        return lVar17;
      }
      if ((param_4 == 0x3fe00000) && (-1 < (int)param_2)) {
        lVar17 = FUN_030f9a80(param_1,param_2);
        return lVar17;
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
      return -0x8000000000000000;
    }
    if (uVar5 == DAT_030f94cc) {
      if ((0 < (int)param_2) && (-1 < (int)param_4)) {
        return (ulonglong)DAT_030f94cc << 0x20;
      }
      if ((0 < (int)param_2) && ((int)param_4 < 0)) {
        return 0;
      }
      if (((int)param_2 < 0) && (-1 < (int)param_4)) {
        uVar2 = DAT_030f94cc;
        if (iVar13 == 1) {
          uVar2 = DAT_030f94dc;
        }
        return (ulonglong)uVar2 << 0x20;
      }
      if ((int)param_2 < 0 && (int)param_4 < 0) {
        if (iVar13 != 1) {
          return 0;
        }
        return -0x8000000000000000;
      }
    }
  }
  if ((int)param_2 < 0 && iVar13 == 0) {
    FUN_030f87dc(1);
    lVar17 = FUN_030f6706(0,0,0,0);
    return lVar17;
  }
  if (DAT_030f94e0 < (int)uVar2) {
    if (DAT_030f94e4 < (int)uVar2) {
      if (DAT_030f94e8 < (int)uVar5) {
        if ((int)uVar5 < (int)DAT_030f94c8) goto LAB_030f938e;
joined_r0x030f938a:
        if (0 < (int)param_4) goto LAB_030f93a2;
        goto LAB_030f93c4;
      }
    }
    else {
LAB_030f938e:
      if (DAT_030f94e8 <= (int)uVar5) {
        if ((int)DAT_030f94c8 < (int)uVar5) goto joined_r0x030f938a;
        uVar21 = FUN_030f6ba8(param_1,param_2,0);
        uVar4 = (undefined4)((ulonglong)uVar21 >> 0x20);
        uVar11 = (undefined4)uVar21;
        uVar21 = FUN_030f6bb4(uVar11,uVar4,0xfffffffe);
        uVar21 = FUN_030f6bae((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),0x55555555,DAT_030f94ec);
        uVar21 = softfloat_dmul_a((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),uVar11,uVar4);
        uVar21 = FUN_030f6bae((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),0,DAT_030f94f0);
        uVar18 = softfloat_dmul_a(uVar11,uVar4);
        uVar21 = softfloat_dmul_a((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar21,
                                  (int)((ulonglong)uVar21 >> 0x20));
        uVar18 = softfloat_dmul_a(uVar11,uVar4,0x60000000,DAT_030f94f4);
        uVar6 = (undefined4)((ulonglong)uVar18 >> 0x20);
        uVar21 = softfloat_dmul_a((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),DAT_030f94f8,
                                  DAT_030f94f4);
        uVar19 = softfloat_dmul_a(uVar11,uVar4,DAT_030f94fc,DAT_030f9500);
        uVar21 = FUN_030f6ba8((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar21,
                              (int)((ulonglong)uVar21 >> 0x20));
        uVar11 = (undefined4)((ulonglong)uVar21 >> 0x20);
        softfloat_dadd_a((int)uVar21,uVar11,(int)uVar18,uVar6);
        uVar18 = FUN_030f6ba8(0,extraout_r1,(int)uVar18,uVar6);
        uVar21 = FUN_030f6bae((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar21,uVar11);
        uVar11 = extraout_r1;
        goto LAB_030f9776;
      }
    }
    if ((int)param_4 < 0) {
LAB_030f93a2:
      FUN_030f87dc(2);
      uVar21 = FUN_030f6bb4(0,0x70000000,0x301);
      return CONCAT44(DAT_030f94cc & 0x80000000 | (uint)((ulonglong)uVar21 >> 0x20) & 0x7fffffff,
                      (int)uVar21);
    }
LAB_030f93c4:
    FUN_030f87dc(2);
    uVar21 = FUN_030f87cc();
    return CONCAT44(DAT_030f94c8 & 0x80000000 | (uint)((ulonglong)uVar21 >> 0x20) & 0x7fffffff,
                    (int)uVar21);
  }
  iVar9 = 0;
  if (uVar5 < 0x100000) {
    uVar21 = FUN_030f6bb4(param_1,param_2 & 0x7fffffff,0x35);
    uVar5 = (uint)((ulonglong)uVar21 >> 0x20);
    param_1 = (int)uVar21;
    iVar9 = -0x35;
  }
  iVar9 = iVar9 + ((int)uVar5 >> 0x14);
  iStack_6c = iVar9 + -0x3ff;
  uVar5 = uVar5 & 0xfffff;
  uStack_68 = uVar5 | 0x3ff00000;
  if (DAT_030f9504 < (int)uVar5) {
    if ((int)uVar5 < DAT_030f990c) {
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
  puVar3 = (undefined4 *)(DAT_030f9910 + 0x30f9536 + iVar12 * 8);
  uVar21 = FUN_030f6ba8(param_1,uStack_68,*puVar3,puVar3[1]);
  uVar6 = (undefined4)((ulonglong)uVar21 >> 0x20);
  uVar18 = softfloat_dadd_a(param_1,uStack_68,*puVar3,puVar3[1]);
  uVar18 = FUN_030f6706(0,DAT_030f9914,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
  uVar7 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = softfloat_dmul_a((int)uVar21,uVar6,(int)uVar18,uVar7);
  uVar8 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar11 = (undefined4)uVar19;
  uVar4 = *(undefined4 *)(DAT_030f9918 + 0x30f9580);
  iVar9 = ((int)uStack_68 >> 1 | 0x20000000U) + iVar12 * 0x40000 + 0x80000;
  uVar19 = FUN_030f6ba8(uVar4,iVar9,*puVar3,puVar3[1]);
  uVar19 = FUN_030f6bae((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),param_1,uStack_68);
  uVar19 = softfloat_dmul_a((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0,uVar8);
  uVar20 = softfloat_dmul_a(0,uVar8,uVar4,iVar9);
  uVar21 = FUN_030f6bae((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar21,uVar6);
  uVar21 = FUN_030f6ba8((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),(int)uVar19,
                        (int)((ulonglong)uVar19 >> 0x20));
  uVar21 = softfloat_dmul_a((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),(int)uVar18,uVar7);
  uVar4 = (undefined4)((ulonglong)uVar21 >> 0x20);
  uVar18 = softfloat_dmul_a(uVar11,uVar8);
  uVar6 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = FUN_030f8722(DAT_030f991c + 0x30f95fa,6,(int)uVar18,uVar6);
  uVar18 = softfloat_dmul_a((int)uVar18,uVar6);
  uVar18 = softfloat_dmul_a((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar19,
                            (int)((ulonglong)uVar19 >> 0x20));
  uVar19 = softfloat_dadd_a(0,uVar8,uVar11);
  uVar19 = softfloat_dmul_a((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar21,uVar4);
  uVar18 = softfloat_dadd_a((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,
                            (int)((ulonglong)uVar18 >> 0x20));
  uVar6 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = softfloat_dmul_a(0,uVar8);
  uVar7 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar20 = softfloat_dadd_a((int)uVar19,uVar7,0,DAT_030f9920);
  softfloat_dadd_a((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar18,uVar6);
  uVar20 = FUN_030f6ba8(0,extraout_r1_00,0,DAT_030f9920);
  uVar19 = FUN_030f6ba8((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar19,uVar7);
  uVar18 = FUN_030f6bae((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,uVar6);
  uVar19 = softfloat_dmul_a(0,uVar8,0,extraout_r1_00);
  uVar6 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar18 = softfloat_dmul_a((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar11,uVar8);
  uVar21 = softfloat_dmul_a((int)uVar21,uVar4,0,extraout_r1_00);
  uVar21 = softfloat_dadd_a((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),(int)uVar18,
                            (int)((ulonglong)uVar18 >> 0x20));
  uVar11 = (undefined4)((ulonglong)uVar21 >> 0x20);
  softfloat_dadd_a((int)uVar19,uVar6,(int)uVar21,uVar11);
  uVar18 = FUN_030f6ba8(0,extraout_r1_01,(int)uVar19,uVar6);
  uVar21 = FUN_030f6bae((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar21,uVar11);
  uVar18 = softfloat_dmul_a(0,extraout_r1_01,0xe0000000,DAT_030f9924);
  uVar11 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar21 = softfloat_dmul_a((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),DAT_030f9928,DAT_030f9924);
  uVar19 = softfloat_dmul_a(0,extraout_r1_01,DAT_030f992c,DAT_030f9930);
  uVar21 = softfloat_dadd_a((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar21,
                            (int)((ulonglong)uVar21 >> 0x20));
  puVar3 = (undefined4 *)(DAT_030f9934 + 0x30f9712 + iVar12 * 8);
  uVar21 = softfloat_dadd_a((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),*puVar3,puVar3[1]);
  uVar4 = (undefined4)((ulonglong)uVar21 >> 0x20);
  uVar19 = FUN_030f6c84(iStack_6c);
  uVar6 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar20 = softfloat_dadd_a((int)uVar18,uVar11,(int)uVar21,uVar4);
  puVar3 = (undefined4 *)(DAT_030f9938 + 0x30f973c + iVar12 * 8);
  uVar20 = softfloat_dadd_a((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),*puVar3,puVar3[1]);
  softfloat_dadd_a((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar19,uVar6);
  uVar19 = FUN_030f6ba8(0,extraout_r1_02,(int)uVar19,uVar6);
  uVar19 = FUN_030f6ba8((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),*puVar3,puVar3[1]);
  uVar18 = FUN_030f6ba8((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,uVar11);
  uVar21 = FUN_030f6bae((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar21,uVar4);
  uVar11 = extraout_r1_02;
LAB_030f9776:
  bVar1 = (int)param_2 < 0;
  param_2 = DAT_030f9914;
  if (bVar1 && iVar13 == 1) {
    param_2 = DAT_030f993c;
  }
  uVar21 = softfloat_dmul_a(param_3,param_4,(int)uVar21,(int)((ulonglong)uVar21 >> 0x20));
  uVar18 = FUN_030f6ba8(param_3,param_4,0);
  uVar18 = softfloat_dmul_a((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),0,uVar11);
  uVar21 = softfloat_dadd_a((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar21,
                            (int)((ulonglong)uVar21 >> 0x20));
  uVar6 = (undefined4)((ulonglong)uVar21 >> 0x20);
  uVar4 = (undefined4)uVar21;
  uVar21 = softfloat_dmul_a(0,param_4,0,uVar11);
  uVar7 = (undefined4)((ulonglong)uVar21 >> 0x20);
  uVar11 = (undefined4)uVar21;
  lVar17 = softfloat_dadd_a(uVar11,uVar7,uVar4,uVar6);
  uVar2 = (uint)((ulonglong)lVar17 >> 0x20);
  iVar13 = (int)lVar17;
  cVar15 = DAT_030f9940 <= uVar2;
  if ((int)DAT_030f9940 <= (int)uVar2) {
    if (uVar2 == DAT_030f9940 && iVar13 == 0) {
      uVar18 = FUN_030f6ba8(iVar13,uVar2,uVar11,uVar7);
      uVar19 = softfloat_dadd_a(uVar4,uVar6,DAT_030f9944,DAT_030f9948);
      FUN_030f6d00((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,
                   (int)((ulonglong)uVar18 >> 0x20));
      if (cVar15 != '\0') goto LAB_030f986a;
    }
LAB_030f9808:
    FUN_030f87dc(2);
    uVar21 = FUN_030f6bb4(0,0x70000000,0x301);
    return CONCAT44(param_2 & 0x80000000 | (uint)((ulonglong)uVar21 >> 0x20) & 0x7fffffff,
                    (int)uVar21);
  }
  uVar16 = DAT_030f994c <= (uVar2 & 0x7fffffff);
  if ((bool)uVar16) {
    bVar1 = uVar2 + DAT_030f9950 == 0;
    uVar14 = bVar1 && iVar13 == 0;
    if (bVar1 && iVar13 == 0) {
      uVar18 = FUN_030f6ba8(iVar13,uVar2,uVar11,uVar7);
      FUN_030f6d00((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar4,uVar6);
      if ((bool)uVar16 && !(bool)uVar14) goto LAB_030f986a;
    }
    FUN_030f87dc(2);
    uVar21 = FUN_030f87cc();
    return CONCAT44(param_2 & 0x80000000 | (uint)((ulonglong)uVar21 >> 0x20) & 0x7fffffff,
                    (int)uVar21);
  }
LAB_030f986a:
  uVar5 = 0;
  if (DAT_030f9958 < (int)(uVar2 & 0x7fffffff)) {
    uVar2 = (0x100000U >> (DAT_030f9954 + ((int)(uVar2 & 0x7fffffff) >> 0x14) + 1U & 0xff)) + uVar2;
    uVar10 = ((uVar2 & 0x7fffffff) >> 0x14) - 0x3ff;
    uVar5 = (uVar2 & 0xfffff | 0x100000) >> (0x14 - uVar10 & 0xff);
    if (lVar17 < 0) {
      uVar5 = -uVar5;
    }
    uVar21 = FUN_030f6ba8(uVar11,uVar7,*(undefined4 *)(DAT_030f995c + 0x30f9898),
                          uVar2 & ~(DAT_030f9960 >> (uVar10 & 0xff)));
  }
  uVar11 = (undefined4)((ulonglong)uVar21 >> 0x20);
  softfloat_dadd_a(uVar4,uVar6,(int)uVar21,uVar11);
  uVar18 = softfloat_dmul_a(0,extraout_r1_03,0,DAT_030f9964);
  uVar7 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = softfloat_dmul_a(0,extraout_r1_03,DAT_030f9968,DAT_030f996c);
  uVar21 = FUN_030f6ba8(0,extraout_r1_03,(int)uVar21,uVar11);
  uVar21 = FUN_030f6bae((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),uVar4,uVar6);
  uVar21 = softfloat_dmul_a((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),DAT_030f9a70,DAT_030f9a74);
  uVar21 = softfloat_dadd_a((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),(int)uVar19,
                            (int)((ulonglong)uVar19 >> 0x20));
  uVar4 = (undefined4)((ulonglong)uVar21 >> 0x20);
  uVar19 = softfloat_dadd_a((int)uVar21,uVar4,(int)uVar18,uVar7);
  uVar6 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar11 = (undefined4)uVar19;
  uVar18 = FUN_030f6ba8(uVar11,uVar6,(int)uVar18,uVar7);
  uVar21 = FUN_030f6bae((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar21,uVar4);
  uVar4 = (undefined4)((ulonglong)uVar21 >> 0x20);
  uVar18 = softfloat_dmul_a(uVar11,uVar6);
  uVar7 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = FUN_030f8722(DAT_030f9a78 + 0x30f99c0,5,(int)uVar18,uVar7);
  uVar18 = softfloat_dmul_a((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,uVar7);
  uVar18 = FUN_030f6bae((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar11,uVar6);
  uVar7 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = softfloat_dmul_a(uVar11,uVar6,(int)uVar21,uVar4);
  uVar21 = softfloat_dadd_a((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar21,uVar4);
  uVar19 = FUN_030f6ba8((int)uVar18,uVar7,0,0x40000000);
  uVar18 = softfloat_dmul_a(uVar11,uVar6,(int)uVar18,uVar7);
  uVar18 = FUN_030f6706((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar19,
                        (int)((ulonglong)uVar19 >> 0x20));
  uVar21 = FUN_030f6ba8((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar21,
                        (int)((ulonglong)uVar21 >> 0x20));
  uVar21 = FUN_030f6ba8((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),uVar11,uVar6);
  uVar21 = FUN_030f6bae((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),0,DAT_030f9a7c);
  iVar13 = (int)((ulonglong)uVar21 >> 0x20);
  uVar11 = (undefined4)uVar21;
  iVar9 = iVar13 + uVar5 * 0x100000;
  uVar21 = CONCAT44(iVar9,uVar11);
  if (iVar9 >> 0x14 < 1) {
    FUN_030f6bb4(uVar11,iVar13,uVar5);
    iVar9 = FUN_030f86fa();
    if (iVar9 == 4) {
      FUN_030f87cc();
    }
    uVar21 = FUN_030f6bb4(uVar11,iVar13,uVar5);
  }
  lVar17 = softfloat_dmul_a(0,param_2,(int)uVar21,(int)((ulonglong)uVar21 >> 0x20));
  return lVar17;
}


