/**
 * FUN_030a5844 @ 0x030a5844
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030a5844(byte *param_1,uint *param_2,undefined4 param_3,code *param_4)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char extraout_r1;
  int *piVar6;
  uint uVar7;
  char *pcVar8;
  undefined1 uVar9;
  uint *puVar10;
  int extraout_r2;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  byte *pbVar15;
  char *pcVar16;
  byte *pbVar17;
  uint *puVar18;
  char **unaff_r10;
  uint uVar19;
  undefined4 *puVar20;
  bool bVar21;
  bool bVar22;
  bool bVar23;
  longlong lVar24;
  char *local_88;
  undefined4 local_84;
  char **local_80;
  char *local_7c;
  char **local_78;
  uint local_74;
  undefined1 auStack_70 [32];
  char *local_50;
  char **local_4c;
  char *pcStack_48;
  int local_44;
  byte local_3b [3];
  char *local_38;
  byte *pbStack_34;
  uint *puStack_30;
  undefined4 local_2c;
  code *pcStack_28;
  
  pcStack_28 = param_4;
  local_2c = param_3;
  puStack_30 = param_2;
  pbStack_34 = param_1;
  iVar14 = 0;
LAB_030a5c7a:
  uVar4 = (uint)*param_1;
  if (uVar4 == 0) {
    return iVar14;
  }
  if (uVar4 == 0x25) {
    uVar13 = 0;
    pcVar16 = (char *)0x0;
    local_74 = 0;
    while( true ) {
      pbVar15 = param_1 + 1;
      uVar4 = 1 << (*pbVar15 - 0x20 & 0xff);
      if ((uVar4 & DAT_030a5c44) == 0) break;
      uVar13 = uVar13 | uVar4;
      param_1 = pbVar15;
    }
    if (*pbVar15 == 0x2a) {
      puVar10 = param_2 + 1;
      local_74 = *param_2;
      if ((int)local_74 < 0) {
        uVar13 = uVar13 | 0x2000;
        local_74 = -local_74;
      }
      uVar13 = uVar13 | 2;
      pbVar15 = param_1 + 2;
    }
    else {
      for (; puVar10 = param_2, *pbVar15 - 0x30 < 10; pbVar15 = pbVar15 + 1) {
        uVar13 = uVar13 | 2;
        local_74 = (uint)*pbVar15 + local_74 * 10 + -0x30;
      }
    }
    param_1 = pbVar15;
    puVar18 = puVar10;
    if (*pbVar15 == 0x2e) {
      param_1 = pbVar15 + 1;
      uVar13 = uVar13 | 4;
      if (*param_1 == 0x2a) {
        puVar18 = puVar10 + 1;
        pcVar16 = (char *)*puVar10;
        param_1 = pbVar15 + 2;
      }
      else {
        for (; *param_1 - 0x30 < 10; param_1 = param_1 + 1) {
          pcVar16 = (char *)((uint)*param_1 + (int)pcVar16 * 10 + -0x30);
        }
      }
    }
    bVar1 = *param_1;
    if (bVar1 == 0x6c) {
      uVar13 = uVar13 | 0x100000;
LAB_030a591c:
      if (param_1[1] == bVar1) {
        param_1 = param_1 + 1;
        uVar13 = uVar13 + 0x100000;
      }
    }
    else if (bVar1 < 0x6d) {
      if (bVar1 != 0x4c) {
        if (bVar1 == 0x68) {
          uVar13 = uVar13 | 0x300000;
          goto LAB_030a591c;
        }
        if (bVar1 != 0x6a) goto LAB_030a592a;
        uVar13 = uVar13 | 0x200000;
      }
    }
    else if ((bVar1 != 0x74) && (bVar1 != 0x7a)) goto LAB_030a592a;
    param_1 = param_1 + 1;
LAB_030a592a:
    uVar4 = (uint)*param_1;
    bVar23 = SBORROW4(uVar4,0x66);
    bVar21 = (int)(uVar4 - 0x66) < 0;
    bVar22 = uVar4 == 0x66;
LAB_030a592e:
    while (!bVar22) {
      param_2 = puVar18;
      if (bVar21 == bVar23) {
        if (uVar4 == 0x70) {
          uVar13 = uVar13 | 4;
          pcVar16 = &NMI;
          local_88 = (char *)0x10;
        }
        else if (uVar4 < 0x71) {
          if (uVar4 == 0x67) break;
          if (uVar4 == 0x69) goto LAB_030a5a48;
          if (uVar4 == 0x6e) {
            uVar4 = (uVar13 & 0x7fffff) >> 0x14;
            if (uVar4 == 2) {
              piVar6 = (int *)*puVar18;
              *piVar6 = iVar14;
              piVar6[1] = iVar14 >> 0x1f;
            }
            else if (uVar4 == 3) {
              *(short *)*puVar18 = (short)iVar14;
            }
            else if (uVar4 == 4) {
              *(char *)*puVar18 = (char)iVar14;
            }
            else {
              *(int *)*puVar18 = iVar14;
            }
            param_2 = puVar18 + 1;
            goto LAB_030a5c76;
          }
          if (uVar4 != 0x6f) goto LAB_030a597e;
          local_88 = (char *)0x8;
        }
        else {
          if (uVar4 == 0x73) {
            unaff_r10 = (char **)*puVar18;
            iVar5 = -1;
            goto LAB_030a59d8;
          }
          if (uVar4 == 0x75) {
            local_88 = (char *)0xa;
          }
          else {
            if (uVar4 != 0x78) goto LAB_030a597e;
            local_88 = (char *)0x10;
          }
        }
LAB_030a5ae6:
        uVar12 = (uVar13 & 0x7fffff) >> 0x14;
        if (uVar12 == 2) {
          puVar10 = (uint *)((uint)((int)puVar18 + 7) & 0xfffffff8);
          param_2 = puVar10 + 2;
          uVar19 = *puVar10;
          uVar7 = puVar10[1];
        }
        else {
          param_2 = puVar18 + 1;
          uVar19 = *puVar18;
          uVar7 = 0;
          if (uVar12 == 3) {
            uVar19 = uVar19 & 0xffff;
          }
          if (uVar12 == 4) {
            uVar19 = uVar19 & 0xff;
          }
        }
        iVar5 = 0;
        if ((int)(uVar13 << 0x1c) < 0) {
          if (uVar4 == 0x70) {
            local_84 = (char *)CONCAT31(local_84._1_3_,0x40);
            iVar5 = 1;
          }
          else if ((local_88 == (char *)0x10) && (uVar19 != 0 || uVar7 != 0)) {
            local_84._0_2_ = CONCAT11(*param_1,0x30);
            iVar5 = 2;
          }
          if ((local_88 == (char *)0x8) &&
             ((uVar19 != 0 || uVar7 != 0 || ((int)(uVar13 << 0x1d) < 0)))) {
            local_84 = (char *)CONCAT31(local_84._1_3_,0x30);
            iVar5 = 1;
            pcVar16 = pcVar16 + -1;
          }
        }
LAB_030a5b64:
        lVar24 = CONCAT44(uVar7,uVar19);
        if (uVar4 == 0x58) {
          local_7c = s_0123456789ABCDEF_030a5c5c;
        }
        else {
          local_7c = s_0123456789abcdef_030a5c48;
        }
        local_80 = &local_50;
        while( true ) {
          if (lVar24 == 0) break;
          lVar24 = FUN_0309f72e((int)lVar24,(int)((ulonglong)lVar24 >> 0x20),local_88,0);
          local_80 = (char **)((int)local_80 + -1);
          *(char *)local_80 = local_7c[extraout_r2];
        }
        pcVar8 = (char *)((int)&local_50 - (int)local_80);
        if ((int)(uVar13 << 0x1d) < 0) {
          uVar13 = uVar13 & 0xfffeffff;
        }
        else {
          pcVar16 = (char *)0x1;
        }
        if ((int)pcVar8 < (int)pcVar16) {
          local_88 = pcVar16 + -(int)pcVar8;
        }
        else {
          local_88 = (char *)0x0;
        }
        local_74 = local_74 - (int)(pcVar8 + (int)(local_88 + iVar5));
        if (-1 < (int)(uVar13 << 0xf)) {
          iVar3 = FUN_030a5f5a(local_74,uVar13,local_2c,param_4);
          iVar14 = iVar14 + iVar3;
        }
        for (iVar3 = 0; iVar3 < iVar5; iVar3 = iVar3 + 1) {
          (*param_4)(*(undefined1 *)((int)&local_84 + iVar3),local_2c);
          iVar14 = iVar14 + 1;
        }
        if ((int)(uVar13 << 0xf) < 0) {
          iVar5 = FUN_030a5f5a(local_74,uVar13,local_2c,param_4);
          iVar14 = iVar14 + iVar5;
        }
        while (pcVar16 = local_88 + -1, bVar22 = 0 < (int)local_88, local_88 = pcVar16, bVar22) {
          (*param_4)(0x30,local_2c);
          iVar14 = iVar14 + 1;
        }
        while (unaff_r10 = (char **)(pcVar8 + -1), uVar4 = local_74, 0 < (int)pcVar8) {
          cVar2 = *(char *)local_80;
          local_80 = (char **)((int)local_80 + 1);
          (*param_4)(cVar2,local_2c);
          iVar14 = iVar14 + 1;
          pcVar8 = (char *)unaff_r10;
        }
        goto LAB_030a5c70;
      }
      if (uVar4 == 0x58) {
        local_88 = (char *)0x10;
        goto LAB_030a5ae6;
      }
      if (0x58 < uVar4) {
        if (uVar4 == 99) {
          local_88._0_2_ = (ushort)(byte)*puVar18;
          iVar5 = 1;
          unaff_r10 = &local_88;
LAB_030a59d8:
          param_2 = puVar18 + 1;
          iVar3 = 0;
          if ((int)(uVar13 << 0x1d) < 0) {
            for (; (iVar3 < (int)pcVar16 &&
                   ((iVar3 < iVar5 || (*(char *)((int)unaff_r10 + iVar3) != '\0'))));
                iVar3 = iVar3 + 1) {
            }
          }
          else {
            for (; (iVar3 < iVar5 || (*(char *)((int)unaff_r10 + iVar3) != '\0')); iVar3 = iVar3 + 1
                ) {
            }
          }
          uVar4 = local_74 - iVar3;
          iVar5 = FUN_030a5f5a(uVar4,uVar13,local_2c,param_4);
          iVar14 = iVar5 + iVar14 + iVar3;
          while (bVar22 = iVar3 != 0, iVar3 = iVar3 + -1, bVar22) {
            (*param_4)(*(char *)unaff_r10,local_2c);
            unaff_r10 = (char **)((int)unaff_r10 + 1);
          }
          goto LAB_030a5c70;
        }
        if (uVar4 == 100) {
LAB_030a5a48:
          local_88 = (char *)0xa;
          uVar12 = (uVar13 & 0x7fffff) >> 0x14;
          if (uVar12 == 2) {
            puVar10 = (uint *)((uint)((int)puVar18 + 7) & 0xfffffff8);
            param_2 = puVar10 + 2;
            uVar19 = *puVar10;
            uVar7 = puVar10[1];
          }
          else {
            param_2 = puVar18 + 1;
            uVar19 = *puVar18;
            if (uVar12 == 3) {
              uVar19 = (uint)(short)uVar19;
            }
            uVar7 = (int)uVar19 >> 0x1f;
            if (uVar12 == 4) {
              uVar19 = (uint)(char)uVar19;
              uVar7 = (int)uVar19 >> 0x1f;
            }
          }
          if ((int)uVar7 < 0) {
            bVar22 = uVar19 != 0;
            uVar19 = -uVar19;
            uVar7 = -(uint)bVar22 - uVar7;
            uVar9 = 0x2d;
LAB_030a5aa8:
            local_84 = (char *)CONCAT31(local_84._1_3_,uVar9);
            iVar5 = 1;
          }
          else {
            if ((int)(uVar13 << 0x14) < 0) {
              uVar9 = 0x2b;
              goto LAB_030a5aa8;
            }
            iVar5 = 0;
            if ((uVar13 & 1) != 0) {
              uVar9 = 0x20;
              goto LAB_030a5aa8;
            }
          }
          goto LAB_030a5b64;
        }
        if (uVar4 == 0x65) break;
        goto LAB_030a597e;
      }
      if (uVar4 == 0) {
        return iVar14;
      }
      bVar23 = SBORROW4(uVar4,0x45);
      bVar21 = (int)(uVar4 - 0x45) < 0;
      bVar22 = uVar4 == 0x45;
      if (!bVar22) goto code_r0x030a5940;
    }
    goto LAB_030a5c8a;
  }
  goto LAB_030a597e;
code_r0x030a5940:
  bVar23 = SBORROW4(uVar4,0x46);
  bVar21 = (int)(uVar4 - 0x46) < 0;
  bVar22 = uVar4 == 0x46;
  if (!bVar22) goto code_r0x030a5944;
  goto LAB_030a592e;
code_r0x030a5944:
  if (uVar4 != 0x47) {
LAB_030a597e:
    (*param_4)(uVar4,local_2c);
    iVar14 = iVar14 + 1;
    goto LAB_030a5c76;
  }
LAB_030a5c8a:
  if (-1 < (int)(uVar13 << 0x1d)) {
    pcVar16 = (char *)0x6;
  }
  puVar20 = (undefined4 *)((uint)((int)puVar18 + 7) & 0xfffffff8);
  param_2 = puVar20 + 2;
  uVar11 = *puVar20;
  if ((puVar20[1] & 0x80000000) == 0) {
    if ((int)(uVar13 << 0x14) < 0) {
      local_38 = &DAT_030a5f2c;
    }
    else if ((uVar13 & 1) == 0) {
      local_38 = s_0123456789abcdef_030a5c48 + 0x10;
    }
    else {
      local_38 = &DAT_030a5f30;
    }
  }
  else {
    local_38 = &DAT_030a5f28;
  }
  uVar12 = puVar20[1] & 0x7fffffff;
  if (uVar4 == 0x65) {
LAB_030a5cf4:
    if ((int)pcVar16 < 0x11) {
      local_88 = pcVar16 + 1;
    }
    else {
      local_88 = &DAT_00000011;
    }
    local_84 = (char *)0x0;
    FUN_030a56e8(&local_50,auStack_70,uVar11,uVar12);
    local_7c = pcStack_48;
    local_88 = local_50;
    unaff_r10 = (char **)(pcVar16 + 1);
    local_78 = (char **)0x0;
LAB_030a5dbe:
    local_78 = (char **)0x0;
    local_84 = (char *)0x1;
    local_80 = local_4c;
    local_88 = local_50;
    local_7c = pcStack_48;
  }
  else if (uVar4 < 0x66) {
    if (uVar4 == 0x45) goto LAB_030a5cf4;
    if (uVar4 == 0x46) goto LAB_030a5d20;
    if (uVar4 == 0x47) goto LAB_030a5d68;
  }
  else if (uVar4 == 0x66) {
LAB_030a5d20:
    local_84 = (char *)0x1;
    local_80 = (char **)0x80000000;
    local_88 = pcVar16;
    FUN_030a56e8(&local_50,auStack_70,uVar11,uVar12);
    local_7c = pcStack_48;
    local_88 = local_50;
    local_78 = (char **)0x0;
    unaff_r10 = (char **)pcStack_48;
    if (local_44 == 0) {
      unaff_r10 = (char **)((int)local_4c + (int)(pcVar16 + 1));
    }
    iVar5 = (int)pcVar16 - (int)unaff_r10;
    if (-1 < iVar5) {
      unaff_r10 = (char **)(pcVar16 + 1);
      local_78 = (char **)(-1 - iVar5);
    }
    local_84 = (char *)((int)unaff_r10 + -(int)pcVar16);
  }
  else {
    if (uVar4 != 0x67) goto LAB_030a5df6;
LAB_030a5d68:
    if ((int)pcVar16 < 1) {
      pcVar16 = (char *)0x1;
    }
    local_88 = pcVar16;
    if (0x11 < (int)pcVar16) {
      local_88 = &DAT_00000011;
    }
    local_84 = (char *)0x0;
    FUN_030a56e8(&local_50,auStack_70,uVar11,uVar12);
    local_7c = pcStack_48;
    local_78 = (char **)0x0;
    local_88 = local_50;
    unaff_r10 = (char **)pcVar16;
    if (-1 < (int)(uVar13 << 0x1c)) {
      pcVar8 = pcStack_48;
      if ((int)pcVar16 <= (int)pcStack_48) goto LAB_030a5da2;
      while( true ) {
        unaff_r10 = (char **)pcVar8;
LAB_030a5da2:
        if (((int)unaff_r10 < 2) || (*(char *)((int)unaff_r10 + (int)(local_50 + -1)) != '0'))
        break;
        pcVar8 = (char *)((int)unaff_r10 + -1);
      }
    }
    if (((int)pcVar16 <= (int)local_4c) || ((int)local_4c < -4)) goto LAB_030a5dbe;
    if ((int)local_4c < 1) {
      local_78 = local_4c;
      pcVar16 = (char *)((int)unaff_r10 + -(int)local_4c);
LAB_030a5de2:
      unaff_r10 = (char **)pcVar16;
    }
    else {
      pcVar16 = (char *)((int)local_4c + 1);
      if ((int)unaff_r10 < (int)pcVar16) goto LAB_030a5de2;
    }
    local_84 = (char *)((int)local_4c + (1 - (int)local_78));
    local_80 = (char **)0x80000000;
  }
LAB_030a5df6:
  if ((-1 < (int)(uVar13 << 0x1c)) && ((int)unaff_r10 <= (int)local_84)) {
    local_84 = (char *)0xffffffff;
  }
  local_3b[2] = 0;
  pbVar15 = local_3b + 2;
  if (local_80 != (char **)0x80000000) {
    local_50 = (char *)0x2b;
    iVar5 = 2;
    if ((int)local_80 < 0) {
      local_80 = (char **)-(int)local_80;
      local_50 = (char *)0x2d;
    }
    while ((0 < iVar5 || (local_80 != (char **)0x0))) {
      local_80 = (char **)FUN_0309f702(local_80,10);
      pbVar15 = pbVar15 + -1;
      *pbVar15 = extraout_r1 + 0x30;
      iVar5 = iVar5 + -1;
    }
    pbVar15[-1] = (byte)local_50;
    pbVar15 = pbVar15 + -2;
    *pbVar15 = *param_1 & 0x20 | 0x45;
  }
  pbVar17 = local_3b + (2 - (int)pbVar15);
  local_74 = (local_74 -
             (int)((int)unaff_r10 +
                  (int)(pbVar17 + ((int)local_84 >> 0x1f) + (uint)(*local_38 != '\0')))) - 1;
  if (-1 < (int)(uVar13 << 0xf)) {
    iVar5 = FUN_030a5f5a(local_74,uVar13,local_2c,param_4);
    iVar14 = iVar14 + iVar5;
  }
  if (*local_38 != '\0') {
    (*param_4)(*local_38,local_2c);
    iVar14 = iVar14 + 1;
  }
  iVar5 = iVar14;
  pcVar16 = (char *)unaff_r10;
  if ((int)(uVar13 << 0xf) < 0) {
    iVar5 = FUN_030a5f5a(local_74,uVar13,local_2c,param_4);
    iVar5 = iVar14 + iVar5;
  }
  while (iVar14 = iVar5, unaff_r10 = (char **)(pcVar16 + -1), 0 < (int)pcVar16) {
    if (((int)local_78 < 0) || ((int)local_7c <= (int)local_78)) {
      cVar2 = '0';
    }
    else {
      cVar2 = local_88[(int)local_78];
    }
    (*param_4)(cVar2,local_2c);
    local_78 = (char **)((int)local_78 + 1);
    local_84 = local_84 + -1;
    iVar5 = iVar14 + 1;
    pcVar16 = (char *)unaff_r10;
    if (local_84 == (char *)0x0) {
      (*param_4)(0x2e,local_2c);
      iVar5 = iVar14 + 2;
    }
  }
  while (uVar4 = local_74, 0 < (int)pbVar17) {
    (*param_4)(*pbVar15,local_2c);
    iVar14 = iVar14 + 1;
    pbVar15 = pbVar15 + 1;
    pbVar17 = pbVar17 + -1;
  }
LAB_030a5c70:
  iVar5 = FUN_030a5f34(uVar4,uVar13,local_2c,param_4);
  iVar14 = iVar14 + iVar5;
LAB_030a5c76:
  param_1 = param_1 + 1;
  goto LAB_030a5c7a;
}


