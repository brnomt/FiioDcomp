/**
 * FUN_030873fc @ 0x030873fc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030873fc(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iStack_10;
  
  iVar2 = *param_1;
  iStack_10 = param_4;
  iVar1 = FUN_03088390(param_1 + 0x21,0x15);
  if (iVar1 < 0) {
    return;
  }
  while( true ) {
    iVar1 = wma_bitreader_getbits(param_1 + 0x21,7,&iStack_10);
    if (iVar1 < 0) {
      return;
    }
    if (iStack_10 != 0x7f) break;
    *(int *)(iVar2 + 0xc4) = *(int *)(iVar2 + 0xc4) + 0x7f;
  }
  *(int *)(iVar2 + 0xc4) = iStack_10 + *(int *)(iVar2 + 0xc4);
  return;
}


