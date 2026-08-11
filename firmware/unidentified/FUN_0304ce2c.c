/**
 * FUN_0304ce2c @ 0x0304ce2c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0304ce2c(int param_1,uint param_2,int param_3,int param_4)

{
  longlong lVar1;
  int iVar2;
  uint *unaff_r5;
  int unaff_r7;
  int unaff_r8;
  bool bVar3;
  
  while( true ) {
    *unaff_r5 = param_2 | param_3 << 0x13;
    bVar3 = param_1 == 0;
    param_1 = param_1 + -1;
    if (bVar3) break;
    lVar1 = (longlong)(int)unaff_r5[1] * (longlong)param_4;
    param_3 = (int)((ulonglong)lVar1 >> 0x20);
    param_2 = (uint)lVar1 >> 0xd;
    unaff_r5 = unaff_r5 + 1;
  }
  iVar2 = 9;
  do {
    if (*(char *)(unaff_r7 + iVar2) == '\0') {
      FUN_0304c68c();
    }
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  iVar2 = 9;
  do {
    if (*(char *)(unaff_r7 + iVar2) == '\0') {
      FUN_0304c68c(unaff_r8 + 4);
    }
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return;
}


