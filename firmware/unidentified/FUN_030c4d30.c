/**
 * FUN_030c4d30 @ 0x030c4d30
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


bool FUN_030c4d30(int *param_1,int *param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(*param_1 + 0x1c) + param_1[0xc] * 4);
  if (param_3 == 0) {
    memset_byte(param_4,0,(uVar1 & 0x3fffffff) << 1);
  }
  else {
    FUN_030c4528(param_4,(int)uVar1 / 2,param_2[2],param_3,*param_2,
                 *(undefined4 *)(param_3 + *param_2 * 4),param_2[4],param_2[1] >> 1);
  }
  return param_3 != 0;
}


