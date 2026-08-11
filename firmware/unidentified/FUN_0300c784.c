/**
 * FUN_0300c784 @ 0x0300c784
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_0300c784(void)

{
  char *pcVar1;
  
  FUN_02ffa6d6();
  FUN_02ffa6d6(0x13f);
  pcVar1 = DAT_0300c82c;
  FUN_02feb4bc((int)*DAT_0300c82c);
  *pcVar1 = -1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


