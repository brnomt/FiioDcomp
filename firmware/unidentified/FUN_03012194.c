/**
 * FUN_03012194 @ 0x03012194
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


char * FUN_03012194(int param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  
  cVar2 = *DAT_03012214;
  pcVar1 = DAT_03012214;
  while ((cVar2 != '\x06' &&
         (iVar3 = FUN_02ff307c(param_1 + 8,*(undefined4 *)(pcVar1 + 4),0x20), iVar3 != 1))) {
    pcVar1 = pcVar1 + 8;
    cVar2 = *pcVar1;
  }
  return pcVar1;
}


