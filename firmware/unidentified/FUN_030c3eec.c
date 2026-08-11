/**
 * FUN_030c3eec @ 0x030c3eec
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int * FUN_030c3eec(int *param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  
  bVar1 = param_1 != (int *)0x0;
  if (bVar1) {
    param_2 = *param_1;
  }
  bVar2 = param_2 != 0;
  if (bVar1 && bVar2) {
    param_2 = *(int *)(param_2 + 0x1c);
  }
  if ((!bVar1 || !bVar2) || param_2 == 0) {
    param_1 = (int *)0xffffffff;
  }
  if ((bVar1 && bVar2) && param_2 != 0) {
    param_1[10] = -1;
    param_1[9] = -1;
    param_1[0xe] = -1;
    param_1[0xf] = -1;
    param_1[0x10] = -1;
    param_1[0x11] = -1;
    param_1[0x12] = -1;
    param_1[0x13] = -1;
    return (int *)0x0;
  }
  return param_1;
}


