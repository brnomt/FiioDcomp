/**
 * FUN_0309127c @ 0x0309127c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_0309127c(byte *param_1,int *param_2,undefined4 param_3,code *param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int extraout_r2;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined1 *puVar11;
  bool bVar12;
  longlong lVar13;
  undefined1 local_68;
  undefined1 local_67;
  undefined1 local_49;
  int local_48;
  undefined4 uStack_44;
  byte local_40 [4];
  char *local_3c;
  byte *pbStack_34;
  int *piStack_30;
  undefined4 local_2c;
  code *pcStack_28;
  
  pcStack_28 = param_4;
  local_2c = param_3;
  piStack_30 = param_2;
  pbStack_34 = param_1;
  iVar8 = 0;
  do {
    bVar1 = *param_1;
    if (bVar1 == 0) {
      return iVar8;
    }
    if (bVar1 == 0x25) {
      uVar7 = 0;
      iVar10 = 0;
      pbVar6 = param_1;
      while( true ) {
        param_1 = pbVar6 + 1;
        uVar2 = 1 << (*param_1 - 0x20 & 0xff);
        if ((uVar2 & DAT_03091510) == 0) break;
        uVar7 = uVar7 | uVar2;
        pbVar6 = param_1;
      }
      piVar9 = param_2;
      if (*param_1 == 0x2e) {
        param_1 = pbVar6 + 2;
        uVar7 = uVar7 | 4;
        if (*param_1 == 0x2a) {
          piVar9 = param_2 + 1;
          iVar10 = *param_2;
          param_1 = pbVar6 + 3;
        }
        else {
          for (; *param_1 - 0x30 < 10; param_1 = param_1 + 1) {
            iVar10 = (uint)*param_1 + iVar10 * 10 + -0x30;
          }
        }
      }
      bVar1 = *param_1;
      if (bVar1 == 0x6c) {
        uVar7 = uVar7 | 0x100000;
        if (param_1[1] == 0x6c) {
          param_1 = param_1 + 1;
          uVar7 = uVar7 + 0x100000;
        }
LAB_03091318:
        param_1 = param_1 + 1;
      }
      else {
        if (bVar1 < 0x6d) {
          if (bVar1 != 0x4c) {
            if (bVar1 != 0x6a) goto LAB_0309131a;
            uVar7 = uVar7 | 0x200000;
          }
          goto LAB_03091318;
        }
        if ((bVar1 == 0x74) || (bVar1 == 0x7a)) goto LAB_03091318;
      }
LAB_0309131a:
      bVar1 = *param_1;
      if (bVar1 == 0x69) {
LAB_030913ae:
        local_48 = 10;
        uStack_44 = 0;
        if ((uVar7 & 0x7fffff) >> 0x14 == 2) {
          piVar9 = (int *)((uint)((int)piVar9 + 7) & 0xfffffff8);
          param_2 = piVar9 + 2;
          iVar3 = *piVar9;
          iVar4 = piVar9[1];
        }
        else {
          iVar3 = *piVar9;
          param_2 = piVar9 + 1;
          iVar4 = iVar3 >> 0x1f;
        }
        if (iVar4 < 0) {
          bVar12 = iVar3 != 0;
          iVar3 = -iVar3;
          iVar4 = -(uint)bVar12 - iVar4;
          local_40[0] = 0x2d;
LAB_030913ea:
          iVar5 = 1;
        }
        else {
          if ((int)(uVar7 << 0x14) < 0) {
            local_40[0] = 0x2b;
            goto LAB_030913ea;
          }
          iVar5 = 0;
          if ((uVar7 & 1) != 0) {
            local_40[0] = 0x20;
            goto LAB_030913ea;
          }
        }
LAB_03091456:
        if (bVar1 != 0x58) goto LAB_03091472;
        local_3c = s_0123456789ABCDEF_03091528;
      }
      else {
        param_2 = piVar9;
        if (bVar1 < 0x6a) {
          if (bVar1 == 0) {
            return iVar8;
          }
          if (bVar1 != 0x58) {
            if (bVar1 == 99) {
              local_68 = (char)*piVar9;
              local_67 = 0;
              iVar3 = 1;
              puVar11 = &local_68;
              goto LAB_0309136e;
            }
            if (bVar1 != 100) goto LAB_03091348;
            goto LAB_030913ae;
          }
LAB_030913fe:
          local_48 = 0x10;
LAB_03091400:
          uStack_44 = 0;
        }
        else {
          if (bVar1 != 0x70) {
            if (bVar1 == 0x73) {
              puVar11 = (undefined1 *)*piVar9;
              iVar3 = -1;
LAB_0309136e:
              param_2 = piVar9 + 1;
              iVar4 = 0;
              if ((int)(uVar7 << 0x1d) < 0) {
                for (; (iVar4 < iVar10 && ((iVar4 < iVar3 || (puVar11[iVar4] != '\0'))));
                    iVar4 = iVar4 + 1) {
                }
              }
              else {
                for (; (iVar4 < iVar3 || (puVar11[iVar4] != '\0')); iVar4 = iVar4 + 1) {
                }
              }
              iVar8 = iVar8 + iVar4;
              while (bVar12 = iVar4 != 0, iVar4 = iVar4 + -1, bVar12) {
                (*param_4)(*puVar11,local_2c);
                puVar11 = puVar11 + 1;
              }
              goto LAB_030914fc;
            }
            if (bVar1 != 0x75) {
              if (bVar1 != 0x78) goto LAB_03091348;
              goto LAB_030913fe;
            }
            local_48 = 10;
            goto LAB_03091400;
          }
          uVar7 = uVar7 | 4;
          local_48 = 0x10;
          uStack_44 = 0;
          iVar10 = 8;
        }
        if ((uVar7 & 0x7fffff) >> 0x14 == 2) {
          piVar9 = (int *)((uint)((int)piVar9 + 7) & 0xfffffff8);
          param_2 = piVar9 + 2;
          iVar3 = *piVar9;
          iVar4 = piVar9[1];
        }
        else {
          iVar3 = *piVar9;
          param_2 = piVar9 + 1;
          iVar4 = 0;
        }
        iVar5 = 0;
        if (-1 < (int)(uVar7 << 0x1c)) goto LAB_03091456;
        if (bVar1 != 0x70) {
          if ((local_48 == 0x10) && (iVar3 != 0 || iVar4 != 0)) {
            local_40[0] = 0x30;
            local_40[1] = bVar1;
            iVar5 = 2;
          }
          goto LAB_03091456;
        }
        local_40[0] = 0x40;
        iVar5 = 1;
LAB_03091472:
        local_3c = s_0123456789abcdef_03091514;
      }
      lVar13 = CONCAT44(iVar4,iVar3);
      uStack_44 = 0;
      piVar9 = &local_48;
      while( true ) {
        if (lVar13 == 0) break;
        lVar13 = FUN_030826d0((int)lVar13,(int)((ulonglong)lVar13 >> 0x20),local_48,uStack_44);
        piVar9 = (int *)((int)piVar9 + -1);
        *(char *)piVar9 = local_3c[extraout_r2];
      }
      local_48 = (int)&local_48 - (int)piVar9;
      if (-1 < (int)(uVar7 << 0x1d)) {
        iVar10 = 1;
      }
      if (local_48 < iVar10) {
        iVar10 = iVar10 - local_48;
      }
      else {
        iVar10 = 0;
      }
      for (iVar3 = 0; iVar3 < iVar5; iVar3 = iVar3 + 1) {
        (*param_4)(local_40[iVar3],local_2c);
        iVar8 = iVar8 + 1;
      }
      while (0 < iVar10) {
        (*param_4)(0x30,local_2c);
        iVar8 = iVar8 + 1;
        iVar10 = iVar10 + -1;
      }
      while (iVar10 = local_48, local_48 = local_48 + -1, 0 < iVar10) {
        (*param_4)((char)*piVar9,local_2c);
        iVar8 = iVar8 + 1;
        piVar9 = (int *)((int)piVar9 + 1);
      }
    }
    else {
LAB_03091348:
      (*param_4)(bVar1,local_2c);
      iVar8 = iVar8 + 1;
    }
LAB_030914fc:
    param_1 = param_1 + 1;
  } while( true );
}


