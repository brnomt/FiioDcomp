/**
 * FUN_030f0bfc @ 0x030f0bfc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030f0bfc(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  iVar1 = DAT_030f0cac;
  if (*(int *)(DAT_030f0cac + 0x10) == 1) {
    hifi_busy_delay_ovl_0ed6(1);
    iVar5 = DAT_030f0cb4;
    do {
      if (*(int *)(iVar1 + 0x10) != 1) goto LAB_030f0c2e;
      hifi_busy_delay_ovl_0ed6(1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    log_printf_ts(s_AudioFileSeek2__timeout___030f0cfc);
  }
LAB_030f0c2e:
  piVar2 = DAT_030f0cb8;
  uVar6 = *(uint *)(DAT_030f0cf8 + param_3 * 4);
  if (param_2 == 0) {
    uVar3 = uVar6 - (*DAT_030f0cb8 + DAT_030f0cb8[1]);
    bVar7 = param_1 <= uVar3;
    if (uVar3 <= param_1) {
      bVar7 = uVar6 <= param_1;
    }
    if (!bVar7) {
      iVar5 = *(int *)(iVar1 + 0x18);
      uVar3 = param_1 - uVar3;
      uVar6 = DAT_030f0cb8[iVar5];
      if (uVar3 < uVar6) goto LAB_030f0d1a;
      goto LAB_030f0c92;
    }
  }
  else if (param_2 == 1) {
    uVar3 = *(int *)(iVar1 + 0x14) + param_1;
    if ((uint)(*DAT_030f0cb8 + DAT_030f0cb8[1]) <= uVar3) {
      uVar3 = (uVar6 - (*DAT_030f0cb8 + DAT_030f0cb8[1])) + uVar3;
      uVar4 = FUN_030eccea(uVar3 & 0xfffffe00,0,param_3);
      FUN_030f08c0(param_3);
      *(uint *)(iVar1 + 0x14) = (uVar3 & 0x1ff) + *(int *)(iVar1 + 0x14);
      return uVar4;
    }
    if ((int)param_1 < 1) {
      if (-1 < (int)param_1) {
        return 0;
      }
LAB_030f0d1a:
      *(uint *)(iVar1 + 0x14) = uVar3;
      return 0;
    }
    *(uint *)(iVar1 + 0x14) = uVar3;
    iVar5 = *(int *)(iVar1 + 0x18);
    uVar6 = piVar2[iVar5];
    if (uVar3 <= uVar6) {
      return 0;
    }
LAB_030f0c92:
    *(uint *)(iVar1 + 0x14) = uVar3 - uVar6;
    piVar2[iVar5] = 0;
    *(int *)(iVar1 + 0x1c) = iVar5;
    *(int *)(iVar1 + 0x18) = 1 - iVar5;
    FUN_030f11a8(0x115);
    return 0;
  }
  uVar4 = FUN_030eccea(((int)param_1 / 0x200) * 0x200,param_2,param_3);
  FUN_030f08c0(param_3);
  *(int *)(iVar1 + 0x14) = (int)param_1 % 0x200 + *(int *)(iVar1 + 0x14);
  return uVar4;
}


