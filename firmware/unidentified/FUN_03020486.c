/**
 * FUN_03020486 @ 0x03020486
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03020486(void)

{
  int iVar1;
  undefined4 in_r3;
  undefined4 uStack_8;
  
  iVar1 = DAT_03020690;
  *(undefined4 *)(DAT_03020690 + 0xe0) = 0;
  *(undefined4 *)(iVar1 + 0xe4) = 0;
  *(undefined4 *)(iVar1 + 0xe8) = 0;
  *(undefined4 *)(iVar1 + 0xec) = 0;
  *(undefined4 *)(iVar1 + 0xf0) = 0;
  *(undefined4 *)(iVar1 + 0xf4) = 0;
  *(undefined4 *)(iVar1 + 0xf8) = 0;
  *(undefined4 *)(iVar1 + 0xfc) = 0;
  *(undefined4 *)(iVar1 + 0x100) = 0;
  uStack_8 = in_r3;
  iVar1 = FUN_0301e3de(DAT_03020694,0x2000,&uStack_8);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  if (iVar1 != -1) {
    FUN_0301e6c0(DAT_03020698,DAT_03020694);
    *(undefined4 *)(DAT_03020698 + 0x20) = uStack_8;
    return 0;
  }
  return 0xfffffffe;
}


