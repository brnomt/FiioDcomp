/**
 * FUN_030f0b1a @ 0x030f0b1a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030f0b1a(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = DAT_030f0cb8;
  iVar3 = DAT_030f0cac;
  if (param_3 != 0) {
    if (*(int *)(DAT_030f0cac + 0x10) == 1) {
      hifi_busy_delay_ovl_0ed6(1);
      iVar6 = DAT_030f0cb4;
      do {
        if (*(int *)(iVar3 + 0x10) != 1) goto LAB_030f0b52;
        hifi_busy_delay_ovl_0ed6(1);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      log_printf_ts(s_AudioFileMhRead2__timeout___030f0cdc);
    }
LAB_030f0b52:
    iVar3 = FUN_030ecd50(param_1,param_2,(int)(char)param_3);
    return iVar3;
  }
  iVar3 = 0;
  if (param_2 == 0) {
    return 0;
  }
  piVar7 = (int *)(DAT_030f0cb8 + -0x20);
  while( true ) {
    iVar4 = *(int *)(iVar6 + -0xc);
    uVar5 = *(int *)(iVar6 + *(int *)(iVar6 + -8) * 4) - iVar4;
    if (param_2 < uVar5) break;
    FUN_030ee8d8(param_1,*(int *)(iVar6 + -8) * *(int *)(iVar6 + -0x14) + iVar4 + *piVar7,uVar5);
    param_2 = param_2 - uVar5;
    uVar2 = *(int *)(iVar6 + -0xc) + uVar5;
    *(uint *)(iVar6 + -0xc) = uVar2;
    iVar3 = iVar3 + uVar5;
    param_1 = param_1 + uVar5;
    if (*(uint *)(iVar6 + *(int *)(iVar6 + -8) * 4) <= uVar2) {
      *(undefined4 *)(iVar6 + -0xc) = 0;
      if (*(int *)(iVar6 + -0x10) == 1) {
        hifi_busy_delay_ovl_0ed6(1);
        iVar4 = DAT_030f0cb4;
        do {
          if (*(int *)(iVar6 + -0x10) != 1) goto LAB_030f0ac6;
          hifi_busy_delay_ovl_0ed6(1);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        log_printf_ts(DAT_030f0cbc);
      }
LAB_030f0ac6:
      *(undefined4 *)(iVar6 + -0xc) = 0;
      iVar4 = *(int *)(iVar6 + -8);
      *(undefined4 *)(iVar6 + iVar4 * 4) = 0;
      *(int *)(iVar6 + -4) = iVar4;
      iVar4 = 1 - iVar4;
      *(int *)(iVar6 + -8) = iVar4;
      if (*(int *)(iVar6 + iVar4 * 4) == 0) {
        *(undefined1 *)(DAT_030f0cb0 + 1) = 1;
        uVar1 = FUN_030ecd50(iVar4 * *(int *)(iVar6 + -0x14) + *piVar7,*(int *)(iVar6 + -0x14),0);
        *(undefined4 *)(iVar6 + *(int *)(iVar6 + -8) * 4) = uVar1;
      }
      FUN_030f11a8(0x115);
      if (*(int *)(iVar6 + *(int *)(iVar6 + -8) * 4) == 0) {
        return iVar3;
      }
    }
  }
  FUN_030ee8d8(param_1,*(int *)(iVar6 + -8) * *(int *)(iVar6 + -0x14) + *piVar7 + iVar4,param_2);
  uVar5 = *(int *)(iVar6 + -0xc) + param_2;
  *(uint *)(iVar6 + -0xc) = uVar5;
  if (uVar5 < *(uint *)(iVar6 + *(int *)(iVar6 + -8) * 4)) {
    return iVar3 + param_2;
  }
  *(undefined4 *)(iVar6 + -0xc) = 0;
  if (*(int *)(iVar6 + -0x10) == 1) {
    hifi_busy_delay_ovl_0ed6(1);
    iVar4 = DAT_030f0cb4;
    do {
      if (*(int *)(iVar6 + -0x10) != 1) goto LAB_030f0a34;
      hifi_busy_delay_ovl_0ed6(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    log_printf_ts(DAT_030f0cbc);
  }
LAB_030f0a34:
  *(undefined4 *)(iVar6 + -0xc) = 0;
  iVar4 = *(int *)(iVar6 + -8);
  *(undefined4 *)(iVar6 + iVar4 * 4) = 0;
  *(int *)(iVar6 + -4) = iVar4;
  iVar4 = 1 - iVar4;
  *(int *)(iVar6 + -8) = iVar4;
  if (*(int *)(iVar6 + iVar4 * 4) == 0) {
    *(undefined1 *)(DAT_030f0cb0 + 1) = 1;
    uVar1 = FUN_030ecd50(iVar4 * *(int *)(iVar6 + -0x14) + *piVar7,*(int *)(iVar6 + -0x14),0);
    *(undefined4 *)(iVar6 + *(int *)(iVar6 + -8) * 4) = uVar1;
  }
  FUN_030f11a8(0x115);
  return iVar3 + param_2;
}


