/**
 * FUN_0308f2bc @ 0x0308f2bc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0308f2bc(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = DAT_0308f6ac;
  iVar6 = *param_1;
  param_1[2] = DAT_0308f6ac;
  iVar4 = 0;
  if (*(short *)(iVar6 + 0x26) != 0) {
    do {
      iVar5 = param_2 + iVar4 * 0xfc;
      puVar2 = (undefined4 *)(iVar1 + 0x10 + iVar4 * 0x18);
      *(undefined4 **)(iVar5 + 0xc0) = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        return DAT_0308f6b0;
      }
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      iVar3 = iVar4 * 0x43 + iVar1 + 0x40;
      *(int *)(*(int *)(iVar5 + 0xc0) + 4) = iVar3;
      if (iVar3 == 0) {
        return DAT_0308f6b0;
      }
      wma_memclr(iVar3,*(int *)(iVar6 + 0x80) * 2 + 7);
      iVar3 = *(int *)(*(int *)(iVar5 + 0xc0) + 4) + 2;
      *(int *)(*(int *)(iVar5 + 0xc0) + 8) = iVar3;
      iVar3 = iVar3 + *(int *)(iVar6 + 0x80) * 2 + 2;
      *(int *)(*(int *)(iVar5 + 0xc0) + 0xc) = iVar3;
      *(int *)(*(int *)(iVar5 + 0xc0) + 0x10) = iVar3 + 2;
      iVar4 = (int)(short)((short)iVar4 + 1);
    } while (iVar4 < (int)(uint)*(ushort *)(iVar6 + 0x26));
  }
  return 0;
}


