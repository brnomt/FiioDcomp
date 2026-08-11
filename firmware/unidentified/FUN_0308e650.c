/**
 * FUN_0308e650 @ 0x0308e650
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_0308e650(undefined4 param_1)

{
  short sVar1;
  undefined1 auStack_90 [116];
  uint local_1c [5];
  
  FUN_03090174(auStack_90);
  sVar1 = FUN_0308282e(param_1);
  FUN_030900a2(auStack_90,param_1,(int)sVar1);
  FUN_030900ac(auStack_90,local_1c);
  return local_1c[0] + (uint)((ulonglong)DAT_0308e9a8 * (ulonglong)local_1c[0] >> 0x23) * -10;
}


