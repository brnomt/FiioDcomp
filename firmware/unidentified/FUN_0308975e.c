/**
 * FUN_0308975e @ 0x0308975e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_0308975e(int *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *param_1;
  iVar3 = 0;
  if ((short)param_1[0xd] < *(short *)(iVar4 + 0x188)) {
    do {
      iVar3 = 0;
      iVar2 = *(int *)(iVar4 + 0xd8) +
              *(short *)(*(int *)(iVar4 + 0x18c) + (short)param_1[0xd] * 2) * 0xfc;
      if ((*(int *)(iVar2 + 0x30) != 0) &&
         (iVar3 = FUN_0308959c(param_1,iVar2,0,*(undefined4 *)(iVar2 + 0x2c)), iVar3 < 0)) {
        return iVar3;
      }
      if (*(int *)(iVar4 + 0x40) == 1) {
        param_1[0x2b] = param_1[0x2b] - (param_1[0x2b] & 7U);
      }
      *(undefined2 *)(iVar4 + 0x6c) = 0;
      FUN_03086348(param_1);
      sVar1 = (short)param_1[0xd] + 1;
      *(short *)(param_1 + 0xd) = sVar1;
    } while (sVar1 < *(short *)(iVar4 + 0x188));
  }
  return iVar3;
}


