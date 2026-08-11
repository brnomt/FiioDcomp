/**
 * FUN_030a2fdc @ 0x030a2fdc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_030a2fdc(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  short sVar14;
  short *psVar15;
  short *psVar16;
  short *psVar17;
  short *psVar18;
  int iVar19;
  int local_54;
  
  local_54 = 0;
  if (*(int *)(param_3 + 4) == 0) {
    if (param_5 < 1) {
      return;
    }
    do {
      iVar19 = 0;
      psVar16 = (short *)(param_3 + 0x108);
      psVar15 = (short *)(param_1 + local_54 * param_6 * 4);
      psVar17 = psVar16;
      psVar18 = psVar16;
      if (0 < param_4) {
        do {
          sVar7 = psVar15[param_4 * 2];
          sVar1 = *psVar16;
          sVar2 = psVar16[1];
          sVar3 = psVar15[param_4 * 2 + 1];
          sVar8 = psVar15[param_4 * 6];
          sVar4 = *psVar18;
          sVar5 = psVar15[param_4 * 6 + 1];
          sVar6 = psVar18[1];
          sVar12 = (short)(((int)psVar15[param_4 * 4] * (int)*psVar17 -
                           (int)psVar15[param_4 * 4 + 1] * (int)psVar17[1]) + 0x10000 >> 0x11);
          sVar9 = (short)(*psVar15 + 2 >> 2);
          sVar10 = sVar9 - sVar12;
          sVar14 = (short)((int)psVar15[param_4 * 4 + 1] * (int)*psVar17 +
                           (int)psVar15[param_4 * 4] * (int)psVar17[1] + 0x10000 >> 0x11);
          sVar13 = (short)(psVar15[1] + 2 >> 2);
          sVar11 = sVar13 - sVar14;
          *psVar15 = sVar9 + sVar12;
          iVar19 = iVar19 + 1;
          psVar15[1] = sVar13 + sVar14;
          psVar16 = psVar16 + param_2 * 2;
          sVar12 = (short)(((int)sVar7 * (int)sVar1 - (int)sVar3 * (int)sVar2) + 0x10000 >> 0x11);
          sVar13 = (short)(((int)sVar8 * (int)sVar4 - (int)sVar5 * (int)sVar6) + 0x10000 >> 0x11);
          sVar9 = sVar12 + sVar13;
          psVar17 = psVar17 + param_2 * 4;
          sVar2 = (short)((int)sVar3 * (int)sVar1 + (int)sVar7 * (int)sVar2 + 0x10000 >> 0x11);
          sVar3 = (short)((int)sVar5 * (int)sVar4 + (int)sVar8 * (int)sVar6 + 0x10000 >> 0x11);
          sVar1 = sVar2 + sVar3;
          sVar12 = sVar12 - sVar13;
          sVar2 = sVar2 - sVar3;
          psVar15[param_4 * 4] = (short)(psVar15[param_4 * 4] + 2 >> 2);
          psVar15[param_4 * 4 + 1] = (short)(psVar15[param_4 * 4 + 1] + 2 >> 2);
          psVar15[param_4 * 4] = *psVar15 - sVar9;
          psVar15[param_4 * 4 + 1] = psVar15[1] - sVar1;
          psVar18 = psVar18 + param_2 * 6;
          *psVar15 = *psVar15 + sVar9;
          psVar15[1] = psVar15[1] + sVar1;
          psVar15[param_4 * 2] = sVar10 + sVar2;
          psVar15[param_4 * 2 + 1] = sVar11 - sVar12;
          psVar15[param_4 * 6] = sVar10 - sVar2;
          psVar15[param_4 * 6 + 1] = sVar11 + sVar12;
          psVar15 = psVar15 + 2;
        } while (iVar19 < param_4);
      }
      local_54 = local_54 + 1;
    } while (local_54 < param_5);
    return;
  }
  if (param_5 < 1) {
    return;
  }
  do {
    iVar19 = 0;
    psVar16 = (short *)(param_3 + 0x108);
    psVar15 = (short *)(param_1 + local_54 * param_6 * 4);
    psVar17 = psVar16;
    psVar18 = psVar16;
    if (0 < param_4) {
      do {
        sVar7 = psVar15[param_4 * 2];
        sVar1 = *psVar16;
        sVar2 = psVar16[1];
        sVar3 = psVar15[param_4 * 2 + 1];
        sVar8 = psVar15[param_4 * 6];
        sVar4 = *psVar18;
        sVar5 = psVar15[param_4 * 6 + 1];
        sVar6 = psVar18[1];
        sVar9 = (short)((uint)((((int)psVar15[param_4 * 4] * (int)*psVar17 -
                                (int)psVar15[param_4 * 4 + 1] * (int)psVar17[1]) + 0x4000) * 2) >>
                       0x10);
        sVar11 = *psVar15 - sVar9;
        iVar19 = iVar19 + 1;
        sVar10 = (short)((uint)(((int)psVar15[param_4 * 4 + 1] * (int)*psVar17 +
                                 (int)psVar15[param_4 * 4] * (int)psVar17[1] + 0x4000) * 2) >> 0x10)
        ;
        sVar13 = psVar15[1] - sVar10;
        sVar9 = *psVar15 + sVar9;
        *psVar15 = sVar9;
        psVar15[1] = sVar10 + psVar15[1];
        sVar12 = (short)((uint)((((int)sVar7 * (int)sVar1 - (int)sVar3 * (int)sVar2) + 0x4000) * 2)
                        >> 0x10);
        sVar14 = (short)((uint)((((int)sVar8 * (int)sVar4 - (int)sVar5 * (int)sVar6) + 0x4000) * 2)
                        >> 0x10);
        sVar10 = sVar12 + sVar14;
        sVar2 = (short)((uint)(((int)sVar3 * (int)sVar1 + (int)sVar7 * (int)sVar2 + 0x4000) * 2) >>
                       0x10);
        sVar3 = (short)((uint)(((int)sVar5 * (int)sVar4 + (int)sVar8 * (int)sVar6 + 0x4000) * 2) >>
                       0x10);
        sVar1 = sVar2 + sVar3;
        sVar12 = sVar12 - sVar14;
        psVar15[param_4 * 4] = sVar9 - sVar10;
        sVar2 = sVar2 - sVar3;
        psVar16 = psVar16 + param_2 * 2;
        psVar17 = psVar17 + param_2 * 4;
        psVar15[param_4 * 4 + 1] = psVar15[1] - sVar1;
        psVar18 = psVar18 + param_2 * 6;
        *psVar15 = *psVar15 + sVar10;
        psVar15[1] = psVar15[1] + sVar1;
        psVar15[param_4 * 2] = sVar11 - sVar2;
        psVar15[param_4 * 2 + 1] = sVar12 + sVar13;
        psVar15[param_4 * 6] = sVar11 + sVar2;
        psVar15[param_4 * 6 + 1] = sVar13 - sVar12;
        psVar15 = psVar15 + 2;
      } while (iVar19 < param_4);
    }
    local_54 = local_54 + 1;
  } while (local_54 < param_5);
  return;
}


