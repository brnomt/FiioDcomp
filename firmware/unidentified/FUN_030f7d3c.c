/**
 * FUN_030f7d3c @ 0x030f7d3c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030f7d3c(uint *param_1,int param_2,uint param_3,int param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  bool bVar17;
  int local_4c;
  
  iVar4 = DAT_030f7fb4;
  uVar7 = param_1[3];
  uVar13 = *param_1;
  local_4c = 0;
  if (0 < (int)uVar13) {
    uVar8 = *DAT_030f7fb0;
    do {
      iVar3 = local_4c * 0x44 + 0x14;
      uVar6 = param_1[local_4c * 0x11 + 0x15];
      uVar14 = 0;
      if (param_3 / uVar13 != 0) {
        puVar11 = (uint *)(local_4c * (param_5 >> 3) + param_4);
        do {
          uVar6 = uVar6 + 1 & 0x3f;
          *(undefined1 *)((int)param_1 + uVar6 + iVar3) =
               *(undefined1 *)(uVar14 * uVar13 + param_2 + local_4c);
          puVar12 = puVar11;
          if (uVar14 == param_1[3] * ((int)uVar14 / (int)param_1[3])) {
            uVar5 = 0;
            if (0 < (int)uVar8) {
              bVar17 = (uVar8 & 1) != 0;
              if (bVar17) {
                uVar5 = *(uint *)(iVar4 + (uint)*(byte *)((int)param_1 + uVar6 + iVar3) * 0xf0);
              }
              uVar9 = (uint)bVar17;
              iVar15 = 0;
              for (iVar10 = (int)uVar8 >> 1; iVar10 != 0; iVar10 = iVar10 + -1) {
                uVar16 = uVar6 - uVar9;
                iVar2 = uVar9 * 4;
                iVar1 = uVar9 * 4;
                uVar9 = uVar9 + 2;
                uVar5 = uVar5 + *(int *)(iVar4 + (uint)*(byte *)((int)param_1 +
                                                                (uVar16 & 0x3f) + iVar3) * 0xf0 +
                                        iVar1);
                iVar15 = iVar15 + *(int *)(iVar4 + (uint)*(byte *)((int)param_1 +
                                                                  (uVar16 - 1 & 0x3f) + iVar3) *
                                                   0xf0 + iVar2 + 4);
              }
              uVar5 = uVar5 + iVar15;
            }
            iVar15 = (int)uVar5 >> 0x1f;
            if ((int)((-1 - iVar15) - (uint)(0x80000000 < uVar5)) < 0 ==
                (SBORROW4(-1,iVar15) != SBORROW4(-1 - iVar15,(uint)(0x80000000 < uVar5)))) {
              uVar5 = 0x80000000;
            }
            puVar12 = puVar11 + 2;
            *puVar11 = uVar5;
          }
          uVar14 = uVar14 + 1;
          param_1[local_4c * 0x11 + 0x15] = uVar6;
          puVar11 = puVar12;
        } while (uVar14 < param_3 / uVar13);
      }
      local_4c = local_4c + 1;
    } while (local_4c < (int)uVar13);
  }
  return param_3 / uVar7;
}


