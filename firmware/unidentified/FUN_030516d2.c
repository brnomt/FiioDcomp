/**
 * FUN_030516d2 @ 0x030516d2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030516d2(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  FUN_0302916a(0x1d);
  FUN_030290c0(0x1d);
  FUN_03039734(0x1d);
  iVar1 = DAT_03051a88;
  iVar2 = *(int *)(DAT_03051a88 + 0x2c);
  bVar3 = iVar2 == 1;
  if (bVar3) {
    iVar2 = *(int *)(DAT_03051a88 + 0x10);
  }
  if (bVar3 && iVar2 == 5) {
    FUN_03024598(3,0);
    FUN_03028194(0,2,0,*(undefined4 *)(iVar1 + 0x18),0,*(undefined1 *)(iVar1 + 0x24),0);
    return;
  }
  FUN_030506b0(*(undefined4 *)(DAT_03051a88 + 0x14));
  FUN_03022304(0,2);
  return;
}


