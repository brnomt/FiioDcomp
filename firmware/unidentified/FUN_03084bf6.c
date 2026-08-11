/**
 * FUN_03084bf6 @ 0x03084bf6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03084bf6(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uStack_10;
  
  iVar1 = DAT_03084c34;
  uStack_10 = param_4;
  iVar2 = FUN_03085014(*(undefined4 *)(DAT_03084c34 + 0xc),*(undefined4 *)(param_1 + 8),&uStack_10);
  if (iVar2 == 0) {
    iVar2 = (uStack_10 / 1000) * *(int *)(DAT_03084c38 + 4) +
            (*(int *)(DAT_03084c38 + 4) * (uStack_10 % 1000)) / 1000;
    *(int *)(iVar1 + 0x14) = iVar2;
    *(int *)(param_1 + 0x14) = iVar2;
    return 0;
  }
  return 1;
}


