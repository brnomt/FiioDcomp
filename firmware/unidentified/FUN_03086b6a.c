/**
 * FUN_03086b6a @ 0x03086b6a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03086b6a(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(short *)(param_1 + 0x188)) {
    do {
      iVar3 = (int)*(short *)(*(int *)(param_1 + 0x18c) + iVar2 * 2);
      iVar1 = *(int *)(param_1 + 0xd8) + iVar3 * 0xfc;
      iVar2 = iVar2 + 1;
      iVar3 = *(int *)(param_1 + 0xdc) + ((*(int *)(param_1 + 0x9c) * 3) / 2) * iVar3 * 4 +
              (*(int *)(param_1 + 0x9c) >> 1) * 4 + *(short *)(iVar1 + 0x7e) * 4;
      *(int *)(iVar1 + 0x44) = iVar3;
      *(int *)(iVar1 + 0x9c) = iVar3;
      *(short *)(iVar1 + 0x7e) = *(short *)(iVar1 + 0x98) + *(short *)(iVar1 + 0x7e);
    } while (iVar2 < *(short *)(param_1 + 0x188));
  }
  return 0;
}


