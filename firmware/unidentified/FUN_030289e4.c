/**
 * FUN_030289e4 @ 0x030289e4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030289e4(ushort *param_1,undefined2 *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 uVar5;
  ushort *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar7 = 8;
  puVar6 = param_1;
  do {
    uVar1 = puVar6[1];
    uVar2 = puVar6[3];
    uVar3 = puVar6[5];
    uVar4 = puVar6[7];
    if (((((uVar1 == 0 && puVar6[2] == 0) && (puVar6[4] == 0 && uVar2 == 0)) && uVar3 == 0) &&
        puVar6[6] == 0) && uVar4 == 0) {
      uVar1 = *puVar6 << 2;
      *puVar6 = uVar1;
      puVar6[1] = uVar1;
      puVar6[2] = uVar1;
      puVar6[3] = uVar1;
    }
    else {
      iVar11 = (short)puVar6[2] * 0x3b21 + (short)puVar6[6] * -0x187e;
      iVar10 = (uint)*puVar6 * 0x4000 + iVar11;
      iVar11 = (uint)*puVar6 * 0x4000 - iVar11;
      iVar12 = (short)uVar1 * 0x21f9 +
               (short)uVar2 * DAT_03028cc0 + (short)uVar3 * 0x2e75 + (short)uVar4 * -0x6c2;
      iVar8 = (short)uVar1 * 0x5203 +
              (short)uVar2 * 0x1ccd + (short)uVar4 * DAT_03028cc4 + (short)uVar3 * DAT_03028cc8 * 2;
      *puVar6 = (ushort)((uint)((iVar10 + iVar8 + 0x800) * 0x10) >> 0x10);
      puVar6[3] = (ushort)((uint)(((iVar10 - iVar8) + 0x800) * 0x10) >> 0x10);
      puVar6[1] = (ushort)((uint)((iVar11 + iVar12 + 0x800) * 0x10) >> 0x10);
      puVar6[2] = (ushort)((uint)(((iVar11 - iVar12) + 0x800) * 0x10) >> 0x10);
    }
    do {
      puVar6 = puVar6 + 8;
      iVar7 = iVar7 + -1;
      if (iVar7 < 1) {
        iVar7 = 4;
        do {
          uVar1 = param_1[8];
          uVar2 = param_1[0x18];
          uVar3 = param_1[0x28];
          uVar4 = param_1[0x38];
          if ((((uVar1 == 0 && param_1[0x10] == 0) && (uVar2 == 0 && uVar3 == 0)) &&
              param_1[0x30] == 0) && uVar4 == 0) {
            iVar8 = ((short)*param_1 + 0x10 >> 5) + 0x80;
            if (iVar8 < 0) {
              iVar8 = 0;
            }
            else if (0xff < iVar8) {
              iVar8 = 0xff;
            }
            uVar5 = (undefined2)iVar8;
            *param_2 = uVar5;
            param_2[8] = uVar5;
            param_2[0x10] = uVar5;
            param_2[0x18] = uVar5;
          }
          else {
            iVar10 = (short)param_1[0x10] * 0x3b21 + (short)param_1[0x30] * -0x187e;
            iVar11 = (short)*param_1 * 0x4000 + iVar10;
            iVar10 = (short)*param_1 * 0x4000 - iVar10;
            iVar12 = (short)uVar1 * 0x21f9 +
                     (short)uVar2 * DAT_03028cc0 + (short)uVar3 * 0x2e75 + (short)uVar4 * -0x6c2;
            iVar8 = (short)uVar1 * 0x5203 +
                    (short)uVar2 * 0x1ccd +
                    (short)uVar4 * DAT_03028cc4 + (short)uVar3 * DAT_03028cc8 * 2;
            uVar9 = (iVar11 + iVar8 + 0x40000 >> 0x13) + 0x80;
            if ((uVar9 & 0xff00) != 0) {
              uVar9 = (~uVar9 & 0x7fffff) >> 0xf;
            }
            *param_2 = (short)uVar9;
            uVar9 = ((iVar11 - iVar8) + 0x40000 >> 0x13) + 0x80;
            if ((uVar9 & 0xff00) != 0) {
              uVar9 = (~uVar9 & 0x7fffff) >> 0xf;
            }
            param_2[0x18] = (short)uVar9;
            uVar9 = (iVar10 + iVar12 + 0x40000 >> 0x13) + 0x80;
            if ((uVar9 & 0xff00) != 0) {
              uVar9 = (~uVar9 & 0x7fffff) >> 0xf;
            }
            param_2[8] = (short)uVar9;
            uVar9 = ((iVar10 - iVar12) + 0x40000 >> 0x13) + 0x80;
            if ((uVar9 & 0xff00) != 0) {
              uVar9 = (~uVar9 & 0x7fffff) >> 0xf;
            }
            param_2[0x10] = (short)uVar9;
          }
          param_1 = param_1 + 1;
          param_2 = param_2 + 1;
          iVar7 = iVar7 + -1;
        } while (0 < iVar7);
        return;
      }
    } while (iVar7 == 4);
  } while( true );
}


