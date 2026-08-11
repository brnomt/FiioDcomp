/**
 * FUN_030a3580 @ 0x030a3580
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int * FUN_030a3580(int param_1,int param_2,int *param_3,uint *param_4)

{
  int iVar1;
  short sVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  bool bVar12;
  
  piVar11 = (int *)0x0;
  uVar9 = param_1 * 4 + 0x108;
  if ((param_3 == (int *)0x0) || (*param_4 < uVar9)) {
    *param_4 = uVar9;
  }
  else {
    *param_4 = uVar9;
    *param_3 = param_1;
    param_3[1] = param_2;
    uVar4 = DAT_030a38fc;
    iVar5 = 0;
    if (0 < param_1) {
      do {
        iVar8 = iVar5;
        if (param_3[1] == 0) {
          iVar8 = -iVar5;
        }
        uVar10 = (iVar8 << 0x11) / param_1;
        uVar9 = uVar10 & 0x1ffff;
        if (0x10000 < uVar9) {
          uVar9 = 0x20000 - uVar9;
        }
        sVar2 = (short)uVar4;
        sVar7 = -0x7fff;
        if ((uVar9 & 0x7fff) == 0) {
          if ((uVar9 & 0xffff) == 0) {
            sVar6 = sVar7;
            if ((uVar9 & 0x1ffff) == 0) {
              sVar6 = 0x7fff;
            }
          }
          else {
            sVar6 = 0;
          }
        }
        else {
          sVar6 = (short)uVar9;
          if ((int)uVar9 < 0x8000) {
            iVar8 = ((int)sVar6 * (int)sVar6 + 0x4000) * 2 >> 0x10;
            iVar8 = (0x7fff - iVar8) +
                    ((short)(sVar2 + (short)(((iVar8 * -0x272 + 0x4000 >> 0xf) + 0x2055) * iVar8 +
                                             0x4000 >> 0xf)) * iVar8 + 0x4000 >> 0xf);
            if (0x7ffe < iVar8) {
              iVar8 = 0x7ffe;
            }
            sVar6 = (short)iVar8 + 1;
          }
          else {
            iVar8 = ((int)-sVar6 * (int)-sVar6 + 0x4000) * 2 >> 0x10;
            iVar8 = (0x7fff - iVar8) +
                    ((short)(sVar2 + (short)(((iVar8 * -0x272 + 0x4000 >> 0xf) + 0x2055) * iVar8 +
                                             0x4000 >> 0xf)) * iVar8 + 0x4000 >> 0xf);
            if (0x7ffe < iVar8) {
              iVar8 = 0x7ffe;
            }
            sVar6 = -((short)iVar8 + 1);
          }
        }
        *(short *)(param_3 + iVar5 + 0x42) = sVar6;
        uVar9 = uVar10 - 0x8000 & 0x1ffff;
        if (0x10000 < uVar9) {
          uVar9 = 0x20000 - uVar9;
        }
        if ((uVar9 & 0x7fff) == 0) {
          if ((uVar9 & 0xffff) == 0) {
            if ((uVar9 & 0x1ffff) == 0) {
              sVar7 = 0x7fff;
            }
          }
          else {
            sVar7 = 0;
          }
        }
        else {
          sVar7 = (short)uVar9;
          if ((int)uVar9 < 0x8000) {
            iVar8 = ((int)sVar7 * (int)sVar7 + 0x4000) * 2 >> 0x10;
            iVar8 = (0x7fff - iVar8) +
                    ((short)(sVar2 + (short)(((iVar8 * -0x272 + 0x4000 >> 0xf) + 0x2055) * iVar8 +
                                             0x4000 >> 0xf)) * iVar8 + 0x4000 >> 0xf);
            if (0x7ffe < iVar8) {
              iVar8 = 0x7ffe;
            }
            sVar7 = (short)iVar8 + 1;
          }
          else {
            iVar8 = ((int)-sVar7 * (int)-sVar7 + 0x4000) * 2 >> 0x10;
            iVar8 = (0x7fff - iVar8) +
                    ((short)(sVar2 + (short)(((iVar8 * -0x272 + 0x4000 >> 0xf) + 0x2055) * iVar8 +
                                             0x4000 >> 0xf)) * iVar8 + 0x4000 >> 0xf);
            if (0x7ffe < iVar8) {
              iVar8 = 0x7ffe;
            }
            sVar7 = -((short)iVar8 + 1);
          }
        }
        iVar8 = iVar5 + 1;
        *(short *)((int)param_3 + iVar5 * 4 + 0x10a) = sVar7;
        iVar5 = iVar8;
      } while (iVar8 < param_1);
    }
    iVar5 = 4;
    piVar3 = param_3;
    do {
      iVar8 = iVar5 * (param_1 / iVar5);
      while (param_1 != iVar8) {
        if (iVar5 == 2) {
          iVar8 = 3;
LAB_030a36d4:
          iVar5 = iVar8;
          if (iVar8 * iVar8 - param_1 != 0 && param_1 <= iVar8 * iVar8) goto LAB_030a36dc;
        }
        else {
          if (iVar5 != 4) {
            iVar8 = iVar5 + 2;
            bVar12 = SBORROW4(iVar8,32000);
            iVar1 = iVar5 + -0x7cfe;
          }
          else {
            iVar8 = 2;
            bVar12 = false;
            iVar1 = 0;
          }
          if ((iVar5 == 4 || iVar8 == 32000) || iVar1 < 0 != bVar12) goto LAB_030a36d4;
LAB_030a36dc:
          iVar5 = param_1;
        }
        iVar8 = iVar5 * (param_1 / iVar5);
      }
      param_1 = param_1 / iVar5;
      piVar3[2] = iVar5;
      piVar3[3] = param_1;
      piVar11 = param_3;
      piVar3 = piVar3 + 2;
    } while (1 < param_1);
  }
  return piVar11;
}


