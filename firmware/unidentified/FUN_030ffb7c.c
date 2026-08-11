/**
 * FUN_030ffb7c @ 0x030ffb7c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_030ffb7c(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  int local_3c;
  
  iVar1 = (int)(param_2 + 7 + ((uint)(param_2 + 7 >> 0x1f) >> 0x1d)) >> 3;
  *DAT_030ffca4 = iVar1;
  iVar11 = 0;
  local_3c = 0;
  if (iVar1 < 1) {
    return;
  }
  do {
    uVar10 = param_2 + iVar11 * -8;
    if (8 < (int)uVar10) {
      uVar10 = 8;
    }
    uVar12 = uVar10 - 1;
    piVar3 = (int *)(param_1 + local_3c * 4);
    uVar2 = 0;
    do {
      iVar4 = 0;
      if (0 < (int)uVar12) {
        bVar13 = (uVar10 & 1) == 0;
        piVar5 = piVar3 + -1;
        if (bVar13) {
          iVar4 = ((uVar2 & 1) * 2 + -1) * *piVar3;
          piVar5 = piVar3;
        }
        uVar6 = (uint)bVar13;
        iVar8 = 0;
        iVar9 = piVar5[1];
        for (iVar7 = (int)uVar12 >> 1; iVar7 != 0; iVar7 = iVar7 + -1) {
          iVar4 = (((int)uVar2 >> (uVar6 & 0xff) & 1U) * 2 + -1) * iVar9 + iVar4;
          iVar9 = piVar5[3];
          iVar8 = (((int)uVar2 >> (uVar6 + 1 & 0xff) & 1U) * 2 + -1) * piVar5[2] + iVar8;
          uVar6 = uVar6 + 2;
          piVar5 = piVar5 + 2;
        }
        iVar4 = iVar4 + iVar8;
      }
      if (-1 < (int)uVar12) {
        iVar4 = (((int)uVar2 >> (uVar12 & 0xff) & 1U) * 2 + -1) *
                *(int *)(param_1 + (local_3c + uVar12) * 4) + iVar4;
      }
      uVar6 = uVar2 + 1;
      *(int *)(DAT_030ffca8 + uVar2 * 0xf0 + iVar11 * 4) = iVar4;
      uVar2 = uVar6;
    } while ((int)uVar6 < 0x100);
    iVar11 = iVar11 + 1;
    local_3c = local_3c + 8;
  } while (iVar11 < iVar1);
  return;
}


