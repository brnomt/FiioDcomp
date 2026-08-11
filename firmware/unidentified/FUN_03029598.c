/**
 * FUN_03029598 @ 0x03029598
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_03029598(code *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int param_5)

{
  undefined4 *puVar1;
  
  *(int *)(param_5 + 0x3c) = 1 << *(sbyte *)(param_5 + 0x1c);
  *(undefined4 *)(param_5 + 0x38) = DAT_0302991c;
  do {
  } while (0x100 < *(uint *)(param_5 + 0x3c));
  puVar1 = param_4;
  FUN_02ffb400(*(undefined4 *)(param_5 + 0x38),*(int *)(param_5 + 0x3c) << 2);
  (*param_1)(*(undefined4 *)(param_5 + 0x38),4,*(undefined4 *)(param_5 + 0x3c),*param_4,param_1,
             param_2,param_3,puVar1);
  return 1;
}


