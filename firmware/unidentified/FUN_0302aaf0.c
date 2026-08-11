/**
 * FUN_0302aaf0 @ 0x0302aaf0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0302aaf0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_0302ace0;
  iVar1 = DAT_0302ac84;
  *(undefined4 *)(DAT_0302ac84 + 0x7c) = 0;
  func_0x030124a0(0x74,0,2);
  func_0x03012474(1,0,2);
  iVar2 = *(int *)(iVar1 + 0x7c);
  while (iVar2 == 0) {
    FUN_030059bc();
    FUN_02ff73f0();
    FUN_030098c0(1);
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) break;
    iVar2 = *(int *)(iVar1 + 0x7c);
  }
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  return;
}


