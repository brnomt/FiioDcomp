/**
 * FUN_03083faa @ 0x03083faa
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03083faa(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  
  iVar2 = 0;
  sVar5 = 0;
  do {
    *(char *)(param_1 + iVar2) = (char)iVar2;
    sVar5 = sVar5 + 2;
    *(char *)(param_1 + iVar2 + 1) = (char)(iVar2 + 1);
    iVar2 = iVar2 + 2;
  } while (sVar5 < 0x100);
  iVar2 = 0;
  *(undefined1 *)(param_1 + 0x100) = 0;
  *(undefined1 *)(param_1 + 0x101) = 0;
  uVar6 = 0;
  uVar3 = 0;
  iVar4 = 0x100;
  do {
    bVar1 = *(byte *)(param_1 + iVar2);
    uVar6 = uVar6 + bVar1 + (uint)*(byte *)(param_3 + uVar3) & 0xff;
    *(undefined1 *)(param_1 + iVar2) = *(undefined1 *)(param_1 + uVar6);
    *(byte *)(param_1 + uVar6) = bVar1;
    iVar2 = iVar2 + 1;
    uVar3 = (uVar3 + 1) - param_2 * ((int)(uVar3 + 1) / param_2) & 0xff;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}


