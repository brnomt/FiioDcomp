/**
 * FUN_03087fd0 @ 0x03087fd0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03087fd0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = DAT_0308837c;
  iVar5 = 0;
  if (0 < *(short *)(param_1 + 0x188)) {
    do {
      iVar2 = *(int *)(param_1 + 0xd8) + *(short *)(*(int *)(param_1 + 0x18c) + iVar5 * 2) * 0xfc;
      iVar3 = (int)*(short *)(iVar2 + 0x84);
      if ((int)*(short *)(iVar2 + 0x86) <= (int)*(short *)(iVar2 + 0x84)) {
        iVar3 = (int)*(short *)(iVar2 + 0x86);
      }
      if (iVar3 - 0x40U < 0x7c1) {
        piVar4 = *(int **)(iVar1 + (iVar3 >> 7) * 4);
        *(int *)(iVar2 + 0x54) = *piVar4 >> 1;
        *(int *)(iVar2 + 0x58) = piVar4[1] >> 1;
        *(int *)(iVar2 + 0x5c) = -(*piVar4 >> 1);
        *(int *)(iVar2 + 0x60) = piVar4[1] >> 1;
        *(int *)(iVar2 + 100) = piVar4[8];
      }
      iVar5 = (int)(short)((short)iVar5 + 1);
    } while (iVar5 < *(short *)(param_1 + 0x188));
  }
  return 0;
}


