/**
 * FUN_03011370 @ 0x03011370
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03011370(void)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  undefined1 *puVar6;
  int extraout_r2;
  int extraout_r2_00;
  int extraout_r2_01;
  int extraout_r2_02;
  int extraout_r2_03;
  int extraout_r2_04;
  int extraout_r2_05;
  int extraout_r2_06;
  uint uVar7;
  int extraout_r3;
  int extraout_r3_00;
  int extraout_r3_01;
  int extraout_r3_02;
  int extraout_r3_03;
  int extraout_r3_04;
  int extraout_r3_05;
  int extraout_r3_06;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  char *pcVar15;
  longlong lVar16;
  longlong lVar17;
  undefined8 uVar18;
  
  iVar12 = DAT_030114c8;
  *(undefined1 *)(DAT_030114c8 + 0xb) = 0;
  FUN_03011192(0);
  bVar3 = *(byte *)(iVar12 + 3);
  bVar4 = *(byte *)(iVar12 + 4);
  if ((uint)bVar3 < (uint)bVar4) {
    *(byte *)(iVar12 + 5) = bVar4;
  }
  else {
    *(byte *)(iVar12 + 5) = bVar3;
  }
  uVar7 = *(uint *)(iVar12 + 0x1c);
  uVar8 = *(uint *)(iVar12 + 0x20);
  uVar10 = *(uint *)(iVar12 + 0x24);
  if (uVar7 < uVar10 || uVar10 - uVar7 < (uint)(*(uint *)(iVar12 + 0x18) <= uVar8)) {
    *(uint *)(iVar12 + 0x10) = uVar8;
    *(uint *)(iVar12 + 0x14) = uVar10;
  }
  else {
    *(uint *)(iVar12 + 0x10) = *(uint *)(iVar12 + 0x18);
    *(uint *)(iVar12 + 0x14) = uVar7;
  }
  if (*(char *)(iVar12 + 9) == 'X') {
    lVar16 = (ulonglong)*(uint *)(iVar12 + 0x28) * (ulonglong)*(uint *)(iVar12 + 0x10);
    lVar16 = FUN_02feccb4((int)lVar16,
                          *(uint *)(iVar12 + 0x28) * *(int *)(iVar12 + 0x14) +
                          *(int *)(iVar12 + 0x2c) * *(uint *)(iVar12 + 0x10) +
                          (int)((ulonglong)lVar16 >> 0x20));
  }
  else {
    uVar7 = *(uint *)(iVar12 + 0x10);
    iVar13 = *(int *)(iVar12 + 0x14);
    lVar16 = (ulonglong)*(uint *)(iVar12 + 0x40) * (ulonglong)uVar7;
    lVar16 = FUN_02feccb4((int)lVar16,
                          *(uint *)(iVar12 + 0x40) * iVar13 +
                          *(int *)(iVar12 + 0x44) * uVar7 + (int)((ulonglong)lVar16 >> 0x20));
    lVar17 = (ulonglong)*(uint *)(iVar12 + 0x28) * (ulonglong)uVar7;
    lVar16 = lVar16 + CONCAT44(*(uint *)(iVar12 + 0x28) * iVar13 +
                               *(int *)(iVar12 + 0x2c) * uVar7 + (int)((ulonglong)lVar17 >> 0x20),
                               (int)lVar17);
  }
  iVar13 = DAT_030114c8;
  *(longlong *)(iVar12 + 0x28) = lVar16;
  uVar11 = *(uint *)(iVar13 + 0x10);
  iVar12 = *(int *)(iVar13 + 0x14);
  lVar16 = (ulonglong)*(uint *)(iVar13 + 0x48) * (ulonglong)uVar11;
  lVar17 = FUN_02feccb4((int)lVar16,
                        *(uint *)(iVar13 + 0x48) * iVar12 +
                        *(int *)(iVar13 + 0x4c) * uVar11 + (int)((ulonglong)lVar16 >> 0x20),uVar8,
                        uVar10);
  lVar16 = (ulonglong)*(uint *)(iVar13 + 0x30) * (ulonglong)uVar11;
  lVar17 = lVar17 + CONCAT44(*(uint *)(iVar13 + 0x30) * iVar12 +
                             *(int *)(iVar13 + 0x34) * uVar11 + (int)((ulonglong)lVar16 >> 0x20),
                             (int)lVar16);
  uVar7 = (uint)lVar17;
  uVar8 = (uint)((ulonglong)lVar17 >> 0x20);
  *(longlong *)(iVar13 + 0x30) = lVar17;
  cVar5 = *(char *)(iVar13 + 10);
  pcVar15 = (char *)(iVar13 + 0x65);
  if (cVar5 == '\x0f') {
    if (*pcVar15 == *DAT_030114cc) {
      *(undefined1 *)(DAT_030114c8 + 0xc) = 0;
    }
    else {
      *(undefined1 *)(DAT_030114c8 + 0xc) = 0xc;
    }
    uVar7 = DAT_030114d4;
    iVar13 = DAT_030114c8;
    lVar17 = lVar17 * *(longlong *)(DAT_030114c8 + 0x28);
    uVar14 = (uint)lVar17;
    iVar9 = (int)((ulonglong)lVar17 >> 0x20);
    uVar8 = (uint)((ulonglong)uVar11 * (ulonglong)uVar11);
    uVar10 = uVar11 * iVar12 +
             iVar12 * uVar11 + (int)((ulonglong)uVar11 * (ulonglong)uVar11 >> 0x20);
    *(longlong *)(DAT_030114c8 + 0x38) = lVar17;
    if ((0x5af2 < uVar10 && (uint)(uVar8 <= uVar7) <= 0x5af3 - uVar10) ||
       (bVar2 = *(byte *)(iVar13 + 5), 8 < bVar2)) {
      *(undefined4 *)(iVar13 + 0x38) = DAT_030114d8;
      *(undefined4 *)(iVar13 + 0x3c) = 0x5af3;
      *(undefined1 *)(iVar13 + 8) = 0x37;
      goto LAB_03011820;
    }
    uVar18 = FUN_02feccb4(uVar14,iVar9);
    puVar6 = DAT_030118dc;
    if (extraout_r2 == 0 && extraout_r3 == 0) {
      *(undefined8 *)(DAT_030118dc + 0x38) = uVar18;
      *(undefined4 *)(puVar6 + 0x10) = 1;
      *(undefined4 *)(puVar6 + 0x14) = 0;
      puVar6[3] = 0;
      *(undefined4 *)(puVar6 + 0x18) = 1;
      *(undefined4 *)(puVar6 + 0x1c) = 0;
    }
    else {
      uVar18 = FUN_02feccb4(uVar14,iVar9,uVar11,iVar12);
      puVar6 = DAT_030118dc;
      if (extraout_r2_00 == 0 && extraout_r3_00 == 0) {
        *(undefined8 *)(DAT_030118dc + 0x38) = uVar18;
        puVar6[3] = bVar2;
        *(uint *)(puVar6 + 0x18) = uVar11;
        *(int *)(puVar6 + 0x1c) = iVar12;
      }
      else if ((uint)-iVar9 < (uint)(uVar14 <= DAT_030118e0)) {
        if (1 < (uint)bVar3 + (uint)bVar4) {
          *(longlong *)(DAT_030118dc + 0x28) = lVar17;
          *(uint *)(puVar6 + 0x18) = uVar8;
          *(uint *)(puVar6 + 0x1c) = uVar10;
          *(uint *)(puVar6 + 0x10) = uVar8;
          *(uint *)(puVar6 + 0x14) = uVar10;
          cVar5 = bVar2 * '\x02' + -1;
          puVar6[5] = cVar5;
          puVar6[3] = cVar5;
        }
      }
      else {
        *(uint *)(DAT_030118dc + 0x18) = uVar11;
        *(int *)(puVar6 + 0x1c) = iVar12;
        puVar6[3] = bVar2;
        *(undefined8 *)(puVar6 + 0x38) = uVar18;
      }
    }
    puVar6 = DAT_030118dc;
    DAT_030118dc[5] = DAT_030118dc[3];
    puVar6[8] = 3;
  }
  else if (cVar5 == '\x10') {
    puVar1 = (uint *)(iVar13 + 0x28);
    uVar10 = *puVar1;
    uVar11 = *(uint *)(iVar13 + 0x2c);
    if (uVar8 < uVar11 || uVar11 - uVar8 < (uint)(uVar7 <= uVar10)) {
      if (*pcVar15 == '\f') {
        *(longlong *)(iVar13 + 0x38) = lVar17 + *(longlong *)puVar1;
        *(undefined1 *)(iVar13 + 0xc) = 0xc;
      }
      else {
        *(uint *)(iVar13 + 0x38) = uVar10 - uVar7;
        *(uint *)(iVar13 + 0x3c) = (uVar11 - uVar8) - (uint)(uVar10 < uVar7);
        *(undefined1 *)(iVar13 + 0xc) = 0;
      }
    }
    else {
      if (*pcVar15 == '\f') {
        *(longlong *)(iVar13 + 0x38) = lVar17 + *(longlong *)puVar1;
      }
      else {
        *(longlong *)(iVar13 + 0x38) = lVar17 - *(longlong *)puVar1;
      }
      *(undefined1 *)(iVar13 + 0xc) = 0xc;
    }
    *(undefined1 *)(iVar13 + 3) = *(undefined1 *)(iVar13 + 5);
    *(undefined1 *)(iVar13 + 8) = 3;
  }
  else if (cVar5 == '\x11') {
    puVar1 = (uint *)(iVar13 + 0x28);
    uVar10 = *puVar1;
    uVar11 = *(uint *)(iVar13 + 0x2c);
    if (uVar8 < uVar11 || uVar11 - uVar8 < (uint)(uVar7 <= uVar10)) {
      if (*pcVar15 == '\f') {
        *(uint *)(iVar13 + 0x38) = uVar10 - uVar7;
        *(uint *)(iVar13 + 0x3c) = (uVar11 - uVar8) - (uint)(uVar10 < uVar7);
        *(undefined1 *)(iVar13 + 0xc) = 0xc;
      }
      else {
        *(longlong *)(iVar13 + 0x38) = lVar17 + *(longlong *)puVar1;
        *(undefined1 *)(iVar13 + 0xc) = 0;
      }
    }
    else {
      if (*pcVar15 == '\f') {
        *(longlong *)(iVar13 + 0x38) = lVar17 - *(longlong *)puVar1;
      }
      else {
        *(longlong *)(iVar13 + 0x38) = lVar17 + *(longlong *)puVar1;
      }
      *(undefined1 *)(iVar13 + 0xc) = 0;
    }
    *(undefined1 *)(iVar13 + 8) = 3;
    *(undefined1 *)(iVar13 + 3) = *(undefined1 *)(iVar13 + 5);
  }
  else if (cVar5 == '\x0e') {
    if (*pcVar15 == *DAT_030118e4) {
      *(undefined1 *)(iVar13 + 0xc) = 0;
    }
    else {
      *(undefined1 *)(iVar13 + 0xc) = 0xc;
    }
    if (lVar17 == 0) {
      *(undefined4 *)(iVar13 + 0x38) = DAT_030118e8;
      *(undefined4 *)(iVar13 + 0x3c) = 0x5af3;
      *(undefined1 *)(iVar13 + 8) = 0x37;
      goto LAB_03011820;
    }
    uVar10 = *(uint *)(iVar13 + 0x28);
    iVar12 = *(int *)(iVar13 + 0x2c);
    uVar18 = FUN_02feccb4(uVar10,iVar12,uVar7,uVar8);
    if (extraout_r2_01 == 0 && extraout_r3_01 == 0) {
      *(undefined8 *)(iVar13 + 0x38) = uVar18;
      *(undefined4 *)(iVar13 + 0x10) = 1;
      *(undefined4 *)(iVar13 + 0x14) = 0;
      *(undefined1 *)(iVar13 + 3) = 0;
      *(undefined1 *)(iVar13 + 5) = 0;
    }
    else {
      uVar18 = FUN_02feccb4((int)((ulonglong)uVar10 * 10),
                            iVar12 * 10 + (int)((ulonglong)uVar10 * 10 >> 0x20),uVar7,uVar8);
      if (extraout_r2_02 == 0 && extraout_r3_02 == 0) {
        *(undefined8 *)(iVar13 + 0x38) = uVar18;
        *(undefined4 *)(iVar13 + 0x10) = 10;
        *(undefined4 *)(iVar13 + 0x14) = 0;
        *(undefined1 *)(iVar13 + 3) = 2;
        *(undefined1 *)(iVar13 + 5) = 2;
      }
      else {
        uVar18 = FUN_02feccb4((int)((ulonglong)uVar10 * 100),
                              iVar12 * 100 + (int)((ulonglong)uVar10 * 100 >> 0x20),uVar7,uVar8);
        if (extraout_r2_03 == 0 && extraout_r3_03 == 0) {
          *(undefined8 *)(iVar13 + 0x38) = uVar18;
          *(undefined4 *)(iVar13 + 0x10) = 100;
          *(undefined4 *)(iVar13 + 0x14) = 0;
          *(undefined1 *)(iVar13 + 3) = 3;
          *(undefined1 *)(iVar13 + 5) = 3;
        }
        else {
          uVar18 = FUN_02feccb4((int)((ulonglong)uVar10 * 1000),
                                iVar12 * 1000 + (int)((ulonglong)uVar10 * 1000 >> 0x20),uVar7,uVar8)
          ;
          if (extraout_r2_04 == 0 && extraout_r3_04 == 0) {
            *(undefined8 *)(iVar13 + 0x38) = uVar18;
            *(undefined4 *)(iVar13 + 0x10) = 1000;
            *(undefined4 *)(iVar13 + 0x14) = 0;
            *(undefined1 *)(iVar13 + 3) = 4;
            *(undefined1 *)(iVar13 + 5) = 4;
          }
          else {
            uVar18 = FUN_02feccb4((int)((ulonglong)uVar10 * 10000),
                                  iVar12 * 10000 + (int)((ulonglong)uVar10 * 10000 >> 0x20),uVar7,
                                  uVar8);
            if (extraout_r2_05 == 0 && extraout_r3_05 == 0) {
              *(undefined8 *)(iVar13 + 0x38) = uVar18;
              *(undefined4 *)(iVar13 + 0x10) = 10000;
              *(undefined4 *)(iVar13 + 0x14) = 0;
              *(undefined1 *)(iVar13 + 3) = 5;
              *(undefined1 *)(iVar13 + 5) = 5;
            }
            else {
              uVar18 = FUN_02feccb4((int)((ulonglong)uVar10 * (ulonglong)DAT_030118ec),
                                    iVar12 * DAT_030118ec +
                                    (int)((ulonglong)uVar10 * (ulonglong)DAT_030118ec >> 0x20),uVar7
                                    ,uVar8);
              if (extraout_r2_06 == 0 && extraout_r3_06 == 0) {
                *(undefined8 *)(iVar13 + 0x38) = uVar18;
                *(uint *)(iVar13 + 0x10) = DAT_030118ec;
                *(undefined4 *)(iVar13 + 0x14) = 0;
                *(undefined1 *)(iVar13 + 3) = 6;
                *(undefined1 *)(iVar13 + 5) = 6;
              }
              else {
                uVar18 = FUN_02feccb4((int)((ulonglong)uVar10 * (ulonglong)DAT_030118f0),
                                      iVar12 * DAT_030118f0 +
                                      (int)((ulonglong)uVar10 * (ulonglong)DAT_030118f0 >> 0x20),
                                      uVar7,uVar8);
                *(undefined8 *)(iVar13 + 0x38) = uVar18;
                *(uint *)(iVar13 + 0x10) = DAT_030118f0;
                *(undefined4 *)(iVar13 + 0x14) = 0;
                *(undefined1 *)(iVar13 + 3) = 7;
                *(undefined1 *)(iVar13 + 5) = 7;
              }
            }
          }
        }
      }
    }
    *(undefined1 *)(iVar13 + 8) = 3;
  }
  puVar6 = DAT_030118dc;
  *pcVar15 = DAT_030118dc[0xc];
  puVar6[9] = 0x58;
  *(undefined4 *)(puVar6 + 0x28) = *(undefined4 *)(puVar6 + 0x38);
  *(undefined4 *)(puVar6 + 0x2c) = *(undefined4 *)(puVar6 + 0x3c);
  *(undefined4 *)(puVar6 + 0x18) = *(undefined4 *)(puVar6 + 0x10);
  *(undefined4 *)(puVar6 + 0x1c) = *(undefined4 *)(puVar6 + 0x14);
  puVar6[5] = puVar6[3];
  *puVar6 = 0;
  puVar6[1] = 0;
  *(undefined4 *)(puVar6 + 0x30) = 0;
  *(undefined4 *)(puVar6 + 0x34) = 0;
  *(undefined4 *)(puVar6 + 0x20) = 1;
  *(undefined4 *)(puVar6 + 0x24) = 0;
  puVar6[4] = 0;
  *(undefined4 *)(puVar6 + 0x7b) = 0;
  *(undefined4 *)(puVar6 + 0x7f) = 0;
  *(undefined4 *)(puVar6 + 0x83) = 0;
  *(undefined4 *)(puVar6 + 0x87) = 0;
  *(undefined4 *)(puVar6 + 0x8b) = 0;
  *(undefined2 *)(puVar6 + 0x8f) = 0;
  puVar6[0x7c] = 0xff;
  puVar6[0xb] = 0;
LAB_03011820:
  FUN_02ffff38(0x33);
  return;
}


