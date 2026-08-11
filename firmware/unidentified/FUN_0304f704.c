/**
 * FUN_0304f704 @ 0x0304f704
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_0304f704(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    FUN_0304ed3e(*param_1,param_2,0);
    uVar1 = dict_stream_read(*param_1,param_4,param_3);
    return uVar1;
  }
  return 0xffffffff;
}


