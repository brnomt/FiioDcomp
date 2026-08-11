/**
 * FUN_03013826 @ 0x03013826
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_03013826(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = MediaLib_GetTotalFiles_d(0xdf);
  if (iVar1 != 0) {
    return;
  }
  iVar2 = MediaLib_GetTotalFiles_d(0xe0);
  iVar1 = DAT_03013ae0;
  if (iVar2 != 0) {
    return;
  }
  if (*(char *)(DAT_03013ae0 + 3) == '\x01') {
    FUN_03012a44();
  }
  if (*(char *)(iVar1 + 3) == '\x02') {
    FUN_03013714();
  }
  iVar1 = MediaLib_GetTotalFiles_d(1);
  if (iVar1 == 0) {
    return;
  }
  iVar1 = MediaLib_GetTotalFiles_b(0x3e);
  if (iVar1 != 1) {
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


