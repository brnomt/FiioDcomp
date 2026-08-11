/**
 * FUN_030efaa4 @ 0x030efaa4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_030efaa4(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8)

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
  
  iVar1 = param_1 + param_3 * 4;
  iVar10 = *(int *)(iVar1 + 4);
  *(int *)(param_4 + param_5 * 4) = iVar10;
  *(uint *)(param_4 + param_7 * 4) = -(uint)(0 < iVar10) - (iVar10 >> 0x1f);
  iVar10 = param_4 + param_5 * 4;
  iVar11 = *(int *)(param_4 + param_5 * 4) - *(int *)(iVar10 + -4);
  *(int *)(iVar10 + -4) = iVar11;
  iVar3 = param_4 + param_7 * 4;
  *(uint *)(iVar3 + -4) = -(uint)(0 < iVar11) - (iVar11 >> 0x1f);
  iVar12 = param_1 + param_3 * 0x10;
  iVar4 = *(int *)(param_4 + param_5 * 4);
  iVar6 = *(int *)(iVar12 + 0x1c);
  iVar13 = *(int *)(iVar12 + 0x20);
  iVar7 = *(int *)(iVar10 + -4);
  iVar8 = *(int *)(iVar10 + -8);
  iVar14 = *(int *)(iVar12 + 0x24);
  iVar10 = *(int *)(iVar10 + -0xc);
  iVar15 = *(int *)(iVar12 + 0x28);
  iVar9 = param_1 + (param_3 ^ 1) * 4;
  iVar11 = *(int *)(iVar9 + 0xc) - (*(int *)(iVar1 + 0x14) * 0x1f >> 5);
  *(int *)(param_4 + param_6 * 4) = iVar11;
  *(uint *)(param_4 + param_8 * 4) = -(uint)(0 < iVar11) - (iVar11 >> 0x1f);
  iVar5 = param_4 + param_6 * 4;
  iVar11 = *(int *)(param_4 + param_6 * 4) - *(int *)(iVar5 + -4);
  *(int *)(iVar5 + -4) = iVar11;
  iVar2 = param_4 + param_8 * 4;
  *(uint *)(iVar2 + -4) = -(uint)(0 < iVar11) - (iVar11 >> 0x1f);
  *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar9 + 0xc);
  param_1 = param_1 + param_3 * 0x14;
  iVar10 = param_2 + (iVar10 * iVar15 + iVar8 * iVar14 + iVar7 * iVar13 + iVar4 * iVar6 +
                      (*(int *)(iVar5 + -0x10) * *(int *)(param_1 + 0x4c) +
                       *(int *)(iVar5 + -4) * *(int *)(param_1 + 0x40) +
                       *(int *)(param_4 + param_6 * 4) * *(int *)(param_1 + 0x3c) +
                       *(int *)(iVar5 + -0xc) * *(int *)(param_1 + 0x48) +
                       *(int *)(iVar5 + -8) * *(int *)(param_1 + 0x44) >> 1) >> 10);
  *(int *)(iVar1 + 4) = iVar10;
  *(int *)(iVar1 + 0xc) = iVar10 + (*(int *)(iVar1 + 0xc) * 0x1f >> 5);
  iVar10 = -(uint)(0 < param_2) - (param_2 >> 0x1f);
  *(int *)(iVar12 + 0x1c) = *(int *)(param_4 + param_7 * 4) * iVar10 + *(int *)(iVar12 + 0x1c);
  *(int *)(iVar12 + 0x20) = *(int *)(iVar3 + -4) * iVar10 + *(int *)(iVar12 + 0x20);
  *(int *)(iVar12 + 0x24) = *(int *)(iVar3 + -8) * iVar10 + *(int *)(iVar12 + 0x24);
  *(int *)(iVar12 + 0x28) = *(int *)(iVar3 + -0xc) * iVar10 + *(int *)(iVar12 + 0x28);
  *(int *)(param_1 + 0x3c) = *(int *)(param_4 + param_8 * 4) * iVar10 + *(int *)(param_1 + 0x3c);
  *(int *)(param_1 + 0x40) = *(int *)(iVar2 + -4) * iVar10 + *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x44) = *(int *)(iVar2 + -8) * iVar10 + *(int *)(param_1 + 0x44);
  *(int *)(param_1 + 0x48) = *(int *)(iVar2 + -0xc) * iVar10 + *(int *)(param_1 + 0x48);
  *(int *)(param_1 + 0x4c) = *(int *)(iVar2 + -0x10) * iVar10 + *(int *)(param_1 + 0x4c);
  return *(undefined4 *)(iVar1 + 0xc);
}


