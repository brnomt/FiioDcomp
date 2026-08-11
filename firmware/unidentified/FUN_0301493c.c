/**
 * FUN_0301493c @ 0x0301493c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301493c(undefined2 *param_1)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  
  puVar1 = DAT_030149d4;
  *(undefined2 *)(DAT_030149d4 + 2) = *param_1;
  FUN_0300992c(s_Setdef____d_030149d8);
  FUN_03014a0a();
  func_0x030037a8(199);
  ui_post_redraw(0x1dc);
  puVar2 = DAT_030149e8;
  *(undefined2 *)(puVar1 + 4) = 0;
  puVar2[1] = 0;
  puVar2[3] = 0;
  *puVar2 = 0;
  puVar2[2] = 0;
  *DAT_030149ec = 0;
  FUN_02ffcf3a();
  *puVar1 = 0;
  ui_post_redraw(0x9e);
  ui_post_redraw(0x1cc);
  ui_post_redraw(0xca);
  FUN_03003df4(2,7);
  ui_post_redraw(0xae);
  ui_post_redraw(0x1b0);
  ui_post_redraw(0xaf);
  ui_post_redraw(0xac);
  return;
}


