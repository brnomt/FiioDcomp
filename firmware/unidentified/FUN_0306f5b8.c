/**
 * FUN_0306f5b8 @ 0x0306f5b8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0306f5b8(uint *param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  uint local_4c;
  uint local_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  
  pcVar5 = (char *)param_2[6];
  iVar7 = param_2[1];
  if (pcVar5 == (char *)0x0) {
    uVar1 = 2;
LAB_0306f7e2:
    *(undefined2 *)(param_2 + 0xf) = uVar1;
  }
  else {
    iVar2 = param_2[2];
    if (iVar2 == 0) goto LAB_0306f5fe;
    if (param_2[3] == 0) {
      pcVar5 = (char *)param_2[5];
    }
    if (iVar7 - (int)pcVar5 < iVar2) {
      param_2[6] = iVar7;
      param_2[2] = iVar2 - (iVar7 - (int)pcVar5);
      *(undefined2 *)(param_2 + 0xf) = 1;
    }
    else {
      pcVar5 = pcVar5 + iVar2;
      param_2[2] = 0;
      param_2[3] = 1;
LAB_0306f602:
      if (iVar7 - (int)pcVar5 < 8) {
        param_2[6] = pcVar5;
LAB_0306f672:
        *(undefined2 *)(param_2 + 0xf) = 1;
      }
      else {
        if ((*pcVar5 == -1) && ((~pcVar5[1] & 0xe0U) == 0)) {
          do {
            param_2[5] = pcVar5;
            param_2[6] = pcVar5 + 1;
            FUN_03070b64(param_2 + 7);
            uVar10 = FUN_0306f3e8(param_1,param_2);
            iVar2 = (int)((ulonglong)uVar10 >> 0x20);
            if ((int)uVar10 == -1) goto LAB_0306f676;
            if (param_1[3] == 0) {
              uVar3 = param_2[4];
              if (uVar3 != 0) {
                iVar2 = param_2[3];
              }
              if ((uVar3 == 0 || iVar2 == 0) || (((byte)*param_1 == 3 && (DAT_0306f77c < uVar3)))) {
                uVar8 = param_2[7];
                uVar9 = param_2[8];
                uVar3 = 0;
                iVar2 = (int)(param_1[6] << 0x18) >> 0x1f;
                if (((byte)*param_1 == 3) && ((param_1[6] & 0x1000) != 0)) {
                  local_4c = 0x48;
                }
                else {
                  local_4c = 0x90;
                }
                iVar6 = FUN_03070742(param_2);
                while (iVar6 == 0) {
                  local_90 = *param_2;
                  uStack_8c = param_2[1];
                  uStack_88 = param_2[2];
                  uStack_84 = param_2[3];
                  local_80 = param_2[4];
                  uStack_7c = param_2[5];
                  uStack_78 = param_2[6];
                  uStack_74 = param_2[7];
                  local_70 = param_2[8];
                  uStack_6c = param_2[9];
                  uStack_68 = param_2[10];
                  uStack_64 = param_2[0xb];
                  local_60 = param_2[0xc];
                  uStack_5c = param_2[0xd];
                  local_58 = param_2[0xe];
                  uStack_54 = param_2[0xf];
                  local_48 = *param_1;
                  uStack_44 = param_1[1];
                  uStack_40 = param_1[2];
                  uStack_3c = param_1[3];
                  local_38 = param_1[4];
                  uStack_34 = param_1[5];
                  uStack_30 = param_1[6];
                  uStack_2c = param_1[7];
                  iVar6 = FUN_0306f3e8(&local_48,&local_90);
                  if (((iVar6 == 0) && ((local_48 & 0xff) == (uint)(byte)*param_1)) &&
                     (local_38 == param_1[4])) {
                    iVar6 = FUN_03070b86(param_2 + 7);
                    if ((byte)*param_1 == 1) {
                      uVar3 = param_1[4] * ((iVar6 - param_2[5]) + iVar2 * 4 + 4);
                      uVar4 = 48000;
                    }
                    else {
                      uVar3 = (((iVar6 - param_2[5]) + iVar2 + 1) * param_1[4]) / local_4c;
                      uVar4 = 1000;
                    }
                    uVar3 = uVar3 / uVar4;
                    if (7 < uVar3) break;
                  }
                  FUN_03070b92(param_2 + 7,8);
                  iVar6 = FUN_03070742(param_2);
                }
                param_2[8] = uVar9;
                param_2[7] = uVar8;
                if ((uVar3 < 8) || (((byte)*param_1 == 3 && (0x280 < uVar3)))) {
                  uVar1 = 0x101;
                  goto LAB_0306f7e2;
                }
                param_2[4] = uVar3 * 1000;
              }
              param_1[3] = param_2[4];
              param_1[6] = param_1[6] | 0x400;
            }
            iVar2 = -((int)(param_1[6] << 0x18) >> 0x1f);
            if ((byte)*param_1 == 1) {
              iVar2 = (iVar2 + (param_1[3] * 0xc) / param_1[4]) * 4;
            }
            else {
              if (((byte)*param_1 == 3) && ((param_1[6] & 0x1000) != 0)) {
                iVar6 = 0x48;
              }
              else {
                iVar6 = 0x90;
              }
              iVar2 = (param_1[3] * iVar6) / param_1[4] + iVar2;
            }
            iVar6 = param_2[5];
            if (iVar7 - iVar6 < iVar2 + 8) {
              param_2[6] = iVar6;
              goto LAB_0306f672;
            }
            pcVar5 = (char *)(iVar2 + iVar6);
            param_2[6] = pcVar5;
            if (param_2[3] != 0) {
LAB_0306f854:
              param_1[6] = param_1[6] | 8;
              return 0;
            }
            if ((*pcVar5 == -1) && ((~pcVar5[1] & 0xe0U) == 0)) {
              param_2[3] = 1;
              goto LAB_0306f854;
            }
            pcVar5 = (char *)(iVar6 + 1);
            param_2[6] = pcVar5;
LAB_0306f5fe:
            if (param_2[3] != 0) goto LAB_0306f602;
            FUN_03070b64(param_2 + 7);
            iVar2 = FUN_03070742(param_2);
            if (iVar2 == -1) {
              if (7 < iVar7 - param_2[6]) {
                param_2[6] = iVar7 + -8;
              }
              goto LAB_0306f672;
            }
            pcVar5 = (char *)FUN_03070b86(param_2 + 7);
          } while( true );
        }
        param_2[5] = pcVar5;
        param_2[6] = pcVar5 + 1;
        *(undefined2 *)(param_2 + 0xf) = 0x101;
      }
    }
  }
LAB_0306f676:
  param_2[3] = 0;
  return 0xffffffff;
}


