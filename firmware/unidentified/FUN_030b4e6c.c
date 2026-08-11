/**
 * FUN_030b4e6c @ 0x030b4e6c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030b4e6c(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  iVar1 = DAT_030b4f1c;
  if (*(int *)(DAT_030b4f1c + 0x10) == 1) {
    hifi_busy_delay_ovl_0ab8(1);
    iVar5 = DAT_030b4f24;
    do {
      if (*(int *)(iVar1 + 0x10) != 1) goto LAB_030b4e9e;
      hifi_busy_delay_ovl_0ab8(1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    hifi_debug_printf_ovl(s_AudioFileSeek2__timeout___030b4f6c);
  }
LAB_030b4e9e:
  piVar2 = DAT_030b4f28;
  uVar6 = *(uint *)(DAT_030b4f68 + param_3 * 4);
  if (param_2 == 0) {
    uVar3 = uVar6 - (*DAT_030b4f28 + DAT_030b4f28[1]);
    bVar7 = param_1 <= uVar3;
    if (uVar3 <= param_1) {
      bVar7 = uVar6 <= param_1;
    }
    if (!bVar7) {
      iVar5 = *(int *)(iVar1 + 0x18);
      uVar3 = param_1 - uVar3;
      uVar6 = DAT_030b4f28[iVar5];
      if (uVar3 < uVar6) goto LAB_030b4f8a;
      goto LAB_030b4f02;
    }
  }
  else if (param_2 == 1) {
    uVar3 = *(int *)(iVar1 + 0x14) + param_1;
    if ((uint)(*DAT_030b4f28 + DAT_030b4f28[1]) <= uVar3) {
      uVar3 = (uVar6 - (*DAT_030b4f28 + DAT_030b4f28[1])) + uVar3;
      uVar4 = FUN_030aafba(uVar3 & 0xfffffe00,0,param_3);
      FUN_030b4b30(param_3);
      *(uint *)(iVar1 + 0x14) = (uVar3 & 0x1ff) + *(int *)(iVar1 + 0x14);
      return uVar4;
    }
    if ((int)param_1 < 1) {
      if (-1 < (int)param_1) {
        return 0;
      }
LAB_030b4f8a:
      *(uint *)(iVar1 + 0x14) = uVar3;
      return 0;
    }
    *(uint *)(iVar1 + 0x14) = uVar3;
    iVar5 = *(int *)(iVar1 + 0x18);
    uVar6 = piVar2[iVar5];
    if (uVar3 <= uVar6) {
      return 0;
    }
LAB_030b4f02:
    *(uint *)(iVar1 + 0x14) = uVar3 - uVar6;
    piVar2[iVar5] = 0;
    *(int *)(iVar1 + 0x1c) = iVar5;
    *(int *)(iVar1 + 0x18) = 1 - iVar5;
    FUN_030b5418(0x102);
    return 0;
  }
  uVar4 = FUN_030aafba(((int)param_1 / 0x200) * 0x200,param_2,param_3);
  FUN_030b4b30(param_3);
  *(int *)(iVar1 + 0x14) = (int)param_1 % 0x200 + *(int *)(iVar1 + 0x14);
  return uVar4;
}


