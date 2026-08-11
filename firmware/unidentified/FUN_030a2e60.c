/**
 * FUN_030a2e60 @ 0x030a2e60
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_030a2e60(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short *psVar6;
  short *psVar7;
  short *psVar8;
  int iVar9;
  short *psVar10;
  short *psVar11;
  short *psVar12;
  int iVar13;
  int local_3c;
  
  if (*(int *)(param_3 + 4) == 0) {
    local_3c = 0;
    if (0 < param_5) {
      do {
        psVar8 = (short *)(param_3 + 0x108);
        psVar6 = (short *)(param_1 + local_3c * param_6 * 4);
        if (0 < param_4) {
          psVar12 = (short *)(param_3 + 0x10a);
          psVar7 = psVar6 + param_4 * 2;
          psVar10 = psVar6 + 1;
          psVar11 = psVar6 + param_4 * 2 + 1;
          iVar13 = param_4;
          do {
            sVar2 = *psVar7;
            sVar3 = *psVar8;
            sVar4 = *psVar11;
            sVar5 = *psVar12;
            iVar9 = (int)sVar2 * (int)sVar3 - (int)sVar4 * (int)sVar5 >> 1;
            *psVar7 = (short)((uint)(((*psVar6 * 0x4000 - iVar9) + 0x4000) * 2) >> 0x10);
            iVar1 = (int)sVar2 * (int)sVar5 + (int)sVar4 * (int)sVar3 >> 1;
            *psVar11 = (short)((uint)(((*psVar10 * 0x4000 - iVar1) + 0x4000) * 2) >> 0x10);
            psVar8 = psVar8 + param_2 * 2;
            *psVar6 = (short)((uint)((iVar9 + *psVar6 * 0x4000 + 0x4000) * 2) >> 0x10);
            psVar12 = psVar12 + param_2 * 2;
            *psVar10 = (short)((uint)((iVar1 + *psVar10 * 0x4000 + 0x4000) * 2) >> 0x10);
            iVar13 = iVar13 + -1;
            psVar6 = psVar6 + 2;
            psVar7 = psVar7 + 2;
            psVar10 = psVar10 + 2;
            psVar11 = psVar11 + 2;
          } while (iVar13 != 0);
        }
        local_3c = local_3c + 1;
      } while (local_3c < param_5);
      return;
    }
    return;
  }
  iVar13 = 0;
  if (0 < param_5) {
    do {
      psVar6 = (short *)(param_1 + iVar13 * param_6 * 4);
      iVar9 = 0;
      psVar7 = psVar6 + param_4 * 2;
      psVar8 = (short *)(param_3 + 0x108);
      if (0 < param_4) {
        do {
          sVar2 = *psVar7;
          sVar3 = *psVar8;
          sVar4 = psVar8[1];
          sVar5 = (short)((uint)((((int)sVar2 * (int)sVar3 - (int)psVar7[1] * (int)sVar4) + 0x4000)
                                * 2) >> 0x10);
          *psVar7 = *psVar6 - sVar5;
          sVar2 = (short)((uint)(((int)psVar7[1] * (int)sVar3 + (int)sVar2 * (int)sVar4 + 0x4000) *
                                2) >> 0x10);
          psVar7[1] = psVar6[1] - sVar2;
          iVar9 = iVar9 + 1;
          *psVar6 = sVar5 + *psVar6;
          psVar8 = psVar8 + param_2 * 2;
          psVar6[1] = psVar6[1] + sVar2;
          psVar6 = psVar6 + 2;
          psVar7 = psVar7 + 2;
        } while (iVar9 < param_4);
      }
      iVar13 = iVar13 + 1;
    } while (iVar13 < param_5);
    return;
  }
  return;
}


