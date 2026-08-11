/**
 * FUN_030012e6 @ 0x030012e6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined2 FUN_030012e6(void)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = (uint)*(ushort *)(DAT_0300161c + 10);
  if (uVar2 == 0) {
    return 0;
  }
  iVar3 = DAT_0300161c + (uint)*(ushort *)(DAT_0300161c + 10) * 2;
  iVar4 = DAT_03001640 + (uint)*(ushort *)(DAT_0300161c + 10) * 4;
  if ((*(short *)(DAT_03001640 + uVar2 * 2 + 4) == 0x400) &&
     (*DAT_03001620 == 3 || *DAT_03001620 == 5)) {
    uVar1 = FUN_03001f28(*(undefined4 *)(iVar4 + 0xc),
                         (uint)*(ushort *)(DAT_0300161c + uVar2 * 2) + (uint)*(ushort *)(iVar3 + 10)
                         + -1,1);
    return uVar1;
  }
  uVar1 = FUN_03001f28(*(undefined4 *)(iVar4 + 0xc),
                       (uint)*(ushort *)(iVar3 + 10) + (uint)*(ushort *)(DAT_0300161c + uVar2 * 2),1
                      );
  return uVar1;
}


