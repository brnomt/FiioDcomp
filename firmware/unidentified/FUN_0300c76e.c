/**
 * FUN_0300c76e @ 0x0300c76e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_0300c76e(void)

{
  char *pcVar1;
  
  if (*(int *)(DAT_0300c828 + 8) == 1) {
    FUN_02ff7930();
    FUN_02ff8364();
  }
  FUN_02ffa6d6(0x13c);
  FUN_02ffa6d6(0x13f);
  pcVar1 = DAT_0300c82c;
  FUN_02feb4bc((int)*DAT_0300c82c);
  *pcVar1 = -1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


