/**
 * FUN_0300b034 @ 0x0300b034
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_0300b034(void)

{
  int iVar1;
  
  iVar1 = FUN_02fe878c(*DAT_0300b05c,DAT_0300b058);
  if (iVar1 != 1) {
    return;
  }
  FUN_02fff884(s_RecordWinSvcStop_0300b060);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


