/**
 * FUN_0306b340 @ 0x0306b340
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0306b340(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint in_r3;
  uint local_8;
  
  local_8 = in_r3;
  uVar2 = FmFreqToChan();
  iVar1 = DAT_0306b584;
  uVar3 = *(byte *)(DAT_0306b584 + 6) & 0x3f | (uVar2 & 3) << 6;
  *(ushort *)(DAT_0306b584 + 6) = (ushort)uVar3 | (ushort)(((int)uVar2 >> 2) << 8);
  local_8 = CONCAT13((char)uVar3,
                     CONCAT12((char)((int)uVar2 >> 2),
                              CONCAT11((char)*(undefined2 *)(iVar1 + 4),
                                       (char)((ushort)*(undefined2 *)(iVar1 + 4) >> 8)))) &
            0xffffffbf;
  FUN_0306b24a(&local_8,4);
  return;
}


