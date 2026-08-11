/**
 * FUN_0302ca7c @ 0x0302ca7c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0302ca7c(undefined4 param_1)

{
  if (*DAT_0302ca9c != 0xff) {
                    /* WARNING: Could not recover jumptable at 0x0302ca98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(DAT_0302caa0 + *DAT_0302ca9c * 4))(0x11,param_1,0);
    return;
  }
  return;
}


