/**
 * FUN_030e8ec4 @ 0x030e8ec4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e8ec4(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  iVar1 = DAT_030e8f78;
  if (*(int *)(DAT_030e8f78 + 0x10) == 1) {
    hifi_busy_delay_ovl_0e48(1);
    iVar5 = DAT_030e8f80;
    do {
      if (*(int *)(iVar1 + 0x10) != 1) goto LAB_030e8ef6;
      hifi_busy_delay_ovl_0e48(1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    hifi_debug_printf_sync_ovl_0e45(s_AudioFileSeek2__timeout___030e8fc8);
  }
LAB_030e8ef6:
  piVar2 = DAT_030e8f84;
  uVar6 = *(uint *)(DAT_030e8fc4 + param_3 * 4);
  if (param_2 == 0) {
    uVar3 = uVar6 - (*DAT_030e8f84 + DAT_030e8f84[1]);
    bVar7 = param_1 <= uVar3;
    if (uVar3 <= param_1) {
      bVar7 = uVar6 <= param_1;
    }
    if (!bVar7) {
      iVar5 = *(int *)(iVar1 + 0x18);
      uVar3 = param_1 - uVar3;
      uVar6 = DAT_030e8f84[iVar5];
      if (uVar3 < uVar6) goto LAB_030e8f74;
      goto LAB_030e8f5a;
    }
  }
  else if (param_2 == 1) {
    uVar3 = *(int *)(iVar1 + 0x14) + param_1;
    if ((uint)(*DAT_030e8f84 + DAT_030e8f84[1]) <= uVar3) {
      uVar3 = (uVar6 - (*DAT_030e8f84 + DAT_030e8f84[1])) + uVar3;
      uVar4 = FUN_030e3e1a(uVar3 & 0xfffffe00,0,param_3);
      FUN_030e8b94(param_3);
      *(uint *)(iVar1 + 0x14) = (uVar3 & 0x1ff) + *(int *)(iVar1 + 0x14);
      return uVar4;
    }
    if ((int)param_1 < 1) {
      if (-1 < (int)param_1) {
        return 0;
      }
LAB_030e8f74:
      *(uint *)(iVar1 + 0x14) = uVar3;
      return 0;
    }
    *(uint *)(iVar1 + 0x14) = uVar3;
    iVar5 = *(int *)(iVar1 + 0x18);
    uVar6 = piVar2[iVar5];
    if (uVar3 <= uVar6) {
      return 0;
    }
LAB_030e8f5a:
    *(uint *)(iVar1 + 0x14) = uVar3 - uVar6;
    piVar2[iVar5] = 0;
    *(int *)(iVar1 + 0x1c) = iVar5;
    *(int *)(iVar1 + 0x18) = 1 - iVar5;
    FUN_030e9468(0xf2);
    return 0;
  }
  uVar4 = FUN_030e3e1a(((int)param_1 / 0x200) * 0x200,param_2,param_3);
  FUN_030e8b94(param_3);
  *(int *)(iVar1 + 0x14) = (int)param_1 % 0x200 + *(int *)(iVar1 + 0x14);
  return uVar4;
}


