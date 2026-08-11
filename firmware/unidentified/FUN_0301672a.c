/**
 * FUN_0301672a @ 0x0301672a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301672a(void)

{
  int iVar1;
  
  iVar1 = ui_refresh_and_redraw(0xdf);
  if (iVar1 != 0) {
    return;
  }
  iVar1 = ui_refresh_and_redraw(0xe0);
  if (iVar1 != 0) {
    return;
  }
  iVar1 = ui_refresh_and_redraw(0x7d);
  if (iVar1 != 0) {
    return;
  }
  iVar1 = ui_refresh_and_redraw(0x6a);
  if (iVar1 != 0) {
    return;
  }
  iVar1 = ui_refresh_and_redraw(0xc9);
  if (iVar1 != 0) {
    return;
  }
  iVar1 = ui_refresh_and_redraw(200);
  if (iVar1 != 0) {
    return;
  }
  iVar1 = ui_refresh_and_redraw(0x26);
  if ((iVar1 != 0) && (iVar1 = ui_refresh_and_redraw(0xd1), iVar1 != 0)) {
    return;
  }
  FUN_0301575e();
  FUN_02fff2ce(0);
  return;
}


