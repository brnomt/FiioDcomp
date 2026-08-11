/**
 * FUN_03001f96 @ 0x03001f96
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03001f96(void)

{
  ushort uVar1;
  int *piVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  
  puVar3 = DAT_03002150;
  piVar2 = DAT_0300214c;
  iVar4 = *DAT_03002148;
  *DAT_0300214c = iVar4;
  uVar1 = *puVar3;
  if (uVar1 == 4) {
    *(undefined2 *)(piVar2 + 1) = 0x600;
    *(undefined2 *)((int)piVar2 + 6) = 0x400;
    piVar2[3] = iVar4 + 0x52140;
    piVar2[4] = iVar4 + 0x52160;
    FUN_02ff6210(s_SortInfoAddr_ulFileSortInfoSecto_03002154);
    return;
  }
  if (4 < uVar1) {
    if (uVar1 == 5) {
      *(undefined2 *)(piVar2 + 1) = 0x700;
      *(undefined2 *)((int)piVar2 + 6) = 0x500;
      *(undefined2 *)(piVar2 + 2) = 0x600;
      *(undefined2 *)((int)piVar2 + 10) = 0x400;
      piVar2[3] = iVar4 + 0x521e0;
      piVar2[4] = iVar4 + 0x52200;
      piVar2[5] = iVar4 + 0x52280;
      piVar2[6] = iVar4 + 0x52300;
      return;
    }
    return;
  }
  if (uVar1 == 1) {
    *(undefined2 *)(piVar2 + 1) = 0x400;
    iVar5 = iVar4 + 0x52000;
  }
  else {
    iVar5 = iVar4 + 0x50000;
    if (uVar1 != 2) {
      if (uVar1 == 3) {
        *(undefined2 *)(piVar2 + 1) = 0x500;
        *(undefined2 *)((int)piVar2 + 6) = 0x600;
        *(undefined2 *)(piVar2 + 2) = 0x400;
        piVar2[3] = iVar4 + 0xa2020;
        piVar2[4] = iVar4 + 0xa2040;
        piVar2[5] = iVar4 + 0xa20c0;
        return;
      }
      return;
    }
    *(undefined2 *)(piVar2 + 1) = 0x400;
  }
  piVar2[3] = iVar5;
  return;
}


