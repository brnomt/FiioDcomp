/**
 * FUN_0302af3a @ 0x0302af3a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0302af3a(int param_1,int param_2)

{
  short *psVar1;
  int iVar2;
  
  iVar2 = FUN_0302ced0();
  psVar1 = DAT_0302b0e8;
  if (iVar2 == 0) {
    while (*psVar1 == 0) {
      FUN_02ff73f0();
      FUN_030059bc();
      dac_gain_curve_apply(1);
      param_1 = param_1 + -1;
      if ((param_1 == 0) || (iVar2 = FUN_0302ced0(), iVar2 != 0)) break;
    }
  }
  if (param_2 == 1) {
    *(undefined4 *)(DAT_0302b0dc + 0x24) = 1;
  }
  return 0;
}


