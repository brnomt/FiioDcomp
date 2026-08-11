/**
 * FUN_03026b52 @ 0x03026b52
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03026b52(void)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
  iVar5 = (int)*DAT_03026e04;
  if ((iVar5 < 0x1f41) && (iVar4 = (int)*DAT_03026e08, iVar4 < 0x1f41)) {
    iVar7 = *DAT_03026df8;
    iVar6 = *(int *)(iVar7 + 0xc);
    iVar1 = iVar6 * 8;
    bVar8 = SBORROW4(iVar5,iVar1);
    iVar2 = iVar5 + iVar6 * -8;
    if (iVar5 < iVar1) {
      iVar7 = *(int *)(iVar7 + 0x10);
    }
    if (iVar5 < iVar1) {
      bVar8 = SBORROW4(iVar4,iVar7 * 8);
      iVar2 = iVar4 + iVar7 * -8;
    }
    if (iVar2 < 0 == bVar8) {
      uVar3 = 1;
    }
    else {
      bVar8 = SBORROW4(iVar5,iVar6 * 4);
      iVar1 = iVar5 + iVar6 * -4;
      if (iVar5 < iVar6 * 4) {
        bVar8 = SBORROW4(iVar4,iVar7 * 4);
        iVar1 = iVar4 + iVar7 * -4;
      }
      if (iVar1 < 0 == bVar8) {
        uVar3 = 2;
      }
      else {
        bVar8 = SBORROW4(iVar5,iVar6 * 2);
        iVar1 = iVar5 + iVar6 * -2;
        if (iVar5 < iVar6 * 2) {
          bVar8 = SBORROW4(iVar4,iVar7 * 2);
          iVar1 = iVar4 + iVar7 * -2;
        }
        if (iVar1 < 0 == bVar8) {
          uVar3 = 4;
        }
        else {
          uVar3 = 8;
        }
      }
    }
    *DAT_03026de0 = uVar3;
    return 0;
  }
  return 0xffffff32;
}


