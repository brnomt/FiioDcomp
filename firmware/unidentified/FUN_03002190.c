/**
 * FUN_03002190 @ 0x03002190
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03002190(undefined4 *param_1,uint param_2,undefined4 param_3,uint param_4)

{
  undefined2 local_20;
  short local_1e;
  undefined2 local_1c;
  short local_1a;
  
  local_20 = *(undefined2 *)param_1;
  local_1e = *(short *)((int)param_1 + 2) + 5;
  local_1c = *(undefined2 *)(param_1 + 1);
  local_1a = *(short *)((int)param_1 + 2) + 0x14;
  FUN_02feb550(&local_20,*param_1,0x100005,param_4 & 0xffff0000 | param_2 & 0xffff,param_3,param_4);
  return;
}


