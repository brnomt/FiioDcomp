/**
 * FUN_0302ca22 @ 0x0302ca22
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0302ca22(void)

{
  if (*DAT_0302ca9c != 0xff) {
                    /* WARNING: Could not recover jumptable at 0x0302ca3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(DAT_0302caa0 + *DAT_0302ca9c * 4))(0xf,1,0);
    return;
  }
  return;
}


