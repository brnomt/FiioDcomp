/**
 * FUN_030febb4 @ 0x030febb4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030febb4(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_030feef0;
  if (DAT_030feef0[4] == 1) {
    hifi_busy_delay_ovl_0fd1(1);
    iVar3 = DAT_030feef8;
    do {
      if (piVar1[4] != 1) goto LAB_030febdc;
      hifi_busy_delay_ovl_0fd1(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    FUN_030fce44(s_AudioFileInput2__timeout___030fef04);
  }
LAB_030febdc:
  *(undefined1 *)(DAT_030feef4 + 1) = 0;
  piVar1[4] = 1;
  uVar2 = FUN_030fc774(piVar1[7] * piVar1[3] + *piVar1,piVar1[3],param_1);
  *(undefined4 *)(DAT_030feefc + piVar1[7] * 4) = uVar2;
  return 0;
}


