/**
 * FUN_030cb504 @ 0x030cb504
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


longlong FUN_030cb504(undefined4 *param_1,undefined4 param_2,uint param_3,int param_4)

{
  byte bVar1;
  longlong lVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  code *pcVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  undefined8 uVar13;
  char local_438;
  char local_437;
  char local_436;
  char local_435;
  byte local_41e;
  byte local_41d [997];
  undefined4 *puStack_38;
  undefined4 local_34;
  uint uStack_30;
  int local_2c;
  
  piVar5 = DAT_030cb768;
  puStack_38 = param_1;
  local_34 = param_2;
  uStack_30 = param_3;
  local_2c = param_4;
  uVar12 = param_3;
  if ((int)(-(uint)(param_3 != 0) - param_4) < 0 !=
      (SBORROW4(0,param_4) != SBORROW4(-param_4,(uint)(param_3 != 0)))) {
    uVar12 = param_1[2] + param_3;
    local_2c = param_1[3] + param_4 + (uint)CARRY4(param_1[2],param_3);
  }
LAB_030cb542:
  do {
    if (((int)(-(uint)(uVar12 != 0) - local_2c) < 0 !=
         (SBORROW4(0,local_2c) != SBORROW4(-local_2c,(uint)(uVar12 != 0)))) &&
       (iVar9 = param_1[3],
       (int)((iVar9 - local_2c) - (uint)((uint)param_1[2] < uVar12)) < 0 ==
       (SBORROW4(iVar9,local_2c) != SBORROW4(iVar9 - local_2c,(uint)((uint)param_1[2] < uVar12)))))
    {
      return -1;
    }
    uVar6 = FUN_030c6e3e(param_1[6],local_34);
    if ((int)uVar6 < 0) {
      uVar13 = CONCAT44((param_1[3] - ((int)uVar6 >> 0x1f)) - (uint)((uint)param_1[2] < uVar6),
                        param_1[2] - uVar6);
LAB_030cb584:
      *(undefined8 *)(param_1 + 2) = uVar13;
      goto LAB_030cb542;
    }
    if (uVar6 != 0) {
      if (uVar6 != 3) {
        if ((int)uVar6 < 0xfe01) {
          uVar12 = param_1[2];
          lVar2 = *(longlong *)(param_1 + 2);
          param_1[2] = uVar12 + uVar6;
          param_1[3] = ((int)uVar6 >> 0x1f) + param_1[3] + (uint)CARRY4(uVar12,uVar6);
          return lVar2;
        }
        iVar9 = 0;
        if (*DAT_030cb76c == 2) {
          *DAT_030cb76c = 3;
          *piVar5 = 0;
        }
        else if (0xff54 < *piVar5) {
          return 0;
        }
        if (*DAT_030cb760 != 3) {
          return 0;
        }
        *piVar5 = 0;
LAB_030cb674:
        *piVar5 = 0xff55;
        iVar10 = 0xff55;
        iVar11 = 0;
        pcVar8 = (code *)param_1[0x25];
        uVar7 = *param_1;
        do {
          (*pcVar8)(uVar7,pcVar8,iVar10,iVar11,0);
          (*(code *)param_1[0x24])(&local_438,0x400,*param_1);
          uVar6 = (uint)local_41e;
          cVar3 = local_438;
          if (local_438 == 'O') {
            cVar3 = local_437;
          }
          if (local_438 != 'O' || cVar3 != 'g') {
LAB_030cb698:
            return (longlong)iVar9;
          }
          cVar3 = local_436;
          if (local_436 == 'g') {
            cVar3 = local_435;
          }
          if (local_436 != 'g' || cVar3 != 'S') goto LAB_030cb698;
          iVar9 = 0;
          iVar11 = 0;
          if (uVar6 != 0) {
            do {
              if (local_41d[iVar11] != 0xff) {
                bVar1 = local_41d[iVar11];
                FUN_030c0f56(DAT_030cb770,&local_438,0x400);
                (*(code *)param_1[0x25])(*param_1,(code *)param_1[0x25],*piVar5,*piVar5 >> 0x1f,0);
                iVar11 = *piVar5;
                *DAT_030cb778 = iVar11;
                piVar4 = DAT_030cb760;
                *piVar5 = iVar11 + iVar9 + (uint)bVar1 + uVar6 + 0x1b;
                *piVar4 = 0;
                FUN_030c66b8(*(undefined4 *)(param_1[6] + 8));
                iVar9 = FUN_030cb34a(param_1);
                if (iVar9 == 0) goto LAB_030cb61c;
                if (iVar9 < 0) goto LAB_030cb616;
                *piVar4 = 0xff55;
                param_1[2] = 0;
                param_1[3] = 0;
                goto LAB_030cb542;
              }
              iVar11 = iVar11 + 1;
              iVar9 = iVar9 + 0xff;
            } while (iVar11 < (int)uVar6);
          }
          if (*piVar5 == 0) goto LAB_030cb674;
          iVar10 = *piVar5 + iVar9 + uVar6 + 0x1b;
          *piVar5 = iVar10;
          pcVar8 = (code *)param_1[0x25];
          iVar11 = iVar10 >> 0x1f;
          uVar7 = *param_1;
        } while( true );
      }
      (*(code *)param_1[0x25])(*param_1,(code *)param_1[0x25],0x3a,0,0);
      uVar13 = FUN_030cb34a(param_1);
      iVar9 = (int)uVar13;
      if (0 < iVar9) {
        uVar13 = 0;
      }
      if (iVar9 == 0) {
LAB_030cb61c:
        uVar12 = 1;
        goto LAB_030cb5b4;
      }
      if (-1 < iVar9) goto LAB_030cb584;
      goto LAB_030cb616;
    }
    if (uVar12 == 0 && local_2c == 0) {
      return -1;
    }
    iVar9 = FUN_030cb34a(param_1);
    if (iVar9 == 0) goto LAB_030cb61c;
    if (iVar9 < 0) {
LAB_030cb616:
      uVar12 = 0x7f;
LAB_030cb5b4:
      return CONCAT44(0xffffffff,~uVar12);
    }
  } while( true );
}


