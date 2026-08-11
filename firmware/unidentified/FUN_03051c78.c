/**
 * FUN_03051c78 @ 0x03051c78
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03051c78(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined2 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  
  iVar2 = DAT_03051fd0;
  *DAT_03051fcc = 0;
  piVar3 = DAT_03051fdc;
  *DAT_03051fd4 = iVar2;
  *DAT_03051fd8 = iVar2;
  *piVar3 = iVar2 + 0x3000;
  uVar7 = 0;
  do {
    *(undefined2 *)(iVar2 + uVar7 * 2) = 0;
    iVar8 = DAT_03051fe4;
    puVar4 = DAT_03051fe0;
    uVar7 = uVar7 + 1;
  } while (uVar7 < 0x3000);
  *DAT_03051fe0 = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
  uVar7 = 0;
  do {
    *(undefined1 *)(iVar8 + uVar7) = 0;
    piVar3 = DAT_03051ff0;
    iVar2 = DAT_03051fec;
    uVar7 = uVar7 + 1;
  } while (uVar7 < 0xc000);
  uVar11 = *DAT_03051fe8;
  *(undefined4 *)(DAT_03051fec + 0x224) = uVar11;
  piVar5 = DAT_03051ff4;
  iVar9 = *piVar3;
  *(char *)(iVar2 + 0x228) = (char)iVar9;
  iVar8 = *piVar5;
  if (iVar8 == 0) {
    *(undefined2 *)(iVar2 + 0x230) = 2;
  }
  else if (iVar8 == 2) {
    *(undefined2 *)(iVar2 + 0x230) = 1;
  }
  puVar4 = DAT_03051ff8;
  piVar1 = DAT_03051fc8;
  *DAT_03051ff8 = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
  puVar4[3] = 0;
  puVar4[4] = 0;
  puVar4[5] = 0;
  puVar4[10] = 0;
  puVar4[0xc] = 0;
  puVar4[0xd] = 0;
  puVar4[7] = iVar9;
  iVar9 = DAT_03051fc4;
  uVar10 = *DAT_03051ffc;
  puVar4[0xb] = iVar2;
  puVar4[6] = uVar11;
  puVar4[8] = uVar10;
  puVar4[9] = iVar8;
  *piVar1 = 0;
  FUN_03040224(0xcd,0,1);
  FUN_030401f8(puVar4,0,1);
  iVar8 = *piVar1;
  while (iVar8 == 0) {
    FUN_03033740();
    FUN_03025174();
    FUN_03037644(1);
    iVar9 = iVar9 + -1;
    if (iVar9 == 0) break;
    iVar8 = *piVar1;
  }
  *piVar1 = 0;
  iVar8 = *piVar3;
  if ((iVar8 == 1) && (iVar9 = *piVar5, iVar9 == 0 || iVar9 == 2)) {
    iVar8 = (uint)*(ushort *)(iVar2 + 0x22c) << 1;
  }
  else {
    iVar8 = (uint)*(ushort *)(iVar2 + 0x22c) * iVar8;
  }
  *DAT_03052000 = iVar8;
  puVar6 = DAT_03052010;
  *DAT_03052004 = 0;
  *DAT_03052008 = 0;
  *DAT_0305200c = 1;
  *puVar6 = 0x13;
  return;
}


