/**
 * FUN_0308d7e4 @ 0x0308d7e4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


bool FUN_0308d7e4(uint *param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 local_10;
  
  local_10 = 0;
  iVar1 = wma_input_cache_read
                    (param_1,&local_10,*param_1 + param_3 + 0x18,
                     param_1[1] + (uint)(0xffffffe7 < param_3) +
                     (uint)CARRY4(*param_1,param_3 + 0x18),param_2,&local_10);
  return iVar1 != param_2;
}


