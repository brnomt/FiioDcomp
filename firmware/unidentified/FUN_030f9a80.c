/**
 * FUN_030f9a80 @ 0x030f9a80
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined8 FUN_030f9a80(int param_1,uint param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_030f6be2();
  if (((int)(0x7ff00000 - ((uint)((int)uVar1 != 0) | (uint)((ulonglong)uVar1 >> 0x20) & 0x7fffffff))
       < 0) && (-1 < (int)(0x7ff00000 - ((uint)(param_1 != 0) | param_2 & 0x7fffffff)))) {
    FUN_030f87dc(1);
  }
  return uVar1;
}


