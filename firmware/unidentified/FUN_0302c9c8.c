/**
 * FUN_0302c9c8 @ 0x0302c9c8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0302c9c8(undefined4 param_1)

{
  if (*DAT_0302ca9c != 0xff) {
                    /* WARNING: Could not recover jumptable at 0x0302c9e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(DAT_0302caa0 + *DAT_0302ca9c * 4))(5,param_1,0);
    return;
  }
  return;
}


