/**
 * FUN_0301db2a @ 0x0301db2a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0301db2a(undefined4 param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_r4;
  uint uVar5;
  int unaff_r5;
  int unaff_r6;
  int unaff_r7;
  
  uVar2 = (undefined1)param_4;
  *(undefined1 *)(param_3 + param_2) = uVar2;
  *(undefined4 *)(unaff_r5 + 0x44) = param_1;
  *(char *)(unaff_r4 + 0x19) = (char)param_2;
  uVar4 = *(undefined4 *)(unaff_r5 + 4);
  uVar1 = *(ushort *)(param_4 + unaff_r5);
  uVar5 = (uint)uVar1;
  *(undefined1 *)(unaff_r6 + 0x11) = uVar2;
  *(undefined1 *)(unaff_r6 + 0x11) = uVar2;
  *(char *)(uVar5 + 0x15) = (char)uVar4;
  *(char *)(uVar5 + 0xd) = (char)uVar1;
  iVar3 = (int)*(short *)(param_4 + unaff_r7);
  *(uint *)(unaff_r7 + 0x3c) = uVar5;
  *(int *)(param_4 + 0x7c) = iVar3;
  if (iVar3 + 1 != 0) {
    FUN_0301d69c(iVar3,iVar3 + 1,iVar3 << 0xc);
  }
  return 0;
}


