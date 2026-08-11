/**
 * FUN_03014102 @ 0x03014102
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03014102(void)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  undefined4 *puVar4;
  uint uVar5;
  short sVar6;
  uint uVar7;
  undefined4 in_r3;
  
  puVar4 = DAT_03014448;
  uVar5 = (uint)*(ushort *)(DAT_03014448 + 0x73);
  uVar1 = *(ushort *)(DAT_03014448 + uVar5 * 0xe + 3);
  uVar7 = (uint)uVar1;
  if (uVar7 == 0) {
    return;
  }
  sVar6 = *(short *)((int)DAT_03014448 + 0x1ee);
  *(short *)(DAT_03014448 + 0x7c) = sVar6;
  if (sVar6 != 0) {
    *(short *)((int)puVar4 + 0x1ee) = sVar6 + -1;
    MediaLib_GetTotalFiles(0x150,uVar7,sVar6,in_r3);
    return;
  }
  uVar2 = *(ushort *)((int)puVar4 + uVar5 * 2 + 0x1ce);
  if (uVar2 == 0) {
    lVar3 = (longlong)DAT_0301445c * (longlong)(int)(uVar7 - 1);
    sVar6 = (short)((ulonglong)lVar3 >> 0x20) - (short)(lVar3 >> 0x3f);
    *(short *)((int)puVar4 + uVar5 * 2 + 0x1ce) = sVar6 * 6;
    sVar6 = (uVar1 - 1) + sVar6 * -6;
  }
  else {
    if (5 < uVar2) {
      sVar6 = uVar2 - 6;
    }
    else {
      sVar6 = 0;
    }
    *(short *)((int)puVar4 + uVar5 * 2 + 0x1ce) = sVar6;
    if (5 >= uVar2) {
      *(short *)((int)puVar4 + 0x1ee) = sVar6;
      goto LAB_0301415c;
    }
    sVar6 = 5;
  }
  *(short *)((int)puVar4 + 0x1ee) = sVar6;
LAB_0301415c:
  FUN_030122a2(*(undefined4 *)(puVar4[0x7d] + 4),*puVar4,
               puVar4 + (uint)*(ushort *)(puVar4 + 0x73) * 0xe + 3,
               *(undefined2 *)((int)puVar4 + (uint)*(ushort *)(puVar4 + 0x73) * 2 + 0x1ce));
  MediaLib_GetTotalFiles(0x14f);
  return;
}


