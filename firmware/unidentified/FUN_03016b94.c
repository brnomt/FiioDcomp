/**
 * FUN_03016b94 @ 0x03016b94
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03016b94(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*(byte *)(DAT_03016f7c + 0x12) < *(byte *)(DAT_03016f7c + 0x1e)) {
    *(byte *)(DAT_03016f7c + 0x12) = *(byte *)(DAT_03016f7c + 0x12) + 1;
  }
  puVar1 = DAT_03016f84;
  iVar2 = FUN_02ff2834(*DAT_03016f84,DAT_03016f80);
  if (iVar2 == 1) {
    FUN_03020bf0(0xff,0);
  }
  iVar2 = FUN_02ff2834(*puVar1,DAT_03016f88);
  if (iVar2 == 1) {
    FUN_0302da66(0xb6,0);
  }
  func_0x030037a8(0x3e);
  return 1;
}


