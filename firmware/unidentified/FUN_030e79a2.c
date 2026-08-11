/**
 * FUN_030e79a2 @ 0x030e79a2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e79a2(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  uint local_38;
  int local_34;
  uint local_30;
  int local_2c [2];
  
  local_38 = 0;
  iVar9 = 0;
  local_34 = 0;
  buffered_fseek_ovl_0e64(param_1,0,0);
  iVar2 = DAT_030e7aa8;
  iVar7 = DAT_030e7a88;
  do {
    do {
      while( true ) {
        uVar4 = buffered_fread_ovl_0e65(&local_38,1,4,param_1);
        if (uVar4 < 4) {
          return 0;
        }
        local_38 = local_38 << 0x18 | (local_38 >> 8 & 0xff) << 0x10 |
                   (local_38 >> 0x10 & 0xff) << 8 | local_38 >> 0x18;
        iVar9 = iVar9 + local_38;
        uVar5 = buffered_fread_ovl_0e65(&local_34,1,4,param_1);
        uVar4 = local_38;
        uVar3 = DAT_030e7f10;
        iVar8 = DAT_030e7a7c;
        if (uVar5 < 4) {
          return 0xfffffffb;
        }
        if (local_34 + DAT_030e7aac == 0) break;
        iVar6 = DAT_030e7ab0;
        if (local_34 != DAT_030e7ab0) {
          iVar6 = DAT_030e7ab4;
        }
        if (local_34 != DAT_030e7ab0 && local_34 != iVar6) {
          iVar6 = DAT_030e7ab8;
          if (local_34 != DAT_030e7ab8) {
            iVar6 = DAT_030e7abc;
          }
          if ((local_34 != DAT_030e7ab8 && local_34 != iVar6) &&
             (local_34 != DAT_030e7ac0 && local_34 != iVar2)) {
            iVar6 = DAT_030e7ac4;
            if (local_34 != DAT_030e7ac4) {
              iVar6 = DAT_030e7ac8;
            }
            if (local_34 != DAT_030e7ac4 && local_34 != iVar6) {
              bVar10 = local_34 != DAT_030e7acc;
              iVar6 = DAT_030e7acc;
              if (bVar10) {
                iVar6 = DAT_030e7ad0;
              }
              iVar1 = iVar6;
              if (bVar10 && local_34 != iVar6) {
                iVar1 = DAT_030e7ad4;
              }
              if ((bVar10 && local_34 != iVar6) && local_34 != iVar1) {
                iVar7 = (*(code *)*DAT_030e7f14)(*(undefined4 *)(param_1 + 0x204));
                if (*DAT_030e7f18 -
                    (iVar7 - ((uint)*(ushort *)(param_1 + 0x202) -
                             (uint)*(ushort *)(param_1 + 0x200))) < 0x200) {
                  hifi_debug_printf_sync_ovl_0e45(&LAB_030e7f1c);
                  return 0;
                }
                hifi_debug_printf_sync_ovl_0e45(s_0x_x_pos_unkown_box_030e7f28);
                return 0xffffffff;
              }
            }
          }
        }
        if ((local_34 == iVar2) && (*(int *)(DAT_030e7a7c + 0x44) < 0x201)) {
          *(uint *)(DAT_030e7a7c + 0x4c) = (iVar9 - local_38) + 8;
          *(uint *)(iVar8 + 0x44) = local_38;
        }
        buffered_fseek_ovl_0e64(param_1,local_38 - 8,1);
      }
      iVar8 = 0;
      local_30 = 0;
      local_2c[0] = 0;
    } while ((int)local_38 < 9);
    do {
      uVar5 = buffered_fread_ovl_0e65(&local_30,1,4,param_1);
      if (uVar5 < 4) {
        return 0xffffffff;
      }
      local_30 = local_30 << 0x18 | (local_30 >> 8 & 0xff) << 0x10 | (local_30 >> 0x10 & 0xff) << 8
                 | local_30 >> 0x18;
      iVar8 = iVar8 + local_30;
      uVar5 = buffered_fread_ovl_0e65(local_2c,1,4,param_1);
      if (uVar5 < 4) {
        return 0xffffffff;
      }
      if (local_2c[0] + iVar7 == 0) {
        iVar6 = FUN_030e7736(param_1,uVar3,local_30);
        if (iVar6 != 0) {
          return 0xffffffff;
        }
      }
      else {
        buffered_fseek_ovl_0e64(param_1,local_30 - 8,1);
      }
    } while (iVar8 + 8U < uVar4);
  } while( true );
}


