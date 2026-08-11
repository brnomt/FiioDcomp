/**
 * FUN_0301a3b4 @ 0x0301a3b4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301a3b4(void)

{
  char cVar1;
  int iVar2;
  char *unaff_r5;
  short *unaff_r8;
  
  FUN_03008e98();
  if ((*unaff_r8 == 0) && (*unaff_r5 != '\0')) {
    FUN_03008e98(0x12d);
    FUN_03008e98(0x12a);
    FUN_03008e98(0x127);
  }
  iVar2 = FUN_03008ef8(0x21);
  cVar1 = '\0';
  if (iVar2 != 0) {
    cVar1 = *unaff_r5;
  }
  if (iVar2 != 0 && cVar1 != '\0') {
    FUN_03008e98(0x129);
  }
  return;
}


