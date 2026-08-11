/**
 * FUN_0301283e @ 0x0301283e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301283e(void)

{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = DAT_03012a24;
  sVar1 = *(short *)(DAT_03012a24 + 10);
  bVar4 = sVar1 != 4;
  if (bVar4) {
    sVar1 = *(short *)(DAT_03012a24 + 0xc);
  }
  if (!bVar4 || sVar1 == 1) {
    FUN_03012630(1);
    puVar2 = DAT_03012a20;
    FUN_0301245e(*(undefined4 *)(DAT_03012a20[0x7d] + 4),
                 DAT_03012a20 + (uint)*(ushort *)(DAT_03012a20 + 0x73) * 0xe + 3,
                 *(undefined1 *)(iVar3 + 8));
    FUN_030122a2(*(undefined4 *)(puVar2[0x7d] + 4),*puVar2,
                 puVar2 + (uint)*(ushort *)(puVar2 + 0x73) * 0xe + 3,
                 *(undefined2 *)((int)puVar2 + (uint)*(ushort *)(puVar2 + 0x73) * 2 + 0x1ce));
    *(undefined2 *)(iVar3 + 10) = 2;
    *(undefined2 *)(puVar2 + 2) = 1;
    *(undefined2 *)(iVar3 + 0xc) = 1;
    FUN_0301223a();
    MediaLib_GetTotalFiles_c(0x154);
    MediaLib_GetTotalFiles(0x14f);
    return;
  }
  return;
}


