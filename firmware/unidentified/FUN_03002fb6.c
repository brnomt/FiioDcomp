/**
 * FUN_03002fb6 @ 0x03002fb6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03002fb6(void)

{
  short *psVar1;
  int iVar2;
  undefined4 uVar3;
  short local_28 [16];
  
  uVar3 = 0;
  iVar2 = FUN_02ff00a8(0x194);
  if (iVar2 != 0) {
    local_28[0] = 0x38;
    local_28[1] = 0x46;
    local_28[2] = 3;
    local_28[3] = 0;
    local_28[4] = 1;
    func_0x02fdef88(DAT_030030f8,DAT_030030fc,local_28);
  }
  iVar2 = FUN_02ff00ec(0x179);
  if ((iVar2 != 0) && (iVar2 = FUN_02ff00ec(0xe3), iVar2 != 0)) {
    FUN_02ff00ce(0x179);
    FUN_02ff00ce(0xe3);
    FUN_02ff008c(0x172);
  }
  iVar2 = FUN_02ff00a8(0xe3);
  psVar1 = DAT_03003100;
  if (iVar2 == 1) {
    if (*DAT_03003100 == 0xc) {
      FUN_02ff02b6(5,0);
      uVar3 = 1;
    }
    else {
      iVar2 = func_0x02fdf118(*DAT_03003108,DAT_03003104);
      local_28[0] = *psVar1;
      if (iVar2 == 0) {
        local_28[0] = local_28[0] + -1;
      }
      FUN_02ff02b6(1,local_28);
      uVar3 = 1;
    }
  }
  iVar2 = FUN_02ff00a8(0x17a);
  if (iVar2 == 1) {
    FUN_02ff008c(0x102);
    FUN_02ff008c(0x113);
    *DAT_03003110 = *DAT_0300310c;
    FUN_02ff06d8(0x18,7);
    func_0x02fdf0d4(DAT_03003108);
    uVar3 = FUN_03003120();
  }
  return uVar3;
}


