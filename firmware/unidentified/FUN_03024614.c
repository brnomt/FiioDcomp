/**
 * FUN_03024614 @ 0x03024614
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_03024614(char param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  int local_bc [24];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  
  local_48 = *(undefined4 *)(DAT_03024a1c + 0x1c);
  uStack_44 = *(undefined4 *)(DAT_03024a1c + 0x20);
  uStack_40 = *(undefined4 *)(DAT_03024a1c + 0x24);
  uStack_3c = *(undefined4 *)(DAT_03024a1c + 0x28);
  local_38 = *(undefined4 *)(DAT_03024a1c + 0x2c);
  local_bc[0x17] = *(undefined4 *)(DAT_03024a1c + 0x30);
  uStack_5c = *(undefined4 *)(DAT_03024a1c + 0x34);
  uStack_58 = *(undefined4 *)(DAT_03024a1c + 0x38);
  uStack_54 = *(undefined4 *)(DAT_03024a1c + 0x3c);
  local_50 = *(undefined4 *)(DAT_03024a1c + 0x40);
  uStack_4c = *(undefined4 *)(DAT_03024a1c + 0x44);
  local_dc = 0;
  local_d8 = 0;
  local_c8 = 0;
  local_c4 = 0;
  local_bc[2] = 0;
  local_bc[3] = 0;
  local_bc[7] = 0;
  local_bc[8] = 0;
  local_bc[0xc] = 0;
  local_e8 = 0;
  local_e4 = 0;
  local_e0 = 0;
  local_bc[0xd] = 0;
  local_bc[0x11] = 0;
  local_d4 = 0;
  local_d0 = 0;
  local_cc = 0;
  local_bc[0x12] = 0;
  local_bc[0x16] = 0;
  local_c0 = 0;
  local_bc[0] = 0;
  local_bc[1] = 0;
  local_bc[4] = 0;
  local_bc[5] = 0;
  local_bc[6] = 0;
  local_bc[9] = 0;
  local_bc[10] = 0;
  local_bc[0xb] = 0;
  local_bc[0xe] = 0;
  local_bc[0xf] = 0;
  local_bc[0x10] = 0;
  iVar1 = (int)param_1;
  local_bc[0x13] = 0;
  local_bc[0x14] = 0;
  local_bc[0x15] = 0;
  iVar2 = FUN_02ffce8c();
  uVar3 = FUN_02ffc9d6(&local_e8,0x2a,iVar1);
  if ((0x29 < uVar3) && (uVar3 = FUN_02ffc9d6(local_bc,4,iVar1), 3 < uVar3)) {
    iVar4 = FUN_02ffce8c(iVar1);
    if (local_bc[0] + iVar4 < iVar2) {
      return 0xffffffff;
    }
    FUN_02ffce8c(iVar1);
    uVar3 = FUN_02ffc9d6(local_bc + 1,0x18,iVar1);
    if (0x17 < uVar3) {
      uVar5 = FUN_02ff89ce(local_bc + 1,&local_48,0x10);
      return uVar5;
    }
  }
  return 0xffffffff;
}


