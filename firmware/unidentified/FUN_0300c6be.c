/**
 * FUN_0300c6be @ 0x0300c6be
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300c6be(undefined2 *param_1)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_0300c820;
  *(undefined2 *)(DAT_0300c820 + 0x21d) = *param_1;
  FUN_02ff3e26();
  FUN_02ffa538(0x1a);
  FUN_0300cdea();
  iVar1 = DAT_0300c834;
  *DAT_0300c830 = 0;
  *(undefined2 *)(iVar1 + 0xf2) = 0;
  iVar3 = FUN_02fef674(iVar1,*(undefined2 *)(iVar4 + 0x21d),3,0);
  iVar4 = DAT_0300c824;
  if (iVar3 == 0) {
    *(undefined4 *)(DAT_0300c824 + 4) = *(undefined4 *)(iVar1 + 0x30);
    FUN_02fe7572(iVar4 + 0x10,iVar1 + 0x9a,0x66);
    FUN_02fed62c(*(undefined4 *)(iVar1 + 0x34),*(int *)(iVar1 + 0x38) + -1,3,iVar4 + 0x82);
    *(undefined4 *)(iVar4 + 0x76) = *(undefined4 *)(iVar1 + 0x14);
    *(undefined4 *)(iVar4 + 0x7a) = *(undefined4 *)(iVar1 + 0x18);
    *(undefined2 *)(iVar4 + 0x7e) = *(undefined2 *)(iVar1 + 0x1c);
    *(undefined1 *)(iVar4 + 0x80) = *(undefined1 *)(iVar1 + 0x1e);
    *(undefined1 *)(iVar4 + 0x81) = 0;
    iVar4 = FUN_0300ca34();
    if (iVar4 == 0) {
      uVar2 = FUN_02feafee(iVar1 + 0x14,*(undefined4 *)(iVar1 + 0x34),*(int *)(iVar1 + 0x38) + -1,3)
      ;
      *DAT_0300c82c = uVar2;
      FUN_0300cd58();
    }
  }
  FUN_02ffa694(0x135);
  FUN_02ffa694(0x13f);
  return;
}


