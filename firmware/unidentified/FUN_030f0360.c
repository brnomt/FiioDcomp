/**
 * FUN_030f0360 @ 0x030f0360
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030f0360(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_030f0468;
  iVar1 = FUN_030f0178(DAT_030f0468,DAT_030f0464);
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_030f007a(uVar2,param_1);
  }
  *param_2 = uVar2;
  return;
}


