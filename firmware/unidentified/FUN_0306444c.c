/**
 * FUN_0306444c @ 0x0306444c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0306444c(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = DAT_03064474;
  iVar5 = *(int *)(DAT_03064474 + 0x14);
  if (param_1 == 0) {
    param_2 = -param_2;
  }
  uVar4 = *(int *)(iVar5 + 0xc) + param_2;
  *(uint *)(iVar5 + 0xc) = uVar4;
  uVar2 = *(ushort *)(iVar3 + 4);
  uVar1 = *(ushort *)(DAT_03064474 + 6);
  if (uVar2 < uVar4) {
    *(uint *)(iVar5 + 0xc) = (uint)uVar1;
  }
  if (*(uint *)(iVar5 + 0xc) < (uint)uVar1) {
    *(uint *)(iVar5 + 0xc) = (uint)uVar2;
  }
  return;
}


