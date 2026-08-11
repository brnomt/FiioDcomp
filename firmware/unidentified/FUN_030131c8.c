/**
 * FUN_030131c8 @ 0x030131c8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030131c8(void)

{
  undefined4 *puVar1;
  int iVar2;
  ushort uVar3;
  undefined4 in_r3;
  
  iVar2 = DAT_03013278;
  puVar1 = DAT_03013274;
  if (*(short *)(DAT_03013274 + 0x73) == 0) {
    *(undefined2 *)(DAT_03013278 + 0xc) = 1;
    FUN_0301223a();
    MediaLib_GetTotalFiles(0x14d);
    MediaLib_GetTotalFiles(0x153);
    return 0;
  }
  uVar3 = *(short *)(DAT_03013274 + 0x73) - 1;
  *(ushort *)(DAT_03013274 + 0x73) = uVar3;
  *(undefined2 *)((int)puVar1 + 0x1ee) = *(undefined2 *)((int)puVar1 + (uint)uVar3 * 2 + 0x1de);
  FUN_0301245e(*(undefined4 *)(puVar1[0x7d] + 4),puVar1 + (uint)uVar3 * 0xe + 3,
               *(undefined1 *)(iVar2 + 8),in_r3,in_r3);
  FUN_030122a2(*(undefined4 *)(puVar1[0x7d] + 4),*puVar1,
               puVar1 + (uint)*(ushort *)(puVar1 + 0x73) * 0xe + 3,
               *(undefined2 *)((int)puVar1 + (uint)*(ushort *)(puVar1 + 0x73) * 2 + 0x1ce),
               *(undefined1 *)(iVar2 + 8));
  if (*(short *)(puVar1 + 0x73) == 0) {
    MediaLib_GetTotalFiles(0x14d);
    MediaLib_GetTotalFiles(0x153);
  }
  MediaLib_GetTotalFiles(0x14f);
  return 0;
}


