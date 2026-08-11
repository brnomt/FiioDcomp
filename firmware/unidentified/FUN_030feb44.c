/**
 * FUN_030feb44 @ 0x030feb44
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030feb44(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = DAT_030feef0;
  if (DAT_030feef0[4] == 1) {
    hifi_busy_delay_ovl_0fd1(1);
    iVar4 = DAT_030feef8;
    do {
      if (piVar1[4] != 1) goto LAB_030feb6c;
      hifi_busy_delay_ovl_0fd1(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_030fce44(DAT_030fef00);
  }
LAB_030feb6c:
  piVar1[5] = 0;
  iVar4 = DAT_030feefc;
  iVar2 = piVar1[6];
  *(undefined4 *)(DAT_030feefc + iVar2 * 4) = 0;
  piVar1[7] = iVar2;
  iVar2 = 1 - iVar2;
  piVar1[6] = iVar2;
  if (*(int *)(iVar4 + iVar2 * 4) == 0) {
    *(undefined1 *)(DAT_030feef4 + 1) = 1;
    uVar3 = FUN_030fc774(iVar2 * piVar1[3] + *piVar1,piVar1[3],param_1);
    *(undefined4 *)(iVar4 + piVar1[6] * 4) = uVar3;
  }
  FUN_030ffdb4(0xf2);
  return;
}


