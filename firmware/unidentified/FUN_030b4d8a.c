/**
 * FUN_030b4d8a @ 0x030b4d8a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030b4d8a(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = DAT_030b4f28;
  iVar3 = DAT_030b4f1c;
  if (param_3 != 0) {
    if (*(int *)(DAT_030b4f1c + 0x10) == 1) {
      hifi_busy_delay_ovl_0ab8(1);
      iVar6 = DAT_030b4f24;
      do {
        if (*(int *)(iVar3 + 0x10) != 1) goto LAB_030b4dc2;
        hifi_busy_delay_ovl_0ab8(1);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      hifi_debug_printf_ovl(s_AudioFileMhRead2__timeout___030b4f4c);
    }
LAB_030b4dc2:
    iVar3 = FUN_030ab020(param_1,param_2,(int)(char)param_3);
    return iVar3;
  }
  iVar3 = 0;
  if (param_2 == 0) {
    return 0;
  }
  piVar7 = (int *)(DAT_030b4f28 + -0x20);
  while( true ) {
    iVar4 = *(int *)(iVar6 + -0xc);
    uVar5 = *(int *)(iVar6 + *(int *)(iVar6 + -8) * 4) - iVar4;
    if (param_2 < uVar5) break;
    FUN_030ac8a8(param_1,*(int *)(iVar6 + -8) * *(int *)(iVar6 + -0x14) + iVar4 + *piVar7,uVar5);
    param_2 = param_2 - uVar5;
    uVar2 = *(int *)(iVar6 + -0xc) + uVar5;
    *(uint *)(iVar6 + -0xc) = uVar2;
    iVar3 = iVar3 + uVar5;
    param_1 = param_1 + uVar5;
    if (*(uint *)(iVar6 + *(int *)(iVar6 + -8) * 4) <= uVar2) {
      *(undefined4 *)(iVar6 + -0xc) = 0;
      if (*(int *)(iVar6 + -0x10) == 1) {
        hifi_busy_delay_ovl_0ab8(1);
        iVar4 = DAT_030b4f24;
        do {
          if (*(int *)(iVar6 + -0x10) != 1) goto LAB_030b4d36;
          hifi_busy_delay_ovl_0ab8(1);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        hifi_debug_printf_ovl(DAT_030b4f2c);
      }
LAB_030b4d36:
      *(undefined4 *)(iVar6 + -0xc) = 0;
      iVar4 = *(int *)(iVar6 + -8);
      *(undefined4 *)(iVar6 + iVar4 * 4) = 0;
      *(int *)(iVar6 + -4) = iVar4;
      iVar4 = 1 - iVar4;
      *(int *)(iVar6 + -8) = iVar4;
      if (*(int *)(iVar6 + iVar4 * 4) == 0) {
        *(undefined1 *)(DAT_030b4f20 + 1) = 1;
        uVar1 = FUN_030ab020(iVar4 * *(int *)(iVar6 + -0x14) + *piVar7,*(int *)(iVar6 + -0x14),0);
        *(undefined4 *)(iVar6 + *(int *)(iVar6 + -8) * 4) = uVar1;
      }
      FUN_030b5418(0x102);
      if (*(int *)(iVar6 + *(int *)(iVar6 + -8) * 4) == 0) {
        return iVar3;
      }
    }
  }
  FUN_030ac8a8(param_1,*(int *)(iVar6 + -8) * *(int *)(iVar6 + -0x14) + *piVar7 + iVar4,param_2);
  uVar5 = *(int *)(iVar6 + -0xc) + param_2;
  *(uint *)(iVar6 + -0xc) = uVar5;
  if (uVar5 < *(uint *)(iVar6 + *(int *)(iVar6 + -8) * 4)) {
    return iVar3 + param_2;
  }
  *(undefined4 *)(iVar6 + -0xc) = 0;
  if (*(int *)(iVar6 + -0x10) == 1) {
    hifi_busy_delay_ovl_0ab8(1);
    iVar4 = DAT_030b4f24;
    do {
      if (*(int *)(iVar6 + -0x10) != 1) goto LAB_030b4ca4;
      hifi_busy_delay_ovl_0ab8(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    hifi_debug_printf_ovl(DAT_030b4f2c);
  }
LAB_030b4ca4:
  *(undefined4 *)(iVar6 + -0xc) = 0;
  iVar4 = *(int *)(iVar6 + -8);
  *(undefined4 *)(iVar6 + iVar4 * 4) = 0;
  *(int *)(iVar6 + -4) = iVar4;
  iVar4 = 1 - iVar4;
  *(int *)(iVar6 + -8) = iVar4;
  if (*(int *)(iVar6 + iVar4 * 4) == 0) {
    *(undefined1 *)(DAT_030b4f20 + 1) = 1;
    uVar1 = FUN_030ab020(iVar4 * *(int *)(iVar6 + -0x14) + *piVar7,*(int *)(iVar6 + -0x14),0);
    *(undefined4 *)(iVar6 + *(int *)(iVar6 + -8) * 4) = uVar1;
  }
  FUN_030b5418(0x102);
  return iVar3 + param_2;
}


