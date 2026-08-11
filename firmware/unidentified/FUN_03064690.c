/**
 * FUN_03064690 @ 0x03064690
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03064690(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = DAT_0306487c;
  iVar1 = *(int *)(DAT_0306487c + 0x14);
  *(undefined1 *)(iVar1 + 0x50) = 1;
  uVar3 = (uint)*(ushort *)(iVar4 + 4);
  uVar2 = (uint)*(ushort *)(iVar4 + 6);
  iVar4 = (int)((ulonglong)
                ((longlong)DAT_0306488c * (longlong)(int)((*DAT_03064888 - 0x14) * (uVar3 - uVar2)))
               >> 0x20);
  uVar5 = (uint)((ulonglong)DAT_03064880 * (ulonglong)(((iVar4 >> 6) - (iVar4 >> 0x1f)) + uVar2) >>
                0x23) * 10;
  *(uint *)(iVar1 + 0xc) = uVar5;
  *(undefined2 *)(iVar1 + 10) = 0;
  if (uVar3 <= uVar5 && uVar5 - uVar3 != 0) {
    *(uint *)(iVar1 + 0xc) = uVar2;
  }
  if (*(uint *)(iVar1 + 0xc) < uVar2) {
    *(uint *)(iVar1 + 0xc) = uVar3;
  }
  return;
}


