/**
 * FUN_0304fe20 @ 0x0304fe20
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_0304fe20(short *param_1,int param_2,int param_3)

{
  int unaff_r5;
  
  if (param_1 != (short *)0x0 && param_2 != -1) {
    if (*param_1 != 0x75 && *param_1 != 0x76) {
      unaff_r5 = FUN_03050172(param_1,param_2,param_3);
    }
    if (unaff_r5 < *(int *)(param_3 + 4)) {
      FUN_0301a35c(*(int *)(param_3 + 0xc) * unaff_r5 + *(int *)(param_3 + 8),
                   *(int *)(param_3 + 0xc) * (*(int *)(param_3 + 4) - unaff_r5));
    }
    return unaff_r5;
  }
  return 0;
}


