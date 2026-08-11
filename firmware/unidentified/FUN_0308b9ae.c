/**
 * FUN_0308b9ae @ 0x0308b9ae
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0308b9ae(undefined4 param_1,undefined4 param_2,int *param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int iStack_70;
  int aiStack_6c [11];
  int iStack_40;
  int aiStack_3c [12];
  
  FUN_0308b604(param_1,param_2,&iStack_70,&iStack_40,param_4);
  piVar2 = &iStack_70;
  piVar1 = &iStack_40;
  if (param_4 < 2) {
    return;
  }
  uVar4 = param_4 - (param_4 >> 0x1f);
  piVar3 = param_3 + param_4;
  piVar6 = param_3 + -1;
  if ((uVar4 & 2) != 0) {
    *param_3 = -((aiStack_6c[0] >> 1) + (aiStack_3c[0] >> 1));
    piVar1 = aiStack_3c;
    piVar2 = aiStack_6c;
    piVar3 = piVar3 + -1;
    *piVar3 = (aiStack_3c[0] >> 1) - (aiStack_6c[0] >> 1);
    piVar6 = param_3;
  }
  iVar5 = (int)uVar4 >> 2;
  if (iVar5 != 0) {
    do {
      piVar6[1] = -((piVar2[1] >> 1) + (piVar1[1] >> 1));
      piVar3[-1] = (piVar1[1] >> 1) - (piVar2[1] >> 1);
      piVar2 = piVar2 + 2;
      piVar1 = piVar1 + 2;
      piVar6 = piVar6 + 2;
      *piVar6 = -((*piVar2 >> 1) + (*piVar1 >> 1));
      piVar3 = piVar3 + -2;
      *piVar3 = (*piVar1 >> 1) - (*piVar2 >> 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    return;
  }
  return;
}


