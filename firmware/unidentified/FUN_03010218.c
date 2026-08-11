/**
 * FUN_03010218 @ 0x03010218
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03010218(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  
  pbVar3 = DAT_03010280;
  DAT_03010280[2] = 0;
  pbVar3[3] = 0;
  *pbVar3 = 0;
  pbVar3[4] = 0;
  iVar2 = DAT_03010254;
  *(undefined1 *)(*(int *)(pbVar3 + 0x30) + 1) = 0;
  **(undefined1 **)(pbVar3 + 0x30) = 0x7c;
  puVar4 = DAT_03010284;
  pbVar3[8] = 0;
  pbVar3[9] = 0;
  *(undefined1 *)(iVar2 + 0x1bb) = 0;
  *puVar4 = 0;
  pbVar3[2] = 0;
  pbVar3[3] = 0;
  iVar6 = rom_event_pending(0x159);
  puVar4 = DAT_030104d0;
  if (iVar6 == 0) {
    cVar5 = DSP_GOODEF_Init(s_WOOOOONXBIN_0300fe1c,6);
    if (cVar5 == '\x01') {
      *puVar4 = 1;
    }
    else {
      *puVar4 = 0;
    }
  }
  else {
    DSP_GOODEF_Init(s_WOOOOONXBIN_0300fe1c,2);
  }
  FUN_02ffec94(0x3b,7);
  uVar7 = FUN_03020810(*(undefined4 *)(pbVar3 + 0x2c));
  *(undefined4 *)(puVar4 + 4) = uVar7;
  iVar8 = FUN_02ffe664(0x159);
  iVar6 = DAT_030104d8;
  if (iVar8 == 0) {
    rom_post_event(0x32);
  }
  else {
    bVar1 = *DAT_030104d4;
    *pbVar3 = bVar1;
    pbVar3[4] = bVar1;
    uVar9 = 0;
    do {
      *(undefined1 *)(*(int *)(pbVar3 + 0x30) + uVar9) = *(undefined1 *)(iVar6 + uVar9 * 2);
      uVar9 = uVar9 + 1 & 0xff;
    } while (uVar9 < 2);
    if (*(char *)(iVar2 + 0x1bc) == '\0') {
      *(undefined1 *)(*(int *)(pbVar3 + 0x30) + *pbVar3 + 1) = 0;
      *(undefined1 *)(*(int *)(pbVar3 + 0x30) + (uint)*pbVar3) = 0;
    }
    if (*(char *)(iVar2 + 0x356) != '\0') {
      FUN_0300fa06(DAT_030104dc);
    }
    if (*(char *)(iVar2 + 0x1bc) == '\0') {
      *(undefined1 *)(*(int *)(pbVar3 + 0x30) + (uint)*pbVar3) = 0x7c;
    }
    DSP_GOODEF_Process();
  }
  FUN_030047cc(s_V333____030104e0);
  return;
}


