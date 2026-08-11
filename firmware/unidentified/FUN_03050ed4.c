/**
 * FUN_03050ed4 @ 0x03050ed4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03050ed4(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = DAT_03051228;
  iVar3 = DAT_03051224;
  *DAT_03051228 = '\0';
  FUN_03040224(0xd1,0,2);
  FUN_030401f8(1,0,2);
  cVar1 = *pcVar2;
  while (cVar1 == '\0') {
    FUN_03033740();
    FUN_03025174();
    FUN_03037644(1);
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) break;
    cVar1 = *pcVar2;
  }
  *pcVar2 = '\0';
  return;
}


