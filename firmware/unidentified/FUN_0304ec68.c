/**
 * FUN_0304ec68 @ 0x0304ec68
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0304ec68(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    switch(*(undefined1 *)param_1) {
    case 0:
      return 0xfffffffd;
    case 1:
      if (param_1[8] != 0) {
        FUN_030198f0(param_1[7]);
      }
      if (param_1[7] != -1) {
        FUN_030198de();
        param_1[7] = 0xffffffff;
      }
      break;
    case 2:
    case 3:
    case 4:
      break;
    default:
      return 0xfffffffc;
    }
    FUN_0304f35c(param_1);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    *(undefined1 *)param_1 = 0;
    return 0;
  }
  return 0xfffffffe;
}


