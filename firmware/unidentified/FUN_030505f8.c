/**
 * FUN_030505f8 @ 0x030505f8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030505f8(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = DAT_030509ac;
  uVar2 = 0;
  if (*(int *)(DAT_030509a4 + 0x24) == 0xf) {
    if (param_2 >> 2 != 0) {
      do {
        uVar4 = *(uint *)(iVar1 + 0xc004);
        *(undefined4 *)(uVar4 + iVar1) = *(undefined4 *)(param_1 + uVar2 * 4);
        *(uint *)(iVar1 + 0xc004) = ((uVar4 & 0xffff) + 4) % 0xc000;
        uVar2 = uVar2 + 1;
        *(int *)(iVar1 + 0xc008) = *(int *)(iVar1 + 0xc008) + 4;
      } while (uVar2 < param_2 >> 2);
      return;
    }
    return;
  }
  if (param_2 >> 2 != 0) {
    do {
      iVar3 = param_1 + uVar2 * 4;
      uVar4 = (uint)*(ushort *)(iVar1 + 0xc004);
      *(undefined1 *)(iVar1 + uVar4) = *(undefined1 *)(iVar3 + 1);
      *(undefined1 *)(iVar1 + uVar4 + 1) = *(undefined1 *)(iVar3 + 2);
      *(undefined1 *)(iVar1 + uVar4 + 2) = *(undefined1 *)(iVar3 + 3);
      *(uint *)(iVar1 + 0xc004) = (uVar4 + 3) % 0xc000;
      uVar2 = uVar2 + 1;
      *(int *)(iVar1 + 0xc008) = *(int *)(iVar1 + 0xc008) + 3;
    } while (uVar2 < param_2 >> 2);
    return;
  }
  return;
}


