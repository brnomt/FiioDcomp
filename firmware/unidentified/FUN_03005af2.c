/**
 * FUN_03005af2 @ 0x03005af2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03005af2(undefined4 *param_1,uint param_2,undefined4 param_3,uint param_4)

{
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  short local_1a;
  
  local_20 = *(undefined2 *)param_1;
  local_1e = *(undefined2 *)((int)param_1 + 2);
  local_1c = *(undefined2 *)(param_1 + 1);
  local_1a = *(short *)((int)param_1 + 2) + 0xf;
  FUN_02fee2a8(&local_20,*param_1,0x100000,param_4 & 0xffff0000 | param_2 & 0xffff,param_3,param_4);
  return;
}


