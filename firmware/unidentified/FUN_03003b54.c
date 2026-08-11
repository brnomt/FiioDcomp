/**
 * FUN_03003b54 @ 0x03003b54
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03003b54(void)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  undefined2 auStack_30 [16];
  
  iVar5 = FUN_02fea58e();
  iVar2 = DAT_03003eac;
  iVar8 = iVar5 - DAT_03003eb0;
  if (iVar5 == DAT_03003eb0) {
LAB_03003bce:
    if (*(char *)(DAT_03003eac + 3) != '\x02') {
      func_0x02fdfb28(*DAT_03003ec8,DAT_03003ec4);
    }
    if (*(short *)(DAT_03003ecc + 0xf2) == 2) {
      *(undefined1 *)(DAT_03003ed0 + 0x6c) = 0;
    }
    puVar3 = DAT_03003ed4;
    cVar4 = *(char *)(iVar2 + 3);
    if (cVar4 == '\0') {
      FUN_03003eec(DAT_03003ed4[DAT_03003ed4[5] + 6]);
      uVar1 = puVar3[5];
      uVar9 = (uint)puVar3[0xb];
      uVar7 = (uint)puVar3[uVar1 + 6];
      bVar10 = uVar7 == uVar9;
      if (uVar9 <= uVar7 && !bVar10) {
        uVar7 = uVar7 - 1;
        puVar3[uVar1 + 6] = (ushort)uVar7;
      }
      if (((bVar10) && (uVar9 != 0)) && (uVar7 == *puVar3 - 1)) {
        puVar3[uVar1 + 6] = (short)uVar7 - 1;
        puVar3[0xb] = puVar3[0xb] - 1;
      }
      FUN_0300276a();
      func_0x02fdf9b0(DAT_03003ec0);
      FUN_02ff0ade(0x178);
    }
    else {
      if (cVar4 == '\x01') {
        FUN_03003f20();
        FUN_02fea22e();
        func_0x03001ed8();
        FUN_0300276a();
        func_0x02fdf9b0(DAT_03003ec0);
        FUN_02ff0ade(0x178);
        FUN_02ff0a9c(0x172);
        uVar6 = 0x194;
        goto LAB_03003c96;
      }
      if (cVar4 != '\x02') {
        return 0;
      }
      func_0x02fdf9b0(DAT_03003ec0);
    }
    uVar6 = 0x172;
    goto LAB_03003c96;
  }
  if (iVar5 < DAT_03003eb0) {
    iVar8 = iVar5 - DAT_03003eb4;
    if (iVar5 == DAT_03003eb4) goto LAB_03003ca0;
    if (iVar5 < DAT_03003eb4) {
      iVar8 = iVar8 + 0x20000000;
      if (iVar8 == 0) goto LAB_03003ca0;
      if (iVar8 != 4) {
        if (iVar8 + DAT_03003eb8 != 0) {
          return 0;
        }
        goto LAB_03003bc2;
      }
    }
    else if (iVar8 != 4) {
      if (iVar8 + DAT_03003ebc != 0) {
        return 0;
      }
      goto LAB_03003bce;
    }
LAB_03003c84:
    cVar4 = *(char *)(DAT_03003eac + 3);
    *(char *)(DAT_03003eac + 4) = cVar4;
    if (cVar4 == '\0') {
      cVar4 = '\x02';
    }
    else {
      cVar4 = cVar4 + -1;
    }
    *(char *)(iVar2 + 3) = cVar4;
  }
  else {
    if (iVar8 != 0x7fc0) {
      if (0x7fc0 < iVar8) {
        if (iVar8 == 0xffffc0) {
          auStack_30[0] = 0;
          func_0x02fdf998(DAT_03003ec0,DAT_03003ed8,auStack_30);
          return 0;
        }
        if (iVar8 != 0x1ffffc0) {
          return 0;
        }
        auStack_30[0] = 1;
        func_0x02fdf998(DAT_03003ec0,DAT_03003ed8,auStack_30);
        return 0;
      }
      if (iVar8 == 0xfc0) {
LAB_03003bc2:
        func_0x02fdf9b0(DAT_03003ec0);
        uVar6 = 0x172;
        goto LAB_03003c96;
      }
      if (iVar8 != 0x3fc0) {
        return 0;
      }
      goto LAB_03003c84;
    }
LAB_03003ca0:
    cVar4 = *(char *)(DAT_03003eac + 3);
    *(char *)(DAT_03003eac + 4) = cVar4;
    if (cVar4 == '\x02') {
      *(undefined1 *)(iVar2 + 3) = 0;
    }
    else {
      *(char *)(iVar2 + 3) = cVar4 + '\x01';
    }
  }
  uVar6 = 0x18a;
LAB_03003c96:
  FUN_02ff0a9c(uVar6);
  return 0;
}


