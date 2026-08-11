/**
 * FUN_03051744 @ 0x03051744
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03051744(void)

{
  int iVar1;
  short *psVar2;
  undefined4 uVar3;
  
  psVar2 = DAT_03051a8c;
  if (*DAT_03051a8c != 1) {
    if (*DAT_03051a8c == 2) {
      FUN_030386aa();
    }
    FUN_03051680();
    uVar3 = FUN_03021f9a(0);
    iVar1 = DAT_03051a88;
    if (*psVar2 != 1) {
      *(ushort *)(DAT_03051a88 + 0xc) = *(ushort *)(DAT_03051a88 + 0xc) | 2;
      *(undefined4 *)(iVar1 + 0x34) = 1;
      FUN_0303238c(5,uVar3,*(undefined4 *)(iVar1 + 0x44),*(uint *)(iVar1 + 0x3c) >> 1);
      *psVar2 = 1;
      *(undefined4 *)(iVar1 + 0x30) = 0;
      *(ushort *)(iVar1 + 10) = *(ushort *)(iVar1 + 10) & 0xfffe | 2;
      FUN_03022252(0,2);
      if (*(int *)(iVar1 + 0x2c) == 0) {
        FUN_030234d6(0,*(undefined4 *)(iVar1 + 0x24),0,1);
        FUN_030506de(*(undefined4 *)(iVar1 + 0x14));
        FUN_0303323e(*(undefined4 *)(iVar1 + 0x18));
      }
    }
    return 1;
  }
  return 1;
}


