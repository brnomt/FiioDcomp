/**
 * FUN_0301a34a @ 0x0301a34a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301a34a(int param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  undefined2 unaff_r4;
  char *unaff_r5;
  char unaff_r6;
  undefined4 unaff_r7;
  short *unaff_r8;
  undefined1 *unaff_r9;
  undefined2 uStack00000001;
  undefined1 uStack00000003;
  
  *param_2 = param_1 + 1U;
  if ((uint)*DAT_0301a4b0 == param_1 + 1U) {
    FUN_02ff7e7c(DAT_0301a49c,DAT_0301a498);
    iVar2 = FUN_03008ef8(0x157);
    uStack00000001 = unaff_r4;
    if (iVar2 == 0) {
      uStack00000001 = *(undefined2 *)(DAT_0301a4a0 + 0x1b1);
    }
    uStack00000003 = (char)unaff_r4;
    FUN_030090c2(9);
    return 1;
  }
  cVar1 = *DAT_0301a45c;
  *unaff_r5 = unaff_r6;
  *unaff_r9 = (char)unaff_r4;
  if (cVar1 == '\0') {
    FUN_0301ab96(0x122,1);
    FUN_03008e98(0x128);
  }
  else {
    FUN_0301ab96(0x122,0xffffffff);
    FUN_03008e98(0x128);
  }
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
  return unaff_r7;
}


