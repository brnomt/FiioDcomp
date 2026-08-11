/**
 * FUN_030ada46 @ 0x030ada46
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_030ada46(int param_1,int *param_2,int *param_3,short *param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uStack_840;
  short asStack_83c [1021];
  short sStack_42;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int *piStack_30;
  int *piStack_2c;
  short *psStack_28;
  
  psStack_28 = param_4;
  piStack_2c = param_3;
  piStack_30 = param_2;
  iStack_34 = param_1;
  if (param_1 == 0) {
    return 1;
  }
  iStack_3c = *param_2;
  iStack_38 = 0;
  iStack_40 = *param_3 << 3;
  *(undefined4 *)(param_1 + 0x4c) = 1;
  if (*(int *)(param_1 + 0x38) == 0) {
    if ((*DAT_030adc00 == 1) && (*(int *)(DAT_030adc04 + 0x14) != 0)) {
      iVar2 = FUN_030ad8c8(iStack_3c,iStack_40 >> 3);
    }
    else {
      iVar2 = FUN_030ad412(iStack_3c,iStack_40 >> 3);
    }
    if (iVar2 < 0) {
      return -1;
    }
    iStack_3c = iStack_3c + iVar2;
    iStack_40 = iStack_40 + iVar2 * -8;
    iVar2 = FUN_030ade84(param_1,&iStack_3c,&iStack_38,&iStack_40);
    if (iVar2 != 0) {
      return iVar2;
    }
    if ((*(int *)(param_1 + 0x40) == -1) &&
       (iVar2 = FUN_030ae06a(param_1,iStack_3c,iStack_38,iStack_40), iVar2 != 0)) {
      return iVar2;
    }
  }
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
  if ((2 < *(int *)(param_1 + 0x40)) || (*(int *)(param_1 + 0x40) < 1)) {
    FUN_030ab8a4(10000);
    return 4;
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  iVar2 = DAT_030ade7c;
  *(undefined4 *)(param_1 + 0x58) = 0;
  iStack_38 = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  iVar2 = 0;
  iVar8 = 0;
  do {
    iVar3 = iVar2;
    if (0xff < iVar8) break;
    iVar3 = FUN_030b1990(param_1,&iStack_3c,&iStack_38,&iStack_40);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar10 = *(int *)(*DAT_030ade80 + *(int *)(param_1 + 0x28) * 4);
    iVar3 = iVar2 + iVar10;
    if (2 < iVar3) {
      return 5;
    }
    iVar9 = 0;
    if (0 < iVar10) {
      do {
        uStack_840 = iVar9;
        iVar4 = FUN_030b27e4(param_1,&iStack_3c,&iStack_38,&iStack_40);
        if (iVar4 != 0) {
          return iVar4;
        }
        iVar4 = FUN_030b1bc0(param_1,iVar9);
        if (iVar4 != 0) {
          return 6;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar10);
    }
    if ((*(int *)(param_1 + 0x28) == 1) && (iVar9 = FUN_030b3248(param_1), iVar9 != 0)) {
      return 7;
    }
    if ((iVar3 < 4) && (iVar9 = 0, 0 < iVar10)) {
      do {
        iVar4 = FUN_030b2de8(param_1,iVar9);
        if (iVar4 != 0) {
          return 8;
        }
        iVar4 = param_1 + iVar9 * 4;
        if (*(int *)(iVar4 + 0x30) != 0) {
          iVar5 = FUN_030b1f02(param_1,iVar9);
          if (iVar5 != 0) {
            return 9;
          }
          *(undefined4 *)(iVar4 + 0x30) = 0;
        }
        iVar4 = FUN_030b354c(param_1,iVar9);
        if (iVar4 != 0) {
          return 10;
        }
        iVar4 = FUN_030b1f20(param_1,iVar9,iVar2 + iVar9,param_4);
        if (iVar4 != 0) {
          return 0xb;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar10);
    }
    iVar2 = iVar3;
    iVar8 = iVar8 + 1;
  } while (*(int *)(param_1 + 0x28) != 7);
  iVar2 = *(int *)(param_1 + 0x40);
  if (iVar2 < 3) {
    if (iVar2 == 1) {
      if (iVar3 == 1) {
        FUN_030ac8a8(&uStack_840,param_4,0x800);
        *param_4 = (short)uStack_840;
        param_4[1] = (short)uStack_840;
        iVar2 = 0x1ff;
        psVar6 = param_4;
        psVar7 = (short *)&uStack_840;
        do {
          sVar1 = psVar7[2];
          psVar6[2] = uStack_840._2_2_;
          psVar6[3] = uStack_840._2_2_;
          uStack_840._2_2_ = psVar7[3];
          psVar6[4] = sVar1;
          psVar6[5] = sVar1;
          psVar6 = psVar6 + 4;
          iVar2 = iVar2 + -1;
          psVar7 = psVar7 + 2;
        } while (iVar2 != 0);
        param_4[0x7fe] = sStack_42;
        param_4[0x7ff] = sStack_42;
      }
      goto LAB_030ade1c;
    }
    if (iVar2 != 2) goto LAB_030ade1c;
  }
  else {
    iVar2 = 0;
    iVar8 = 0x800;
    psVar6 = param_4;
    do {
      iVar3 = iVar2 % 0x400;
      iVar2 = iVar2 + 1;
      *psVar6 = (short)((uint)((((int)*psVar6 + (int)param_4[iVar3 + 0x800]) -
                               ((int)*psVar6 + (int)param_4[iVar3 + 0x800] >> 0x1f)) * 0x8000) >>
                       0x10);
      iVar8 = iVar8 + -1;
      psVar6 = psVar6 + 1;
    } while (iVar8 != 0);
    *(undefined4 *)(param_1 + 0x40) = 2;
  }
  if (*(int *)(DAT_030ade7c + 8) == 1) {
    iVar2 = 0x800;
    do {
      sVar1 = (*param_4 >> 1) + (param_4[1] >> 1);
      *param_4 = sVar1;
      param_4[1] = sVar1;
      param_4 = param_4 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
LAB_030ade1c:
  if ((iStack_38 == 0) || (iStack_3c = iStack_3c + 1, -1 < iStack_40 - (8 - iStack_38))) {
    *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
    *piStack_2c = *piStack_2c - (iStack_3c - *piStack_30);
    *piStack_30 = iStack_3c;
    iVar2 = 0;
  }
  else {
    iVar2 = 0xc;
  }
  return iVar2;
}


