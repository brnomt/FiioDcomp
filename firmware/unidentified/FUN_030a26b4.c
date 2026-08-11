/**
 * FUN_030a26b4 @ 0x030a26b4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int * FUN_030a26b4(uint param_1,int param_2,int *param_3,uint *param_4)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  uint *puVar4;
  short sVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  uint *local_28;
  
  if ((param_1 & 1) == 0) {
    iVar11 = (int)param_1 >> 1;
    local_28 = param_4;
    FUN_030a3580(iVar11,param_2,0,&local_28);
    if (param_4 == (uint *)0x0) {
      param_3 = DAT_030a2b10;
      if ((param_2 != 0) && (param_3 = DAT_030a2b14, param_2 != 1)) {
        return (int *)0x0;
      }
    }
    else {
      puVar4 = (uint *)*param_4;
      *param_4 = (uint)(local_28 + iVar11 * 2 + 3);
      if (puVar4 < local_28 + iVar11 * 2 + 3) {
        return (int *)0x0;
      }
    }
    if (param_3 != (int *)0x0) {
      piVar6 = param_3 + 3;
      *param_3 = (int)piVar6;
      param_3[1] = (int)local_28 + (int)piVar6;
      param_3[2] = (int)local_28 + (int)piVar6 + iVar11 * 4;
      FUN_030a3580(iVar11,param_2,piVar6,&local_28);
      uVar2 = DAT_030a2b0c;
      iVar3 = 0;
      if (0 < iVar11) {
        do {
          iVar7 = iVar3 + ((int)param_1 >> 2);
          if (param_2 == 0) {
            iVar7 = -iVar7;
          }
          uVar10 = (iVar7 << 0x10) / iVar11;
          uVar8 = uVar10 & 0x1ffff;
          if (0x10000 < uVar8) {
            uVar8 = 0x20000 - uVar8;
          }
          sVar5 = (short)uVar8;
          sVar1 = (short)uVar2;
          if ((uVar8 & 0x7fff) == 0) {
            if ((uVar8 & 0xffff) == 0) {
              uVar9 = DAT_030a2b18;
              if ((uVar8 & 0x1ffff) == 0) {
                uVar9 = 0x7fff;
              }
              sVar5 = (short)uVar9;
            }
            else {
              sVar5 = 0;
            }
          }
          else if ((int)uVar8 < 0x8000) {
            iVar7 = ((int)sVar5 * (int)sVar5 + 0x4000) * 2 >> 0x10;
            iVar7 = (0x7fff - iVar7) +
                    ((short)(sVar1 + (short)(((iVar7 * -0x272 + 0x4000 >> 0xf) + 0x2055) * iVar7 +
                                             0x4000 >> 0xf)) * iVar7 + 0x4000 >> 0xf);
            if (0x7ffe < iVar7) {
              iVar7 = 0x7ffe;
            }
            sVar5 = (short)iVar7 + 1;
          }
          else {
            iVar7 = ((int)-sVar5 * (int)-sVar5 + 0x4000) * 2 >> 0x10;
            iVar7 = (0x7fff - iVar7) +
                    ((short)(sVar1 + (short)(((iVar7 * -0x272 + 0x4000 >> 0xf) + 0x2055) * iVar7 +
                                             0x4000 >> 0xf)) * iVar7 + 0x4000 >> 0xf);
            if (0x7ffe < iVar7) {
              iVar7 = 0x7ffe;
            }
            sVar5 = -((short)iVar7 + 1);
          }
          *(short *)(param_3[2] + iVar3 * 4) = sVar5;
          uVar8 = uVar10 - 0x8000 & 0x1ffff;
          if (0x10000 < uVar8) {
            uVar8 = 0x20000 - uVar8;
          }
          if ((uVar8 & 0x7fff) == 0) {
            if ((uVar8 & 0xffff) == 0) {
              uVar9 = DAT_030a2b18;
              if ((uVar8 & 0x1ffff) == 0) {
                uVar9 = 0x7fff;
              }
              sVar5 = (short)uVar9;
            }
            else {
              sVar5 = 0;
            }
          }
          else {
            sVar5 = (short)uVar8;
            if ((int)uVar8 < 0x8000) {
              iVar7 = ((int)sVar5 * (int)sVar5 + 0x4000) * 2 >> 0x10;
              iVar7 = (0x7fff - iVar7) +
                      ((short)(sVar1 + (short)(((iVar7 * -0x272 + 0x4000 >> 0xf) + 0x2055) * iVar7 +
                                               0x4000 >> 0xf)) * iVar7 + 0x4000 >> 0xf);
              if (0x7ffe < iVar7) {
                iVar7 = 0x7ffe;
              }
              sVar5 = (short)iVar7 + 1;
            }
            else {
              iVar7 = ((int)-sVar5 * (int)-sVar5 + 0x4000) * 2 >> 0x10;
              iVar7 = (0x7fff - iVar7) +
                      ((short)(sVar1 + (short)(((iVar7 * -0x272 + 0x4000 >> 0xf) + 0x2055) * iVar7 +
                                               0x4000 >> 0xf)) * iVar7 + 0x4000 >> 0xf);
              if (0x7ffe < iVar7) {
                iVar7 = 0x7ffe;
              }
              sVar5 = -((short)iVar7 + 1);
            }
          }
          iVar7 = iVar3 * 4;
          iVar3 = iVar3 + 1;
          *(short *)(param_3[2] + iVar7 + 2) = sVar5;
        } while (iVar3 < iVar11);
      }
      return param_3;
    }
  }
  return (int *)0x0;
}


