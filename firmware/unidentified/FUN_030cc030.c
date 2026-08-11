/**
 * FUN_030cc030 @ 0x030cc030
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030cc030(int *param_1,undefined4 param_2,uint param_3,int param_4)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int extraout_r1;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  undefined8 uVar10;
  undefined1 auStack_e0 [24];
  int iStack_c8;
  undefined4 uStack_c4;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  uint local_80;
  int local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 auStack_38 [20];
  
  FUN_030c0fa4(auStack_e0,0x50);
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  if (1 < param_1[0x1a]) {
    if (param_1[1] == 0) {
      return 0xffffff76;
    }
    if ((-1 < param_4) &&
       (iVar4 = param_1[5],
       (int)((iVar4 - param_4) - (uint)((uint)param_1[4] < param_3)) < 0 ==
       (SBORROW4(iVar4,param_4) != SBORROW4(iVar4 - param_4,(uint)((uint)param_1[4] < param_3))))) {
      param_1[0x18] = -1;
      param_1[0x19] = -1;
      FUN_030c756e(param_1[0x22],param_1[0x1b]);
      FUN_030c3eec(param_1[0x23]);
      if (*param_1 != -1) {
        (*(code *)param_1[0x25])(*param_1,(code *)param_1[0x25],param_3,param_4);
        param_1[2] = param_3;
        param_1[3] = param_4;
        FUN_030c6c66(param_1[6]);
      }
      iVar4 = 0;
      iStack_c8 = param_1[0x1b];
      uVar7 = 0;
      uStack_c4 = 0xffffffff;
LAB_030cc0fe:
      while ((2 < param_1[0x1a] && (iVar1 = FUN_030c775e(auStack_e0,&local_90), 0 < iVar1))) {
        if (param_1[0x13] == 0) {
          FUN_030c775e(param_1[0x22],0);
          break;
        }
        iVar1 = FUN_030c415a(param_1 + 0xc,&local_90);
        if (iVar1 < 0) {
          FUN_030c775e(param_1[0x22],0);
          iVar1 = 0;
        }
        else if (param_3 == 0) {
          if (iVar4 != 0) {
            uVar7 = uVar7 + (iVar4 + iVar1 >> 2);
          }
        }
        else {
          FUN_030c775e(param_1[0x22],0);
        }
        iVar4 = iVar1;
        if (local_80 != 0xffffffff || local_7c != -1) {
          iVar4 = param_1[0x1c];
          puVar2 = (uint *)(param_1[0xb] + iVar4 * 0x10);
          uVar5 = *puVar2;
          uVar3 = (local_7c - puVar2[1]) - (uint)(local_80 < uVar5);
          uVar5 = local_80 - uVar5;
          if ((int)uVar3 < 0) {
            uVar3 = 0;
            uVar5 = uVar3;
          }
          if (0 < iVar4) {
            puVar2 = (uint *)(param_1[0xb] + 8);
            do {
              bVar9 = CARRY4(*puVar2,uVar5);
              uVar5 = *puVar2 + uVar5;
              uVar3 = puVar2[1] + uVar3 + bVar9;
              puVar2 = puVar2 + 4;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_1[0x18] = uVar5 - uVar7;
          param_1[0x19] = (uVar3 - ((int)uVar7 >> 0x1f)) - (uint)(uVar5 < uVar7);
LAB_030cc1d2:
          FUN_030c75ac(&local_90);
          FUN_030c6e1e(&local_68);
          FUN_030c713c(auStack_e0);
          param_1[0x1e] = 0;
          param_1[0x1f] = 0;
          param_1[0x20] = 0;
          param_1[0x21] = 0;
          return 0;
        }
      }
      if (iVar4 == 0) {
        FUN_030cb504(param_1,&local_68,0xffffffff,0xffffffff);
        if (-1 < extraout_r1) {
          if (param_1[0x1a] < 3) {
LAB_030cc230:
            iVar1 = FUN_030c6bc2(&local_68);
            param_1[0x1b] = iVar1;
            uVar3 = param_1[7];
            uVar5 = 0;
            if ((int)uVar3 < 1) {
              uVar8 = 0;
            }
            else {
              uVar8 = uVar3 & 1;
              if (uVar8 != 0) {
                do {
                  if (*(int *)(param_1[10] + uVar5 * 4) == iVar1) goto LAB_030cc2a2;
                  uVar5 = uVar5 + 1;
                } while ((int)uVar5 < (int)uVar8);
              }
            }
            uVar5 = uVar8;
            if ((int)uVar5 < (int)uVar3) {
              do {
                if (*(int *)(param_1[10] + uVar5 * 4) == iVar1) break;
                if (*(int *)(param_1[10] + uVar5 * 4 + 4) == iVar1) {
                  uVar5 = uVar5 + 1;
                  break;
                }
                uVar5 = uVar5 + 2;
              } while ((int)uVar5 < (int)uVar3);
            }
LAB_030cc2a2:
            if (uVar3 == uVar5) {
LAB_030cc2b6:
              FUN_030c75ac(&local_90);
              FUN_030c6e1e(&local_68);
              param_1[0x18] = -1;
              param_1[0x19] = -1;
              FUN_030c713c(auStack_e0);
              if (param_1[0x1a] == 5) {
                UdpRecive(param_1[0x23]);
                param_1[0x1a] = 3;
                param_1[0x23] = 0;
              }
              else if (param_1[0x1a] < 3) {
                return 0xffffff77;
              }
              FUN_030c7b12(param_1 + 0xc);
              FUN_030c7ab4(param_1 + 0x14);
              param_1[0x1a] = 2;
              return 0xffffff77;
            }
            uVar3 = param_1[2];
            iVar6 = param_1[3];
            iVar1 = FUN_030cbb76(param_1,uVar5);
            if (iVar1 != 0) goto LAB_030cc2b6;
            if (*param_1 != -1) {
              (*(code *)param_1[0x25])(*param_1,(code *)param_1[0x25],uVar3,iVar6);
              param_1[3] = iVar6;
              param_1[2] = uVar3;
              FUN_030c6c66(param_1[6]);
            }
            puVar2 = (uint *)(param_1[8] + uVar5 * 8);
            uVar8 = puVar2[1];
            bVar9 = uVar3 < *puVar2;
            if (((int)((iVar6 - uVar8) - (uint)bVar9) < 0 !=
                 (SBORROW4(iVar6,uVar8) != SBORROW4(iVar6 - uVar8,(uint)bVar9))) ||
               (puVar2 = (uint *)(uVar5 * 8 + 8 + param_1[8]), uVar5 = puVar2[1],
               bVar9 = uVar3 < *puVar2,
               (int)((iVar6 - uVar5) - (uint)bVar9) < 0 ==
               (SBORROW4(iVar6,uVar5) != SBORROW4(iVar6 - uVar5,(uint)bVar9)))) {
              param_1[0x1a] = 3;
            }
            FUN_030c756e(param_1[0x22],param_1[0x1b]);
            FUN_030c756e(auStack_e0,param_1[0x1b]);
          }
          else {
            iVar1 = FUN_030c6bc2(&local_68);
            if (iVar1 != param_1[0x1b]) {
              if (param_1[0x1a] == 5) {
                UdpRecive(param_1[0x23]);
                param_1[0x1a] = 3;
                param_1[0x23] = 0;
LAB_030cc210:
                FUN_030c7b12(param_1 + 0xc);
                FUN_030c7ab4(param_1 + 0x14);
                param_1[0x1a] = 2;
              }
              else if (2 < param_1[0x1a]) goto LAB_030cc210;
              FUN_030c713c(auStack_e0);
            }
            if (param_1[0x1a] < 3) goto LAB_030cc230;
          }
          FUN_030c7766(auStack_38,&local_68);
          param_3 = FUN_030c6b74(&local_68);
          FUN_030c7400(param_1[0x22],&local_68);
          FUN_030c7400(auStack_e0,auStack_38);
          goto LAB_030cc0fe;
        }
        uVar10 = FUN_030cbfda(param_1,0xffffffff);
      }
      else {
        uVar10 = 0xffffffffffffffff;
      }
      *(undefined8 *)(param_1 + 0x18) = uVar10;
      goto LAB_030cc1d2;
    }
  }
  return 0xffffff7d;
}


