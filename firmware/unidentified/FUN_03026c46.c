/**
 * FUN_03026c46 @ 0x03026c46
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03026c46(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  bool bVar9;
  
  piVar5 = DAT_03026e38;
  piVar4 = DAT_03026e34;
  puVar3 = DAT_03026e30;
  piVar2 = DAT_03026e28;
  piVar1 = DAT_03026df0;
  iVar6 = *DAT_03026e10;
  if (iVar6 != 3 && iVar6 != 1) {
    return 0xffffff1f;
  }
  iVar8 = DAT_03026e28[1];
  bVar9 = iVar8 != 1;
  if (!bVar9) {
    iVar8 = DAT_03026e2c[1];
  }
  if (bVar9 || iVar8 != 1) {
LAB_03026c7a:
    if (iVar6 == 3) {
      return 0xffffff1e;
    }
  }
  else {
    iVar8 = DAT_03026e28[2];
    bVar9 = iVar8 == 1;
    if (bVar9) {
      iVar8 = DAT_03026e2c[2];
    }
    if (!bVar9 || iVar8 != 1) goto LAB_03026c7a;
  }
  if (iVar6 == 1) {
    *DAT_03026e2c = 1;
    *piVar2 = 1;
  }
  else {
    iVar8 = *DAT_03026e28;
    iVar6 = *DAT_03026e2c;
    if (iVar8 != 1) {
      if (iVar8 == 2) {
        if (iVar6 != 1) {
          if (iVar6 != 2) {
            return 0xffffff1e;
          }
          *DAT_03026e30 = 3;
          *piVar1 = 6;
          *piVar4 = 0x10;
          goto LAB_03026d0e;
        }
        *DAT_03026e30 = 2;
        *piVar1 = 4;
        *piVar4 = 0x10;
      }
      else {
        if (iVar8 == 1) goto LAB_03026cc2;
        if (iVar8 != 4 || iVar6 != 1) {
          return 0xffffff1e;
        }
        *DAT_03026e30 = 5;
        *piVar1 = 6;
        *piVar4 = 0x20;
      }
      *piVar5 = 8;
      goto LAB_03026d20;
    }
    if (iVar6 != 1) {
LAB_03026cc2:
      if (iVar6 != 2) {
        return 0xffffff1e;
      }
      *DAT_03026e30 = 4;
      *piVar1 = 4;
      *piVar4 = 8;
LAB_03026d0e:
      *piVar5 = 0x10;
      goto LAB_03026d20;
    }
  }
  *puVar3 = 1;
  *piVar1 = 3;
  *piVar4 = 8;
  *piVar5 = 8;
LAB_03026d20:
  iVar6 = ((int)*DAT_03026e04 + *piVar4 + -1) / *piVar4;
  *DAT_03026e3c = iVar6;
  *DAT_03026e40 = ((int)*DAT_03026e08 + *piVar5 + -1) / *piVar5;
  iVar6 = *piVar1 * iVar6;
  *DAT_03026e44 = iVar6;
  if (iVar6 < 0x1f41) {
    uVar7 = 0;
  }
  else {
    uVar7 = 0xffffff1b;
  }
  return uVar7;
}


