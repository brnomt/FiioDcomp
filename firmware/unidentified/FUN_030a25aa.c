/**
 * FUN_030a25aa @ 0x030a25aa
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 * FUN_030a25aa(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_030a26b0;
  uVar2 = FUN_030a26b4(param_1,0,0);
  *puVar1 = uVar2;
  uVar2 = FUN_030a26b4(param_1,1,0);
  puVar1[1] = uVar2;
  puVar1[2] = param_1;
  return puVar1;
}


