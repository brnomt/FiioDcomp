/**
 * shared_mid_entry_c6f6 @ 0x0300c6f6
 * Tags: os (**bogus former event_clear**)
 * Auto-exported from Ghidra decompilation
 */

void shared_mid_entry_c6f6(void)

{
  undefined1 uVar1;
  int iVar2;
  int unaff_r5;
  undefined1 unaff_r6;
  char in_ZR;
  
  iVar2 = DAT_0300c824;
  if (in_ZR != '\0') {
    *(undefined4 *)(DAT_0300c824 + 4) = *(undefined4 *)(unaff_r5 + 0x30);
    FUN_02fe7572(iVar2 + 0x10,unaff_r5 + 0x9a,0x66);
    FUN_02fed62c(*(undefined4 *)(unaff_r5 + 0x34),*(int *)(unaff_r5 + 0x38) + -1,3,iVar2 + 0x82);
    *(undefined4 *)(iVar2 + 0x76) = *(undefined4 *)(unaff_r5 + 0x14);
    *(undefined4 *)(iVar2 + 0x7a) = *(undefined4 *)(unaff_r5 + 0x18);
    *(undefined2 *)(iVar2 + 0x7e) = *(undefined2 *)(unaff_r5 + 0x1c);
    *(undefined1 *)(iVar2 + 0x80) = *(undefined1 *)(unaff_r5 + 0x1e);
    *(undefined1 *)(iVar2 + 0x81) = unaff_r6;
    iVar2 = __align();
    if (iVar2 == 0) {
      uVar1 = FUN_02feafee(unaff_r5 + 0x14,*(undefined4 *)(unaff_r5 + 0x34),
                           *(int *)(unaff_r5 + 0x38) + -1,3);
      *DAT_0300c82c = uVar1;
      CodeResume();
    }
  }
  FUN_02ffa694(0x135);
  FUN_02ffa694(0x13f);
  return;
}
