/**
 * FUN_0306e498 @ 0x0306e498
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0306e498(undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  
  puVar2 = DAT_0306e89c;
  puVar1 = DAT_0306e898;
  iVar8 = param_1[1];
  iVar7 = 0;
  if (iVar8 != 0) {
    uVar5 = *DAT_0306e898;
    pcVar6 = (code *)*DAT_0306e89c;
    piVar4 = param_2;
    if (param_2[5] != 0) {
      piVar4 = (int *)param_2[6];
    }
    if (param_2[5] == 0 || piVar4 == (int *)0x0) {
      iVar8 = (*pcVar6)(*param_1,iVar8,uVar5);
    }
    else {
      piVar3 = (int *)*param_2;
      iVar7 = iVar8 - ((int)piVar4 - (int)piVar3);
      if (piVar3 == piVar4) {
        iVar7 = 0;
      }
      else {
        hifi_memmove(piVar3,piVar4,iVar7);
        pcVar6 = (code *)*puVar2;
        iVar8 = param_1[1] - iVar7;
        uVar5 = *puVar1;
        piVar3 = (int *)(*param_2 + iVar7);
      }
      iVar8 = (*pcVar6)(piVar3,iVar8,uVar5);
    }
    param_1[1] = iVar8 + iVar7;
    if (iVar8 + iVar7 != 0) {
      FUN_03070726(param_2,*param_1);
      return 0;
    }
  }
  return 0x10;
}


