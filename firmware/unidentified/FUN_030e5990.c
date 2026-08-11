/**
 * FUN_030e5990 @ 0x030e5990
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030e5990(int *param_1,uint param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  while( true ) {
    if (param_3 <= iVar2) {
      return;
    }
    uVar3 = param_1[2];
    bVar1 = *(byte *)(*param_1 + (uVar3 >> 3));
    param_1[2] = uVar3 + 1;
    if (((uint)bVar1 << (uVar3 & 7) & 0xff) >> 7 == param_2) break;
    iVar2 = iVar2 + 1;
  }
  return;
}


