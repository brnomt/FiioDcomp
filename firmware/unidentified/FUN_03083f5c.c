/**
 * FUN_03083f5c @ 0x03083f5c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03083f5c(int param_1,short param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = (uint)*(byte *)(param_1 + 0x100);
  uVar4 = (uint)*(byte *)(param_1 + 0x101);
  iVar3 = 0;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    uVar2 = uVar2 + 1 & 0xff;
    bVar1 = *(byte *)(param_1 + uVar2);
    uVar4 = uVar4 + bVar1 & 0xff;
    *(undefined1 *)(param_1 + uVar2) = *(undefined1 *)(param_1 + uVar4);
    *(byte *)(param_1 + uVar4) = bVar1;
    *(byte *)(param_3 + iVar3) =
         *(byte *)(param_1 + ((uint)bVar1 + (uint)*(byte *)(param_1 + uVar2) & 0xff)) ^
         *(byte *)(param_3 + iVar3);
    iVar3 = (int)(short)((short)iVar3 + 1);
  }
  *(char *)(param_1 + 0x100) = (char)uVar2;
  *(char *)(param_1 + 0x101) = (char)uVar4;
  return;
}


