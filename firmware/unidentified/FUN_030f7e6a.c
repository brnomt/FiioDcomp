/**
 * FUN_030f7e6a @ 0x030f7e6a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_030f7e6a(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  byte *pbVar15;
  int iVar16;
  int local_40;
  
  iVar3 = (int)(param_2 + 7 + ((uint)(param_2 + 7 >> 0x1f) >> 0x1d)) >> 3;
  *DAT_030f7fb0 = iVar3;
  iVar14 = 0;
  local_40 = 0;
  if (iVar3 < 1) {
    return;
  }
  bVar1 = *DAT_030f7fb8;
  do {
    uVar13 = param_2 + iVar14 * -8;
    if (8 < (int)uVar13) {
      uVar13 = 8;
    }
    iVar16 = uVar13 - 1;
    piVar4 = (int *)(param_1 + local_40 * 4);
    uVar6 = 0;
    do {
      iVar5 = 0;
      if (0 < iVar16) {
        piVar8 = piVar4 + -1;
        pbVar15 = DAT_030f7fbc;
        if ((uVar13 & 1) == 0) {
          if ((bVar1 & uVar6) == 0) {
            iVar5 = -1;
          }
          else {
            iVar5 = 1;
          }
          pbVar15 = DAT_030f7fbc + 1;
          iVar5 = iVar5 * *piVar4;
          piVar8 = piVar4;
        }
        bVar2 = pbVar15[1];
        iVar10 = 0;
        iVar11 = piVar8[1];
        for (iVar9 = iVar16 >> 1; iVar9 != 0; iVar9 = iVar9 + -1) {
          if ((uVar6 & bVar2) == 0) {
            iVar12 = -1;
          }
          else {
            iVar12 = 1;
          }
          iVar5 = iVar12 * iVar11 + iVar5;
          bVar2 = pbVar15[3];
          iVar11 = piVar8[3];
          if ((uVar6 & pbVar15[2]) == 0) {
            iVar12 = -1;
          }
          else {
            iVar12 = 1;
          }
          iVar10 = iVar12 * piVar8[2] + iVar10;
          piVar8 = piVar8 + 2;
          pbVar15 = pbVar15 + 2;
        }
        iVar5 = iVar5 + iVar10;
      }
      if (-1 < iVar16) {
        if ((DAT_030f7fb8[iVar16] & uVar6) == 0) {
          iVar9 = -1;
        }
        else {
          iVar9 = 1;
        }
        iVar5 = iVar9 * *(int *)(param_1 + (local_40 + iVar16) * 4) + iVar5;
      }
      uVar7 = uVar6 + 1;
      *(int *)(DAT_030f7fb4 + uVar6 * 0xf0 + iVar14 * 4) = iVar5;
      uVar6 = uVar7;
    } while ((int)uVar7 < 0x100);
    iVar14 = iVar14 + 1;
    local_40 = local_40 + 8;
  } while (iVar14 < iVar3);
  return;
}


