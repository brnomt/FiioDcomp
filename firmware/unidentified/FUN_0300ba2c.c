/**
 * FUN_0300ba2c @ 0x0300ba2c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


char FUN_0300ba2c(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint *puVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined1 *puVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  char cStack_13e0;
  char cStack_13df;
  char cStack_13de;
  char local_11e0 [4];
  undefined4 uStack_11dc;
  undefined4 uStack_11d8;
  uint uStack_11d0;
  undefined4 uStack_11cc;
  int iStack_11c8;
  undefined1 auStack_11c0 [102];
  undefined4 uStack_115a;
  undefined4 uStack_1156;
  undefined4 uStack_1152;
  undefined1 auStack_114e [40];
  undefined2 uStack_1126;
  undefined4 auStack_1124 [51];
  undefined1 auStack_1058 [2048];
  undefined1 auStack_858 [2104];
  
  FUN_02fffd02(1,auStack_1058,0x800);
  FUN_02fe750e(local_11e0,auStack_1058 + param_1 * 0x188,0x188);
  if (local_11e0[0] != '\0') {
    return local_11e0[0];
  }
  iVar9 = FUN_02feb2f6(auStack_11c0,&uStack_115a,&DAT_0300bc50);
  pcVar6 = DAT_0300bc54;
  if (iVar9 == -1) {
    FUN_02fffd02(1,auStack_858,0x800);
    auStack_858[param_1 * 0x188] = 1;
    FUN_02fface0(2,7);
    FUN_02fffd74(1,auStack_858,0x800);
    FUN_02feb4bc(0xffffffff);
    return '\0';
  }
  *DAT_0300bc54 = (char)iVar9;
  FUN_02feb5d6(&cStack_13e0,0x200,iVar9);
  iVar9 = FUN_0300cb04(&cStack_13e0,0x200);
  puVar7 = DAT_0300bc58;
  puVar1 = DAT_0300bc2c;
  if (iVar9 == 1) {
    *DAT_0300bc2c = 3;
    *puVar7 = 0;
  }
  else {
    if (cStack_13e0 == -1) {
      if (cStack_13df == -2) {
        *DAT_0300bc2c = 1;
        goto LAB_0300bae8;
      }
    }
    else {
      bVar13 = cStack_13e0 == -0x11;
      if (bVar13) {
        cStack_13e0 = cStack_13df;
      }
      if ((bVar13 && cStack_13e0 == -0x45) && (cStack_13de == -0x41)) {
        *DAT_0300bc2c = 3;
        *puVar7 = 3;
        goto LAB_0300bae8;
      }
    }
    *DAT_0300bc2c = 2;
  }
LAB_0300bae8:
  *(undefined2 *)(DAT_0300bc4c + 0x21d) = uStack_1126;
  FUN_02fe750e(puVar1 + 4,auStack_11c0,0x66);
  *(undefined4 *)((int)puVar1 + 0x76) = uStack_115a;
  *(undefined4 *)((int)puVar1 + 0x7a) = uStack_1156;
  *(undefined4 *)((int)puVar1 + 0x7e) = uStack_1152;
  FUN_02fe750e((int)puVar1 + 0x82,auStack_114e,0x28);
  FUN_02febace(0,0,(int)*pcVar6);
  puVar2 = DAT_0300bc34;
  puVar1[1] = uStack_11dc;
  puVar5 = DAT_0300bc48;
  puVar1 = DAT_0300bc44;
  *puVar2 = uStack_11d8;
  *puVar5 = uStack_11d8;
  *puVar1 = uStack_11d8;
  iVar9 = FUN_02ffa6f4(200);
  puVar8 = DAT_0300bc5c;
  if (iVar9 == 0) {
    uVar12 = 0;
    do {
      FUN_0300c65a();
      uVar12 = uVar12 + 1;
    } while (uVar12 < 0xc);
  }
  else {
    if (*DAT_0300bc5c == 0) {
      FUN_02ffa6d6(200);
      uVar12 = 0;
      do {
        FUN_0300c65a();
        uVar12 = uVar12 + 1;
      } while (uVar12 < 0xc);
    }
    if (uStack_11d0 < *puVar8) {
      FUN_02ffa6d6(200);
      uVar12 = 0;
      do {
        FUN_0300c65a();
        uVar12 = uVar12 + 1;
      } while (uVar12 < 0xc);
    }
  }
  piVar3 = DAT_0300bc38;
  *puVar2 = uStack_11d8;
  puVar4 = DAT_0300bc3c;
  *piVar3 = iStack_11c8;
  puVar1 = DAT_0300bc40;
  *puVar4 = uStack_11d0;
  *puVar1 = uStack_11cc;
  iVar9 = DAT_0300bc30;
  uVar12 = 0;
  do {
    *(undefined4 *)(iVar9 + uVar12 * 4) = auStack_1124[uVar12];
    uVar12 = uVar12 + 1;
  } while (uVar12 < 0x32);
  iVar10 = FUN_02ffa6f4(200);
  if (iVar10 != 0) {
    uVar12 = *puVar8;
    if ((uVar12 == 0) || (*puVar4 < uVar12)) {
      FUN_02ffa6d6(200);
    }
    else {
      uVar11 = (uVar12 - 1) / 400;
      *puVar8 = uVar12 - 1;
      uStack_11d8 = *(undefined4 *)(iVar9 + uVar11 * 4);
      *puVar5 = uStack_11d8;
      *puVar2 = uStack_11d8;
      *piVar3 = uVar11 * 400;
      uVar12 = 0;
      do {
        FUN_0300c65a();
        uVar12 = uVar12 + 1;
      } while (uVar12 < 0xc);
    }
  }
  return '\x01';
}


