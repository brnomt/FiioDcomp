/**
 * FUN_03083380 @ 0x03083380
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03083380(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  iVar1 = DAT_03083430;
  if (*(int *)(DAT_03083430 + 0x10) == 1) {
    hifi_busy_delay_ovl_0817(1);
    iVar5 = DAT_03083438;
    do {
      if (*(int *)(iVar1 + 0x10) != 1) goto LAB_030833b2;
      hifi_busy_delay_ovl_0817(1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    FUN_03081592(s_AudioFileSeek2__timeout___03083480);
  }
LAB_030833b2:
  piVar2 = DAT_0308343c;
  uVar6 = *(uint *)(DAT_0308347c + param_3 * 4);
  if (param_2 == 0) {
    uVar3 = uVar6 - (*DAT_0308343c + DAT_0308343c[1]);
    bVar7 = param_1 <= uVar3;
    if (uVar3 <= param_1) {
      bVar7 = uVar6 <= param_1;
    }
    if (!bVar7) {
      iVar5 = *(int *)(iVar1 + 0x18);
      uVar3 = param_1 - uVar3;
      uVar6 = DAT_0308343c[iVar5];
      if (uVar3 < uVar6) goto LAB_0308349e;
      goto LAB_03083416;
    }
  }
  else if (param_2 == 1) {
    uVar3 = *(int *)(iVar1 + 0x14) + param_1;
    if ((uint)(*DAT_0308343c + DAT_0308343c[1]) <= uVar3) {
      uVar3 = (uVar6 - (*DAT_0308343c + DAT_0308343c[1])) + uVar3;
      uVar4 = HifiFileSeek_ovl(uVar3 & 0xfffffe00,0,param_3);
      FUN_03083044(param_3);
      *(uint *)(iVar1 + 0x14) = (uVar3 & 0x1ff) + *(int *)(iVar1 + 0x14);
      return uVar4;
    }
    if ((int)param_1 < 1) {
      if (-1 < (int)param_1) {
        return 0;
      }
LAB_0308349e:
      *(uint *)(iVar1 + 0x14) = uVar3;
      return 0;
    }
    *(uint *)(iVar1 + 0x14) = uVar3;
    iVar5 = *(int *)(iVar1 + 0x18);
    uVar6 = piVar2[iVar5];
    if (uVar3 <= uVar6) {
      return 0;
    }
LAB_03083416:
    *(uint *)(iVar1 + 0x14) = uVar3 - uVar6;
    piVar2[iVar5] = 0;
    *(int *)(iVar1 + 0x1c) = iVar5;
    *(int *)(iVar1 + 0x18) = 1 - iVar5;
    FUN_0308392c(0x102);
    return 0;
  }
  uVar4 = HifiFileSeek_ovl(((int)param_1 / 0x200) * 0x200,param_2,param_3);
  FUN_03083044(param_3);
  *(int *)(iVar1 + 0x14) = (int)param_1 % 0x200 + *(int *)(iVar1 + 0x14);
  return uVar4;
}


