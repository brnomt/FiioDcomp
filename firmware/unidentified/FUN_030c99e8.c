/**
 * FUN_030c99e8 @ 0x030c99e8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_030c99e8(int param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint local_44;
  
  pbVar3 = DAT_030c9e38;
  local_44 = 0;
  for (iVar4 = 7 - param_3; 0 < iVar4; iVar4 = iVar4 + -1) {
    iVar5 = 1 << (local_44 & 0xff);
    iVar19 = 0;
    if (0 < iVar5) {
      iVar18 = 4 << (param_3 + local_44 & 0xff);
      iVar6 = param_2 >> (local_44 & 0xff);
      do {
        iVar7 = param_1 + iVar6 * iVar19 * 4;
        piVar9 = (int *)(iVar7 + iVar6 * 4 + -0x10);
        piVar8 = (int *)(iVar7 + (iVar6 >> 1) * 4 + -0x10);
        pbVar10 = DAT_030c9e34;
        do {
          iVar14 = *piVar9;
          iVar11 = piVar9[1];
          *piVar9 = iVar11 + iVar14;
          iVar7 = piVar9[2];
          iVar15 = piVar9[3];
          piVar9[2] = iVar7 + iVar15;
          iVar16 = *piVar8;
          iVar12 = piVar8[1];
          piVar9[1] = iVar12 + iVar16;
          iVar13 = piVar8[2];
          iVar17 = piVar8[3];
          piVar9[3] = iVar13 + iVar17;
          bVar1 = *pbVar10;
          iVar7 = iVar15 - iVar7 >> 8;
          bVar2 = pbVar10[1];
          iVar11 = iVar14 - iVar11 >> 8;
          *piVar8 = iVar11 * (uint)bVar2 + iVar7 * (uint)bVar1;
          piVar8[2] = iVar11 * (uint)bVar1 - iVar7 * (uint)bVar2;
          bVar1 = *pbVar10;
          bVar2 = pbVar10[1];
          iVar7 = iVar12 - iVar16 >> 8;
          iVar11 = iVar17 - iVar13 >> 8;
          piVar8[1] = iVar11 * (uint)bVar2 + iVar7 * (uint)bVar1;
          piVar8[3] = (uint)bVar1 * iVar11 - iVar7 * (uint)bVar2;
          pbVar10 = pbVar10 + iVar18;
          piVar9 = piVar9 + -4;
          piVar8 = piVar8 + -4;
        } while (pbVar10 < pbVar3);
        do {
          iVar7 = *piVar9;
          iVar14 = piVar9[1];
          *piVar9 = iVar7 + iVar14;
          iVar11 = piVar9[2];
          iVar15 = piVar9[3];
          piVar9[2] = iVar11 + iVar15;
          iVar12 = *piVar8;
          iVar16 = piVar8[1];
          piVar9[1] = iVar12 + iVar16;
          iVar13 = piVar8[2];
          iVar17 = piVar8[3];
          piVar9[3] = iVar13 + iVar17;
          bVar1 = *pbVar10;
          iVar7 = iVar7 - iVar14 >> 8;
          bVar2 = pbVar10[1];
          iVar11 = iVar11 - iVar15 >> 8;
          *piVar8 = iVar7 * (uint)bVar1 - iVar11 * (uint)bVar2;
          piVar8[2] = iVar7 * (uint)bVar2 + iVar11 * (uint)bVar1;
          bVar1 = *pbVar10;
          bVar2 = pbVar10[1];
          iVar11 = iVar17 - iVar13 >> 8;
          iVar7 = iVar12 - iVar16 >> 8;
          piVar8[1] = iVar11 * (uint)bVar1 - iVar7 * (uint)bVar2;
          piVar8[3] = iVar11 * (uint)bVar2 + (uint)bVar1 * iVar7;
          pbVar10 = pbVar10 + -iVar18;
          piVar9 = piVar9 + -4;
          piVar8 = piVar8 + -4;
        } while (DAT_030c9e34 < pbVar10);
        iVar19 = iVar19 + 1;
      } while (iVar19 < iVar5);
    }
    local_44 = local_44 + 1;
  }
  iVar4 = 0;
  if (0 < param_2) {
    do {
      FUN_030c9756(param_1 + iVar4 * 4);
      iVar4 = iVar4 + 0x20;
    } while (iVar4 < param_2);
    return;
  }
  return;
}


