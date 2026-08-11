/**
 * FUN_03088f36 @ 0x03088f36
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined1 FUN_03088f36(int param_1,uint param_2,byte *param_3,int param_4)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  short sVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined1 uVar14;
  int iVar15;
  uint uVar16;
  bool bVar17;
  int local_28;
  
  iVar6 = (int)*(short *)(param_1 + 0x92);
  iVar11 = (int)*(short *)(param_1 + 0x94) + param_2;
  uVar14 = iVar6 < iVar11;
  if ((iVar11 <= iVar6) && (param_2 != 0)) {
    bVar17 = *(char *)(param_1 + 0x90) != '\0';
    cVar3 = '\0';
    if (bVar17) {
      cVar3 = *(char *)(param_1 + 0x91);
    }
    if (bVar17 && cVar3 != '\0') {
      if (iVar6 < 0x10) {
        if (0 < (int)(param_2 - 1)) {
          pbVar8 = (byte *)((int)*(short *)(param_1 + 0x94) + param_1 + 0x7b);
          pbVar7 = param_3 + -1;
          if ((param_2 & 1) == 0) {
            pbVar8 = pbVar8 + 1;
            *param_3 = *param_3 ^ *pbVar8;
            pbVar7 = param_3;
          }
          bVar2 = pbVar8[1];
          for (iVar6 = (int)(param_2 - 1) >> 1; iVar6 != 0; iVar6 = iVar6 + -1) {
            bVar4 = pbVar8[2];
            pbVar7[1] = bVar2 ^ pbVar7[1];
            pbVar1 = pbVar7 + 2;
            bVar2 = pbVar8[3];
            pbVar7 = pbVar7 + 2;
            *pbVar7 = *pbVar1 ^ bVar4;
            pbVar8 = pbVar8 + 2;
          }
        }
        iVar6 = param_2 - 1;
        if (-1 < iVar6) {
          param_3[iVar6] =
               param_3[iVar6] ^ *(byte *)(*(short *)(param_1 + 0x94) + param_1 + param_2 + 0x7b);
        }
        *(short *)(param_1 + 0x94) = *(short *)(param_1 + 0x94) + (short)param_2;
      }
      else {
        uVar9 = (uint)*(byte *)(param_1 + 0x1a8);
        uVar12 = (uint)*(byte *)(param_1 + 0x1a9);
        iVar6 = 0;
        iVar11 = param_1 + 0xa8;
        for (uVar16 = param_2; (uVar16 & 0xffff) != 0; uVar16 = (uVar16 & 0xffff) - 1) {
          uVar9 = uVar9 + 1 & 0xff;
          bVar2 = *(byte *)(iVar11 + uVar9);
          uVar12 = uVar12 + bVar2 & 0xff;
          *(undefined1 *)(iVar11 + uVar9) = *(undefined1 *)(iVar11 + uVar12);
          *(byte *)(iVar11 + uVar12) = bVar2;
          param_3[iVar6] =
               *(byte *)(iVar11 + ((uint)bVar2 + (uint)*(byte *)(iVar11 + uVar9) & 0xff)) ^
               param_3[iVar6];
          iVar6 = (int)(short)((short)iVar6 + 1);
        }
        *(char *)(param_1 + 0x1a8) = (char)uVar9;
        *(char *)(param_1 + 0x1a9) = (char)uVar12;
        sVar5 = (*(short *)(param_1 + 0x92) / 8) * 8;
        iVar6 = (int)sVar5;
        sVar5 = sVar5 + -8;
        iVar13 = (int)sVar5;
        iVar11 = (int)*(short *)(param_1 + 0x94) + param_2;
        iVar15 = (int)(short)iVar11;
        if (*(short *)(param_1 + 0x94) < iVar13) {
          if (iVar11 < iVar13) {
            local_28 = param_4;
            FUN_030889f0(param_1,param_1 + 0x60,param_2,param_3);
          }
          else {
            local_28 = 0;
            FUN_030889f0(param_1,param_1 + 0x60,(int)(short)(sVar5 - *(short *)(param_1 + 0x94)),
                         param_3);
            iVar11 = FUN_03088d9e(param_1,param_1 + 0x60,&local_28);
            iVar11 = *(int *)(param_1 + 0x74) - (iVar11 + *(int *)(param_1 + 0x78));
            uVar9 = *(int *)(param_1 + 0x58) * (*(int *)(param_1 + 0x78) - *(int *)(param_1 + 0x2c))
            ;
            uVar9 = *(int *)(param_1 + 0x54) * (uVar9 >> 0x10 | uVar9 * 0x10000);
            uVar9 = *(int *)(param_1 + 0x50) * (uVar9 >> 0x10 | uVar9 * 0x10000);
            uVar9 = *(int *)(param_1 + 0x4c) * (uVar9 >> 0x10 | uVar9 * 0x10000);
            uVar12 = *(int *)(param_1 + 0x40) * (iVar11 - *(int *)(param_1 + 0x14));
            uVar12 = *(int *)(param_1 + 0x3c) * (uVar12 >> 0x10 | uVar12 * 0x10000);
            uVar12 = *(int *)(param_1 + 0x38) * (uVar12 >> 0x10 | uVar12 * 0x10000);
            uVar12 = *(int *)(param_1 + 0x34) * (uVar12 >> 0x10 | uVar12 * 0x10000);
            *(uint *)(param_1 + 0x74) =
                 *(int *)(param_1 + 0x30) * (uVar12 >> 0x10 | uVar12 * 0x10000) - local_28;
            *(uint *)(param_1 + 0x78) =
                 *(int *)(param_1 + 0x48) * (uVar9 >> 0x10 | uVar9 * 0x10000) - iVar11;
          }
        }
        iVar10 = (int)*(short *)(param_1 + 0x94);
        bVar17 = SBORROW4(iVar10,iVar6);
        iVar11 = iVar10 - iVar6;
        if (iVar10 < iVar6) {
          bVar17 = SBORROW4(iVar13,iVar15);
          iVar11 = iVar13 - iVar15;
        }
        if (iVar11 < 0 != bVar17) {
          iVar11 = iVar13;
          if (iVar13 < iVar10) {
            iVar11 = iVar10;
          }
          if (iVar15 < iVar6) {
            iVar6 = iVar15;
          }
          uVar9 = iVar6 - iVar11;
          if (0 < (int)uVar9) {
            param_3 = param_3 + (iVar11 - iVar10);
            bVar17 = (uVar9 & 1) != 0;
            pbVar8 = param_3 + -1;
            if (bVar17) {
              *param_3 = *(byte *)((iVar11 - iVar13) + param_1 + 0x74);
              pbVar8 = param_3;
            }
            uVar12 = (uint)bVar17;
            for (iVar6 = (int)uVar9 >> 1; iVar6 != 0; iVar6 = (int)(short)((short)iVar6 + -1)) {
              iVar15 = ((iVar11 + uVar12) - iVar13) + param_1;
              pbVar8[1] = *(byte *)(iVar15 + 0x74);
              uVar12 = uVar12 + 2;
              pbVar8 = pbVar8 + 2;
              *pbVar8 = *(byte *)(iVar15 + 0x75);
            }
          }
        }
        sVar5 = *(short *)(param_1 + 0x94) + (short)param_2;
        *(short *)(param_1 + 0x94) = sVar5;
        if (*(short *)(param_1 + 0x92) <= sVar5) {
          *(undefined1 *)(param_1 + 0x91) = 0;
        }
      }
    }
    else {
      uVar14 = 3;
    }
  }
  return uVar14;
}


