/**
 * FUN_030e89d2 @ 0x030e89d2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e89d2(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  iVar2 = DAT_030e8af0;
  puVar1 = DAT_030e8aec;
  iVar3 = *(int *)(param_1 + 0x34);
  iVar7 = 0;
  iVar6 = iVar3 * 4;
  iVar4 = *(int *)(param_1 + 0x10);
  bVar9 = iVar4 == 2;
  iVar8 = iVar4 + -2;
  if (2 >= iVar4) {
    bVar9 = iVar4 == 0;
    iVar8 = iVar4;
  }
  if (!bVar9 && iVar8 < 0 == (2 < iVar4 && SBORROW4(iVar4,2))) {
    do {
      uVar5 = *puVar1;
      *puVar1 = uVar5 + iVar6;
      if (0x183ff < uVar5 + iVar6) {
        hifi_debug_printf_sync_ovl_0e45(DAT_030e8af4);
      }
      iVar8 = param_1 + iVar7 * 4;
      *(uint *)(iVar8 + 0x1c) = *puVar1 + iVar3 * -4 + iVar2;
      *(undefined4 *)(param_1 + 0x44) = 1;
      uVar5 = *puVar1;
      *puVar1 = uVar5 + iVar6;
      if (0x183ff < uVar5 + iVar6) {
        hifi_debug_printf_sync_ovl_0e45(DAT_030e8af4);
      }
      *(uint *)(iVar8 + 0x24) = *puVar1 + iVar3 * -4 + iVar2;
      uVar5 = *puVar1;
      *puVar1 = uVar5 + iVar6;
      if (0x183ff < uVar5 + iVar6) {
        hifi_debug_printf_sync_ovl_0e45(DAT_030e8af4);
      }
      iVar7 = iVar7 + 1;
      *(uint *)(iVar8 + 0x2c) = *puVar1 + iVar3 * -4 + iVar2;
      iVar8 = *(int *)(param_1 + 0x10);
      if (2 < iVar8) {
        iVar8 = 2;
      }
    } while (iVar7 < iVar8);
  }
  return 0;
}


