/**
 * FUN_0301af1c @ 0x0301af1c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301af1c(void)

{
  ushort uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_0301af54;
  iVar3 = DAT_0301af50;
  puVar2 = DAT_0301af48;
  uVar1 = *(ushort *)(DAT_0301af50 + 0x1b1);
  *DAT_0301af48 = (uint)uVar1;
  *(ushort *)(iVar4 + 2) = uVar1;
  puVar2[1] = *(uint *)(iVar3 + 0x1b3);
  *DAT_0301af58 = 0;
  FUN_02ffde94(DAT_0301af54,(uint)uVar1,3,0,DAT_0301af5c);
  return;
}


