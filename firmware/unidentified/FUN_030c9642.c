/**
 * FUN_030c9642 @ 0x030c9642
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c9642(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  
  iVar17 = param_1[8] - param_1[9];
  iVar1 = param_1[9] + param_1[8];
  iVar9 = param_1[10] - param_1[0xb];
  iVar2 = param_1[10] + param_1[0xb];
  iVar3 = param_1[1] - *param_1;
  iVar4 = *param_1 + param_1[1];
  iVar7 = param_1[3] - param_1[2];
  iVar5 = param_1[2] + param_1[3];
  iVar15 = (iVar17 - iVar9 >> 8) * 0xb5;
  iVar6 = iVar3 + iVar7 >> 8;
  iVar3 = iVar7 - iVar3 >> 8;
  iVar13 = (iVar17 + iVar9 >> 8) * 0xb5;
  iVar8 = param_1[0xc] - param_1[0xd];
  iVar12 = param_1[0xc] + param_1[0xd];
  iVar9 = param_1[0xe] - param_1[0xf];
  iVar11 = param_1[0xe] + param_1[0xf];
  iVar7 = param_1[4] - param_1[5];
  iVar10 = param_1[5] + param_1[4];
  iVar17 = param_1[7] - param_1[6];
  iVar16 = param_1[6] + param_1[7];
  iVar18 = iVar15 + iVar6 * 0xb5;
  iVar15 = iVar15 + iVar6 * -0xb5;
  iVar14 = iVar13 + iVar3 * 0xb5;
  iVar13 = iVar13 + iVar3 * -0xb5;
  iVar6 = iVar8 + iVar17;
  iVar8 = iVar8 - iVar17;
  iVar3 = iVar9 + iVar7;
  iVar9 = iVar9 - iVar7;
  *param_1 = iVar8 + iVar13;
  param_1[1] = iVar9 - iVar15;
  param_1[2] = iVar8 - iVar13;
  param_1[3] = iVar9 + iVar15;
  param_1[4] = iVar6 - iVar18;
  param_1[5] = iVar3 - iVar14;
  param_1[6] = iVar6 + iVar18;
  param_1[7] = iVar3 + iVar14;
  iVar6 = iVar1 + iVar4;
  iVar1 = iVar1 - iVar4;
  iVar7 = iVar2 + iVar5;
  iVar2 = iVar2 - iVar5;
  iVar3 = iVar12 + iVar10;
  iVar12 = iVar12 - iVar10;
  iVar9 = iVar11 + iVar16;
  iVar11 = iVar11 - iVar16;
  param_1[8] = iVar12 + iVar2;
  param_1[9] = iVar11 - iVar1;
  param_1[10] = iVar12 - iVar2;
  param_1[0xb] = iVar11 + iVar1;
  param_1[0xc] = iVar3 - iVar6;
  param_1[0xd] = iVar9 - iVar7;
  param_1[0xe] = iVar3 + iVar6;
  param_1[0xf] = iVar9 + iVar7;
  return;
}


