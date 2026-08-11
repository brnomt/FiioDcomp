/**
 * FUN_03086aa2 @ 0x03086aa2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03086aa2(int *param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar3 = *param_1;
  if (param_2 == 0) {
    param_1[0x1f] = 1;
    return 0;
  }
  iVar8 = 0;
  if (0 < *(short *)(iVar3 + 0x188)) {
    do {
      iVar4 = *(int *)(iVar3 + 0xd8) + *(short *)(*(int *)(iVar3 + 0x18c) + iVar8 * 2) * 0xfc;
      iVar1 = (int)*(short *)(iVar4 + 0x7c);
      iVar6 = *(int *)(*(int *)(iVar4 + 0xc0) + 8);
      if ((int)**(short **)(*(int *)(iVar4 + 0xc0) + 0xc) + (int)*(short *)(iVar6 + iVar1 * 2) <
          *(int *)(iVar3 + 0x9c)) {
        iVar7 = iVar1 * 2 + 2;
        *(short *)(iVar6 + iVar7) = (short)param_2;
        psVar2 = *(short **)(*(int *)(iVar4 + 0xc0) + 0xc);
        sVar5 = *psVar2 + *(short *)(*(int *)(*(int *)(iVar4 + 0xc0) + 8) + iVar1 * 2);
        *psVar2 = sVar5;
        psVar2 = *(short **)(iVar4 + 0xc0);
        if (*(int *)(iVar3 + 0x9c) < (int)sVar5 + (int)*(short *)(*(int *)(psVar2 + 4) + iVar7)) {
          return DAT_03086bec;
        }
        *psVar2 = *psVar2 + 1;
      }
      else {
        param_1[0x1f] = 1;
        *(short *)(*(int *)(*(int *)(iVar4 + 0xc0) + 8) + iVar1 * 2 + 2) = (short)param_2;
      }
      iVar8 = (int)(short)((short)iVar8 + 1);
    } while (iVar8 < *(short *)(iVar3 + 0x188));
  }
  return 0;
}


