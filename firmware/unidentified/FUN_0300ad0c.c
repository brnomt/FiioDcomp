/**
 * FUN_0300ad0c @ 0x0300ad0c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300ad0c(void)

{
  int iVar1;
  undefined2 unaff_r5;
  undefined1 unaff_r6;
  undefined1 *unaff_r7;
  undefined2 *unaff_r10;
  
  FUN_03010d78(0x7d,0);
  *unaff_r10 = unaff_r5;
  FUN_02ff9700(0x6a);
  *unaff_r7 = unaff_r6;
  if ((DAT_0307a928 == '\x01' || DAT_0307a928 == '\x02') &&
     (iVar1 = FUN_02ff8bf2(), 1 < (uint)(iVar1 - DAT_0307a930))) {
    DAT_0307a92c = DAT_0307a92c + 1;
    DAT_0307a930 = iVar1;
    FUN_02ff9700(0x1b1);
  }
  return;
}


