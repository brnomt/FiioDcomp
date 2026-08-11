/**
 * FUN_030e01f0 @ 0x030e01f0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030e01f0(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 *puStack_40;
  undefined4 *puStack_3c;
  undefined4 uStack_38;
  
  puVar2 = DAT_030e03f0;
  uVar6 = *param_3;
  iVar3 = param_3[1];
  iVar9 = *param_2;
  *param_2 = 0;
  if (iVar3 < 0xb) {
    return iVar3;
  }
  FUN_030dd888(puVar2 + 8,uVar6,iVar3 << 3);
  puVar10 = puVar2 + 8;
  iVar3 = FUN_030dfd86(puVar10,&uStack_48,0);
  if (-1 < iVar3) {
    puVar2[1] = uStack_44;
    puVar2[0x10] = uStack_38;
    if (puStack_40 == (undefined4 *)0x0) {
      puStack_40 = (undefined4 *)puVar2[2];
    }
    puVar2[2] = puStack_40;
    if ((int)puStack_40 < 0x11) {
      puVar2[0xe] = 0x10 - (int)puStack_40;
      puVar2[0xf] = 0;
    }
    else {
      puVar2[0xe] = 0x20 - (int)puStack_40;
      puVar2[0xf] = 1;
    }
    puVar2[3] = 0x1200;
    if ((int)puStack_3c < 0x1201) {
      puVar2[0xc] = puStack_3c;
      *puVar2 = uStack_48;
      iVar3 = 0;
      if (0 < (int)puVar2[1]) {
        do {
          iVar4 = FUN_030dfb90(puVar2,iVar3);
          if (iVar4 < 0) {
            return -1;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)puVar2[1]);
      }
      FUN_030dd8a8(puVar10);
      hifi_flac_helper(puVar2 + 8,0x10);
      FUN_030dd7a6(puVar10,0x10);
      iVar4 = FUN_030dd6ea(puVar2 + 8);
      iVar3 = DAT_030e03f4;
      iVar7 = puVar2[1];
      uVar5 = puVar2[0xc];
      if (puVar2[0xf] == 0) {
        iVar8 = 2;
      }
      else {
        iVar8 = 4;
      }
      uVar11 = *(uint *)(DAT_030e03f4 + 0x28);
      piVar1 = (int *)(DAT_030e03f4 + 0x2c);
      *(uint *)(DAT_030e03f4 + 0x28) = uVar11 + uVar5;
      *(uint *)(iVar3 + 0x2c) = *piVar1 + ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar11,uVar5);
      if ((int)(iVar8 * uVar5 * iVar7) <= iVar9) {
        puStack_40 = puVar2 + 0x12;
        puStack_3c = puVar2 + 0x1212;
        uStack_48 = puVar2[0xc];
        iVar3 = puVar2[0x10] + -7;
        if (iVar3 < 0) {
          iVar3 = 0;
        }
        iVar3 = FUN_030debb8(param_1,&puStack_40,iVar3,puVar2[2]);
        *param_2 = iVar3;
        *param_2 = puVar2[0xc];
        return (int)(iVar4 + 7 + ((uint)(iVar4 + 7 >> 0x1f) >> 0x1d)) >> 3;
      }
      hifi_debug_printf_ovl_0dc5(s_output_data_size_is_larger_than_a_030e03f8);
      return -1;
    }
    hifi_debug_printf_ovl_0dc5(DAT_030e03ec);
  }
  return -1;
}


