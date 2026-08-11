/**
 * FUN_0308f0b4 @ 0x0308f0b4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0308f0b4(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  
  iVar2 = 0;
  uVar3 = 0;
  if (*(short *)(param_1 + 0x26) != 0) {
    do {
      iVar4 = param_2 + iVar2 * 0xfc;
      *(undefined4 *)(iVar4 + 8) = 0;
      *(undefined4 *)(iVar4 + 0xc4) = 1;
      *(undefined4 *)(iVar4 + 200) = 0;
      uVar3 = *(ushort *)(param_1 + 0x26);
      iVar2 = (int)(short)((short)iVar2 + 1);
    } while (iVar2 < (int)(uint)uVar3);
  }
  iVar2 = 0;
  if (uVar3 != 0) {
    do {
      sVar1 = *(short *)(param_1 + 0x9c) / 2;
      iVar4 = param_2 + iVar2 * 0xfc;
      *(short *)(iVar4 + 0x84) = sVar1;
      *(short *)(iVar4 + 0x86) = sVar1;
      iVar2 = (int)(short)((short)iVar2 + 1);
      **(undefined2 **)(*(int *)(iVar4 + 0xc0) + 8) = *(undefined2 *)(param_1 + 0x9c);
      *(undefined2 *)(iVar4 + 0x7e) = 0;
    } while (iVar2 < (int)(uint)*(ushort *)(param_1 + 0x26));
  }
  return 0;
}


