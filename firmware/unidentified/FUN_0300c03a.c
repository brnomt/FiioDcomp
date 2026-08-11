/**
 * FUN_0300c03a @ 0x0300c03a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0300c03a(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  undefined2 auStack_40 [16];
  
  iVar7 = FUN_02ff4186();
  iVar4 = DAT_0300c114;
  iVar3 = DAT_0300c110;
  iVar9 = DAT_0300c10c;
  iVar10 = DAT_0300c100;
  iVar8 = iVar7;
  if ((iVar7 == DAT_0300c10c || iVar7 == DAT_0300c110) || iVar7 == DAT_0300c114) {
    iVar8 = FUN_02ffa6b0(1);
    if (iVar8 == 0) {
      iVar8 = FUN_02ff3e56(0,0x7d,0xa0,0xaa,0);
      iVar12 = DAT_0300c118;
      iVar1 = DAT_0300c11c;
      iVar2 = DAT_0300c120;
      if (((iVar8 == 0) &&
          (iVar8 = FUN_02ff3e56(0xa0,0x7d,0x140,0xaa,0), iVar12 = DAT_0300c124, iVar1 = DAT_0300c128
          , iVar2 = DAT_0300c12c, iVar8 == 0)) ||
         ((iVar7 != iVar9 && ((iVar12 = iVar1, iVar7 != iVar3 && (iVar12 = iVar2, iVar7 != iVar4))))
         )) goto LAB_0300c0c8;
    }
    else {
      FUN_02ffa694(0x2f);
      iVar12 = 0;
    }
  }
  else {
LAB_0300c0c8:
    if (iVar7 != iVar9) {
      iVar8 = iVar7 + -0x50000000;
    }
    if ((((iVar7 == iVar9 || iVar8 == 0x80) || (iVar12 = iVar7, iVar7 == iVar3 || iVar7 == iVar4))
        && (iVar8 = FUN_02ff3e56(0,0,0x3c,0x32,0), iVar12 = DAT_0300c3d4, iVar8 == 0)) &&
       (iVar12 = iVar7, iVar7 != iVar4)) {
      uVar13 = 0;
      do {
        iVar8 = FUN_02ff3e56(0,uVar13 * 0x18 + 0x1b,0xf0,uVar13 * 0x18 + 0x6b,0);
        if (iVar8 != 0) {
          *(char *)(iVar10 + 3) = (char)uVar13;
          iVar12 = DAT_0300c3d8;
          FUN_02ffa694(0x149);
          FUN_02ffa6d6(0x14a);
          FUN_0300bf34();
          break;
        }
        uVar13 = uVar13 + 1 & 0xffff;
      } while (uVar13 < 3);
    }
  }
  iVar8 = DAT_0300c3e8;
  puVar5 = DAT_0300c3e4;
  iVar9 = iVar12 - DAT_0300c3dc;
  if (iVar12 == DAT_0300c3dc) goto LAB_0300c362;
  if (DAT_0300c3dc <= iVar12) {
    iVar8 = iVar9 - DAT_0300c3f4;
    if (iVar9 == DAT_0300c3f4) {
      auStack_40[0] = 1;
      FUN_02fe9590(DAT_0300c400,DAT_0300c404,auStack_40);
      return 0;
    }
    if (iVar9 < DAT_0300c3f4) {
      if (iVar9 == 0xe00) {
LAB_0300c362:
        FUN_0300b86c();
        FUN_02fe95a8(DAT_0300c400);
        FUN_02ffa6d6(0x14a);
        FUN_02ffa694(0x135);
        return 0;
      }
      if (0xe00 < iVar9) {
        if (iVar9 != 0xfe00) {
          if (iVar9 != 0xfffe00) {
            return 0;
          }
          auStack_40[0] = 0;
          FUN_02fe9590(DAT_0300c400,DAT_0300c404,auStack_40);
          return 0;
        }
        goto LAB_0300c362;
      }
      if (iVar9 != 0x200) {
        if (iVar9 != 0x600) {
          return 0;
        }
        goto LAB_0300c2e6;
      }
    }
    else {
      if (iVar8 == 0xe000200) goto LAB_0300c362;
      if (iVar8 != 0xe000400) {
        if (iVar8 != 0xe000800) {
          if (iVar8 != 0xe010000) {
            return 0;
          }
          goto LAB_0300c362;
        }
        goto LAB_0300c2e6;
      }
    }
    goto LAB_0300c2be;
  }
  iVar9 = iVar12 - DAT_0300c3e0;
  if (iVar12 == DAT_0300c3e0) {
LAB_0300c27a:
    iVar10 = FUN_02fe9720(*DAT_0300c3e4,DAT_0300c3f8);
    if ((iVar10 == 1) && (*(char *)(iVar8 + 0x12) != '\0')) {
      *(char *)(iVar8 + 0x12) = *(char *)(iVar8 + 0x12) + -1;
      FUN_03017adc(0xff,0);
    }
    iVar10 = FUN_02fe9720(*puVar5,DAT_0300c3fc);
    if (iVar10 != 1) {
      return 0;
    }
    if (*(char *)(iVar8 + 0x12) == '\0') {
      return 0;
    }
    *(char *)(iVar8 + 0x12) = *(char *)(iVar8 + 0x12) + -1;
    FUN_03024952(0xb6,0);
    return 0;
  }
  if (iVar12 < DAT_0300c3e0) {
    iVar9 = iVar12 - DAT_0300c3ec;
    if (iVar12 != DAT_0300c3ec) {
      if (iVar12 < DAT_0300c3ec) {
        if (iVar9 == -0x20000000) goto LAB_0300c2e6;
        if (iVar9 != -0x1ffffffc) {
          return 0;
        }
      }
      else if (iVar9 != 4) {
        if (iVar9 != 0xc) {
          return 0;
        }
        goto LAB_0300c22e;
      }
LAB_0300c2be:
      if (*(char *)(iVar10 + 3) == '\0') {
        cVar6 = '\x02';
      }
      else {
        cVar6 = *(char *)(iVar10 + 3) + -1;
      }
      *(char *)(iVar10 + 3) = cVar6;
      cVar6 = *(char *)(iVar10 + 5);
      goto joined_r0x0300c2f6;
    }
  }
  else {
    if (iVar9 == DAT_0300c3f0) {
LAB_0300c22e:
      iVar10 = FUN_02fe9720(*DAT_0300c3e4,DAT_0300c3f8);
      if ((iVar10 == 1) && (*(byte *)(iVar8 + 0x12) < *(byte *)(iVar8 + 0x1e))) {
        *(byte *)(iVar8 + 0x12) = *(byte *)(iVar8 + 0x12) + 1;
        FUN_03017adc(0xff,0);
      }
      iVar10 = FUN_02fe9720(*puVar5,DAT_0300c3fc);
      if (iVar10 != 1) {
        return 0;
      }
      if (*(byte *)(iVar8 + 0x1e) <= *(byte *)(iVar8 + 0x12)) {
        return 0;
      }
      *(byte *)(iVar8 + 0x12) = *(byte *)(iVar8 + 0x12) + 1;
      FUN_03024952(0xb6,0);
      return 0;
    }
    if (DAT_0300c3f0 <= iVar9) {
      if (iVar9 - DAT_0300c3f0 != 0x10) {
        if (iVar9 - DAT_0300c3f0 != 0x30) {
          return 0;
        }
        cVar6 = *(char *)(iVar10 + 2);
        if (cVar6 == '\x02') {
          FUN_0300ba2c(*(byte *)(iVar10 + 3) + 1);
        }
        else if (cVar6 == '\x01') {
          FUN_0300b8d4(*(byte *)(iVar10 + 3) + 1,0);
        }
        else if (cVar6 == '\x03') {
          FUN_0300b8d4(*(byte *)(iVar10 + 3) + 1,1);
          FUN_02ffa6d6(0x14a);
          *(undefined1 *)(iVar10 + 5) = 0;
        }
        FUN_0300b86c();
        if (*(char *)(iVar10 + 2) == '\x02') {
          FUN_02fe95a8(DAT_0300c400);
          FUN_02ffa6d6(0x14a);
          uVar11 = 0x135;
        }
        else {
          uVar11 = 0x143;
        }
        FUN_02ffa694(uVar11);
        return 0;
      }
      goto LAB_0300c27a;
    }
    if (iVar9 == 0x3e0) goto LAB_0300c2be;
    if (iVar9 != 0x7e0) {
      return 0;
    }
  }
LAB_0300c2e6:
  if (*(byte *)(iVar10 + 3) < 2) {
    *(byte *)(iVar10 + 3) = *(byte *)(iVar10 + 3) + 1;
  }
  else {
    *(undefined1 *)(iVar10 + 3) = 0;
  }
  cVar6 = *(char *)(iVar10 + 5);
joined_r0x0300c2f6:
  if (cVar6 == '\x01') {
    *(undefined1 *)(iVar10 + 5) = 0;
  }
  FUN_02ffa694(0x149);
  FUN_02ffa6d6(0x14a);
  return 0;
}


