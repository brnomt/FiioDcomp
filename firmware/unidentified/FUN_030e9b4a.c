/**
 * FUN_030e9b4a @ 0x030e9b4a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030e9b4a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_030e9c44;
  DAT_030e9c44[1] = 0;
  *puVar1 = 0;
  FUN_030e48c6(puVar1[3]);
  FUN_030e4a10(puVar1[2],param_1,param_2,param_3);
  FUN_030e4a10(puVar1[3],param_4,param_5,param_3);
  if (puVar1[1] == 0) {
    do {
      FUN_030e9278();
    } while (puVar1[1] == 0);
    return;
  }
  return;
}


