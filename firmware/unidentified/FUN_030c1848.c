/**
 * FUN_030c1848 @ 0x030c1848
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c1848(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  iVar1 = DAT_030c18f8;
  if (*(int *)(DAT_030c18f8 + 0x10) == 1) {
    hifi_busy_delay_ovl_0bff(1);
    iVar5 = DAT_030c1900;
    do {
      if (*(int *)(iVar1 + 0x10) != 1) goto LAB_030c187a;
      hifi_busy_delay_ovl_0bff(1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    FUN_030bfd16(s_AudioFileSeek2__timeout___030c1948);
  }
LAB_030c187a:
  piVar2 = DAT_030c1904;
  uVar6 = *(uint *)(DAT_030c1944 + param_3 * 4);
  if (param_2 == 0) {
    uVar3 = uVar6 - (*DAT_030c1904 + DAT_030c1904[1]);
    bVar7 = param_1 <= uVar3;
    if (uVar3 <= param_1) {
      bVar7 = uVar6 <= param_1;
    }
    if (!bVar7) {
      iVar5 = *(int *)(iVar1 + 0x18);
      uVar3 = param_1 - uVar3;
      uVar6 = DAT_030c1904[iVar5];
      if (uVar3 < uVar6) goto LAB_030c1966;
      goto LAB_030c18de;
    }
  }
  else if (param_2 == 1) {
    uVar3 = *(int *)(iVar1 + 0x14) + param_1;
    if ((uint)(*DAT_030c1904 + DAT_030c1904[1]) <= uVar3) {
      uVar3 = (uVar6 - (*DAT_030c1904 + DAT_030c1904[1])) + uVar3;
      uVar4 = FUN_030bf61a(uVar3 & 0xfffffe00,0,param_3);
      FUN_030c150c(param_3);
      *(uint *)(iVar1 + 0x14) = (uVar3 & 0x1ff) + *(int *)(iVar1 + 0x14);
      return uVar4;
    }
    if ((int)param_1 < 1) {
      if (-1 < (int)param_1) {
        return 0;
      }
LAB_030c1966:
      *(uint *)(iVar1 + 0x14) = uVar3;
      return 0;
    }
    *(uint *)(iVar1 + 0x14) = uVar3;
    iVar5 = *(int *)(iVar1 + 0x18);
    uVar6 = piVar2[iVar5];
    if (uVar3 <= uVar6) {
      return 0;
    }
LAB_030c18de:
    *(uint *)(iVar1 + 0x14) = uVar3 - uVar6;
    piVar2[iVar5] = 0;
    *(int *)(iVar1 + 0x1c) = iVar5;
    *(int *)(iVar1 + 0x18) = 1 - iVar5;
    FUN_030cd468(0x115);
    return 0;
  }
  uVar4 = FUN_030bf61a(((int)param_1 / 0x200) * 0x200,param_2,param_3);
  FUN_030c150c(param_3);
  *(int *)(iVar1 + 0x14) = (int)param_1 % 0x200 + *(int *)(iVar1 + 0x14);
  return uVar4;
}


