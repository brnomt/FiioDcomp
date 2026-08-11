/**
 * FUN_030dc93c @ 0x030dc93c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030dc93c(uint param_1,int param_2,int param_3,uint param_4,uint *param_5,int param_6)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  
  piVar9 = (int *)(DAT_030dcaf8 + param_1 * 0x58);
  *piVar9 = param_2;
  piVar9[1] = 0;
  piVar9[2] = param_3;
  piVar9[3] = 0;
  piVar9[0x10] = param_5[1];
  piVar9[0x11] = param_5[2];
  uVar3 = *param_5;
  *param_5 = uVar3 | 1;
  if (param_4 < 0xff9) {
    piVar9[6] = uVar3 | 1;
    piVar9[7] = param_4;
    piVar9[4] = 0;
  }
  else {
    uVar4 = (param_4 + 0xff7) / 0xff8;
    iVar8 = param_4 + uVar4 * -0xff8 + 0xff8;
    if (iVar8 == 0) {
      iVar8 = 0xff8;
    }
    iVar6 = 0;
    if ((uVar3 & 0x600) == 0) {
      iVar6 = 0xff8 << ((uVar3 & 0x3f) >> 4);
    }
    else if ((uVar3 & 0x600) == 0x200) {
      iVar6 = -(0xff8 << ((uVar3 & 0x30) >> 4));
    }
    iVar5 = 0;
    if ((uVar3 & 0x180) == 0) {
      iVar5 = 0xff8 << ((uVar3 & 7) >> 1);
    }
    else if ((uVar3 & 0x180) == 0x80) {
      iVar5 = -(0xff8 << ((uVar3 & 6) >> 1));
    }
    uVar3 = 0;
    if (uVar4 != 0) {
      do {
        *(uint *)(param_6 + uVar3 * 0x18) = iVar6 * uVar3 + param_2;
        iVar1 = iVar5 * uVar3;
        iVar7 = param_6 + uVar3 * 0x18;
        uVar3 = uVar3 + 1;
        *(int *)(iVar7 + 4) = iVar1 + param_3;
        *(int *)(iVar7 + 8) = iVar7 + 0x18;
        *(uint *)(iVar7 + 0xc) = *param_5 | 0x18000000;
        *(undefined4 *)(iVar7 + 0x10) = 0xff8;
      } while (uVar3 < uVar4);
    }
    iVar6 = param_6 + uVar3 * 0x18;
    *(undefined4 *)(iVar6 + -0x10) = 0;
    *(int *)(iVar6 + -8) = iVar8;
    piVar9[6] = *param_5 | 0x18000000;
    piVar9[4] = param_6;
  }
  piVar9[5] = 0;
  puVar2 = DAT_030dcafc;
  *DAT_030dcafc = 1;
  puVar2[1] = 0;
  uVar3 = 0x101 << (param_1 & 0xff);
  puVar2[2] = uVar3 | puVar2[2];
  puVar2[3] = puVar2[3] | (int)uVar3 >> 0x1f;
  return 0;
}


