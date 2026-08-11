/**
 * FUN_030cca40 @ 0x030cca40
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030cca40(int *param_1,undefined4 param_2,uint param_3,int param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  undefined4 uVar12;
  uint *puVar13;
  uint *puVar14;
  int extraout_r1;
  int extraout_r1_00;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  bool bVar19;
  longlong lVar20;
  ulonglong uVar21;
  longlong lVar22;
  longlong lVar23;
  longlong lVar24;
  ulonglong uVar25;
  undefined8 uVar26;
  int local_bc;
  uint uStack_b8;
  int iStack_a4;
  int iStack_9c;
  uint uStack_98;
  int iStack_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  uint local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  int iStack_58;
  int iStack_54;
  uint uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int *piStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  int iStack_2c;
  
  piStack_38 = param_1;
  uStack_34 = param_2;
  uStack_30 = param_3;
  iStack_2c = param_4;
  lVar20 = FUN_030cbfda(param_1,0xffffffff);
  iVar7 = (int)((ulonglong)lVar20 >> 0x20);
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  if (param_1[0x1a] < 2) {
    return 0xffffff7d;
  }
  if (param_1[1] == 0) {
    return 0xffffff76;
  }
  if (iStack_2c < 0) {
    return 0xffffff7d;
  }
  bVar19 = (uint)lVar20 < uStack_30;
  if ((int)((iVar7 - iStack_2c) - (uint)bVar19) < 0 !=
      (SBORROW4(iVar7,iStack_2c) != SBORROW4(iVar7 - iStack_2c,(uint)bVar19))) {
    return 0xffffff7d;
  }
  uVar15 = param_1[7] - 1;
  lVar2 = lVar20;
  if (-1 < (int)uVar15) {
    do {
      plVar6 = (longlong *)(uVar15 * 0x10 + 8 + param_1[0xb]);
      lVar24 = lVar20 - *plVar6;
      iVar7 = (int)((ulonglong)lVar24 >> 0x20);
      lVar22 = lVar20 - *plVar6;
      lVar2 = lVar20 - *plVar6;
      lVar20 = lVar20 - *plVar6;
      bVar19 = uStack_30 < (uint)lVar24;
      if ((int)((iStack_2c - iVar7) - (uint)bVar19) < 0 ==
          (SBORROW4(iStack_2c,iVar7) != SBORROW4(iStack_2c - iVar7,(uint)bVar19))) break;
      uVar15 = uVar15 - 1;
      lVar2 = lVar22;
    } while (uVar15 < 0x80000000);
  }
  local_bc = (int)((ulonglong)lVar2 >> 0x20);
  uStack_b8 = (uint)lVar2;
  if (param_1[0x1c] == uVar15) {
    FUN_030c3eec(param_1[0x23]);
  }
  else {
    uVar21 = FUN_030cbb76(param_1,uVar15);
    uVar25 = uVar21 & 0xffffffff00000000;
    if ((int)uVar21 != 0) goto LAB_030ccea8;
  }
  FUN_030c756e(param_1[0x22],*(undefined4 *)(param_1[10] + uVar15 * 4));
  puVar13 = (uint *)(uVar15 * 8 + 8 + param_1[8]);
  puVar8 = (uint *)(param_1[8] + uVar15 * 8);
  uVar16 = puVar13[1];
  lVar20 = *(longlong *)puVar13;
  uVar17 = *puVar8;
  uVar18 = puVar8[1];
  lVar4 = *(longlong *)puVar8;
  puVar14 = (uint *)(param_1[0xb] + uVar15 * 0x10);
  uVar9 = *puVar14;
  lVar24 = *(longlong *)puVar14;
  puVar10 = (uint *)(uVar15 * 0x10 + 8 + param_1[0xb]);
  uVar15 = *puVar10;
  lVar22 = CONCAT44(puVar14[1] + puVar10[1] + (uint)CARRY4(uVar15,uVar9),uVar15 + uVar9);
  uStack_50 = (uStack_30 - uStack_b8) + uVar9;
  iStack_54 = puVar14[1] + ((iStack_2c - local_bc) - (uint)(uStack_30 < uStack_b8)) +
              (uint)CARRY4(uStack_30 - uStack_b8,uVar9);
  lVar1 = *(longlong *)puVar8;
  if ((int)((uVar18 - uVar16) - (uint)(uVar17 < *puVar13)) < 0 !=
      (SBORROW4(uVar18,uVar16) != SBORROW4(uVar18 - uVar16,(uint)(uVar17 < *puVar13)))) {
    do {
      iStack_8c = (int)((ulonglong)lVar1 >> 0x20);
      iStack_58 = (int)lVar1;
      uStack_4c = (undefined4)((ulonglong)lVar22 >> 0x20);
      uStack_48 = (undefined4)lVar22;
      iStack_a4 = (int)((ulonglong)lVar24 >> 0x20);
      uStack_98 = (uint)lVar24;
      iVar7 = (int)((ulonglong)lVar20 >> 0x20);
      lVar1 = CONCAT44(uVar18,uVar17);
      lVar4 = lVar20 - lVar1;
      if ((int)(uint)((uint)lVar4 < 0x400) <= (int)((ulonglong)lVar4 >> 0x20)) {
        lVar4 = lVar4 * CONCAT44((iStack_54 - iStack_a4) - (uint)(uStack_50 < uStack_98),
                                 uStack_50 - uStack_98);
        lVar22 = FUN_030c0ef0((int)lVar4,(int)((ulonglong)lVar4 >> 0x20),(int)(lVar22 - lVar24),
                              (int)((ulonglong)(lVar22 - lVar24) >> 0x20));
        lVar1 = lVar22 + lVar1 + -0x400;
        iVar11 = (int)((ulonglong)lVar1 >> 0x20);
        bVar19 = uVar17 < (uint)lVar1;
        lVar22 = CONCAT44(uStack_4c,uStack_48);
        if ((int)((uVar18 - iVar11) - (uint)bVar19) < 0 ==
            (SBORROW4(uVar18,iVar11) != SBORROW4(uVar18 - iVar11,(uint)bVar19))) {
          lVar1 = CONCAT44(uVar18 + (0xfffffffe < uVar17),uVar17 + 1);
          lVar22 = CONCAT44(uStack_4c,uStack_48);
        }
      }
      uStack_4c = (undefined4)((ulonglong)lVar22 >> 0x20);
      uStack_48 = (undefined4)lVar22;
      iStack_9c = (int)((ulonglong)lVar1 >> 0x20);
      if (*param_1 != -1) {
        (*(code *)param_1[0x25])(*param_1,(code *)param_1[0x25],(int)lVar1,iStack_9c);
        *(longlong *)(param_1 + 2) = lVar1;
        FUN_030c6c66(param_1[6]);
        lVar22 = CONCAT44(uStack_4c,uStack_48);
      }
      lVar4 = CONCAT44(iStack_8c,iStack_58);
      bVar19 = uVar17 < (uint)lVar20;
      lVar5 = lVar24;
      if ((int)((uVar18 - iVar7) - (uint)bVar19) < 0 !=
          (SBORROW4(uVar18,iVar7) != SBORROW4(uVar18 - iVar7,(uint)bVar19))) {
        do {
          uStack_4c = (undefined4)((ulonglong)lVar22 >> 0x20);
          uStack_48 = (undefined4)lVar22;
          iStack_8c = (int)((ulonglong)lVar4 >> 0x20);
          iStack_58 = (int)lVar4;
          lVar3 = CONCAT44(uVar18,uVar17);
          iStack_9c = (int)((ulonglong)lVar1 >> 0x20);
          uVar15 = (uint)lVar1;
          lVar23 = FUN_030cb504(param_1,&local_88,(int)(lVar20 - *(longlong *)(param_1 + 2)),
                                (int)((ulonglong)(lVar20 - *(longlong *)(param_1 + 2)) >> 0x20));
          lVar4 = CONCAT44(iStack_8c,iStack_58);
          lVar22 = CONCAT44(iStack_8c,iStack_58);
          uVar25 = CONCAT44(0xffffff80,(int)lVar23);
          if (lVar23 == -0x80) goto LAB_030ccea8;
          if (lVar23 < 0) {
            uVar9 = uVar17 + 1;
            uVar25 = CONCAT44(uVar9,(int)lVar23);
            iVar7 = uVar18 + (0xfffffffe < uVar17);
            if ((int)((iVar7 - iStack_9c) - (uint)(uVar9 < uVar15)) < 0 !=
                (SBORROW4(iVar7,iStack_9c) != SBORROW4(iVar7 - iStack_9c,(uint)(uVar9 < uVar15)))) {
              if (lVar1 == 0) goto LAB_030ccea8;
              lVar1 = lVar1 + -0x400;
              iVar11 = (int)((ulonglong)lVar1 >> 0x20);
              bVar19 = uVar17 < (uint)lVar1;
              if ((int)((uVar18 - iVar11) - (uint)bVar19) < 0 ==
                  (SBORROW4(uVar18,iVar11) != SBORROW4(uVar18 - iVar11,(uint)bVar19))) {
                lVar1 = CONCAT44(iVar7,uVar9);
              }
              iVar7 = *param_1;
joined_r0x030ccd9c:
              lVar3 = lVar20;
              lVar4 = lVar22;
              if (iVar7 != -1) {
                iStack_9c = (int)((ulonglong)lVar1 >> 0x20);
                (*(code *)param_1[0x25])(iVar7,(code *)param_1[0x25],(int)lVar1,iStack_9c);
                *(longlong *)(param_1 + 2) = lVar1;
                FUN_030c6c66(param_1[6]);
                lVar4 = CONCAT44(iStack_8c,iStack_58);
              }
            }
          }
          else {
            lVar24 = FUN_030c6b9c(&local_88);
            lVar4 = CONCAT44(iStack_8c,iStack_58);
            lVar22 = CONCAT44(uStack_4c,uStack_48);
            iVar7 = (int)((ulonglong)lVar24 >> 0x20);
            uVar9 = (uint)lVar24;
            lVar3 = lVar20;
            if (lVar24 != -1) {
              if ((int)((iVar7 - iStack_54) - (uint)(uVar9 < uStack_50)) < 0 ==
                  (SBORROW4(iVar7,iStack_54) !=
                  SBORROW4(iVar7 - iStack_54,(uint)(uVar9 < uStack_50)))) {
                uVar9 = uVar17 + 1;
                iVar7 = uVar18 + (0xfffffffe < uVar17);
                lVar3 = CONCAT44(uVar18,uVar17);
                if ((int)((iVar7 - iStack_9c) - (uint)(uVar9 < uVar15)) < 0 !=
                    (SBORROW4(iVar7,iStack_9c) != SBORROW4(iVar7 - iStack_9c,(uint)(uVar9 < uVar15))
                    )) {
                  bVar19 = lVar20 == *(longlong *)(param_1 + 2);
                  lVar20 = lVar23;
                  lVar22 = lVar24;
                  lVar24 = lVar5;
                  if (bVar19) {
                    lVar1 = lVar1 + -0x400;
                    iVar11 = (int)((ulonglong)lVar1 >> 0x20);
                    bVar19 = uVar17 < (uint)lVar1;
                    if ((int)((uVar18 - iVar11) - (uint)bVar19) < 0 ==
                        (SBORROW4(uVar18,iVar11) != SBORROW4(uVar18 - iVar11,(uint)bVar19))) {
                      lVar1 = CONCAT44(iVar7,uVar9);
                    }
                    iVar7 = *param_1;
                    lVar22 = lVar4;
                    goto joined_r0x030ccd9c;
                  }
                  break;
                }
              }
              else {
                uVar17 = param_1[2];
                uVar18 = param_1[3];
                lVar1 = *(longlong *)(param_1 + 2);
                iVar7 = (iStack_54 - iVar7) - (uint)(uStack_50 < uVar9);
                bVar19 = 0xac44 < uStack_50 - uVar9;
                lVar4 = lVar23;
                lVar5 = lVar24;
                if ((int)(-(uint)bVar19 - iVar7) < 0 !=
                    (SBORROW4(0,iVar7) != SBORROW4(-iVar7,(uint)bVar19))) break;
              }
            }
          }
          lVar22 = CONCAT44(uStack_4c,uStack_48);
          iVar7 = (int)((ulonglong)lVar3 >> 0x20);
          bVar19 = uVar17 < (uint)lVar3;
          lVar20 = lVar3;
          lVar24 = lVar5;
        } while ((int)((uVar18 - iVar7) - (uint)bVar19) < 0 !=
                 (SBORROW4(uVar18,iVar7) != SBORROW4(uVar18 - iVar7,(uint)bVar19)));
      }
      iVar7 = (int)((ulonglong)lVar20 >> 0x20);
      bVar19 = uVar17 < (uint)lVar20;
      lVar1 = lVar4;
    } while ((int)((uVar18 - iVar7) - (uint)bVar19) < 0 !=
             (SBORROW4(uVar18,iVar7) != SBORROW4(uVar18 - iVar7,(uint)bVar19)));
  }
  iStack_8c = (int)((ulonglong)lVar4 >> 0x20);
  iStack_58 = (int)lVar4;
  uStack_4c = (undefined4)((ulonglong)lVar22 >> 0x20);
  uStack_48 = (undefined4)lVar22;
  if (*param_1 != -1) {
    (*(code *)param_1[0x25])(*param_1,(code *)param_1[0x25],iStack_58,iStack_8c);
    *(longlong *)(param_1 + 2) = lVar4;
    FUN_030c6c66(param_1[6]);
    lVar22 = CONCAT44(uStack_4c,uStack_48);
  }
  uStack_4c = (undefined4)((ulonglong)lVar22 >> 0x20);
  uStack_48 = (undefined4)lVar22;
  param_1[0x18] = -1;
  param_1[0x19] = -1;
  FUN_030cb504(param_1,&local_88,0xffffffff,0xffffffff);
  if (extraout_r1 < 0) {
    FUN_030c6e1e(&local_88);
    return 0xfffffffe;
  }
  FUN_030c7400(param_1[0x22],&local_88);
  while( true ) {
    iVar11 = FUN_030c7762(param_1[0x22],&local_78);
    iVar7 = iStack_58;
    if (iVar11 == 0) break;
    if (iVar11 >> 0x1f < 0) {
      uVar25 = CONCAT44(iVar11 >> 0x1f,0xffffff78);
      goto LAB_030ccea8;
    }
    if (local_68 != 0xffffffff || local_64 != -1) {
      puVar8 = (uint *)(param_1[0xb] + param_1[0x1c] * 0x10);
      uVar15 = *puVar8;
      iVar7 = local_68 - uVar15;
      iVar11 = (local_64 - puVar8[1]) - (uint)(local_68 < uVar15);
      param_1[0x18] = iVar7;
      param_1[0x19] = iVar11;
      if ((int)(-(uint)(iVar7 != 0) - iVar11) < 0 ==
          (SBORROW4(0,iVar11) != SBORROW4(-iVar11,(uint)(iVar7 != 0)))) {
        iVar11 = 0;
        iVar7 = iVar11;
      }
      lVar2 = lVar2 + CONCAT44(iVar11,iVar7);
      uVar15 = (uint)lVar2;
      iVar7 = (int)((ulonglong)lVar2 >> 0x20);
      *(longlong *)(param_1 + 0x18) = lVar2;
      iVar11 = uStack_30 - uVar15;
      if ((int)((iStack_2c - iVar7) - (uint)(uStack_30 < uVar15)) < 0 ==
          (SBORROW4(iStack_2c,iVar7) != SBORROW4(iStack_2c - iVar7,(uint)(uStack_30 < uVar15)))) {
        uVar26 = FUN_030cbfda(param_1,0xffffffff);
        iVar11 = (int)((ulonglong)uVar26 >> 0x20);
        bVar19 = (uint)uVar26 < uStack_30;
        if ((int)((iVar11 - iStack_2c) - (uint)bVar19) < 0 ==
            (SBORROW4(iVar11,iStack_2c) != SBORROW4(iVar11 - iStack_2c,(uint)bVar19))) {
          param_1[0x1e] = 0;
          param_1[0x1f] = 0;
          param_1[0x20] = 0;
          param_1[0x21] = 0;
          FUN_030c6e1e(&local_88);
          FUN_030c75ac(&local_78);
          return 0;
        }
      }
      uVar25 = CONCAT44(iVar11,0xffffff7f);
      goto LAB_030ccea8;
    }
    FUN_030c775e(param_1[0x22],0);
  }
  if (*param_1 != -1) {
    (*(code *)param_1[0x25])(*param_1,(code *)param_1[0x25],iStack_58,iStack_8c);
    param_1[2] = iVar7;
    param_1[3] = iStack_8c;
    FUN_030c6c66(param_1[6]);
  }
  while( true ) {
    uVar25 = FUN_030cb73a(param_1,&local_88);
    if ((longlong)uVar25 < 0) break;
    FUN_030c6b9c(&local_88);
    iVar7 = extraout_r1_00;
    if (-1 < extraout_r1_00) {
LAB_030cce24:
      uVar12 = FUN_030cc030(param_1,iVar7,(int)uVar25,(int)(uVar25 >> 0x20));
      return uVar12;
    }
    uVar26 = FUN_030c6b24(&local_88);
    iVar7 = (int)((ulonglong)uVar26 >> 0x20);
    if ((int)uVar26 == 0) goto LAB_030cce24;
    *(ulonglong *)(param_1 + 2) = uVar25;
  }
LAB_030ccea8:
  FUN_030c6e1e(&local_88,(int)(uVar25 >> 0x20));
  FUN_030c75ac(&local_78);
  param_1[0x18] = -1;
  param_1[0x19] = -1;
  if (param_1[0x1a] == 5) {
    UdpRecive(param_1[0x23]);
    param_1[0x23] = 0;
    param_1[0x1a] = 3;
  }
  else if (param_1[0x1a] < 3) {
    return (int)uVar25;
  }
  FUN_030c7b12(param_1 + 0xc);
  FUN_030c7ab4(param_1 + 0x14);
  param_1[0x1a] = 2;
  return (int)uVar25;
}


