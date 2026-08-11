/**
 * FUN_0300b86c @ 0x0300b86c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300b86c(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char acStack_818 [32];
  undefined1 auStack_7f8 [102];
  undefined1 auStack_792 [258];
  char acStack_690 [1660];
  
  iVar1 = DAT_0300bc2c;
  uVar3 = 1;
  do {
    FUN_02fffd02(1,acStack_818,0x800);
    if (acStack_818[uVar3 * 0x188] == '\0') {
      iVar2 = FUN_02fe75ce(iVar1 + 0x10,auStack_7f8 + uVar3 * 0x188,0x66);
      if (iVar2 == 0) {
        FUN_02fe75ce(iVar1 + 0x76,auStack_792 + uVar3 * 0x188,0xc);
      }
    }
    FUN_02fface0(2,7);
    FUN_02fffd74(1,acStack_818,0x800);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 4);
  return;
}


