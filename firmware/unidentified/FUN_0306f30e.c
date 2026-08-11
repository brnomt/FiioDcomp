/**
 * FUN_0306f30e @ 0x0306f30e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0306f30e(undefined1 *param_1,int param_2)

{
  undefined4 uVar1;
  
  *param_1 = (char)param_2;
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x14) = DAT_0306f33c;
    uVar1 = FUN_0306f1e6(param_1);
    *(undefined4 *)(param_1 + 0x14) = 0;
    return uVar1;
  }
  return 0xffffffff;
}


