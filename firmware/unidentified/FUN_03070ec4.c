/**
 * FUN_03070ec4 @ 0x03070ec4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03070ec4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int local_d8 [5];
  int local_c4 [7];
  int local_a8 [6];
  int local_90 [6];
  int local_78 [6];
  int local_60 [8];
  int local_40;
  int *local_3c;
  int local_38;
  int local_34;
  int local_2c;
  int local_28;
  
  local_28 = param_2;
  local_2c = param_1;
  piVar5 = local_d8;
  iVar6 = 0;
  local_38 = 0;
  local_34 = 0;
  do {
    iVar14 = 0;
    iVar7 = 0;
    iVar1 = local_2c + local_38 * 4;
    iVar4 = 0;
    iVar11 = *(int *)(iVar1 + 0x10) >> 0xc;
    iVar8 = *(int *)(iVar1 + 0x14) >> 0xc;
    local_40 = *(int *)(iVar1 + 0xc) >> 0xc;
    iVar9 = *(int *)(local_2c + local_38 * 4) >> 0xc;
    iVar10 = *(int *)(iVar1 + 8) >> 0xc;
    iVar1 = *(int *)(iVar1 + 4) >> 0xc;
    do {
      iVar12 = iVar14 * 0x18;
      iVar2 = DAT_03071094 + iVar14 * 0x18;
      iVar14 = iVar14 + 2;
      iVar12 = iVar8 * *(int *)(iVar2 + 0x14) +
               iVar10 * *(int *)(iVar2 + 8) +
               iVar1 * *(int *)(iVar2 + 4) + iVar9 * *(int *)(DAT_03071094 + iVar12) +
               iVar11 * *(int *)(iVar2 + 0x10) + local_40 * *(int *)(iVar2 + 0xc);
      iVar13 = iVar6 + iVar4;
      piVar5[iVar13] = iVar12;
      local_3c = piVar5 + iVar6 + iVar7;
      local_c4[iVar6 + iVar7] = -iVar12;
      iVar7 = iVar7 + -1;
      iVar4 = iVar4 + 1;
      iVar12 = iVar8 * *(int *)(iVar2 + 0x2c) +
               iVar10 * *(int *)(iVar2 + 0x20) +
               iVar1 * *(int *)(iVar2 + 0x1c) + iVar9 * *(int *)(iVar2 + 0x18) +
               iVar11 * *(int *)(iVar2 + 0x28) + local_40 * *(int *)(iVar2 + 0x24);
      local_c4[iVar13 + 1] = iVar12;
      local_3c[0xb] = iVar12;
    } while (iVar4 < 3);
    iVar6 = iVar6 + 0xc;
    local_38 = local_38 + 6;
    local_34 = local_34 + 1;
  } while (local_34 < 3);
  iVar6 = 0;
  piVar3 = DAT_03071090;
  do {
    *(undefined4 *)(local_28 + iVar6 * 4) = 0;
    iVar8 = local_28 + iVar6 * 4;
    iVar6 = iVar6 + 1;
    *(int *)(iVar8 + 0x18) = (*piVar5 >> 0xc) * *piVar3;
    *(int *)(iVar8 + 0x30) = (piVar5[0xc] >> 0xc) * *piVar3 + piVar3[6] * (piVar5[6] >> 0xc);
    *(int *)(iVar8 + 0x48) = (piVar5[0x18] >> 0xc) * *piVar3 + piVar3[6] * (piVar5[0x12] >> 0xc);
    iVar9 = piVar5[0x1e];
    iVar10 = piVar3[6];
    piVar5 = piVar5 + 1;
    piVar3 = piVar3 + 1;
    *(undefined4 *)(iVar8 + 0x78) = 0;
    *(int *)(iVar8 + 0x60) = iVar10 * (iVar9 >> 0xc);
  } while (iVar6 < 6);
  return;
}


