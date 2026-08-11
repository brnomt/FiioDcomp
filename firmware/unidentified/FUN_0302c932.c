/**
 * FUN_0302c932 @ 0x0302c932
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0302c932(void)

{
  if (*DAT_0302ca9c != 0xff) {
                    /* WARNING: Could not recover jumptable at 0x0302c94e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(DAT_0302caa0 + *DAT_0302ca9c * 4))(0xc,0,0);
    return;
  }
  return;
}


