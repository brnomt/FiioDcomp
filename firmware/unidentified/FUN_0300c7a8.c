/**
 * FUN_0300c7a8 @ 0x0300c7a8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0300c7a8(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  undefined1 *puVar6;
  int *piVar7;
  ushort uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  
  iVar9 = FUN_02ffa6b0(0x14c);
  puVar4 = DAT_0300c840;
  puVar3 = DAT_0300c828;
  if ((iVar9 != 0) && (DAT_0300c828[2] == 0)) {
    DAT_0300c828[2] = 1;
    puVar3[4] = *puVar4;
    FUN_02ff7942();
    FUN_02ff8906();
  }
  iVar10 = FUN_02ffa6b0(0x14b);
  iVar9 = 0;
  if (iVar10 != 0) {
    iVar9 = puVar3[2];
  }
  if (iVar10 != 0 && iVar9 != 0) {
    puVar3[2] = 0;
    FUN_02ff7930();
    FUN_02ff8364();
  }
  iVar10 = FUN_02ffa6b0(0x140);
  iVar9 = DAT_0300c844;
  if (iVar10 != 0) {
    FUN_02fe9590(DAT_0300c84c,DAT_0300c848,0);
    *(undefined1 *)(iVar9 + 2) = 1;
    *(undefined1 *)(iVar9 + 1) = 1;
  }
  iVar10 = FUN_02ffa6b0(0x141);
  if (iVar10 != 0) {
    FUN_02fe9590(DAT_0300ca10,DAT_0300c848,0);
    *(undefined1 *)(iVar9 + 2) = 2;
    *(undefined1 *)(iVar9 + 1) = 1;
  }
  iVar10 = FUN_02ffa6b0(0x142);
  if (iVar10 != 0) {
    FUN_02fe9590(DAT_0300ca10,DAT_0300ca14,0);
    *(undefined1 *)(iVar9 + 2) = 3;
    *(undefined1 *)(iVar9 + 1) = 1;
  }
  iVar11 = FUN_02ffa6b0(200);
  puVar5 = DAT_0300ca20;
  iVar10 = DAT_0300ca18;
  if (iVar11 != 0) {
    if (*DAT_0300ca1c == 0) {
      return 0;
    }
    if ((uint)puVar3[6] < *DAT_0300ca1c) {
      return 0;
    }
    uVar2 = DAT_0300ca20[1];
    uVar12 = FUN_02ff5e18(1);
    uVar13 = FUN_02ff5df4(2);
    uVar1 = *puVar5;
    *puVar5 = 0;
    FUN_02ff6380(0,0,0x13f,0xa9);
    *puVar5 = 0xffff;
    puVar5[1] = 0;
    FUN_02ff5ec4(0,0x96,0xf0,0xc);
    FUN_02ff5df4(uVar13);
    *puVar5 = uVar1;
    FUN_02ff7404();
    FUN_02ff78c4(0x32);
    FUN_02ff5e18(uVar12);
    puVar5[1] = uVar2;
    *puVar5 = uVar1;
    FUN_02ff5df4(uVar13);
    puVar6 = DAT_0300ca24;
    uVar14 = puVar3[7];
    uVar15 = *DAT_0300ca1c;
    if (uVar14 <= uVar15) {
      uVar16 = 0;
      if (uVar15 != uVar14) {
        do {
          FUN_02ff399c();
          if ((uint)puVar3[1] < *(uint *)(iVar10 + 4)) {
            *puVar6 = 0;
            uVar8 = 0;
            puVar3[8] = *puVar3;
            do {
              FUN_0300c65a();
              uVar8 = uVar8 + 1;
            } while (uVar8 < 0xc);
            puVar3[7] = puVar3[7] + 1;
          }
          uVar16 = uVar16 + 1;
        } while (uVar16 < uVar15 - uVar14);
      }
    }
    FUN_02ffa694(0x13d);
    FUN_02ffa694(0x13b);
  }
  iVar11 = FUN_02ffa6b0(0xdf);
  if (iVar11 != 0) {
    FUN_02ffa694(0x135);
  }
  iVar11 = FUN_02ffa6b0(0xe0);
  if (iVar11 != 0) {
    FUN_02ffa694(0x135);
  }
  iVar11 = DAT_0300ca2c;
  piVar7 = DAT_0300ca28;
  if (((*(char *)(iVar9 + 1) == '\0') && (puVar3[2] != 0)) &&
     (iVar9 = *DAT_0300ca28, puVar3[3] = iVar9 - puVar3[4],
     (*(byte *)(iVar11 + 0x220) + 1) * 200 < (uint)(iVar9 - puVar3[4]))) {
    *DAT_0300ca30 = 0;
    if ((uint)puVar3[1] < *(uint *)(iVar10 + 4)) {
      uVar8 = 0;
      *DAT_0300ca24 = 0;
      puVar3[8] = *puVar3;
      do {
        FUN_0300c65a();
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0xc);
      puVar3[7] = puVar3[7] + 1;
      FUN_02ffa694(0x13d);
      uVar12 = 0x13b;
    }
    else {
      uVar12 = 0x13e;
      puVar3[2] = 0;
    }
    FUN_02ffa694(uVar12);
    puVar3[4] = *piVar7;
  }
  if ((uint)puVar3[5] < *(uint *)(iVar10 + 4)) {
    FUN_0300cf3c();
  }
  return 0;
}


