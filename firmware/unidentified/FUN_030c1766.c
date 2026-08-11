/**
 * FUN_030c1766 @ 0x030c1766
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030c1766(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = DAT_030c1904;
  iVar3 = DAT_030c18f8;
  if (param_3 != 0) {
    if (*(int *)(DAT_030c18f8 + 0x10) == 1) {
      hifi_busy_delay_ovl_0bff(1);
      iVar6 = DAT_030c1900;
      do {
        if (*(int *)(iVar3 + 0x10) != 1) goto LAB_030c179e;
        hifi_busy_delay_ovl_0bff(1);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      FUN_030bfd16(s_AudioFileMhRead2__timeout___030c1928);
    }
LAB_030c179e:
    iVar3 = FUN_030bf680(param_1,param_2,(int)(char)param_3);
    return iVar3;
  }
  iVar3 = 0;
  if (param_2 == 0) {
    return 0;
  }
  piVar7 = (int *)(DAT_030c1904 + -0x20);
  while( true ) {
    iVar4 = *(int *)(iVar6 + -0xc);
    uVar5 = *(int *)(iVar6 + *(int *)(iVar6 + -8) * 4) - iVar4;
    if (param_2 < uVar5) break;
    FUN_030c0f56(param_1,*(int *)(iVar6 + -8) * *(int *)(iVar6 + -0x14) + iVar4 + *piVar7,uVar5);
    param_2 = param_2 - uVar5;
    uVar2 = *(int *)(iVar6 + -0xc) + uVar5;
    *(uint *)(iVar6 + -0xc) = uVar2;
    iVar3 = iVar3 + uVar5;
    param_1 = param_1 + uVar5;
    if (*(uint *)(iVar6 + *(int *)(iVar6 + -8) * 4) <= uVar2) {
      *(undefined4 *)(iVar6 + -0xc) = 0;
      if (*(int *)(iVar6 + -0x10) == 1) {
        hifi_busy_delay_ovl_0bff(1);
        iVar4 = DAT_030c1900;
        do {
          if (*(int *)(iVar6 + -0x10) != 1) goto LAB_030c1712;
          hifi_busy_delay_ovl_0bff(1);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        FUN_030bfd16(DAT_030c1908);
      }
LAB_030c1712:
      *(undefined4 *)(iVar6 + -0xc) = 0;
      iVar4 = *(int *)(iVar6 + -8);
      *(undefined4 *)(iVar6 + iVar4 * 4) = 0;
      *(int *)(iVar6 + -4) = iVar4;
      iVar4 = 1 - iVar4;
      *(int *)(iVar6 + -8) = iVar4;
      if (*(int *)(iVar6 + iVar4 * 4) == 0) {
        *(undefined1 *)(DAT_030c18fc + 1) = 1;
        uVar1 = FUN_030bf680(iVar4 * *(int *)(iVar6 + -0x14) + *piVar7,*(int *)(iVar6 + -0x14),0);
        *(undefined4 *)(iVar6 + *(int *)(iVar6 + -8) * 4) = uVar1;
      }
      FUN_030cd468(0x115);
      if (*(int *)(iVar6 + *(int *)(iVar6 + -8) * 4) == 0) {
        return iVar3;
      }
    }
  }
  FUN_030c0f56(param_1,*(int *)(iVar6 + -8) * *(int *)(iVar6 + -0x14) + *piVar7 + iVar4,param_2);
  uVar5 = *(int *)(iVar6 + -0xc) + param_2;
  *(uint *)(iVar6 + -0xc) = uVar5;
  if (uVar5 < *(uint *)(iVar6 + *(int *)(iVar6 + -8) * 4)) {
    return iVar3 + param_2;
  }
  *(undefined4 *)(iVar6 + -0xc) = 0;
  if (*(int *)(iVar6 + -0x10) == 1) {
    hifi_busy_delay_ovl_0bff(1);
    iVar4 = DAT_030c1900;
    do {
      if (*(int *)(iVar6 + -0x10) != 1) goto LAB_030c1680;
      hifi_busy_delay_ovl_0bff(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_030bfd16(DAT_030c1908);
  }
LAB_030c1680:
  *(undefined4 *)(iVar6 + -0xc) = 0;
  iVar4 = *(int *)(iVar6 + -8);
  *(undefined4 *)(iVar6 + iVar4 * 4) = 0;
  *(int *)(iVar6 + -4) = iVar4;
  iVar4 = 1 - iVar4;
  *(int *)(iVar6 + -8) = iVar4;
  if (*(int *)(iVar6 + iVar4 * 4) == 0) {
    *(undefined1 *)(DAT_030c18fc + 1) = 1;
    uVar1 = FUN_030bf680(iVar4 * *(int *)(iVar6 + -0x14) + *piVar7,*(int *)(iVar6 + -0x14),0);
    *(undefined4 *)(iVar6 + *(int *)(iVar6 + -8) * 4) = uVar1;
  }
  FUN_030cd468(0x115);
  return iVar3 + param_2;
}


