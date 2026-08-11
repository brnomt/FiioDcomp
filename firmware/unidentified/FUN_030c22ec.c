/**
 * FUN_030c22ec @ 0x030c22ec
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_030c22ec(int param_1,int param_2,undefined4 *param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint auStack_c0 [33];
  uint local_3c;
  int local_34;
  int iStack_30;
  undefined4 *puStack_2c;
  undefined4 local_28;
  
  iVar9 = 0;
  iVar7 = 0;
  if (param_2 < 2) {
    *param_3 = 0x80000000;
  }
  else {
    local_34 = param_1;
    iStack_30 = param_2;
    puStack_2c = param_3;
    local_28 = param_4;
    memset_byte(auStack_c0,0,0x84);
    iVar10 = 0;
    do {
      uVar5 = (uint)*(byte *)(local_34 + iVar10);
      if (uVar5 != 0) {
        iVar6 = 0;
        uVar8 = auStack_c0[uVar5];
        if ((iVar9 != 0) && (uVar8 == 0)) {
          return 0xffffffff;
        }
        iVar1 = 0;
        iVar2 = uVar5 - 1;
        if (0 < iVar2) {
          do {
            uVar3 = uVar8 >> ((uVar5 - iVar1) - 1 & 0xff) & 1;
            if (iVar6 < iVar7) {
              iVar4 = uVar3 + iVar6 * 2;
              if (param_3[iVar4] == 0) {
                param_3[iVar4] = iVar7;
              }
            }
            else {
              iVar7 = iVar7 + 1;
              param_3[iVar6 * 2] = iVar7;
              param_3[iVar6 * 2 + 1] = 0;
            }
            iVar1 = iVar1 + 1;
            iVar6 = param_3[uVar3 + iVar6 * 2];
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
          iVar1 = uVar5 - 1;
        }
        local_3c = uVar8 >> ((uVar5 - iVar1) - 1 & 0xff) & 1;
        if (iVar7 <= iVar6) {
          iVar7 = iVar7 + 1;
          param_3[iVar6 * 2 + 1] = 0;
        }
        iVar1 = iVar9 + 1;
        uVar3 = FUN_030c1f92(iVar10,iVar9,local_28,param_5,param_6,param_7);
        param_3[local_3c + iVar6 * 2] = uVar3 | 0x80000000;
        uVar3 = uVar5;
        if (uVar5 != 0) {
          do {
            if ((auStack_c0[uVar3] & 1) != 0) {
              auStack_c0[uVar3] = auStack_c0[uVar3 - 1] << 1;
              break;
            }
            auStack_c0[uVar3] = auStack_c0[uVar3] + 1;
            uVar3 = uVar3 - 1;
          } while (0 < (int)uVar3);
        }
        uVar5 = uVar5 + 1;
        iVar9 = iVar1;
        if (uVar5 < 0x21) {
          do {
            uVar3 = auStack_c0[uVar5];
            if (uVar8 != uVar3 >> 1) break;
            auStack_c0[uVar5] = auStack_c0[uVar5 - 1] << 1;
            uVar5 = uVar5 + 1;
            uVar8 = uVar3;
          } while ((int)uVar5 < 0x21);
        }
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < param_2);
  }
  return 0;
}


