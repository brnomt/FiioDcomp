/**
 * FUN_030242ec @ 0x030242ec
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030242ec(uint param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  puVar6 = DAT_03024404;
  iVar5 = DAT_03024400;
  piVar4 = DAT_030243fc;
  puVar3 = DAT_030243f8;
  piVar2 = DAT_030243e8;
  iVar1 = DAT_030243e4;
  if (1 < param_1) {
    return 0;
  }
  iVar11 = 0;
  do {
    if (*DAT_03024408 == '\x01') {
      if ((*puVar6 & 1) != 0) {
        iVar11 = func_0x03005586();
        iVar7 = iVar11;
        if (iVar11 != 0x40000004) {
          iVar7 = iVar11 + -0x40000000;
        }
        if (iVar11 == 0x40000004 || iVar7 == 8) {
          *puVar6 = *puVar6 | 1;
          return 1;
        }
        iVar7 = 0;
        if (iVar11 != 0x10000004) {
          iVar7 = iVar11 + -0x10000000;
        }
        if (iVar11 == 0x10000004 || iVar7 == 8) {
          iVar11 = 0;
          goto LAB_03024368;
        }
      }
      if (iVar11 != 0) {
        *puVar6 = *puVar6 | 1;
      }
    }
LAB_03024368:
    uVar9 = *(int *)(iVar1 + 0x2c) - *(int *)(iVar5 + 0xc);
    uVar8 = *(uint *)(iVar1 + 0x18);
    if (uVar8 <= uVar9) {
      return 1;
    }
    iVar7 = *(int *)(iVar1 + 0x20);
    if (iVar7 < 0x7d1) {
      iVar7 = *(int *)(iVar1 + 0x1c);
    }
    if ((2000 < iVar7) &&
       (uVar8 = (int)(uVar8 + ((uint)((int)uVar8 >> 0x1f) >> 0x1e)) >> 2,
       uVar9 == uVar8 * (uVar9 / uVar8))) {
      func_0x03004d9c();
    }
    iVar7 = FUN_03027dfa(DAT_030243e4);
    iVar10 = *piVar4 + *(int *)(iVar1 + 0x2c);
    if (iVar7 == 0) {
      FUN_03007810(*puVar3,iVar10,*piVar2,1);
      return 1;
    }
    FUN_03007810(*puVar3,iVar10,*piVar2 + -1,1);
    *(int *)(iVar1 + 0x2c) = *(int *)(iVar1 + 0x2c) + 1;
  } while( true );
}


