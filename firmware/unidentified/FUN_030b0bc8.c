/**
 * FUN_030b0bc8 @ 0x030b0bc8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030b0bc8(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  uint local_60;
  uint local_5c [2];
  uint local_54 [2];
  undefined4 local_4c;
  int local_40;
  uint local_3c [2];
  int local_34 [4];
  
  local_54[0] = 0;
  uVar8 = 0;
  local_5c[0] = 0;
  local_3c[0] = 0;
  bVar1 = false;
  iVar9 = 0;
  local_40 = 0;
  if (param_1 != 0) {
    buffered_fseek(param_1,0);
    iVar3 = DAT_030b0cd4;
    iVar2 = DAT_030b0cd0;
    while (uVar4 = buffered_fread(local_5c,1,4,param_1), 3 < uVar4) {
      local_5c[0] = local_5c[0] << 0x18 | (local_5c[0] >> 8 & 0xff) << 0x10 |
                    (local_5c[0] >> 0x10 & 0xff) << 8 | local_5c[0] >> 0x18;
      uVar4 = buffered_fread(&local_40,1,4,param_1);
      if (uVar4 < 4) {
        hifi_debug_printf_ovl(DAT_030b0cd8 + 0x30,DAT_030b0cd8,0xde3);
        goto LAB_030b0e36;
      }
      if (local_40 == iVar3) {
        if (local_5c[0] == 1) {
          uVar8 = buffered_fread(local_3c,1,4,param_1);
          if (uVar8 < 4) goto LAB_030b0e36;
          local_3c[0] = local_3c[0] << 0x18 | (local_3c[0] >> 8 & 0xff) << 0x10 |
                        (local_3c[0] >> 0x10 & 0xff) << 8 | local_3c[0] >> 0x18;
          uVar8 = buffered_fread(local_54,1,4,param_1);
          if (uVar8 < 4) goto LAB_030b0e36;
          uVar8 = local_54[0] << 0x18 | (local_54[0] >> 8 & 0xff) << 0x10 |
                  (local_54[0] >> 0x10 & 0xff) << 8 | local_54[0] >> 0x18;
          bVar1 = true;
          local_54[0] = uVar8;
        }
        if (local_5c[0] == 0) {
          iVar9 = (*(code *)*DAT_030b1108)(*(undefined4 *)(param_1 + 0x204));
          iVar9 = *DAT_030b110c -
                  (iVar9 - ((uint)*(ushort *)(param_1 + 0x202) - (uint)*(ushort *)(param_1 + 0x200))
                  );
          local_5c[0] = iVar9 + 8;
          *(uint *)(DAT_030b1104 + 0x54) = local_5c[0] + *(int *)(DAT_030b1104 + 0x54);
          buffered_fseek(param_1,iVar9,1);
          return 0;
        }
      }
      uVar4 = local_5c[0];
      if (local_40 + DAT_030b0cdc == 0) {
        local_4c = DAT_030b1110;
        iVar9 = iVar9 + 1;
        local_60 = 0;
        iVar7 = 0;
        local_34[0] = 0;
        if (8 < (int)local_5c[0]) {
          do {
            uVar5 = buffered_fread(&local_60,1,4,param_1);
            if (uVar5 < 4) {
              hifi_debug_printf_ovl(DAT_030b1114 + -0x18,DAT_030b1114,0x836);
              return 0xffffffff;
            }
            local_60 = local_60 << 0x18 | (local_60 >> 8 & 0xff) << 0x10 |
                       (local_60 >> 0x10 & 0xff) << 8 | local_60 >> 0x18;
            iVar7 = iVar7 + local_60;
            uVar5 = buffered_fread(local_34,1,4,param_1);
            if (uVar5 < 4) {
              return 0xffffffff;
            }
            if (local_34[0] + iVar2 == 0) {
              iVar6 = FUN_030b002c(param_1,local_4c,local_60);
              if (iVar6 != 0) {
                hifi_debug_printf_ovl(DAT_030b1114 + -0x18,DAT_030b1114,0x856);
                return 0xffffffff;
              }
            }
            else {
              buffered_fseek(param_1,local_60 - 8,1);
            }
          } while (iVar7 + 8U < uVar4);
        }
      }
      else {
        iVar7 = DAT_030b0ce0;
        if (local_40 != DAT_030b0ce0) {
          iVar7 = DAT_030b0ce4;
        }
        if (local_40 != DAT_030b0ce0 && local_40 != iVar7) {
          iVar7 = DAT_030b10e4;
          if (local_40 != DAT_030b10e4) {
            iVar7 = DAT_030b10e8;
          }
          if ((local_40 != DAT_030b10e4 && local_40 != iVar7) &&
             (local_40 != DAT_030b10ec && local_40 != iVar3)) {
            iVar7 = DAT_030b10f0;
            if (local_40 != DAT_030b10f0) {
              iVar7 = DAT_030b10f4;
            }
            if (local_40 != DAT_030b10f0 && local_40 != iVar7) {
              bVar10 = local_40 != DAT_030b10f8;
              iVar7 = DAT_030b10f8;
              if (bVar10) {
                iVar7 = DAT_030b10fc;
              }
              iVar6 = iVar7;
              if (bVar10 && local_40 != iVar7) {
                iVar6 = DAT_030b1100;
              }
              if ((bVar10 && local_40 != iVar7) && local_40 != iVar6) goto LAB_030b0e36;
            }
          }
        }
        iVar9 = iVar9 + 1;
        if (local_40 == iVar3 && bVar1) {
          buffered_fseek(param_1,uVar8 - 0x10,1);
        }
        else {
          buffered_fseek(param_1,local_5c[0] - 8,1);
        }
        if (local_40 == iVar3) {
          uVar4 = local_5c[0];
          if (bVar1) {
            uVar4 = uVar8;
          }
          *(uint *)(DAT_030b1104 + 0x54) = *(int *)(DAT_030b1104 + 0x54) + uVar4;
        }
      }
    }
    hifi_debug_printf_ovl(DAT_030b0cd8 + 0x30,DAT_030b0cd8,0xdda);
LAB_030b0e36:
    if (iVar9 != 0) {
      return 0;
    }
  }
  return 0xffffffff;
}


