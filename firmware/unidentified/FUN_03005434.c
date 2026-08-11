/**
 * FUN_03005434 @ 0x03005434
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_03005434(byte param_1)

{
  uint uVar1;
  int unaff_r5;
  undefined2 in_stack_00000078;
  undefined2 uStack0000007a;
  undefined2 in_stack_0000007c;
  undefined2 uStack0000007e;
  
  FUN_02fef2b2(0x13c,0xfc);
  uVar1 = param_1 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + (uint)param_1 * 2) = 0;
  *(undefined2 *)(unaff_r5 + uVar1 * 2) = 0;
  uVar1 = uVar1 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar1 * 2) = 0;
  *(undefined2 *)(unaff_r5 + (uVar1 + 1 & 0xff) * 2) = 0;
  in_stack_00000078 = 0x1e;
  uStack0000007a = 0x76;
  in_stack_0000007c = 0x122;
  uStack0000007e = 0x85;
  FUN_02fee544(1);
  if (*(char *)(FUN_03005604 + 0x34f) == '\x04') {
    uRam0301d750 = 0xe162;
  }
  else {
    uRam0301d750 = 0x44de;
  }
                    /* WARNING: Read-only address (ram,0x0301d750) is written */
  FUN_02feda18(&stack0x00000078);
  FUN_02fee544(2);
  return;
}


