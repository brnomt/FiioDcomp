/**
 * FUN_03003ac8 @ 0x03003ac8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03003ac8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 local_50;
  undefined4 uStack_4c;
  
  FUN_02ff5b78(&local_50,*DAT_03003b00,DAT_03003b00[3],param_3);
  FUN_02fecfc4(1,local_50,uStack_4c);
  if (*(char *)(DAT_03003b04 + 0xe) == '\x02') {
    uVar1 = 2;
  }
  else {
    uVar1 = 3;
  }
  FUN_02ff5cd0(uVar1,DAT_03003b08,0x1000);
  return;
}


