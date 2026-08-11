/**
 * FUN_030f07ca @ 0x030f07ca
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030f07ca(uint *param_1)

{
  byte bVar1;
  
  if ((char)param_1[1] != '\0') {
    bVar1 = (char)param_1[1] - 8;
    *(byte *)(param_1 + 1) = bVar1;
    return *param_1 >> (uint)bVar1 & 0xff;
  }
  (*(code *)*DAT_030f0894)(param_1,4,*DAT_030f0890);
  *(undefined1 *)(param_1 + 1) = 0x18;
  return *param_1 >> 0x18;
}


