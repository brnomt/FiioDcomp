/**
 * FUN_030234e8 @ 0x030234e8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030234e8(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  byte bVar2;
  undefined1 *puVar3;
  int *piVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined1 *puVar12;
  uint uVar13;
  byte *pbVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  bool bVar20;
  undefined1 auStack_790 [512];
  byte abStack_590 [512];
  undefined1 auStack_390 [512];
  byte abStack_190 [256];
  byte abStack_90 [52];
  undefined4 uStack_5c;
  uint auStack_58 [2];
  uint local_50;
  uint uStack_4c;
  byte abStack_48 [4];
  char acStack_44 [4];
  undefined4 uStack_40;
  undefined1 auStack_3c [8];
  undefined4 uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  uint uStack_28;
  
  uVar17 = 0;
  if (((param_3 < 0xff1c) &&
      (uStack_34 = param_1, uStack_30 = param_2, uStack_2c = param_3, uStack_28 = param_4,
      uVar6 = FUN_02ffc9d6(&local_50,4,param_1), uVar19 = local_50, 3 < uVar6)) &&
     (local_50 <= param_3)) {
    FUN_02ffcece(local_50 + 4,1,param_1);
    uVar19 = (param_3 - uVar19) - 8;
    if (uVar19 != 0) {
      do {
        uVar7 = FUN_02ffc9d6(&local_50,4,param_1);
        uVar6 = local_50;
        if (uVar7 >= 4) {
          param_3 = uVar17 + 4;
        }
        if (uVar7 < 4 || uVar19 < param_3) {
          return 0;
        }
        if ((int)local_50 < 1) {
          return 0;
        }
        iVar18 = 0;
        do {
          iVar8 = FUN_02ffc9d6(abStack_90 + iVar18,1,param_1);
          if (iVar8 == 0) {
            return 0;
          }
          param_3 = param_3 + 1;
          if (uVar19 < param_3) break;
          uVar17 = (uint)abStack_90[iVar18];
          bVar20 = SBORROW4(uVar17,0x3d);
          iVar8 = uVar17 - 0x3d;
          if (uVar17 != 0x3d) {
            bVar20 = SBORROW4(iVar18 + 1,0x32);
            iVar8 = iVar18 + -0x31;
            iVar18 = iVar18 + 1;
          }
        } while (iVar8 < 0 != bVar20);
        if (iVar18 == 0x32) {
          return 0;
        }
        uVar17 = (uVar6 - iVar18) - 1;
        iVar18 = FUN_02ff8a16(abStack_90,s_METADATA_BLOCK_PICTURE_03023ab8,iVar18);
        piVar4 = DAT_03023ad0;
        if (iVar18 == 0) {
          uVar19 = uVar19 - param_3;
          iVar18 = 0;
          uVar6 = 0;
          if (uVar17 != 0 && uVar19 != 0) {
            uStack_5c = param_1;
            uStack_4c = param_4;
            if (*DAT_03023ad0 != 0) {
              FUN_02ffc8bc((int)*DAT_03023ad4);
              *DAT_03023ad4 = -1;
              *piVar4 = 0;
            }
            FUN_03000296(&DAT_03023ae4,s_PICTURE_OGG_03023ad8);
            iVar8 = FUN_0300024e(&DAT_03023ae4,s_PICTURE_OGG_03023ad8);
            *DAT_03023ad4 = (char)iVar8;
            if (iVar8 != -1) {
              *piVar4 = 1;
              uVar7 = 0;
              goto LAB_03023736;
            }
          }
          return 0;
        }
        FUN_02ffcece(uVar17,1,param_1);
        uVar17 = param_3 + uVar17;
      } while (uVar17 <= uVar19);
    }
  }
  return 0;
LAB_03023736:
  func_0x03004d9c();
  while (uVar19 != 0 && uVar17 != 0) {
    uVar9 = uVar19;
    if (0x1ff < uVar19) {
      uVar9 = 0x200;
    }
    if (uVar7 == 0) {
      if (uVar17 < uVar9) {
        uVar9 = uVar17;
      }
      uVar11 = FUN_02ffc9d6(abStack_590,uVar9,uStack_5c);
      uVar13 = uVar9;
      if (uVar11 < uVar9) {
        return 0;
      }
    }
    else {
      uVar13 = uVar9 - uVar7;
      bVar20 = uVar13 < 0x200 - uVar7;
      if (bVar20) {
        uVar13 = 0x200 - uVar7;
      }
      if (bVar20 && uVar9 < uVar13) {
        uVar13 = uVar9;
      }
      if (uVar17 < uVar13) {
        uVar13 = uVar17;
      }
      uVar9 = FUN_02ffc9d6(abStack_590 + uVar7,uVar13,uStack_5c);
      if (uVar9 < uVar13) {
        return 0;
      }
      uVar9 = uVar7 + uVar13;
      uVar7 = 0;
    }
    uVar17 = uVar17 - uVar13;
    uVar19 = uVar19 - uVar13;
    if (((uVar9 != 0x200) && (uStack_4c == 0xffffffff)) && (uVar17 != 0)) goto LAB_030239ac;
    uStack_40 = 0x200;
    uVar13 = 0;
    uVar11 = 0;
    pbVar14 = abStack_590;
    iVar8 = 0;
    if (uVar9 == 0) {
LAB_030238a4:
      param_4 = 0;
LAB_0302392a:
      iVar8 = 0;
    }
    else {
      do {
        iVar15 = 0;
        for (; (uVar13 < uVar9 && (pbVar14[uVar13] == 0x20)); uVar13 = uVar13 + 1) {
          iVar15 = iVar15 + 1;
        }
        if (uVar13 == uVar9) break;
        bVar20 = uVar9 - uVar13 == 2;
        if (1 < uVar9 - uVar13) {
          bVar20 = pbVar14[uVar13] == 0xd;
        }
        if (bVar20) {
          bVar2 = abStack_590[uVar13 + 1];
        }
        else {
          bVar2 = pbVar14[uVar13];
        }
        if (bVar2 != 10) {
          if (iVar15 == 0) {
            uVar16 = (uint)pbVar14[uVar13];
            if (uVar16 == 0x3d) {
              uVar11 = uVar11 + 1;
              if (2 < uVar11) {
                iVar8 = -2;
                goto LAB_0302392c;
              }
LAB_03023848:
              if (*(byte *)(DAT_03023ae8 + uVar16) != 0x7f) {
                if ((0x3f < *(byte *)(DAT_03023ae8 + uVar16)) || (uVar11 == 0)) {
                  iVar8 = iVar8 + 1;
                  goto LAB_03023876;
                }
                iVar8 = -4;
                goto LAB_0302392c;
              }
            }
            else if (uVar16 < 0x80) goto LAB_03023848;
            iVar8 = -3;
            goto LAB_0302392c;
          }
          iVar8 = -1;
          goto LAB_0302392c;
        }
LAB_03023876:
        uVar13 = uVar13 + 1;
      } while (uVar13 < uVar9);
      if (iVar8 == 0) goto LAB_030238a4;
      param_4 = (iVar8 * 6 + 7U >> 3) - uVar11;
      if ((auStack_390 != (undefined1 *)0x0) && (param_4 < 0x201)) {
        uVar9 = 0;
        uVar11 = 3;
        iVar8 = 0;
        puVar3 = auStack_390;
        for (; uVar13 != 0; uVar13 = uVar13 - 1) {
          uVar16 = (uint)*pbVar14;
          puVar12 = puVar3;
          if ((uVar16 != 0xd && uVar16 != 10) && uVar16 != 0x20) {
            uVar11 = uVar11 - (*(byte *)(DAT_03023ae8 + uVar16) == 0x40);
            uVar1 = uVar9 << 6;
            uVar9 = *(byte *)(DAT_03023ae8 + uVar16) & 0x3f | uVar1;
            iVar8 = iVar8 + 1;
            if ((iVar8 == 4) && (iVar8 = 0, uVar11 != 0)) {
              *puVar3 = (char)(uVar1 >> 0x10);
              puVar12 = puVar3 + 1;
              if (1 < uVar11) {
                puVar3[1] = (char)(uVar1 >> 8);
                puVar12 = puVar3 + 2;
                if (2 < uVar11) {
                  puVar12 = puVar3 + 3;
                  puVar3[2] = (char)uVar9;
                }
              }
            }
          }
          pbVar14 = pbVar14 + 1;
          puVar3 = puVar12;
        }
        param_4 = (int)puVar3 - (int)auStack_390;
        goto LAB_0302392a;
      }
      iVar8 = -5;
    }
LAB_0302392c:
    if (iVar8 != 0) {
      thunk_FUN_03011c1c(s_base64_decode_error__ret___d_03023aec);
    }
    uVar9 = param_4;
    if (0x200 - uVar6 < param_4) {
      uVar9 = 0x200 - uVar6;
    }
    FUN_02ff890e(auStack_790 + uVar6,auStack_390,uVar9);
    uVar6 = uVar6 + uVar9;
    if (uVar6 == 0x200) {
      uVar6 = func_0x03000448(auStack_790,iVar18,0x200,(int)*DAT_03023ad4);
      if (uVar6 < 0x200) goto LAB_03023970;
      uVar6 = param_4 - uVar9;
      iVar18 = iVar18 + 0x200;
      FUN_02ff890e(auStack_790,auStack_390 + uVar9);
    }
  }
  if ((uStack_4c != 0xffffffff) || (uVar9 = uVar7, uVar17 == 0)) {
    if ((uVar6 == 0) ||
       (uVar17 = func_0x03000448(auStack_790,iVar18,uVar6,(int)*DAT_03023ad4), uVar6 <= uVar17)) {
      pcVar5 = DAT_03023ad4;
      FUN_02ffcece(0,0,(int)*DAT_03023ad4);
      uVar17 = FUN_02ffc9d6(auStack_790,0x200,(int)*pcVar5);
      if (0x1ff < uVar17) {
        uVar10 = FUN_02ff89ce(auStack_790,s_image__03023674,6);
        return uVar10;
      }
      thunk_FUN_03011c1c(s_MetaBlockPicHandle_Read_Error_03023f24);
    }
    else {
LAB_03023970:
      thunk_FUN_03011c1c(s_FileWrite_error_03023b0c);
    }
    return 0;
  }
LAB_030239ac:
  uVar7 = FUN_02ffc9d6(auStack_58,4,uStack_5c);
  if (uVar7 < 4) {
    return 0;
  }
  iVar8 = FUN_02ff89b4(auStack_58,&DAT_03023b20,4);
  if (iVar8 != 0) {
    return 0;
  }
  iVar8 = FUN_02ffc9d6(acStack_44,1,uStack_5c);
  if (iVar8 == 0) {
    return 0;
  }
  if (acStack_44[0] != '\0') {
    return 0;
  }
  iVar8 = FUN_02ffc9d6(auStack_3c,1,uStack_5c);
  if (iVar8 == 0) {
    return 0;
  }
  uVar7 = FUN_02ffc9d6(auStack_58,8,uStack_5c);
  if (uVar7 < 8) {
    return 0;
  }
  uStack_4c = auStack_58[0];
  FUN_02ffcece(0xc,1,uStack_5c);
  iVar8 = FUN_02ffc9d6(abStack_48,1,uStack_5c);
  if (iVar8 == 0) {
    return 0;
  }
  uVar7 = FUN_02ffc9d6(abStack_190,abStack_48[0],uStack_5c);
  uVar13 = (uint)abStack_48[0];
  if (uVar7 < uVar13) {
    return 0;
  }
  iVar8 = 0;
  uVar7 = uVar9;
  if (uStack_4c != 0xffffffff) {
    if (uVar13 != 0) {
      do {
        if (abStack_190[iVar8] != 0xff) {
          uVar19 = uVar19 + abStack_190[iVar8];
          break;
        }
        uVar19 = uVar19 + 0xff;
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)uVar13);
    }
    goto LAB_03023736;
  }
  if (uVar13 != 0) {
    do {
      pbVar14 = abStack_190 + iVar8;
      iVar8 = iVar8 + 1;
      uVar19 = uVar19 + *pbVar14;
    } while (iVar8 < (int)uVar13);
  }
  goto LAB_03023736;
}


