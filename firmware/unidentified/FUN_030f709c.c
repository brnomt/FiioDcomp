/**
 * FUN_030f709c @ 0x030f709c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030f709c(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  iVar1 = DAT_030f7150;
  if (*(int *)(DAT_030f7150 + 0x10) == 1) {
    hifi_busy_delay_ovl_0f53(1);
    iVar5 = DAT_030f7158;
    do {
      if (*(int *)(iVar1 + 0x10) != 1) goto LAB_030f70ce;
      hifi_busy_delay_ovl_0f53(1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    FUN_030f50a4(s_AudioFileSeek2__timeout___030f71a0);
  }
LAB_030f70ce:
  piVar2 = DAT_030f715c;
  uVar6 = *(uint *)(DAT_030f719c + param_3 * 4);
  if (param_2 == 0) {
    uVar3 = uVar6 - (*DAT_030f715c + DAT_030f715c[1]);
    bVar7 = param_1 <= uVar3;
    if (uVar3 <= param_1) {
      bVar7 = uVar6 <= param_1;
    }
    if (!bVar7) {
      iVar5 = *(int *)(iVar1 + 0x18);
      uVar3 = param_1 - uVar3;
      uVar6 = DAT_030f715c[iVar5];
      if (uVar3 < uVar6) goto LAB_030f714c;
      goto LAB_030f7132;
    }
  }
  else if (param_2 == 1) {
    uVar3 = *(int *)(iVar1 + 0x14) + param_1;
    if ((uint)(*DAT_030f715c + DAT_030f715c[1]) <= uVar3) {
      uVar3 = (uVar6 - (*DAT_030f715c + DAT_030f715c[1])) + uVar3;
      uVar4 = FUN_030f4972(uVar3 & 0xfffffe00,0,param_3);
      FUN_030f6d6c(param_3);
      *(uint *)(iVar1 + 0x14) = (uVar3 & 0x1ff) + *(int *)(iVar1 + 0x14);
      return uVar4;
    }
    if ((int)param_1 < 1) {
      if (-1 < (int)param_1) {
        return 0;
      }
LAB_030f714c:
      *(uint *)(iVar1 + 0x14) = uVar3;
      return 0;
    }
    *(uint *)(iVar1 + 0x14) = uVar3;
    iVar5 = *(int *)(iVar1 + 0x18);
    uVar6 = piVar2[iVar5];
    if (uVar3 <= uVar6) {
      return 0;
    }
LAB_030f7132:
    *(uint *)(iVar1 + 0x14) = uVar3 - uVar6;
    piVar2[iVar5] = 0;
    *(int *)(iVar1 + 0x1c) = iVar5;
    *(int *)(iVar1 + 0x18) = 1 - iVar5;
    FUN_030f81dc(0xf2);
    return 0;
  }
  uVar4 = FUN_030f4972(((int)param_1 / 0x200) * 0x200,param_2,param_3);
  FUN_030f6d6c(param_3);
  *(int *)(iVar1 + 0x14) = (int)param_1 % 0x200 + *(int *)(iVar1 + 0x14);
  return uVar4;
}


