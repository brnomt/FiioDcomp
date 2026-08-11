/**
 * FUN_0300cdea @ 0x0300cdea
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300cdea(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  
  puVar2 = DAT_0300ce90;
  *(undefined1 *)(DAT_0300ce90 + 4) = 0;
  *(undefined1 *)((int)puVar2 + 0x76) = 0;
  iVar3 = DAT_0300ce9c;
  *(undefined2 *)((int)puVar2 + 0x82) = 0;
  uVar4 = 0;
  do {
    iVar5 = iVar3 + uVar4 * 0xac;
    uVar4 = uVar4 + 1 & 0xffff;
    *(int *)(iVar5 + 0xa8) = iVar5 + 0xac;
  } while (uVar4 < 0xb);
  uVar4 = 1;
  do {
    iVar5 = iVar3 + uVar4 * 0xac;
    uVar4 = uVar4 + 1 & 0xffff;
    *(int *)(iVar5 + 0xa4) = iVar5 + -0xac;
  } while (uVar4 < 0xc);
  uVar4 = 0;
  do {
    *(undefined2 *)(iVar3 + uVar4 * 0xac) = 0;
    iVar5 = uVar4 * 0xac;
    uVar4 = uVar4 + 1 & 0xffff;
    *(undefined2 *)(iVar3 + iVar5 + 2) = 0;
    iVar5 = DAT_0300ce9c;
  } while (uVar4 < 0xc);
  *(int *)(DAT_0300ce9c + 0x80c) = iVar3;
  *(int *)(iVar3 + 0xa4) = iVar5 + 0x764;
  puVar2[3] = iVar3;
  *puVar2 = 2;
  iVar3 = DAT_0300cea0;
  puVar1 = DAT_0300ce8c;
  *(undefined1 *)(DAT_0300cea0 + 2) = 0;
  *(undefined1 *)(iVar3 + 3) = 0;
  *(undefined1 *)(iVar3 + 1) = 0;
  puVar2 = DAT_0300ce98;
  *DAT_0300ce98 = 0;
  puVar2[1] = 0;
  puVar2[7] = 0;
  puVar2[6] = 0;
  puVar2[5] = 0;
  *puVar1 = 0xff;
  uVar6 = *DAT_0300cea4;
  puVar2[2] = 0;
  puVar2[4] = uVar6;
  return;
}


