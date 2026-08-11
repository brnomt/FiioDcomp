/**
 * FUN_030c4c4e @ 0x030c4c4e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030c4c4e(int *param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  bool bVar12;
  
  iVar2 = sbuf_read_bits(param_1 + 1,param_2[3],param_3,param_4,param_4);
  if (0 < iVar2) {
    iVar1 = param_2[3];
    iVar9 = param_2[4];
    uVar3 = FUN_030c1f84(param_2[5]);
    iVar4 = sbuf_read_bits(param_1 + 1,uVar3);
    bVar12 = iVar4 != -1;
    iVar5 = 0;
    iVar8 = 0;
    if (bVar12) {
      iVar8 = param_2[5];
      iVar5 = iVar8 - iVar4;
    }
    if ((bVar12 && iVar8 != iVar4) && iVar5 < 0 == (bVar12 && SBORROW4(iVar8,iVar4))) {
      iVar8 = 0;
      iVar11 = 0;
      puVar10 = (uint *)(*(int *)(*(int *)(*param_1 + 0x1c) + 0x30) +
                        (uint)*(byte *)((int)param_2 + iVar4 + 0x18) * 0x40);
      iVar5 = *param_2;
      if (0 < iVar5) {
        do {
          iVar5 = FUN_030c3da8(puVar10,param_3 + iVar11 * 4,param_1 + 1,*puVar10,0xffffffe8);
          if (iVar5 == -1) {
            return 0;
          }
          iVar11 = iVar11 + *puVar10;
          iVar5 = *param_2;
        } while (iVar11 < iVar5);
      }
      iVar4 = 0;
      if (0 < iVar5) {
        do {
          if (0 < (int)*puVar10) {
            piVar6 = (int *)(param_3 + iVar4 * 4);
            piVar7 = piVar6 + -1;
            if ((*puVar10 & 1) != 0) {
              *piVar6 = *piVar6 + iVar8;
              piVar7 = piVar6;
            }
            for (iVar5 = (int)*puVar10 >> 1; iVar5 != 0; iVar5 = iVar5 + -1) {
              piVar7[1] = piVar7[1] + iVar8;
              piVar6 = piVar7 + 2;
              piVar7 = piVar7 + 2;
              *piVar7 = *piVar6 + iVar8;
            }
            iVar4 = iVar4 + *puVar10;
          }
          iVar8 = *(int *)(param_3 + iVar4 * 4 + -4);
          iVar5 = *param_2;
        } while (iVar4 < iVar5);
      }
      *(int *)(param_3 + iVar5 * 4) = (iVar9 * iVar2 * 0x10) / ((1 << (sbyte)iVar1) + -1);
      return param_3;
    }
  }
  return 0;
}


