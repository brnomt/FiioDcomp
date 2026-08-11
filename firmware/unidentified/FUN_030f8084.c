/**
 * FUN_030f8084 @ 0x030f8084
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030f8084(undefined4 param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = DAT_030f80d0;
  iVar1 = DAT_030f80c0;
  FUN_030f7928(DAT_030f80c0 + 0x4c);
  if (*piVar2 != 0) {
    iVar3 = FUN_030f7d3c(DAT_030f80cc,iVar1 + 0x4c,*piVar2,param_1,*(undefined2 *)(iVar1 + 0x44));
    iVar3 = iVar3 / (int)(uint)*(ushort *)(iVar1 + 0x10);
    *param_2 = iVar3;
    return iVar3;
  }
  return *param_2;
}


