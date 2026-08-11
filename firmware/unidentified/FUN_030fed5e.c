/**
 * FUN_030fed5e @ 0x030fed5e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030fed5e(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = DAT_030feefc;
  iVar3 = DAT_030feef0;
  if (param_3 != 0) {
    if (*(int *)(DAT_030feef0 + 0x10) == 1) {
      hifi_busy_delay_ovl_0fd1(1);
      iVar6 = DAT_030feef8;
      do {
        if (*(int *)(iVar3 + 0x10) != 1) goto LAB_030fed96;
        hifi_busy_delay_ovl_0fd1(1);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      FUN_030fce44(s_AudioFileMhRead2__timeout___030fef20);
    }
LAB_030fed96:
    iVar3 = FUN_030fc774(param_1,param_2,(int)(char)param_3);
    return iVar3;
  }
  iVar3 = 0;
  if (param_2 == 0) {
    return 0;
  }
  piVar7 = (int *)(DAT_030feefc + -0x24);
  while( true ) {
    iVar4 = *(int *)(iVar6 + -0x10);
    uVar5 = *(int *)(iVar6 + *(int *)(iVar6 + -0xc) * 4) - iVar4;
    if (param_2 < uVar5) break;
    FUN_030fe36c(param_1,*(int *)(iVar6 + -0xc) * *(int *)(iVar6 + -0x18) + iVar4 + *piVar7,uVar5);
    param_2 = param_2 - uVar5;
    uVar2 = *(int *)(iVar6 + -0x10) + uVar5;
    *(uint *)(iVar6 + -0x10) = uVar2;
    iVar3 = iVar3 + uVar5;
    param_1 = param_1 + uVar5;
    if (*(uint *)(iVar6 + *(int *)(iVar6 + -0xc) * 4) <= uVar2) {
      *(undefined4 *)(iVar6 + -0x10) = 0;
      if (*(int *)(iVar6 + -0x14) == 1) {
        hifi_busy_delay_ovl_0fd1(1);
        iVar4 = DAT_030feef8;
        do {
          if (*(int *)(iVar6 + -0x14) != 1) goto LAB_030fed0c;
          hifi_busy_delay_ovl_0fd1(1);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        FUN_030fce44(DAT_030fef00);
      }
LAB_030fed0c:
      *(undefined4 *)(iVar6 + -0x10) = 0;
      iVar4 = *(int *)(iVar6 + -0xc);
      *(undefined4 *)(iVar6 + iVar4 * 4) = 0;
      *(int *)(iVar6 + -8) = iVar4;
      iVar4 = 1 - iVar4;
      *(int *)(iVar6 + -0xc) = iVar4;
      if (*(int *)(iVar6 + iVar4 * 4) == 0) {
        *(undefined1 *)(DAT_030feef4 + 1) = 1;
        uVar1 = FUN_030fc774(iVar4 * *(int *)(iVar6 + -0x18) + *piVar7,*(int *)(iVar6 + -0x18),0);
        *(undefined4 *)(iVar6 + *(int *)(iVar6 + -0xc) * 4) = uVar1;
      }
      FUN_030ffdb4(0xf2);
      if (*(int *)(iVar6 + *(int *)(iVar6 + -0xc) * 4) == 0) {
        return iVar3;
      }
    }
  }
  FUN_030fe36c(param_1,*(int *)(iVar6 + -0xc) * *(int *)(iVar6 + -0x18) + *piVar7 + iVar4,param_2);
  uVar5 = *(int *)(iVar6 + -0x10) + param_2;
  *(uint *)(iVar6 + -0x10) = uVar5;
  if (uVar5 < *(uint *)(iVar6 + *(int *)(iVar6 + -0xc) * 4)) {
    return iVar3 + param_2;
  }
  *(undefined4 *)(iVar6 + -0x10) = 0;
  if (*(int *)(iVar6 + -0x14) == 1) {
    hifi_busy_delay_ovl_0fd1(1);
    iVar4 = DAT_030feef8;
    do {
      if (*(int *)(iVar6 + -0x14) != 1) goto LAB_030fec7c;
      hifi_busy_delay_ovl_0fd1(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_030fce44(DAT_030fef00);
  }
LAB_030fec7c:
  *(undefined4 *)(iVar6 + -0x10) = 0;
  iVar4 = *(int *)(iVar6 + -0xc);
  *(undefined4 *)(iVar6 + iVar4 * 4) = 0;
  *(int *)(iVar6 + -8) = iVar4;
  iVar4 = 1 - iVar4;
  *(int *)(iVar6 + -0xc) = iVar4;
  if (*(int *)(iVar6 + iVar4 * 4) == 0) {
    *(undefined1 *)(DAT_030feef4 + 1) = 1;
    uVar1 = FUN_030fc774(iVar4 * *(int *)(iVar6 + -0x18) + *piVar7,*(int *)(iVar6 + -0x18),0);
    *(undefined4 *)(iVar6 + *(int *)(iVar6 + -0xc) * 4) = uVar1;
  }
  FUN_030ffdb4(0xf2);
  return iVar3 + param_2;
}


