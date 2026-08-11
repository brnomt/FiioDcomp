/**
 * FUN_0300f088 @ 0x0300f088
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0300f088(uint param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  char cVar2;
  char cVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  char *pcVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  ushort uVar12;
  ushort uVar13;
  int unaff_r4;
  int unaff_r5;
  undefined4 unaff_r6;
  int unaff_r7;
  char *unaff_r8;
  undefined4 unaff_r9;
  int in_r12;
  int iVar14;
  bool bVar15;
  undefined4 in_stack_00000020;
  
  while( true ) {
    param_1 = param_1 + 1 & 0xffff;
    *(undefined1 *)(in_r12 + -0x26) = *(undefined1 *)(param_4 + 4);
    if (5 < param_1) break;
    in_r12 = param_2 + param_1;
    param_4 = unaff_r4 + param_1 + param_3;
  }
  uVar7 = 0;
  do {
    iVar11 = unaff_r4 + uVar7;
    uVar7 = uVar7 + 1 & 0xffff;
    cVar2 = (char)unaff_r6;
    *(char *)(iVar11 + param_3 + 10) = cVar2;
  } while (uVar7 < 0x20);
  FUN_02ffc8a4(0x1c6);
  puVar4 = DAT_0300f3b4;
  iVar11 = DAT_0300f3a8;
  cVar1 = *(char *)(unaff_r5 + 1);
  if (cVar1 == 'P') {
    if (*(char *)(unaff_r7 + 0x34a) == '\0') {
      FUN_02ffc8a4(0x1dd);
      *puVar4 = (short)unaff_r9;
    }
    else {
      *DAT_0300f3b4 = (short)unaff_r9;
    }
    iVar11 = FUN_02feb930(*DAT_0300f3bc,DAT_0300f3b8);
    if ((iVar11 == 1) && (*DAT_0300f3c0 == 0)) {
      if (*(char *)(unaff_r7 + 0x34a) != '\0') {
        FUN_02ffc8a4(0x1b7);
      }
      uVar8 = FUN_0300f34e();
      return uVar8;
    }
  }
  else {
    if (cVar1 == 'C') {
      if (*(char *)(unaff_r7 + 0x34a) == '\0') {
        FUN_02ffc8a4(0x1dd);
        *puVar4 = 2;
      }
      else {
        *DAT_0300f3b4 = 2;
      }
      iVar11 = FUN_02feb930(*DAT_0300f3bc,DAT_0300f3b8);
      if (iVar11 != 1) {
        uVar8 = FUN_0300f34e();
        return uVar8;
      }
      if (*DAT_0300f3c0 == 3) {
        if (*(char *)(unaff_r7 + 0x34a) == '\0') goto LAB_0300f182;
        uVar8 = 0x1b7;
      }
      else {
        FUN_02ffb1c8(0x48);
        uVar8 = 0x1d5;
      }
    }
    else {
      cVar3 = (char)unaff_r9;
      if (cVar1 == 'H') {
        *(char *)(unaff_r7 + 0x34a) = cVar3;
        *unaff_r8 = cVar2;
        uVar8 = 0x1c8;
      }
      else if (cVar1 == 'T') {
        uVar7 = (uint)*(byte *)(unaff_r5 + 2);
        bVar15 = uVar7 != 0x4f;
        if (!bVar15) {
          uVar7 = (uint)*(byte *)(unaff_r5 + 3);
        }
        if (bVar15 || uVar7 != 0x4b) {
LAB_0300f29a:
          uVar8 = FUN_0300f34e(uVar7);
          return uVar8;
        }
        *unaff_r8 = cVar2;
        *(char *)(unaff_r7 + 0x34a) = cVar2;
        uVar8 = 0x1c6;
      }
      else if (cVar1 == 'A') {
        uVar7 = FUN_02feb930(*DAT_0300f3bc,DAT_0300f3b8);
        if (uVar7 != 1) goto LAB_0300f29a;
        uVar8 = 0x1b6;
      }
      else {
        if (cVar1 != 'B') {
          if (cVar1 != 'D' && cVar1 != 'U') {
            if (cVar1 == 'L') {
              *unaff_r8 = cVar2;
            }
            puVar5 = DAT_0300f3c4;
            if (cVar1 != 'L' && cVar1 != 'M') {
              if (cVar1 != 'Q') {
                uVar8 = FUN_0300f34e();
                return uVar8;
              }
              cVar1 = *(char *)(unaff_r5 + 2);
              if (cVar1 == 'O') {
                if (*(char *)(unaff_r7 + 0x34a) == '\0') {
                  *unaff_r8 = cVar2;
                  *(char *)(unaff_r7 + 0x34a) = cVar3;
                  FUN_02ffc8a4(0x1c8);
                }
                if (*unaff_r8 != '\0') {
                  *unaff_r8 = cVar2;
                  *(char *)(unaff_r7 + 0x34a) = cVar3;
                  FUN_02ffc8a4(0x1c8);
                }
                uVar12 = 0;
                uVar10 = (*(byte *)(unaff_r5 + 3) - 0x30) * 10 + -0x36 +
                         (uint)*(byte *)(unaff_r5 + 4) & 0xffff;
                uVar13 = 0;
                uVar7 = 0;
                if (uVar10 != 0) {
                  do {
                    uVar12 = uVar12 + *(byte *)(unaff_r7 + uVar7 + 0x328);
                    iVar9 = unaff_r4 + uVar7;
                    uVar7 = uVar7 + 1 & 0xffff;
                    uVar13 = uVar13 + *(byte *)(iVar9 + iVar11 + 0xb);
                  } while (uVar7 < uVar10);
                  if (uVar12 != uVar13 && uVar10 != 0) {
                    uVar7 = 0;
                    if (uVar12 != uVar13 || uVar13 <= uVar12) {
                      do {
                        iVar9 = unaff_r4 + uVar7;
                        iVar14 = unaff_r7 + uVar7;
                        uVar7 = uVar7 + 1 & 0xffff;
                        *(undefined1 *)(iVar14 + 0x328) = *(undefined1 *)(iVar9 + iVar11 + 0xb);
                      } while (uVar7 < uVar10);
                    }
                    *(char *)(uVar7 + unaff_r7 + 0x328) = cVar2;
                    uVar7 = 0;
                    do {
                      iVar9 = unaff_r4 + uVar7;
                      iVar14 = unaff_r7 + uVar7;
                      uVar7 = uVar7 + 1 & 0xffff;
                      *(undefined1 *)(iVar14 + 0x23e) = *(undefined1 *)(iVar9 + iVar11 + 5);
                    } while (uVar7 < 6);
                    *(undefined4 *)(DAT_0300f3ac + 0xc) = unaff_r9;
                    FUN_02ffc8a4(0x1c6);
                  }
                }
                *(char *)(unaff_r7 + 0x34a) = cVar3;
                uVar8 = FUN_0300f34e();
                return uVar8;
              }
              if (cVar1 == 'S') {
                if (*unaff_r8 != '\x01') {
                  *unaff_r8 = cVar3;
                  *(undefined4 *)(DAT_0300f3ac + 8) = *puVar5;
                  FUN_02ffc8a4(0x1c6);
                }
              }
              else {
                if (cVar1 != 'L') {
                  if (cVar1 == 'I') {
                    if (*unaff_r8 != '\0') {
                      *unaff_r8 = cVar2;
                      FUN_02ffc8a4(0x1c6);
                    }
                    iVar11 = FUN_02ffc904(0x1c9);
                    if (iVar11 != 0) {
                      *(undefined2 *)(DAT_0300f3ac + 4) = 5;
                    }
                    *(undefined4 *)(DAT_0300f3ac + 0xc) = unaff_r6;
                    *(char *)(unaff_r7 + 0x34a) = cVar2;
                    iVar9 = FUN_02ffc8c0(0x1c8);
                    iVar11 = DAT_0300f3b0;
                    if (iVar9 != 0) {
                      uVar7 = 0;
                      do {
                        uVar10 = 0;
                        iVar9 = iVar11 + uVar7 * 0x26;
                        do {
                          *(char *)(iVar9 + uVar10) = cVar2;
                          uVar10 = uVar10 + 1 & 0xff;
                        } while (uVar10 < 6);
                        uVar10 = 0;
                        do {
                          iVar14 = iVar9 + uVar10;
                          uVar10 = uVar10 + 1 & 0xff;
                          *(char *)(iVar14 + 6) = cVar2;
                        } while (uVar10 < 0x20);
                        uVar7 = uVar7 + 1 & 0xff;
                      } while (uVar7 < 6);
                      uVar7 = 0;
                      do {
                        *(undefined1 *)(iVar11 + uVar7) = *(undefined1 *)(unaff_r7 + uVar7 + 0x23e);
                        uVar7 = uVar7 + 1 & 0xff;
                      } while (uVar7 < 6);
                      uVar7 = 0;
                      do {
                        iVar9 = unaff_r7 + uVar7;
                        iVar14 = iVar11 + uVar7;
                        uVar7 = uVar7 + 1 & 0xff;
                        *(undefined1 *)(iVar14 + 6) = *(undefined1 *)(iVar9 + 0x328);
                        uVar8 = DAT_0300f4b4;
                        pcVar6 = DAT_0300f4b0;
                      } while (uVar7 < 0x20);
                      DAT_0300f4b0[1] = cVar3;
                      *pcVar6 = cVar3;
                      FUN_02feb7a0(DAT_0300f4b8,uVar8);
                    }
                    iVar11 = FUN_02ffc8c0(0x1cb);
                    if (iVar11 != 0) {
                      FUN_02feb7a0(DAT_0300f4b8,DAT_0300f4b4);
                    }
                    iVar11 = FUN_02ffc8c0(0xdf);
                    if (iVar11 != 0) {
                      if (*(char *)(unaff_r7 + 0x34a) != '\0') {
                        FUN_02ffb1c8(0x54);
                        iVar11 = DAT_0300f4bc;
                        uVar7 = 0;
                        do {
                          uVar10 = 0;
                          iVar9 = iVar11 + uVar7 * 0x26;
                          do {
                            *(char *)(iVar9 + uVar10) = cVar2;
                            uVar10 = uVar10 + 1 & 0xff;
                          } while (uVar10 < 6);
                          uVar10 = 0;
                          do {
                            iVar14 = iVar9 + uVar10;
                            uVar10 = uVar10 + 1 & 0xff;
                            *(char *)(iVar14 + 6) = cVar2;
                            pcVar6 = DAT_0300f4b0;
                          } while (uVar10 < 0x20);
                          uVar7 = uVar7 + 1 & 0xff;
                        } while (uVar7 < 6);
                        *DAT_0300f4b0 = cVar2;
                        pcVar6[4] = 'P';
                        pcVar6[5] = -0x3d;
                        FUN_02ffc8a4(0x1c9);
                      }
                      FUN_02ffc8a4(0x1c6);
                    }
                    iVar11 = FUN_02ffc8c0(0xe0);
                    if (iVar11 != 0) {
                      FUN_02ffc8a4(0x1c6);
                    }
                    iVar11 = FUN_02ffc8c0(0xe3);
                    if (iVar11 != 0) {
                      FUN_02ffc8a4(0x1c6);
                    }
                    return in_stack_00000020;
                  }
                  uVar8 = FUN_0300f34e();
                  return uVar8;
                }
                if (*(char *)(unaff_r7 + 0x349) == '\0') {
                  *(char *)(unaff_r7 + 0x34a) = cVar2;
                  puVar5 = DAT_0300f3c4;
                  if (*unaff_r8 != '\x02') {
                    *unaff_r8 = '\x02';
                    *(undefined4 *)(DAT_0300f3ac + 8) = *puVar5;
                    FUN_02ffc8a4(0x1c6);
                  }
                }
                else {
                  if (*(char *)(unaff_r7 + 0x34a) != '\0') {
                    FUN_02ffc8a4(0x1c6);
                    FUN_02ffb1c8(0x54);
                  }
                  *(char *)(unaff_r7 + 0x34a) = cVar2;
                }
              }
              *(undefined4 *)(DAT_0300f3ac + 0xc) = unaff_r6;
              uVar8 = FUN_0300f34e();
              return uVar8;
            }
          }
          goto LAB_0300f182;
        }
        uVar7 = FUN_02feb930(*DAT_0300f3bc,DAT_0300f3b8);
        if (uVar7 != 1) goto LAB_0300f29a;
        uVar8 = 0x1b5;
      }
    }
    FUN_02ffc8a4(uVar8);
  }
LAB_0300f182:
  uVar8 = FUN_0300f34e();
  return uVar8;
}


