/**
 * FUN_0301abb2 @ 0x0301abb2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0301abb2(undefined4 param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = DAT_0301ace0;
  uVar3 = 0;
  switch(param_1) {
  case 0x118:
    iVar2 = FUN_0301d4c4();
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    break;
  case 0x119:
    bVar1 = SpiDMAIntIsr_Test();
    goto LAB_0301abec;
  case 0x11a:
    bVar1 = FUN_0301aad2();
LAB_0301abec:
    uVar3 = (uint)bVar1;
    break;
  case 0x11b:
    FUN_0301aa6c();
    break;
  case 0x11c:
    FUN_0301de00();
    FUN_0301d450();
    break;
  case 0x11f:
    iVar2 = FUN_0301a980(param_2 & 0xffff);
    if ((iVar2 != 0) && (*(char *)(DAT_0301ace4 + 0xe) == '\x02')) {
      FUN_0301aed4(DAT_0301ad00);
    }
    break;
  case 0x120:
    if (*(short *)(DAT_0301ace0 + 4) != 0) {
      *(undefined1 *)(DAT_0301ace0 + 1) = 0;
      return 0;
    }
    *(undefined2 *)(DAT_0301ace0 + 4) = 3;
    *(undefined1 *)(iVar2 + 1) = 3;
    param_2 = 0;
    goto LAB_0301ac30;
  case 0x121:
    FUN_0301a9fe();
    break;
  case 0x122:
    if (*(short *)(DAT_0301ace0 + 4) != 4) {
      FUN_0301a980(1);
    }
    FUN_0301aca6(param_2);
    break;
  case 0x123:
LAB_0301ac30:
    FUN_03001e04(param_2);
    break;
  case 0x124:
    if (*(short *)(DAT_0301ace0 + 4) == 4) {
      return 0;
    }
    if (*(short *)(DAT_0301ace0 + 4) != 1) {
      FUN_03001e04(0);
      *(undefined2 *)(iVar2 + 4) = 1;
    }
    iVar2 = thunk_FUN_0301da82(0x4b,1);
    goto joined_r0x0301ac98;
  case 0x125:
    if (*(short *)(DAT_0301ace0 + 4) == 4) {
      return 0;
    }
    if (*(short *)(DAT_0301ace0 + 4) != 2) {
      FUN_03001e04(0);
      *(undefined2 *)(iVar2 + 4) = 2;
    }
    iVar2 = thunk_FUN_0301da82(0x4b,0xffffffff);
joined_r0x0301ac98:
    if (iVar2 == 0) {
      FUN_0301ddf2();
      FUN_0301dd4e();
    }
  }
  return uVar3;
}


