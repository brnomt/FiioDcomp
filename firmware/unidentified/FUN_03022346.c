/**
 * FUN_03022346 @ 0x03022346
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined1 * FUN_03022346(char param_1,uint param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  undefined1 auStack_274 [2];
  ushort uStack_272;
  uint uStack_13c;
  ushort uStack_130;
  ushort uStack_12e;
  uint uStack_12c;
  uint uStack_128;
  uint uStack_124;
  uint auStack_120 [32];
  undefined1 auStack_a0 [64];
  undefined1 auStack_60 [32];
  undefined4 uStack_40;
  ushort auStack_3c [2];
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  
  iVar3 = (int)param_1;
  uStack_30 = 0;
  uStack_2c = FUN_02ffce6c();
  pcVar2 = DAT_030225e4;
  if (((uStack_2c <= param_2) ||
      (iVar4 = FUN_02ffcece(*(int *)(DAT_030225e4 + 4) + *(int *)(DAT_030225e4 + 0x10) + param_2 +
                            -2,0,iVar3), iVar4 != 0)) ||
     (uVar5 = FUN_02ffc9d6(auStack_3c,2,iVar3), uVar5 < 2)) {
    return (undefined1 *)0x0;
  }
  if (*pcVar2 != '\x01') {
    auStack_3c[0] = auStack_3c[0] << 8 | auStack_3c[0] >> 8;
  }
  uStack_34 = FUN_02ffce8c(iVar3);
  if (param_3 == 1) {
    iVar4 = FUN_02ffcece((uint)auStack_3c[0] * 0xc + *(int *)(pcVar2 + 4) + *(int *)(pcVar2 + 0x10)
                         + 8,0,iVar3);
    if (iVar4 != 0) {
      return (undefined1 *)0x0;
    }
    uVar5 = FUN_02ffc9d6(&uStack_30,4,iVar3);
    if (uVar5 < 4) {
      return (undefined1 *)0x0;
    }
    if (*pcVar2 != '\x01') {
      uStack_30 = uStack_30 << 0x18 | (uStack_30 >> 8 & 0xff) << 0x10 |
                  (uStack_30 >> 0x10 & 0xff) << 8 | uStack_30 >> 0x18;
    }
    FUN_02ffcece(uStack_34,0,iVar3);
  }
  FUN_02ff895c(auStack_274,0x144);
  auStack_274[0] = (undefined1)param_3;
  uStack_272 = auStack_3c[0];
  iVar4 = 0;
  uStack_13c = uStack_30;
  if (auStack_3c[0] != 0) {
    do {
      if (uStack_2c <= uStack_34) {
        return (undefined1 *)0x0;
      }
      iVar6 = FUN_02ffcece(uStack_34,0,iVar3);
      if (iVar6 != 0) {
        return (undefined1 *)0x0;
      }
      uVar5 = FUN_02ffc9d6(&uStack_130,0xc,iVar3);
      if (uVar5 < 0xc) {
        return (undefined1 *)0x0;
      }
      uStack_38 = uStack_128;
      if (*pcVar2 != '\x01') {
        uStack_130 = uStack_130 << 8 | uStack_130 >> 8;
        uStack_12e = uStack_12e << 8 | uStack_12e >> 8;
        uStack_12c = uStack_12c << 0x18 | (uStack_12c >> 8 & 0xff) << 0x10 |
                     (uStack_12c >> 0x10 & 0xff) << 8 | uStack_12c >> 0x18;
        uStack_128 = uStack_128 << 0x18 | (uStack_128 >> 8 & 0xff) << 0x10 |
                     (uStack_128 >> 0x10 & 0xff) << 8 | uStack_128 >> 0x18;
      }
      if (uStack_130 == 0) {
        return (undefined1 *)0x0;
      }
      if (0x1f < uStack_12c) {
        uStack_12c = 0x1f;
      }
      uStack_34 = FUN_02ffce8c(iVar3);
      if (uStack_12e == 2 || uStack_12e == 7) {
        if (uStack_12c < 5) {
          FUN_03022206(auStack_274,uStack_130,uStack_12e,uStack_12c,0,&uStack_38,param_4);
        }
        else {
          if (0x40 < uStack_12c) {
            FUN_02ff895c(auStack_60,uStack_12c);
          }
          iVar6 = FUN_02ffcece(uStack_128 + *(int *)(pcVar2 + 4) + *(int *)(pcVar2 + 0x10) + -2,0,
                               iVar3);
          if ((iVar6 == 0) &&
             (uVar5 = FUN_02ffc9d6(auStack_60,uStack_12c,iVar3), uStack_12c <= uVar5)) {
            FUN_03022206(auStack_274,uStack_130,uStack_12e,uStack_12c,0,auStack_60,param_4);
          }
          else {
LAB_030226bc:
            FUN_03022206(auStack_274,uStack_130,uStack_12e,uStack_12c,0,0,param_4);
          }
        }
      }
      else if (uStack_12e == 5 || uStack_12e == 10) {
        iVar6 = uStack_12c * 2;
        uVar5 = uStack_12c * 8;
        if (((uVar5 < *(ushort *)(DAT_030225ec + 2)) &&
            (iVar7 = FUN_02ffcece(uStack_128 + *(int *)(pcVar2 + 4) + *(int *)(pcVar2 + 0x10) + -2,0
                                  ,iVar3), iVar7 == 0)) &&
           ((uVar8 = FUN_02ffc9d6(auStack_120,uVar5,iVar3), uVar5 <= uVar8 && (iVar7 = 0, 0 < iVar6)
            ))) {
          do {
            uVar5 = auStack_120[iVar7];
            auStack_120[iVar7] =
                 uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                 uVar5 >> 0x18;
            iVar7 = iVar7 + 1;
          } while (iVar6 - iVar7 != 0 && iVar7 <= iVar6);
        }
LAB_030225a2:
        FUN_03022206(auStack_274,uStack_130,uStack_12e,uStack_12c,auStack_120,0,param_4);
      }
      else if (((uStack_12e == 1 || uStack_12e == 3) || (uStack_12e == 4 || uStack_12e == 6)) ||
              (uStack_12e == 8 || uStack_12e == 9)) {
        if (1 < uStack_12c) {
          iVar6 = 4;
          if (uStack_12e == 1 || uStack_12e == 6) {
            iVar6 = 1;
          }
          else if (uStack_12e == 3 || uStack_12e == 8) {
            iVar6 = 2;
          }
          uVar5 = uStack_12c * iVar6;
          if (uVar5 < 5) {
            if (iVar6 == 1) {
              iVar6 = 0;
              if (0 < (int)uStack_12c) {
                do {
                  auStack_120[iVar6] = (uint)*(byte *)((int)&uStack_38 + iVar6);
                  iVar6 = iVar6 + 1;
                } while (iVar6 < (int)uStack_12c);
              }
            }
            else if (iVar6 == 2) {
              cVar1 = *pcVar2;
              iVar6 = 0;
              do {
                uVar9 = *(ushort *)((int)&uStack_38 + iVar6 * 2);
                if (cVar1 != '\x01') {
                  uVar9 = uVar9 << 8 | uVar9 >> 8;
                }
                uStack_40 = CONCAT22(uStack_40._2_2_,uVar9);
                auStack_120[iVar6] = (uint)uVar9;
                iVar6 = iVar6 + 1;
              } while (iVar6 < 2);
            }
          }
          else {
            iVar7 = FUN_02ffcece(uStack_128 + *(int *)(pcVar2 + 4) + *(int *)(pcVar2 + 0x10) + -2,0,
                                 iVar3);
            if ((iVar7 != 0) || (uVar8 = FUN_02ffc9d6(auStack_a0,uVar5,iVar3), uVar8 < uVar5))
            goto LAB_030226bc;
            iVar7 = 0;
            if (0 < (int)uStack_12c) {
              do {
                if (0x1f < iVar7 * iVar6) break;
                FUN_02ff890e(&uStack_124,auStack_a0 + iVar7 * iVar6,iVar6);
                if (iVar6 == 4) {
                  uStack_124 = uStack_124 << 0x18 | (uStack_124 >> 8 & 0xff) << 0x10 |
                               (uStack_124 >> 0x10 & 0xff) << 8 | uStack_124 >> 0x18;
                }
                else if ((iVar6 == 2) && (*pcVar2 != '\x01')) {
                  uStack_124 = (uStack_124 & 0xff) << 8 | (uStack_124 & 0xffff) >> 8;
                }
                auStack_120[iVar7] = uStack_124;
                iVar7 = iVar7 + 1;
              } while (iVar7 < (int)uStack_12c);
            }
          }
          goto LAB_030225a2;
        }
        uStack_124 = uStack_128;
        if (uStack_12e == 1 || uStack_12e == 6) {
          uStack_124 = uStack_38 & 0xff;
        }
        else if (uStack_12e == 3 || uStack_12e == 8) {
          uStack_40 = uStack_38;
          if (*pcVar2 != '\x01') {
            uStack_40._0_2_ = (ushort)uStack_38;
            uStack_40._2_2_ = (undefined2)(uStack_38 >> 0x10);
            uStack_40 = CONCAT22(uStack_40._2_2_,(ushort)uStack_40 << 8 | (ushort)uStack_40 >> 8);
          }
          uStack_124 = uStack_40 & 0xffff;
        }
        FUN_03022206(auStack_274,uStack_130,uStack_12e,uStack_12c,&uStack_124,0,param_4);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uint)auStack_3c[0]);
  }
  return auStack_274;
}


