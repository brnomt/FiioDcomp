/**
 * FUN_03027cb4 @ 0x03027cb4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03027cb4(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  
  FUN_03027afa();
  iVar1 = DAT_03027e38;
  iVar3 = DAT_03027e3c + 0xc;
  *(int *)(DAT_03027e38 + 0x74) = iVar3;
  puVar4 = (undefined2 *)
           (*(int *)(iVar1 + 0x38) * (*(int *)(iVar1 + 0x70) + -2) * *(int *)(iVar1 + 0x6c) + iVar3)
  ;
  *(undefined2 **)(iVar1 + 0x78) = puVar4;
  uVar2 = DAT_03027e4c;
  if (*(int *)(iVar1 + 0x30) == 1) {
    for (iVar3 = 0; iVar5 = *(int *)(iVar1 + 0x6c) * *(int *)(iVar1 + 0x38),
        iVar5 - iVar3 != 0 && iVar3 <= iVar5; iVar3 = (int)(short)((short)iVar3 + 1)) {
      *puVar4 = (short)uVar2;
      puVar4 = puVar4 + 1;
    }
  }
  FUN_0302747a((int)*(short *)(iVar1 + 6),(int)*(short *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x18),
               *(undefined4 *)(iVar1 + 0x74),*(undefined4 *)(iVar1 + 0x78));
  return 1;
}


