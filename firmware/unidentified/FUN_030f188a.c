/**
 * FUN_030f188a @ 0x030f188a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030f188a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_030f1984;
  DAT_030f1984[1] = 0;
  *puVar1 = 0;
  FUN_030ed70e(puVar1[3]);
  FUN_030ed858(puVar1[2],param_1,param_2,param_3);
  FUN_030ed858(puVar1[3],param_4,param_5,param_3);
  if (puVar1[1] == 0) {
    do {
      FUN_030f0fb4();
    } while (puVar1[1] == 0);
    return;
  }
  return;
}


