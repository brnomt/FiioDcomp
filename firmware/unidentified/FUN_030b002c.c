/**
 * FUN_030b002c @ 0x030b002c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030b002c(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint local_38;
  uint uStack_34;
  int local_30;
  short asStack_2c [4];
  
  iVar1 = DAT_030b03dc;
  local_38 = 0;
  iVar7 = 0;
  local_30 = 0;
  if ((param_1 != 0) && (param_2 == 0)) {
    return 0xffffffff;
  }
  *(undefined4 *)(DAT_030b03dc + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x70) = 0;
  *(undefined4 *)(iVar1 + 0x74) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 1;
  iVar3 = DAT_030b03e4;
  iVar2 = DAT_030b03e0;
  if (8 < (int)param_3) {
    do {
      uVar4 = buffered_fread(&local_38,1,4,param_1);
      if (uVar4 < 4) {
        hifi_debug_printf_ovl(DAT_030b03d8 + 0x30,DAT_030b03d8,0x7c1);
        return 0xfffffffb;
      }
      local_38 = local_38 << 0x18 | (local_38 >> 8 & 0xff) << 0x10 | (local_38 >> 0x10 & 0xff) << 8
                 | local_38 >> 0x18;
      iVar7 = iVar7 + local_38;
      uVar4 = buffered_fread(&local_30,1,4,param_1);
      if (uVar4 < 4) {
        hifi_debug_printf_ovl(DAT_030b03d8 + 0x30,DAT_030b03d8,0x7c8);
        return 0xfffffffb;
      }
      if (local_30 + iVar2 == 0) {
        iVar6 = FUN_030afd4e(param_1,param_2,local_38);
        if (iVar6 != 0) {
          hifi_debug_printf_ovl(DAT_030b03d8 + 0x30,DAT_030b03d8,0x7ea);
          return 0xffffffff;
        }
      }
      else if (local_30 + iVar2 + iVar3 == 0) {
        uStack_34 = 0;
        asStack_2c[0] = 0;
        if (((param_1 != 0) && (param_2 == 0)) ||
           (uVar4 = buffered_fread(&uStack_34,1,4,param_1), uVar4 < 4)) {
LAB_030b0168:
          hifi_debug_printf_ovl(DAT_030b03d8 + 0x30,DAT_030b03d8,0x7d1);
          return 0xffffffff;
        }
        uVar4 = uStack_34 << 0x18;
        uStack_34 = uVar4 | (uStack_34 >> 8 & 0xff) << 0x10 | (uStack_34 >> 0x10 & 0xff) << 8 |
                    uStack_34 >> 0x18;
        if (uVar4 == 0) {
          buffered_fseek(param_1,0x20,1);
        }
        else {
          buffered_fseek(param_1,0x2c,1);
        }
        uVar4 = buffered_fread(asStack_2c,1,2,param_1);
        if (uVar4 < 2) goto LAB_030b0168;
        uVar5 = 1;
        if (asStack_2c[0] != 1) {
          uVar5 = 2;
        }
        *(undefined4 *)(iVar1 + 0x24) = uVar5;
        buffered_fseek(param_1,0x2e,1);
      }
      else {
        buffered_fseek(param_1,local_38 - 8,1);
      }
    } while (iVar7 + 8U < param_3);
  }
  return 0;
}


