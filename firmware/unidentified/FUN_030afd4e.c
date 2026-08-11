/**
 * FUN_030afd4e @ 0x030afd4e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030afd4e(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint extraout_r3;
  int iVar10;
  uint uStack_50;
  uint local_4c [4];
  int aiStack_3c [2];
  int local_34;
  int aiStack_30 [3];
  
  iVar2 = DAT_030affa4;
  iVar1 = DAT_030aff98;
  local_4c[0] = 0;
  iVar10 = 0;
  local_34 = 0;
  if ((param_1 != 0) && (param_2 == 0)) {
    return 0xffffffff;
  }
  if (8 < (int)param_3) {
    do {
      uVar4 = buffered_fread(local_4c,1,4,param_1);
      if (uVar4 < 4) {
        hifi_debug_printf_ovl(DAT_030affa8 + 0x30,DAT_030affa8,0x75d);
        return 0xfffffffb;
      }
      local_4c[0] = local_4c[0] << 0x18 | (local_4c[0] >> 8 & 0xff) << 0x10 |
                    (local_4c[0] >> 0x10 & 0xff) << 8 | local_4c[0] >> 0x18;
      iVar10 = iVar10 + local_4c[0];
      uVar5 = buffered_fread(&local_34,1,4,param_1);
      uVar4 = local_4c[0];
      if (uVar5 < 4) {
        hifi_debug_printf_ovl(DAT_030affa8 + 0x30,DAT_030affa8,0x764);
        return 0xfffffffb;
      }
      if (local_34 + iVar2 == 0) {
        iVar7 = FUN_030af8b0(param_1,param_2,local_4c[0]);
        if (iVar7 != 0) {
          hifi_debug_printf_ovl(DAT_030affa8 + 0x30,DAT_030affa8,0x76d);
          return 0xffffffff;
        }
      }
      else {
        iVar7 = local_34 + iVar2 + DAT_030affac;
        if (iVar7 == 0) {
          uStack_50 = 0;
          iVar7 = 0;
          aiStack_30[0] = 0;
          if ((param_1 != 0) && (param_2 == 0)) {
LAB_030b0014:
            hifi_debug_printf_ovl(DAT_030b03d8 + 0x30,DAT_030b03d8,0x77f);
            return 0xffffffff;
          }
          if (8 < (int)local_4c[0]) {
            do {
              uVar5 = buffered_fread(&uStack_50,1,4,param_1);
              if (uVar5 < 4) {
                hifi_debug_printf_ovl(DAT_030aff9c + -0x18,DAT_030aff9c,0x6ae);
                goto LAB_030b0014;
              }
              uStack_50 = uStack_50 << 0x18 | (uStack_50 >> 8 & 0xff) << 0x10 |
                          (uStack_50 >> 0x10 & 0xff) << 8 | uStack_50 >> 0x18;
              iVar7 = iVar7 + uStack_50;
              uVar5 = buffered_fread(aiStack_30,1,4,param_1);
              if (uVar5 < 4) {
                hifi_debug_printf_ovl(DAT_030b03d4 + -0x18,DAT_030b03d4,0x6b5);
                goto LAB_030b0014;
              }
              if (aiStack_30[0] + iVar1 == 0) {
                iVar6 = aac_dec_init(param_1,param_2,uStack_50);
                if (iVar6 != 0) goto LAB_030b0014;
              }
              else {
                buffered_fseek(param_1,uStack_50 - 8,1);
              }
            } while (iVar7 + 8U < uVar4);
          }
        }
        else if (iVar7 + DAT_030affb0 == 0) {
          aiStack_3c[0] = 0;
          if ((param_1 != 0) && (param_2 == 0)) {
LAB_030aff44:
            hifi_debug_printf_ovl(DAT_030affa8 + 0x30,DAT_030affa8,0x776);
            return 0xffffffff;
          }
          buffered_fseek(param_1,8,1);
          uVar5 = buffered_fread(aiStack_3c,1,4,param_1);
          iVar7 = DAT_030affa0;
          if (uVar5 < 4) goto LAB_030aff44;
          if (aiStack_3c[0] == DAT_030affb4) {
            *(undefined4 *)(DAT_030affa0 + 0x24) = 0;
            uVar9 = *(uint *)(iVar7 + 0x1c);
            *(uint *)(param_2 + 0xa0) = uVar9;
            *(undefined1 *)(param_2 + 0xd5) = 1;
            puVar3 = DAT_030affb8;
            uVar5 = *(uint *)(iVar7 + 0x20);
            if (uVar5 == 0) {
              uVar8 = *DAT_030affb8;
              uVar5 = extraout_r3;
              if (uVar8 == 0) {
                uVar5 = DAT_030affb8[1];
              }
              if (uVar8 != 0 || uVar5 != 0) {
                *(uint *)(param_2 + 0xb0) = uVar8;
                *(uint *)(param_2 + 0xb4) = puVar3[1];
                uVar5 = uVar8 / *(uint *)(param_2 + 0xa0);
                *(uint *)(param_2 + 0xc0) =
                     ((uVar8 - *(uint *)(param_2 + 0xa0) * uVar5) * 1000) / uVar9 + uVar5 * 1000;
              }
            }
            else {
              *(uint *)(param_2 + 0xa8) = uVar5;
              uVar8 = uVar5 / *(uint *)(param_2 + 0xa0);
              *(uint *)(param_2 + 0xc0) =
                   ((uVar5 - *(uint *)(param_2 + 0xa0) * uVar8) * 1000) / uVar9 + uVar8 * 1000;
            }
          }
          else if (aiStack_3c[0] == DAT_030aff94) {
            if (*(int *)(DAT_030affa0 + 0x24) == -1) {
              *(undefined4 *)(param_2 + 0xa4) = *(undefined4 *)(DAT_030affa0 + 0x1c);
              puVar3 = DAT_030affb8;
              if (*(int *)(iVar7 + 0x20) == 0) {
                uVar9 = *DAT_030affb8;
                uVar5 = extraout_r3;
                if (uVar9 == 0) {
                  uVar5 = DAT_030affb8[1];
                }
                if (uVar9 != 0 || uVar5 != 0) {
                  *(uint *)(param_2 + 0xb8) = uVar9;
                  *(uint *)(param_2 + 0xbc) = puVar3[1];
                }
              }
              else {
                *(int *)(param_2 + 0xac) = *(int *)(iVar7 + 0x20);
              }
            }
            *(undefined4 *)(iVar7 + 0x24) = 1;
            *(undefined1 *)(param_2 + 0xd4) = 1;
          }
          else {
            *(undefined4 *)(DAT_030affa0 + 0x24) = 2;
          }
          buffered_fseek(param_1,uVar4 - 0x14,1);
        }
        else {
          buffered_fseek(param_1,local_4c[0] - 8,1);
        }
      }
    } while (iVar10 + 8U < param_3);
  }
  return 0;
}


