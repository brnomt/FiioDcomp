/**
 * FUN_030a4aba @ 0x030a4aba
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030a4aba(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  undefined2 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  bool bVar12;
  undefined4 local_50 [2];
  undefined2 local_48 [4];
  int local_40 [4];
  int local_30;
  undefined4 uStack_2c;
  int iStack_28;
  
  iStack_28 = param_4;
  uStack_2c = param_3;
  local_30 = param_2;
  local_40[3] = param_1;
  piVar11 = local_50;
  iVar8 = 0;
  iVar2 = 0;
  if (0 < param_5) {
    do {
      local_48[iVar2] = 0;
      local_40[iVar2] = 0;
      local_50[iVar2] = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_5);
  }
  bVar12 = -1 < local_30;
  iVar2 = local_30;
  if (bVar12) {
    iVar2 = param_6;
  }
  if (iVar2 == 0 || (!bVar12 || iVar2 < 0)) {
    piVar11 = (int *)&stack0xffffffdc;
  }
  if (iVar2 == 0 || (!bVar12 || iVar2 < 0)) {
    return;
  }
  while (param_5 < 1) {
LAB_030a4b76:
    do {
      iVar2 = 0;
      if (0 < param_5) {
        do {
          piVar7 = piVar11 + 4;
          uVar4 = FUN_030a4a44(*(byte *)(param_1 + iVar8) & 0xf,piVar7,(int)(short)piVar11[2]);
          *(short *)(piVar11[9] + *piVar11 * 2) = (short)uVar4;
          *(short *)(piVar11 + 2) = (short)uVar4;
          *piVar11 = *piVar11 + 1;
          uVar1 = FUN_030a4a44(*(byte *)(param_1 + iVar8) >> 4,piVar7,uVar4);
          *(undefined2 *)(piVar11[9] + *piVar11 * 2) = uVar1;
          *(undefined2 *)(piVar11 + 2) = uVar1;
          *piVar11 = *piVar11 + 1;
          uVar4 = FUN_030a4a44(*(byte *)(param_1 + iVar8 + 1) & 0xf,piVar7);
          *(short *)(piVar11[9] + *piVar11 * 2) = (short)uVar4;
          *(short *)(piVar11 + 2) = (short)uVar4;
          *piVar11 = *piVar11 + 1;
          uVar4 = FUN_030a4a44(*(byte *)(param_1 + iVar8 + 1) >> 4,piVar7,uVar4);
          *(short *)(piVar11[9] + *piVar11 * 2) = (short)uVar4;
          *(short *)(piVar11 + 2) = (short)uVar4;
          *piVar11 = *piVar11 + 1;
          uVar4 = FUN_030a4a44(*(byte *)(param_1 + iVar8 + 2) & 0xf,piVar7,uVar4);
          *(short *)(piVar11[9] + *piVar11 * 2) = (short)uVar4;
          *(short *)(piVar11 + 2) = (short)uVar4;
          *piVar11 = *piVar11 + 1;
          uVar4 = FUN_030a4a44(*(byte *)(param_1 + iVar8 + 2) >> 4,piVar7,uVar4);
          iVar6 = iVar8 + 3;
          *(short *)(piVar11[9] + *piVar11 * 2) = (short)uVar4;
          *(short *)(piVar11 + 2) = (short)uVar4;
          *piVar11 = *piVar11 + 1;
          uVar4 = FUN_030a4a44(*(byte *)(param_1 + iVar6) & 0xf,piVar7,uVar4);
          *(short *)(piVar11[9] + *piVar11 * 2) = (short)uVar4;
          *(short *)(piVar11 + 2) = (short)uVar4;
          *piVar11 = *piVar11 + 1;
          uVar1 = FUN_030a4a44(*(byte *)(param_1 + iVar6) >> 4,piVar7,uVar4);
          *(undefined2 *)(piVar11[9] + *piVar11 * 2) = uVar1;
          *(undefined2 *)(piVar11 + 2) = uVar1;
          *piVar11 = *piVar11 + 1;
          iVar5 = iVar2;
          while( true ) {
            iVar8 = iVar6 + 1;
            iVar2 = iVar5 + 1;
            if (param_5 <= iVar2) goto LAB_030a4cd6;
            if (iVar2 == 0) break;
            piVar7 = piVar11 + iVar5 + 5;
            uVar1 = FUN_030a4a44(*(byte *)(param_1 + iVar8) & 0xf,piVar7,
                                 (int)*(short *)((int)piVar11 + iVar2 * 2 + 8));
            *(undefined2 *)(param_4 + piVar11[iVar2] * 2) = uVar1;
            piVar11[iVar2] = piVar11[iVar2] + 1;
            *(undefined2 *)((int)piVar11 + iVar2 * 2 + 8) = uVar1;
            uVar1 = FUN_030a4a44(*(byte *)(param_1 + iVar8) >> 4,piVar7);
            *(undefined2 *)(param_4 + piVar11[iVar2] * 2) = uVar1;
            piVar11[iVar2] = piVar11[iVar2] + 1;
            *(undefined2 *)((int)piVar11 + iVar2 * 2 + 8) = uVar1;
            uVar1 = FUN_030a4a44(*(byte *)(param_1 + iVar6 + 2) & 0xf,piVar7);
            *(undefined2 *)(param_4 + piVar11[iVar2] * 2) = uVar1;
            piVar11[iVar2] = piVar11[iVar2] + 1;
            *(undefined2 *)((int)piVar11 + iVar2 * 2 + 8) = uVar1;
            uVar1 = FUN_030a4a44(*(byte *)(param_1 + iVar6 + 2) >> 4,piVar7);
            *(undefined2 *)(param_4 + piVar11[iVar2] * 2) = uVar1;
            piVar11[iVar2] = piVar11[iVar2] + 1;
            *(undefined2 *)((int)piVar11 + iVar2 * 2 + 8) = uVar1;
            uVar1 = FUN_030a4a44(*(byte *)(param_1 + iVar6 + 3) & 0xf,piVar7);
            *(undefined2 *)(param_4 + piVar11[iVar2] * 2) = uVar1;
            piVar11[iVar2] = piVar11[iVar2] + 1;
            *(undefined2 *)((int)piVar11 + iVar2 * 2 + 8) = uVar1;
            uVar1 = FUN_030a4a44(*(byte *)(param_1 + iVar6 + 3) >> 4,piVar7);
            *(undefined2 *)(param_4 + piVar11[iVar2] * 2) = uVar1;
            piVar11[iVar2] = piVar11[iVar2] + 1;
            iVar6 = iVar6 + 4;
            *(undefined2 *)((int)piVar11 + iVar2 * 2 + 8) = uVar1;
            uVar1 = FUN_030a4a44(*(byte *)(param_1 + iVar6) & 0xf,piVar7);
            *(undefined2 *)(param_4 + piVar11[iVar2] * 2) = uVar1;
            piVar11[iVar2] = piVar11[iVar2] + 1;
            *(undefined2 *)((int)piVar11 + iVar2 * 2 + 8) = uVar1;
            uVar1 = FUN_030a4a44(*(byte *)(param_1 + iVar6) >> 4,piVar7);
            *(undefined2 *)(param_4 + piVar11[iVar2] * 2) = uVar1;
            piVar11[iVar2] = piVar11[iVar2] + 1;
            *(undefined2 *)((int)piVar11 + iVar2 * 2 + 8) = uVar1;
            iVar5 = iVar2;
          }
        } while( true );
      }
LAB_030a4cd6:
      iVar2 = piVar11[8];
      if (iVar8 <= iVar2) {
        iVar2 = piVar11[0x15];
      }
      if (iVar2 <= iVar8) {
        return;
      }
    } while (iVar8 != 0);
  }
  iVar5 = 0;
  piVar7 = piVar11 + 2;
  piVar10 = piVar11 + 4;
  piVar3 = piVar11;
  iVar2 = param_5;
  do {
    uVar1 = *(undefined2 *)((iVar8 - (iVar8 >> 0x1f) & 0xfffffffeU) + param_1);
    *(undefined2 *)(piVar11[9] + *piVar3 * 2) = uVar1;
    *piVar3 = *piVar3 + 1;
    *(undefined2 *)piVar7 = uVar1;
    piVar9 = piVar10;
    while( true ) {
      iVar6 = iVar8 + iVar5 * 4 + 2;
      piVar3 = piVar3 + 1;
      piVar7 = (int *)((int)piVar7 + 2);
      iVar5 = iVar5 + 1;
      piVar10 = piVar9 + 1;
      *piVar9 = (int)*(short *)((iVar6 - (iVar6 >> 0x1f) & 0xfffffffeU) + param_1);
      iVar2 = iVar2 + -1;
      if (iVar2 == 0) {
        iVar8 = iVar8 + param_5 * 4;
        goto LAB_030a4b76;
      }
      if (iVar5 == 0) break;
      iVar6 = iVar8 + iVar5 * 4;
      uVar1 = *(undefined2 *)((iVar6 - (iVar6 >> 0x1f) & 0xfffffffeU) + param_1);
      *(undefined2 *)(param_4 + *piVar3 * 2) = uVar1;
      *piVar3 = *piVar3 + 1;
      *(undefined2 *)piVar7 = uVar1;
      piVar9 = piVar10;
    }
  } while( true );
}


