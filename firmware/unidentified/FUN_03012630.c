/**
 * FUN_03012630 @ 0x03012630
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03012630(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  piVar1 = DAT_03012a20;
  if (param_1 != 0) {
    iVar4 = MediaLib_GetTotalFiles_d(0x15d);
    if (iVar4 == 0) {
      FUN_02fede5c(piVar1,0x1fc);
    }
    iVar4 = DAT_03012a24;
    iVar5 = FUN_030121bc(*(undefined1 *)(DAT_03012a24 + 4));
    piVar1[0x7d] = iVar5;
    uVar3 = 3;
    switch(*(undefined1 *)(iVar4 + 4)) {
    case 2:
      uVar3 = 0x4c;
      break;
    case 3:
      uVar3 = 0xb;
      break;
    case 4:
      uVar3 = 0x4f;
      break;
    case 5:
      uVar3 = 0x60;
    }
    *(undefined2 *)(piVar1 + 0x7e) = uVar3;
    iVar4 = FUN_02ff2f42(*(undefined1 *)(iVar4 + 8));
    piVar1[(uint)*(ushort *)(piVar1 + 0x73) * 0xe + 5] = iVar4;
    piVar1[(uint)*(ushort *)(piVar1 + 0x73) * 0xe + 6] = iVar4;
    *(undefined1 *)(piVar1 + (uint)*(ushort *)(piVar1 + 0x73) * 0xe + 9) = 1;
  }
  *(undefined2 *)(piVar1 + 0x7c) = 0;
  *(undefined2 *)((int)piVar1 + 0x1ee) = 0;
  FUN_02fede5c(DAT_03012a28,0xea0);
  piVar2 = DAT_03012a28;
  uVar7 = 0;
  do {
    uVar6 = uVar7 + 1;
    piVar2[uVar7 * 0x9c + 1] = (int)(piVar2 + uVar7 * 0x9c + 0x9c);
    uVar7 = uVar6;
  } while (uVar6 < 5);
  uVar7 = 1;
  do {
    iVar4 = uVar7 * 0x9c;
    uVar7 = uVar7 + 1;
    piVar2[iVar4] = (int)(piVar2 + iVar4 + -0x9c);
    iVar4 = DAT_03012a2c;
  } while (uVar7 < 6);
  *piVar2 = DAT_03012a2c;
  *(int **)(iVar4 + 4) = piVar2;
  *piVar1 = (int)piVar2;
  return;
}


