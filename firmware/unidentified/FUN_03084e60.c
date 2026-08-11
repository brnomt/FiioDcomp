/**
 * FUN_03084e60 @ 0x03084e60
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4
FUN_03084e60(int *param_1,uint *param_2,uint *param_3,uint *param_4,int param_5,int param_6)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar11 = *param_2;
  uVar10 = *param_3;
  uVar8 = 0;
  bVar4 = false;
  bVar3 = false;
  bVar2 = false;
  bVar1 = false;
  *param_4 = 0;
  if (param_6 != 1) {
    uVar6 = param_1[8];
    uVar10 = 0;
    if (uVar6 != 0) {
      if (uVar6 < uVar11) {
        return 2;
      }
      uVar8 = uVar6 / (uint)param_1[7];
      uVar10 = (uint)(uVar8 == 0);
      if (((uVar8 == 0) || (uVar10 = uVar11 / uVar8, uVar10 != 0)) && ((uVar10 & 0xf) == 0)) {
        uVar10 = uVar10 + 1;
      }
    }
  }
  if ((uint)param_1[7] <= uVar10) {
    uVar10 = param_1[7] - 1;
  }
  do {
    *param_1 = uVar10 * param_1[5] + param_1[4];
    param_1[1] = 0;
    iVar7 = FUN_03085524(param_1);
    if (iVar7 != 0) {
      return 4;
    }
    iVar7 = 0;
    if (param_1[0x46] != 0) {
      iVar7 = param_1[0x44];
    }
    if (param_1[0x46] != 0 && iVar7 != 0) {
      return 4;
    }
    param_1[0x61] = 0;
    uVar6 = 0;
    if (param_1[0x55] != 0) {
      do {
        iVar7 = FUN_03085904(param_1);
        if (iVar7 != 0) {
          return 4;
        }
        if ((ushort)*(byte *)(param_1 + 0x57) == *(ushort *)(param_1 + 0x38)) {
          uVar6 = param_1[0x5a] - param_1[9];
          *param_4 = uVar6;
          if (param_6 == 1) goto LAB_03084fd4;
          bVar1 = false;
          if (bVar2) {
            bVar1 = bVar3;
          }
          if (bVar2 && bVar1) {
            bVar4 = true;
          }
          if (uVar11 < uVar6) {
            uVar9 = uVar6 - uVar11;
            bVar3 = true;
          }
          else {
            uVar9 = uVar11 - uVar6;
            bVar2 = true;
          }
          bVar1 = uVar11 >= uVar6;
          if (param_5 == 1) {
            bVar5 = true;
            if (uVar9 != 0) {
              bVar5 = bVar4;
            }
            if ((uVar9 == 0 || bVar5) || uVar10 == 0) goto LAB_03084fd4;
          }
          else {
            if (uVar9 < uVar8 * 5 >> 2) {
              bVar4 = true;
            }
            if ((uVar10 == 0) || (bVar4 && (uVar10 & 0xf) != 0)) goto LAB_03084fd4;
          }
          if (bVar1) goto LAB_03084fba;
          goto LAB_03084fbe;
        }
        uVar6 = uVar6 + 1;
        param_1[0x61] = param_1[0x61] + 1;
      } while (uVar6 < (uint)param_1[0x55]);
    }
    if (param_6 == 1) {
      bVar1 = false;
    }
    if (param_6 != 1 && bVar1) {
LAB_03084fba:
      uVar10 = uVar10 + 1;
    }
    else if (uVar10 == 0) {
      bVar1 = true;
      uVar10 = 1;
      bVar2 = true;
    }
    else {
LAB_03084fbe:
      uVar10 = uVar10 - 1;
    }
    if ((uint)param_1[7] <= uVar10) {
      if (!bVar4) {
        uVar10 = param_1[7];
        *param_4 = param_1[8];
      }
LAB_03084fd4:
      iVar7 = FUN_03086140(param_1[0x6b]);
      *(undefined1 *)(param_1 + 0x6c) = 1;
      if (iVar7 != 0) {
        return 1;
      }
      param_1[2] = uVar10 * param_1[5] + param_1[4];
      param_1[3] = 0;
      *(undefined1 *)(param_1 + 0x3c) = 3;
      *param_2 = *param_4;
      *param_3 = uVar10;
      return 0;
    }
  } while( true );
}


