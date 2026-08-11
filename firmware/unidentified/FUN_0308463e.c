/**
 * FUN_0308463e @ 0x0308463e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_0308463e(int param_1,uint *param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  uVar9 = 0;
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x4c) = 1;
  }
  else {
    if (param_5 != 0) {
      *(undefined4 *)(param_1 + 0x4c) = 1;
    }
    if (0 < param_3) {
      *(uint **)(param_1 + 0x1c) = param_2;
      *(int *)(param_1 + 0x20) = param_3;
      if (param_4 != 0 || param_6 != 0) {
        *(uint **)(param_1 + 0x14) = param_2;
        *(int *)(param_1 + 0x18) = param_3;
      }
      if (*(int *)(param_1 + 0x38) == 0) {
        if (param_4 != 0) {
          *(uint *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) + 1 & 0x3ff;
        }
      }
      else if ((param_4 != 0) && (param_6 == 0)) {
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 *)(param_1 + 0x10) = 0;
        uVar4 = *param_2;
        uVar8 = uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                (uint)*(byte *)((int)param_2 + 3);
        *(uint *)(param_1 + 0x10) = uVar8;
        piVar5 = *(int **)(param_1 + 8);
        iVar10 = *piVar5;
        if ((*(int *)(iVar10 + 0x40) < 3) && (*(int *)(iVar10 + 0x70) != 0)) {
          uVar6 = *(byte *)(iVar10 + 0xc) + 0xb & 0xff;
        }
        else {
          uVar6 = 0;
        }
        *(uint *)(param_1 + 0x1c) = (int)param_2 + (uVar6 >> 3);
        *(uint *)(param_1 + 0x20) = param_3 - (uVar6 >> 3);
        uVar3 = (uVar4 & 0xff) >> 4;
        iVar10 = *(int *)(param_1 + 0x34);
        *(uint *)(param_1 + 0x34) = uVar3;
        uVar9 = uVar6 & 7;
        if (*(int *)(param_1 + 0x3c) == 0) {
          bVar2 = false;
          if ((2 < param_7) && ((uVar4 << 0x18 & 0x4000000) != 0)) {
            bVar2 = true;
          }
          iVar10 = uVar3 - iVar10;
          if ((iVar10 != 1 && iVar10 != -0xf) || (bVar2)) {
            *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x14) + 4;
            *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x18) + -4;
            *(uint *)(param_1 + 0x24) = uVar8;
            *(uint *)(param_1 + 0x28) = 0x20 - uVar6;
            piVar5[3] = 1;
            return 6;
          }
          piVar5[3] = 0;
        }
        else {
          *(undefined4 *)(param_1 + 0x3c) = 0;
        }
      }
      if ((*(int *)(param_1 + 0x30) == 0) && (*(int *)(param_1 + 0x28) + (8 - uVar9) < 0x21)) {
        while (*(int *)(param_1 + 0x20) != 0) {
          uVar4 = *(int *)(param_1 + 0x28) + (8 - uVar9);
          if (0x20 < uVar4) {
            return 0;
          }
          pbVar7 = *(byte **)(param_1 + 0x1c);
          *(byte **)(param_1 + 0x1c) = pbVar7 + 1;
          bVar1 = *pbVar7;
          *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
          *(uint *)(param_1 + 0x24) =
               ((uint)bVar1 << uVar9 & 0xff) >> uVar9 |
               *(int *)(param_1 + 0x24) << (8 - uVar9 & 0xff);
          *(uint *)(param_1 + 0x28) = uVar4;
          uVar9 = 0;
        }
      }
      else {
        pbVar7 = *(byte **)(param_1 + 0x1c);
        *(byte **)(param_1 + 0x1c) = pbVar7 + 1;
        bVar1 = *pbVar7;
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
        *(uint *)(param_1 + 0x2c) =
             *(int *)(param_1 + 0x2c) << (8 - uVar9 & 0xff) | ((uint)bVar1 << uVar9 & 0xff) >> uVar9
        ;
        *(uint *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (8 - uVar9);
      }
    }
  }
  return 0;
}


