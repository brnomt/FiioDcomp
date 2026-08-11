/**
 * FUN_0304ece0 @ 0x0304ece0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0304ece0(undefined1 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_0304ec68();
  *param_1 = 1;
  uVar1 = FUN_0303e848(param_2,1,1);
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  *(undefined4 *)(param_1 + 0x20) = 0;
  if (*(int *)(param_1 + 0x1c) != -1) {
    uVar1 = FUN_030198f4(*(int *)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x14) = uVar1;
    iVar2 = *(int *)(param_1 + 0xc);
    if (iVar2 < 0) {
      *(int *)(param_1 + 0x18) = iVar2;
    }
    else {
      iVar2 = FUN_030198e4(*(undefined4 *)(param_1 + 0x1c),iVar2,0);
      *(int *)(param_1 + 0x18) = iVar2;
      if (iVar2 < 0) {
        *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0xc);
      }
    }
    return 0;
  }
  return 0xfffffffe;
}


