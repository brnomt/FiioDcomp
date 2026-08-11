/**
 * FUN_030ccf22 @ 0x030ccf22
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_030ccf22(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int extraout_r1;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  bool bVar10;
  undefined8 uVar11;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_58 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  iVar1 = FUN_030cca40();
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar2 = FUN_030cbebc(param_1);
  iVar1 = 0;
  if (iVar2 != 0) {
    return -0x89;
  }
  while( true ) {
    while( true ) {
      iVar2 = FUN_030c7762(*(undefined4 *)(param_1 + 0x88),&local_68);
      if (iVar2 < 1) break;
      iVar2 = FUN_030c415a(param_1 + 0x30,&local_68);
      if (iVar2 < 0) {
        FUN_030c775e(*(undefined4 *)(param_1 + 0x88),0);
      }
      else {
        if (iVar1 != 0) {
          uVar6 = *(uint *)(param_1 + 0x60);
          uVar3 = iVar1 + iVar2 >> 2;
          *(uint *)(param_1 + 0x60) = uVar6 + uVar3;
          *(uint *)(param_1 + 100) =
               *(int *)(param_1 + 100) + (iVar1 + iVar2 >> 0x1f) + (uint)CARRY4(uVar6,uVar3);
        }
        iVar1 = FUN_030c7af0(param_1 + 0x30,1);
        uVar3 = iVar1 + iVar2 >> 2;
        iVar1 = *(int *)(param_1 + 100) + (iVar1 + iVar2 >> 0x1f) +
                (uint)CARRY4(uVar3,*(uint *)(param_1 + 0x60));
        bVar10 = uVar3 + *(uint *)(param_1 + 0x60) < param_3;
        if ((int)((iVar1 - param_4) - (uint)bVar10) < 0 ==
            (SBORROW4(iVar1,param_4) != SBORROW4(iVar1 - param_4,(uint)bVar10))) goto LAB_030cd1ba;
        FUN_030c775e(*(undefined4 *)(param_1 + 0x88),0);
        FUN_030c4238(*(undefined4 *)(param_1 + 0x8c),&local_68,0);
        iVar1 = iVar2;
        if (-1 < local_54) {
          iVar2 = *(int *)(param_1 + 0x2c);
          uVar5 = *(uint *)(param_1 + 0x70);
          puVar9 = (uint *)(iVar2 + uVar5 * 0x10);
          uVar6 = *puVar9;
          uVar3 = local_58 - uVar6;
          uVar6 = (local_54 - puVar9[1]) - (uint)(local_58 < uVar6);
          *(uint *)(param_1 + 0x60) = uVar3;
          *(uint *)(param_1 + 100) = uVar6;
          if ((int)(-(uint)(uVar3 != 0) - uVar6) < 0 ==
              (SBORROW4(0,uVar6) != SBORROW4(-uVar6,(uint)(uVar3 != 0)))) {
            uVar6 = 0;
            uVar3 = uVar6;
          }
          *(uint *)(param_1 + 0x60) = uVar3;
          *(uint *)(param_1 + 100) = uVar6;
          if ((int)uVar5 < 1) {
            uVar4 = 0;
          }
          else {
            uVar4 = uVar5 & 1;
            if (uVar4 != 0) {
              uVar7 = *(uint *)(iVar2 + 8);
              iVar8 = *(int *)(iVar2 + 0xc);
              *(uint *)(param_1 + 0x60) = uVar3 + uVar7;
              *(uint *)(param_1 + 100) = uVar6 + iVar8 + (uint)CARRY4(uVar3,uVar7);
            }
          }
          for (; (int)uVar4 < (int)uVar5; uVar4 = uVar4 + 2) {
            puVar9 = (uint *)(iVar2 + uVar4 * 0x10 + 8);
            uVar3 = *puVar9;
            uVar6 = uVar3 + *(uint *)(param_1 + 0x60);
            iVar8 = puVar9[1] +
                    *(int *)(param_1 + 100) + (uint)CARRY4(uVar3,*(uint *)(param_1 + 0x60));
            puVar9 = (uint *)(iVar2 + uVar4 * 0x10 + 0x18);
            *(uint *)(param_1 + 0x60) = uVar6;
            *(int *)(param_1 + 100) = iVar8;
            uVar3 = *puVar9;
            uVar7 = puVar9[1];
            *(uint *)(param_1 + 0x60) = uVar3 + uVar6;
            *(uint *)(param_1 + 100) = uVar7 + iVar8 + (uint)CARRY4(uVar3,uVar6);
          }
        }
      }
    }
    if ((iVar2 != 0 && iVar2 != -3) ||
       (FUN_030cb504(param_1,&local_40,0xffffffff,0xffffffff), extraout_r1 < 0)) break;
    iVar2 = FUN_030c6bc2(&local_40);
    iVar8 = *(int *)(param_1 + 0x68);
    if (iVar2 == *(int *)(param_1 + 0x6c)) {
      if (iVar8 < 3) goto LAB_030cd0f6;
    }
    else {
      if (iVar8 == 5) {
        UdpRecive(*(undefined4 *)(param_1 + 0x8c));
        *(undefined4 *)(param_1 + 0x8c) = 0;
        *(undefined4 *)(param_1 + 0x68) = 3;
      }
      else if (iVar8 < 3) goto LAB_030cd0f6;
      FUN_030c7b12(param_1 + 0x30);
      FUN_030c7ab4(param_1 + 0x50);
      *(undefined4 *)(param_1 + 0x68) = 2;
LAB_030cd0f6:
      iVar1 = FUN_030c6bc2(&local_40);
      *(int *)(param_1 + 0x6c) = iVar1;
      uVar6 = *(uint *)(param_1 + 0x1c);
      uVar3 = 0;
      if ((int)uVar6 < 1) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar6 & 1;
        if (uVar5 != 0) {
          do {
            if (*(int *)(*(int *)(param_1 + 0x28) + uVar3 * 4) == iVar1) goto LAB_030cd154;
            uVar3 = uVar3 + 1;
          } while ((int)uVar3 < (int)uVar5);
        }
      }
      uVar3 = uVar5;
      if ((int)uVar3 < (int)uVar6) {
        do {
          if (*(int *)(*(int *)(param_1 + 0x28) + uVar3 * 4) == iVar1) break;
          if (*(int *)(*(int *)(param_1 + 0x28) + uVar3 * 4 + 4) == iVar1) {
            uVar3 = uVar3 + 1;
            break;
          }
          uVar3 = uVar3 + 2;
        } while ((int)uVar3 < (int)uVar6);
      }
LAB_030cd154:
      if (uVar6 == uVar3) {
        FUN_030c6e1e(&local_40);
        FUN_030c75ac(&local_68);
        return -0x89;
      }
      *(uint *)(param_1 + 0x70) = uVar3;
      iVar1 = FUN_030cba38(param_1,param_1 + 0x30,param_1 + 0x50,param_1 + 0x6c);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_030cbebc(param_1);
      if (iVar1 != 0) {
        return -0x89;
      }
      iVar1 = 0;
    }
    FUN_030c7400(*(undefined4 *)(param_1 + 0x88),&local_40);
  }
LAB_030cd1ba:
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  iVar1 = *(int *)(param_1 + 100);
  bVar10 = *(uint *)(param_1 + 0x60) < param_3;
  if ((int)((iVar1 - param_4) - (uint)bVar10) < 0 !=
      (SBORROW4(iVar1,param_4) != SBORROW4(iVar1 - param_4,(uint)bVar10))) {
    do {
      uVar6 = param_3 - *(uint *)(param_1 + 0x60);
      iVar2 = (param_4 - iVar1) - (uint)(param_3 < *(uint *)(param_1 + 0x60));
      uVar3 = FUN_030c4012(*(undefined4 *)(param_1 + 0x8c),0);
      iVar1 = (int)uVar3 >> 0x1f;
      if ((int)((iVar2 - iVar1) - (uint)(uVar6 < uVar3)) < 0 !=
          (SBORROW4(iVar2,iVar1) != SBORROW4(iVar2 - iVar1,(uint)(uVar6 < uVar3)))) {
        uVar3 = uVar6;
      }
      FUN_030c4142(*(undefined4 *)(param_1 + 0x8c),uVar3);
      uVar5 = *(uint *)(param_1 + 0x60);
      iVar1 = (int)uVar3 >> 0x1f;
      *(uint *)(param_1 + 0x60) = uVar5 + uVar3;
      *(uint *)(param_1 + 100) = *(int *)(param_1 + 100) + iVar1 + (uint)CARRY4(uVar5,uVar3);
      if (((int)((iVar1 - iVar2) - (uint)(uVar3 < uVar6)) < 0 !=
           (SBORROW4(iVar1,iVar2) != SBORROW4(iVar1 - iVar2,(uint)(uVar3 < uVar6)))) &&
         (iVar1 = FUN_030cc462(param_1,1), iVar1 < 1)) {
        uVar11 = FUN_030cbfda(param_1,0xffffffff);
        *(undefined8 *)(param_1 + 0x60) = uVar11;
      }
      iVar1 = *(int *)(param_1 + 100);
      bVar10 = *(uint *)(param_1 + 0x60) < param_3;
    } while ((int)((iVar1 - param_4) - (uint)bVar10) < 0 !=
             (SBORROW4(iVar1,param_4) != SBORROW4(iVar1 - param_4,(uint)bVar10)));
  }
  FUN_030c6e1e(&local_40);
  FUN_030c75ac(&local_68);
  return 0;
}


