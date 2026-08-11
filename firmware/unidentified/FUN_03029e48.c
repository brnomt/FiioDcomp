/**
 * FUN_03029e48 @ 0x03029e48
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03029e48(void)

{
  undefined4 *puVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 extraout_r3;
  int iVar6;
  undefined4 in_stack_00000000;
  
  FUN_02ff67a4();
  FUN_02ff67a4(0x7e,1);
  rom_dma_config(0xe,0);
  rom_dma_config(0xf,0);
  FUN_03011ef4(0x49);
  pbVar3 = DAT_03029f6c;
  iVar6 = DAT_03029f64;
  *(undefined4 *)(DAT_03029f64 + 0x348) = 0;
  *(undefined4 *)(iVar6 + 0x34c) = 0;
  *(undefined4 *)(iVar6 + 0x350) = 0;
  *(undefined4 *)(iVar6 + 0x354) = 0;
  *(undefined4 *)(iVar6 + 0x358) = 0;
  *(undefined4 *)(iVar6 + 0x35c) = 0;
  puVar1 = DAT_03029f70;
  *pbVar3 = (byte)*DAT_03029f68;
  uVar5 = (*(code *)*puVar1)();
  *(undefined4 *)(pbVar3 + 4) = uVar5;
  *(undefined4 *)(pbVar3 + 8) = *(undefined4 *)(DAT_03029f74 + (uint)*pbVar3 * 0x27e + 0x20);
  iVar2 = DAT_03029f04;
  puVar1 = DAT_03029f00;
  *(undefined4 *)(DAT_03029f04 + 0x7c) = 0;
  *(undefined4 *)(iVar2 + 0x75c) = *puVar1;
  iVar6 = DAT_03029f60;
  func_0x030124a0(0x65,0,2,extraout_r3,in_stack_00000000);
  func_0x03012474(iVar2 + 0x748,0,2);
  iVar4 = *(int *)(iVar2 + 0x7c);
  while (iVar4 == 0) {
    FUN_030059bc();
    FUN_02ff73f0();
    FUN_030098c0(1);
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) break;
    iVar4 = *(int *)(iVar2 + 0x7c);
  }
  *(undefined4 *)(iVar2 + 0x7c) = 0;
  return;
}


