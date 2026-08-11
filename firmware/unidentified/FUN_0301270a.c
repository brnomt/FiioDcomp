/**
 * FUN_0301270a @ 0x0301270a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_0301270a(undefined1 *param_1)

{
  undefined1 uVar1;
  short sVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined2 *puVar6;
  
  puVar4 = DAT_03012a24;
  DAT_03012a24[4] = *param_1;
  *(undefined2 *)(puVar4 + 6) = *(undefined2 *)(param_1 + 1);
  MediaLib_GetTotalFiles_c(0x159);
  if (puVar4[4] == '\x06') {
    MediaLib_GetTotalFiles(0x157);
  }
  else {
    MediaLib_GetTotalFiles_c();
  }
  puVar5 = DAT_03012a30;
  puVar4[5] = 0;
  *puVar5 = 0x5c;
  puVar5[1] = 0;
  *(undefined2 *)(puVar4 + 8) = 3;
  if (*(short *)(puVar4 + 6) == 0) {
    MediaLib_GetTotalFiles_c(0x15d);
    FUN_03012630(1);
    FUN_030124a4(*(undefined2 *)(puVar4 + 6));
  }
  else {
    MediaLib_GetTotalFiles();
    FUN_03012630(1);
    FUN_030124a4(*(undefined2 *)(puVar4 + 6));
  }
  puVar3 = DAT_03012a20;
  FUN_0301245e(*(undefined4 *)(DAT_03012a20[0x7d] + 4),
               DAT_03012a20 + (uint)*(ushort *)(DAT_03012a20 + 0x73) * 0xe + 3,puVar4[8]);
  FUN_030122a2(*(undefined4 *)(puVar3[0x7d] + 4),*puVar3,
               puVar3 + (uint)*(ushort *)(puVar3 + 0x73) * 0xe + 3,
               *(undefined2 *)((int)puVar3 + (uint)*(ushort *)(puVar3 + 0x73) * 2 + 0x1ce),puVar4[8]
              );
  uVar1 = puVar4[4];
  *(ushort *)(puVar4 + 10) = (ushort)*(byte *)(DAT_03012a34 + 0xe);
  sVar2 = *(short *)(puVar4 + 6);
  if (sVar2 != 0) {
    *(undefined2 *)(puVar4 + 0xc) = 0;
  }
  else {
    *(undefined2 *)(puVar4 + 0xc) = 1;
  }
  *(undefined2 *)(puVar3 + 2) = 1;
  if (sVar2 == 0) {
    *(undefined2 *)(puVar4 + 0xc) = 1;
    FUN_0301223a(0,uVar1);
  }
  if ((*(short *)(puVar4 + 0xc) != 1) &&
     (*(short *)(puVar3 + (uint)*(ushort *)(puVar3 + 0x73) * 0xe + 3) == 0)) {
    MediaLib_GetTotalFiles(0x15c);
  }
  *puVar4 = 0;
  puVar6 = puRam03012a38;
  puRam03012a38[1] = 0;
  puVar6[3] = 0;
  *puVar6 = 0;
  puVar6[2] = 0;
  *puRam03012a3c = 0;
  MediaLib_GetTotalFiles(0x14d);
  MediaLib_GetTotalFiles(0x153);
  puVar4[3] = 1;
  MediaLib_GetTotalFiles_c(300);
  puVar4[3] = 1;
  MediaLib_GetTotalFiles_c(0x134);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


