/**
 * MediaLib_thunk_GetFiles @ 0x03012838
 * Tags: media (**was** `debug_printf`)
 * Auto-exported from Ghidra decompilation
 */

void MediaLib_thunk_GetFiles(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  int unaff_r5;
  
  *(undefined1 *)(unaff_r5 + 2) = param_3;
  MediaLib_GetTotalFiles_c();
  return;
}
