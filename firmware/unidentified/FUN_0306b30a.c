/**
 * FUN_0306b30a @ 0x0306b30a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0306b30a(void)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined1 local_60 [92];
  
  uVar3 = 0;
  do {
    uVar2 = *(undefined2 *)(DAT_0306b584 + uVar3 * 2 + 4);
    local_60[uVar3 * 2] = (char)((ushort)uVar2 >> 8);
    iVar1 = uVar3 * 2;
    uVar3 = uVar3 + 1 & 0xff;
    local_60[iVar1 + 1] = (char)uVar2;
  } while (uVar3 < 0x18);
  FUN_0306b24a(local_60,0x30);
  return;
}


