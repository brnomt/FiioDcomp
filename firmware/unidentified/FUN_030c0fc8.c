/**
 * FUN_030c0fc8 @ 0x030c0fc8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


char * FUN_030c0fc8(char *param_1,char param_2,int param_3)

{
  bool bVar1;
  
  while( true ) {
    bVar1 = param_3 == 0;
    param_3 = param_3 + -1;
    if (bVar1) {
      return (char *)0x0;
    }
    if (*param_1 == param_2) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}


