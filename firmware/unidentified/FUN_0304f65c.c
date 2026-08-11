/**
 * FUN_0304f65c @ 0x0304f65c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int * FUN_0304f65c(undefined4 param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  
  piVar2 = DAT_0304f8e0;
  DAT_0304f8e0[1] = -1;
  *piVar2 = -1;
  iVar3 = FUN_0304ec20(0);
  *piVar2 = iVar3;
  if ((iVar3 != -1) && (iVar3 = FUN_0304ecd4(iVar3,param_1,0,0), puVar1 = DAT_0304f8d0, iVar3 == 0))
  {
    *DAT_0304f8d0 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    uVar4 = FUN_0304f8f0();
    puVar1[2] = 0xffffffff;
    *puVar1 = uVar4;
    piVar2[1] = (int)puVar1;
    iVar3 = FUN_0304f5e0(puVar1,*piVar2);
    if (iVar3 != 0) {
      return piVar2;
    }
  }
  piVar5 = (int *)piVar2[1];
  if (piVar5 != (int *)0xffffffff) {
    if ((piVar5 != (int *)0x0) && (*piVar5 != -1)) {
      FUN_0304fdf0();
    }
    piVar2[1] = -1;
  }
  if (*piVar2 != -1) {
    FUN_0304ed30();
    *piVar2 = -1;
  }
  return (int *)0xffffffff;
}


