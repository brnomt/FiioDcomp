/**
 * FUN_0308eff6 @ 0x0308eff6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0308eff6(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = 1 << (*(byte *)(param_1 + 0x5c) - 1 & 0xff);
  *(int *)(param_1 + 0x1b8) = iVar2 + -1;
  *(int *)(param_1 + 0x1bc) = -iVar2;
  uVar1 = DAT_0308f27c;
  iVar2 = (uint)*(ushort *)(param_1 + 0x26) << 2;
  *(undefined4 *)(param_1 + 0xf8) = DAT_0308f27c;
  wma_memclr(uVar1,iVar2);
  uVar1 = DAT_0308f280;
  *(undefined4 *)(param_1 + 0xfc) = DAT_0308f280;
  wma_memclr(uVar1,(uint)*(ushort *)(param_1 + 0x26) << 2);
  uVar1 = DAT_0308f284;
  *(undefined4 *)(param_1 + 0x100) = DAT_0308f284;
  wma_memclr(uVar1,iVar2);
  uVar1 = DAT_0308f288;
  *(undefined4 *)(param_1 + 0x104) = DAT_0308f288;
  wma_memclr(uVar1,iVar2);
  iVar2 = DAT_0308f28c;
  *(int *)(param_1 + 0xdc) = DAT_0308f28c;
  *(int *)(param_1 + 0xe8) = iVar2 + 0xa000;
  *(int *)(param_1 + 0xec) = iVar2 + 0xa014;
  FUN_030908e4(param_1);
  iVar2 = DAT_0308f290;
  *(int *)(param_1 + 0xf4) = DAT_0308f290;
  *(int *)(param_1 + 0xe0) = iVar2 + 0x14;
  *(int *)(param_1 + 0x130) = iVar2 + 0xf4;
  *(int *)(param_1 + 0x134) = iVar2 + 0x108;
  *(int *)(param_1 + 0x13c) = iVar2 + 0x140;
  *(int *)(param_1 + 0x138) = iVar2 + 0x220;
  iVar2 = DAT_0308f294;
  *(int *)(param_1 + 0x1e8) = DAT_0308f294;
  *(int *)(param_1 + 0x1ec) = iVar2 + 8;
  *(int *)(param_1 + 0x18c) = iVar2 + -0x28;
  *(int *)(param_1 + 0x1d4) = iVar2 + -0x24;
  iVar2 = *(int *)(param_1 + 0xb4);
  bVar3 = iVar2 == 0;
  if (bVar3) {
    iVar2 = *(int *)(param_1 + 0x144);
  }
  if (bVar3 && iVar2 == 0) {
    *(undefined4 *)(param_1 + 0x144) = DAT_0308f298;
  }
  return 0;
}


