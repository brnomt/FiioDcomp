/**
 * FUN_0300eaee @ 0x0300eaee
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0300eaee(void)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  char *pcVar4;
  uint *puVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint extraout_r1;
  uint uVar13;
  uint uVar14;
  int iVar15;
  ushort uVar16;
  ushort uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  bool bVar21;
  bool bVar22;
  ushort local_58 [16];
  undefined4 local_38;
  uint local_34;
  ushort auStack_30 [6];
  
  local_38 = 0;
  iVar8 = FUN_02ffc904(0x1c7);
  puVar3 = DAT_0300eb84;
  pcVar2 = DAT_0300eb80;
  iVar15 = DAT_0300eb78;
  iVar12 = DAT_0300eb64;
  if (iVar8 != 0) {
    return local_38;
  }
  if (*(char *)(DAT_0300eb78 + 0x34a) == *DAT_0300eb80) goto LAB_0300ebf0;
  if (*(char *)(DAT_0300eb78 + 0x34a) == '\0') {
    *DAT_0300eb84 = 0;
    *(undefined1 *)(iVar15 + 0x12) = *(undefined1 *)(iVar15 + 0x13);
    FUN_02ffc8e6(0x1dd);
  }
  else {
    FUN_02fe6ae0(2,0);
    FUN_02fea8e0(2,0,1);
    FUN_02fea91a(2,0,1);
    FUN_02fe6ae0(2,0xe,0);
    FUN_02fea8e0(2,0xe,1);
    FUN_02fea91a(2,0xe,0);
    *puVar3 = 1;
    *(undefined1 *)(iVar15 + 0x12) = *(undefined1 *)(iVar15 + 0x15);
    iVar8 = FUN_02feb930(*DAT_0300ef84,DAT_0300ef80);
    if (iVar8 == 1) {
      if ((*DAT_0300ef88 != 3) || (*(char *)(iVar12 + 3) == '\0')) goto LAB_0300ebe8;
      *(undefined1 *)(iVar12 + 3) = 0;
      FUN_03019cec(0xee,0);
      FUN_02ffc8a4(0x1d5);
      uVar9 = 0x2b;
    }
    else {
      uVar9 = 0x1d4;
    }
    FUN_02ffc8a4(uVar9);
  }
LAB_0300ebe8:
  *pcVar2 = *(char *)(iVar15 + 0x34a);
LAB_0300ebf0:
  pcVar2 = DAT_0300ef8c;
  if (*(char *)(iVar15 + 0x34a) == '\0') {
    FUN_02ffc8e6(0x1d4);
  }
  else {
    iVar8 = FUN_02ffc8c0(0x1d5);
    if (iVar8 != 0) {
      FUN_02ffb1ac(0x59,0x1e);
      FUN_02ffb1fa(DAT_0300ef90,(int)*pcVar2);
    }
    iVar8 = FUN_02ffc8c0(0x1d4);
    if (iVar8 != 0) {
      FUN_02ffb1ac(0x59,0);
      FUN_02ffb1fa(DAT_0300ef90,(int)*pcVar2);
    }
  }
  pcVar4 = DAT_0300ef94;
  if (((*(char *)(iVar15 + 0x349) != '\0') && (iVar8 = FUN_02ffc904(0x1cf), iVar8 != 0)) &&
     (*pcVar4 == '\0')) {
    FUN_02ffc8e6(0x1cf);
    iVar8 = FUN_02ffc8c0(0x1d0);
    if (iVar8 != 0) {
      local_58[0] = local_58[0] & 0xff00;
      FUN_02ffcace(0,local_58);
      return 1;
    }
  }
  puVar5 = DAT_0300ef98;
  if ((*DAT_0300ef98 - *(int *)(iVar12 + 8) == 400) && (iVar8 = FUN_02ffc904(0x34), iVar8 != 0)) {
    if (*pcVar4 == '\x01') {
      FUN_02ffb1c8(0x53);
      FUN_02ffc8a4(0x1c6);
    }
    puVar3 = DAT_0300ef90;
    if (*pcVar4 == '\x02') {
      *DAT_0300ef90 = 0x43;
      if (*puVar5 - *(int *)(iVar12 + 8) == 100) {
        puVar3[1] = 0x4c;
      }
      else {
        puVar3[1] = 0x48;
      }
      iVar12 = DAT_0300ef9c + *(char *)(iVar12 + 1) * 0x26;
      uVar11 = 0;
      do {
        uVar10 = uVar11 + 1 & 0xffff;
        puVar3[uVar11 + 4] = *(undefined1 *)(iVar12 + uVar11 + -0x26);
        uVar11 = uVar10;
      } while (uVar10 < 6);
      *(undefined1 *)(iVar15 + 0x349) = 0;
      puVar3[2] = 0x30;
      puVar3[3] = 0x36;
      *pcVar2 = '\n';
      uVar11 = 0;
      do {
        iVar8 = iVar12 + uVar11;
        iVar18 = iVar15 + uVar11;
        uVar11 = uVar11 + 1 & 0xffff;
        *(undefined1 *)(iVar18 + 0x328) = *(undefined1 *)(iVar8 + -0x20);
      } while (uVar11 < 0x20);
      FUN_02ffc8a4(0x1ca);
      FUN_02ffc8a4(0x1c6);
    }
  }
  if (2999 < *DAT_0300ef98 - *(int *)(DAT_0300efa0 + 8)) {
    if (*pcVar4 == '\x01') {
      FUN_02ffb1c8(0x50);
      *pcVar4 = '\0';
      FUN_02ffc8a4(0x1c6);
    }
    if (*pcVar4 == '\x02') {
      FUN_02ffb1c8(0x54);
      *pcVar4 = '\0';
      FUN_02ffc8a4(0x1c6);
    }
  }
  if (*pcVar4 == '\a') {
    local_58[0] = 4;
    FUN_02ffcace(10,local_58);
    return 1;
  }
  iVar12 = FUN_02ffc8c0(0x1ca);
  if (iVar12 == 0) {
    if (*DAT_0300ef98 / 300 != *DAT_0300efa4) {
      *DAT_0300efa4 = *DAT_0300ef98 / 300;
      FUN_02ffb1c8(0x51);
      FUN_02ffc8a4(0x1ca);
    }
  }
  else {
    FUN_02ffb1fa(DAT_0300ef90,(int)*pcVar2);
  }
  iVar8 = FUN_02ffc8c0(0x1c5);
  iVar12 = DAT_0300efa8;
  if (iVar8 == 0) {
code_r0x0300f34e:
    iVar8 = FUN_02ffc8c0(0x1c8);
    iVar12 = DAT_0300f3b0;
    if (iVar8 != 0) {
      uVar11 = 0;
      do {
        uVar10 = 0;
        iVar8 = iVar12 + uVar11 * 0x26;
        do {
          *(undefined1 *)(iVar8 + uVar10) = 0;
          uVar10 = uVar10 + 1 & 0xff;
        } while (uVar10 < 6);
        uVar10 = 0;
        do {
          iVar18 = iVar8 + uVar10;
          uVar10 = uVar10 + 1 & 0xff;
          *(undefined1 *)(iVar18 + 6) = 0;
        } while (uVar10 < 0x20);
        uVar11 = uVar11 + 1 & 0xff;
      } while (uVar11 < 6);
      uVar11 = 0;
      do {
        *(undefined1 *)(iVar12 + uVar11) = *(undefined1 *)(iVar15 + uVar11 + 0x23e);
        uVar11 = uVar11 + 1 & 0xff;
      } while (uVar11 < 6);
      uVar11 = 0;
      do {
        iVar8 = iVar15 + uVar11;
        iVar18 = iVar12 + uVar11;
        uVar11 = uVar11 + 1 & 0xff;
        *(undefined1 *)(iVar18 + 6) = *(undefined1 *)(iVar8 + 0x328);
        uVar9 = DAT_0300f4b4;
        puVar3 = DAT_0300f4b0;
      } while (uVar11 < 0x20);
      DAT_0300f4b0[1] = 1;
      *puVar3 = 1;
      local_58[0] = 8;
      local_58[1] = 0x7e;
      local_58[2] = 1;
      FUN_02feb7a0(DAT_0300f4b8,uVar9,local_58);
    }
    iVar12 = FUN_02ffc8c0(0x1cb);
    if (iVar12 != 0) {
      local_58[0] = 8;
      local_58[1] = 0x7f;
      local_58[2] = 1;
      FUN_02feb7a0(DAT_0300f4b8,DAT_0300f4b4,local_58);
    }
    iVar12 = FUN_02ffc8c0(0xdf);
    if (iVar12 != 0) {
      if (*(char *)(iVar15 + 0x34a) != '\0') {
        FUN_02ffb1c8(0x54);
        iVar12 = DAT_0300f4bc;
        uVar11 = 0;
        do {
          uVar10 = 0;
          iVar15 = iVar12 + uVar11 * 0x26;
          do {
            *(undefined1 *)(iVar15 + uVar10) = 0;
            uVar10 = uVar10 + 1 & 0xff;
          } while (uVar10 < 6);
          uVar10 = 0;
          do {
            iVar8 = iVar15 + uVar10;
            uVar10 = uVar10 + 1 & 0xff;
            *(undefined1 *)(iVar8 + 6) = 0;
            puVar3 = DAT_0300f4b0;
          } while (uVar10 < 0x20);
          uVar11 = uVar11 + 1 & 0xff;
        } while (uVar11 < 6);
        *DAT_0300f4b0 = 0;
        *(undefined2 *)(puVar3 + 4) = 50000;
        FUN_02ffc8a4(0x1c9);
      }
      FUN_02ffc8a4(0x1c6);
    }
    iVar12 = FUN_02ffc8c0(0xe0);
    if (iVar12 != 0) {
      FUN_02ffc8a4(0x1c6);
    }
    iVar12 = FUN_02ffc8c0(0xe3);
    if (iVar12 != 0) {
      FUN_02ffc8a4(0x1c6);
    }
  }
  else {
    uVar11 = 0;
    do {
      if ((*(char *)(iVar12 + uVar11) != 'C') &&
         (uVar11 = uVar11 + 1 & 0xffff, *(char *)(iVar12 + uVar11) != 'C')) {
LAB_0300ee06:
        if (99 < uVar11) {
          return local_38;
        }
        if (*(char *)(iVar12 + uVar11) != 'C') {
          uVar9 = FUN_0300f34e();
          return uVar9;
        }
        FUN_02ffc8e6(0x34);
        pcVar2 = DAT_0300f3ac;
        iVar12 = DAT_0300efa8 + uVar11;
        uVar10 = (uint)*(byte *)(iVar12 + 2);
        if (uVar10 == 0x45) {
          if (*(char *)(iVar12 + 3) == 'R') {
            cVar1 = *(char *)(iVar12 + 1);
            if (cVar1 == 'S') goto code_r0x0300f34e;
            if (cVar1 == 'L') {
              *pcVar4 = '\0';
              *(undefined1 *)(iVar15 + 0x34a) = 0;
              FUN_02ffc8a4(0x1cb);
              goto LAB_0300f0ac;
            }
            if (cVar1 != 'H') goto LAB_0300f0ac;
LAB_0300ef22:
            *pcVar4 = '\0';
            *(undefined1 *)(iVar15 + 0x34a) = 0;
            uVar9 = 0x1cb;
            goto LAB_0300ef42;
          }
LAB_0300ee4a:
          if (*(char *)(iVar12 + 1) != 'S') goto LAB_0300f0ac;
          cVar1 = 'S';
          if (uVar10 == 0x45) {
            cVar1 = *(char *)(iVar12 + 3);
          }
          if ((uVar10 == 0x45 && cVar1 == 'N') ||
             (local_34 = (uVar10 - 0x30) * 10 + -0x30 + (uint)*(byte *)(iVar12 + 3) & 0xffff,
             0x25 < local_34)) {
            *pcVar4 = '\0';
            return local_38;
          }
          uVar13 = 0;
          uVar10 = uVar13;
          do {
            iVar8 = uVar11 + uVar13;
            uVar13 = uVar13 + 1 & 0xffff;
            uVar10 = *(byte *)(iVar8 + DAT_0300f3a8 + 4) + uVar10 & 0xffff;
          } while (uVar13 < 6);
          uVar13 = 0;
          cVar1 = *DAT_0300f3ac;
          iVar8 = (int)cVar1;
          if (0 < iVar8) {
            do {
              auStack_30[uVar13] = 0;
              uVar14 = 0;
              do {
                uVar16 = auStack_30[uVar13] +
                         (ushort)*(byte *)(DAT_0300f3b0 + uVar13 * 0x26 + uVar14);
                uVar14 = uVar14 + 1 & 0xffff;
                auStack_30[uVar13] = uVar16;
              } while (uVar14 < 6);
              if (uVar16 == uVar10) {
                return local_38;
              }
              uVar13 = uVar13 + 1 & 0xffff;
            } while ((int)uVar13 < iVar8);
          }
          uVar10 = local_34 - 6 & 0xffff;
          if (uVar10 != 0) {
            if (5 < iVar8) {
              return local_38;
            }
            cVar1 = cVar1 + '\x01';
            *DAT_0300f3ac = cVar1;
            if (cVar1 == 1) {
              pcVar2[1] = '\x01';
            }
            uVar13 = 0;
            iVar8 = DAT_0300f3b0 + cVar1 * 0x26;
            do {
              iVar18 = iVar8 + uVar13;
              uVar13 = uVar13 + 1 & 0xffff;
              *(undefined1 *)(iVar18 + -0x20) = 0;
              iVar18 = DAT_0300f3a8;
            } while (uVar13 < 0x20);
            uVar13 = 0;
            if (uVar10 != 0) {
              do {
                iVar20 = uVar11 + uVar13;
                iVar19 = iVar8 + uVar13;
                uVar13 = uVar13 + 1 & 0xffff;
                *(undefined1 *)(iVar19 + -0x20) = *(undefined1 *)(iVar20 + iVar18 + 10);
              } while (uVar13 < uVar10);
            }
            iVar18 = DAT_0300f3a8;
            *(undefined1 *)(uVar13 + iVar8 + -0x20) = 0;
            uVar10 = 0;
            do {
              iVar19 = uVar11 + uVar10;
              iVar20 = iVar8 + uVar10;
              uVar10 = uVar10 + 1 & 0xffff;
              *(undefined1 *)(iVar20 + -0x26) = *(undefined1 *)(iVar19 + iVar18 + 4);
            } while (uVar10 < 6);
            uVar10 = 0;
            do {
              iVar8 = uVar11 + uVar10;
              uVar10 = uVar10 + 1 & 0xffff;
              *(undefined1 *)(iVar8 + iVar18 + 10) = 0;
            } while (uVar10 < 0x20);
            uVar9 = 0x1c6;
LAB_0300ef42:
            FUN_02ffc8a4(uVar9);
          }
        }
        else {
          uVar13 = extraout_r1;
          if (uVar10 == 0x4f) {
            uVar13 = (uint)*(byte *)(iVar12 + 3);
          }
          if (uVar10 != 0x4f || uVar13 != 0x4b) goto LAB_0300ee4a;
          cVar1 = *(char *)(iVar12 + 1);
          if (cVar1 != 'L') {
            if (cVar1 == 'T') goto LAB_0300ef22;
            if (cVar1 != 'H') goto LAB_0300f0ac;
            *pcVar4 = '\0';
            *(undefined1 *)(iVar15 + 0x34a) = 1;
            *(undefined1 *)(iVar15 + 0x328) = 0x48;
            uVar9 = 0x1c6;
            goto LAB_0300ef42;
          }
          uVar10 = 0;
          do {
            iVar8 = iVar15 + (uint)*(byte *)(iVar15 + 0x349) * 0x26 + uVar10;
            uVar10 = uVar10 + 1 & 0xffff;
            *(undefined1 *)(iVar8 + 0x24a) = 0;
          } while (uVar10 < 0x20);
          uVar10 = 0;
          iVar8 = DAT_0300ef9c + *(char *)(DAT_0300efa0 + 2) * 0x26;
          do {
            iVar18 = iVar8 + uVar10;
            iVar19 = iVar15 + (uint)*(byte *)(iVar15 + 0x349) * 0x26 + uVar10;
            uVar10 = uVar10 + 1 & 0xffff;
            *(undefined1 *)(iVar19 + 0x24a) = *(undefined1 *)(iVar18 + -0x20);
          } while (uVar10 < 0x20);
          uVar10 = 0;
          do {
            iVar18 = iVar8 + uVar10;
            iVar19 = iVar15 + (uint)*(byte *)(iVar15 + 0x349) * 0x26 + uVar10;
            uVar10 = uVar10 + 1 & 0xffff;
            *(undefined1 *)(iVar19 + 0x244) = *(undefined1 *)(iVar18 + -0x26);
          } while (uVar10 < 6);
          *(char *)(iVar15 + 0x348) = *(char *)(iVar15 + 0x349);
          *(char *)(iVar15 + 0x349) = *(char *)(iVar15 + 0x349) + '\x01';
          *(undefined1 *)(iVar15 + 0x34a) = 0;
          *pcVar4 = '\0';
        }
LAB_0300f0ac:
        puVar6 = DAT_0300f3b4;
        iVar8 = DAT_0300f3a8;
        cVar1 = *(char *)(iVar12 + 1);
        if (cVar1 == 'P') {
          if (*(char *)(iVar15 + 0x34a) == '\0') {
            FUN_02ffc8a4(0x1dd);
            *puVar6 = 1;
          }
          else {
            *DAT_0300f3b4 = 1;
          }
          iVar12 = FUN_02feb930(*DAT_0300f3bc,DAT_0300f3b8);
          if ((iVar12 == 1) && (*DAT_0300f3c0 == 0)) {
            if (*(char *)(iVar15 + 0x34a) != '\0') {
              FUN_02ffc8a4(0x1b7);
            }
            uVar9 = FUN_0300f34e();
            return uVar9;
          }
          goto LAB_0300f182;
        }
        if (cVar1 == 'C') {
          if (*(char *)(iVar15 + 0x34a) == '\0') {
            FUN_02ffc8a4(0x1dd);
            *puVar6 = 2;
          }
          else {
            *DAT_0300f3b4 = 2;
          }
          iVar12 = FUN_02feb930(*DAT_0300f3bc,DAT_0300f3b8);
          if (iVar12 != 1) {
            uVar9 = FUN_0300f34e();
            return uVar9;
          }
          if (*DAT_0300f3c0 == 3) {
            if (*(char *)(iVar15 + 0x34a) == '\0') goto LAB_0300f182;
            uVar9 = 0x1b7;
          }
          else {
            FUN_02ffb1c8(0x48);
            uVar9 = 0x1d5;
          }
LAB_0300f17e:
          FUN_02ffc8a4(uVar9);
LAB_0300f182:
          uVar9 = FUN_0300f34e();
          return uVar9;
        }
        if (cVar1 == 'H') {
          *(undefined1 *)(iVar15 + 0x34a) = 1;
          *pcVar4 = '\0';
          uVar9 = 0x1c8;
          goto LAB_0300f17e;
        }
        if (cVar1 == 'T') {
          uVar11 = (uint)*(byte *)(iVar12 + 2);
          bVar21 = uVar11 != 0x4f;
          if (!bVar21) {
            uVar11 = (uint)*(byte *)(iVar12 + 3);
          }
          if (bVar21 || uVar11 != 0x4b) {
LAB_0300f29a:
            uVar9 = FUN_0300f34e(uVar11);
            return uVar9;
          }
          *pcVar4 = '\0';
          *(undefined1 *)(iVar15 + 0x34a) = 0;
          uVar9 = 0x1c6;
          goto LAB_0300f17e;
        }
        if (cVar1 == 'A') {
          uVar11 = FUN_02feb930(*DAT_0300f3bc,DAT_0300f3b8);
          if (uVar11 != 1) goto LAB_0300f29a;
          uVar9 = 0x1b6;
          goto LAB_0300f17e;
        }
        if (cVar1 == 'B') {
          uVar11 = FUN_02feb930(*DAT_0300f3bc,DAT_0300f3b8);
          if (uVar11 != 1) goto LAB_0300f29a;
          uVar9 = 0x1b5;
          goto LAB_0300f17e;
        }
        if (cVar1 == 'D' || cVar1 == 'U') goto LAB_0300f182;
        if (cVar1 == 'L') {
          *pcVar4 = '\0';
        }
        puVar7 = DAT_0300f3c4;
        if (cVar1 == 'L' || cVar1 == 'M') goto LAB_0300f182;
        if (cVar1 != 'Q') {
          uVar9 = FUN_0300f34e();
          return uVar9;
        }
        cVar1 = *(char *)(iVar12 + 2);
        if (cVar1 == 'O') {
          if (*(char *)(iVar15 + 0x34a) == '\0') {
            *pcVar4 = '\0';
            *(undefined1 *)(iVar15 + 0x34a) = 1;
            FUN_02ffc8a4(0x1c8);
          }
          if (*pcVar4 != '\0') {
            *pcVar4 = '\0';
            *(undefined1 *)(iVar15 + 0x34a) = 1;
            FUN_02ffc8a4(0x1c8);
          }
          uVar16 = 0;
          uVar13 = (*(byte *)(iVar12 + 3) - 0x30) * 10 + -0x36 + (uint)*(byte *)(iVar12 + 4) &
                   0xffff;
          uVar17 = 0;
          uVar10 = 0;
          if (uVar13 != 0) {
            do {
              uVar16 = uVar16 + *(byte *)(iVar15 + uVar10 + 0x328);
              iVar12 = uVar11 + uVar10;
              uVar10 = uVar10 + 1 & 0xffff;
              uVar17 = uVar17 + *(byte *)(iVar12 + iVar8 + 0xb);
            } while (uVar10 < uVar13);
            if (uVar16 != uVar17 && uVar13 != 0) {
              uVar10 = 0;
              if (uVar16 != uVar17 || uVar17 <= uVar16) {
                do {
                  iVar12 = uVar11 + uVar10;
                  iVar18 = iVar15 + uVar10;
                  uVar10 = uVar10 + 1 & 0xffff;
                  *(undefined1 *)(iVar18 + 0x328) = *(undefined1 *)(iVar12 + iVar8 + 0xb);
                } while (uVar10 < uVar13);
              }
              *(undefined1 *)(uVar10 + iVar15 + 0x328) = 0;
              uVar10 = 0;
              do {
                iVar12 = uVar11 + uVar10;
                iVar18 = iVar15 + uVar10;
                uVar10 = uVar10 + 1 & 0xffff;
                *(undefined1 *)(iVar18 + 0x23e) = *(undefined1 *)(iVar12 + iVar8 + 5);
              } while (uVar10 < 6);
              pcVar2 = DAT_0300f3ac;
              pcVar2[0xc] = '\x01';
              pcVar2[0xd] = '\0';
              pcVar2[0xe] = '\0';
              pcVar2[0xf] = '\0';
              FUN_02ffc8a4(0x1c6);
            }
          }
          *(undefined1 *)(iVar15 + 0x34a) = 1;
          uVar9 = FUN_0300f34e();
          return uVar9;
        }
        if (cVar1 == 'S') {
          if (*pcVar4 != '\x01') {
            *pcVar4 = '\x01';
            *(undefined4 *)(DAT_0300f3ac + 8) = *puVar7;
            FUN_02ffc8a4(0x1c6);
          }
LAB_0300f31e:
          pcVar2 = DAT_0300f3ac;
          pcVar2[0xc] = '\0';
          pcVar2[0xd] = '\0';
          pcVar2[0xe] = '\0';
          pcVar2[0xf] = '\0';
          uVar9 = FUN_0300f34e();
          return uVar9;
        }
        if (cVar1 == 'L') {
          if (*(char *)(iVar15 + 0x349) == '\0') {
            *(undefined1 *)(iVar15 + 0x34a) = 0;
            puVar7 = DAT_0300f3c4;
            if (*pcVar4 != '\x02') {
              *pcVar4 = '\x02';
              *(undefined4 *)(DAT_0300f3ac + 8) = *puVar7;
              FUN_02ffc8a4(0x1c6);
            }
          }
          else {
            if (*(char *)(iVar15 + 0x34a) != '\0') {
              FUN_02ffc8a4(0x1c6);
              FUN_02ffb1c8(0x54);
            }
            *(undefined1 *)(iVar15 + 0x34a) = 0;
          }
          goto LAB_0300f31e;
        }
        if (cVar1 != 'I') {
          uVar9 = FUN_0300f34e();
          return uVar9;
        }
        if (*pcVar4 != '\0') {
          *pcVar4 = '\0';
          FUN_02ffc8a4(0x1c6);
        }
        iVar12 = FUN_02ffc904(0x1c9);
        if (iVar12 != 0) {
          pcVar2 = DAT_0300f3ac;
          pcVar2[4] = '\x05';
          pcVar2[5] = '\0';
        }
        pcVar2 = DAT_0300f3ac;
        pcVar2[0xc] = '\0';
        pcVar2[0xd] = '\0';
        pcVar2[0xe] = '\0';
        pcVar2[0xf] = '\0';
        *(undefined1 *)(iVar15 + 0x34a) = 0;
        goto code_r0x0300f34e;
      }
      iVar8 = iVar12 + uVar11;
      cVar1 = *(char *)(iVar8 + 1);
      bVar21 = cVar1 == 'K';
      if (bVar21) {
        cVar1 = *(char *)(iVar8 + 2);
      }
      bVar22 = bVar21 && cVar1 == 'K';
      if (bVar21 && cVar1 == 'K') {
        bVar22 = *(char *)(iVar8 + 3) == 'K';
      }
      if (!bVar22) goto LAB_0300ee06;
      FUN_02ffc8e6(0x34);
      uVar11 = uVar11 + 1 & 0xffff;
    } while (uVar11 < 100);
  }
  return local_38;
}


