/**
 * FUN_030f0740 @ 0x030f0740
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030f0740(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1[1];
  if ((char)uVar1 != '\0') {
    uVar2 = *param_1;
    (*(code *)*DAT_030f0894)(param_1,4);
    return ((1 << (0x20 - (byte)param_1[1] & 0xff)) - 1U & *param_1 >> (uint)(byte)param_1[1]) +
           (uVar2 << (uint)(byte)(0x20 - (char)uVar1));
  }
  (*(code *)*DAT_030f0894)(param_1,4,*DAT_030f0890);
  return *param_1;
}


