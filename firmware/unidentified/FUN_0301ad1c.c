/**
 * FUN_0301ad1c @ 0x0301ad1c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301ad1c(short *param_1)

{
  short sVar1;
  short *psVar2;
  undefined4 *puVar3;
  int iVar4;
  
  FUN_03008d58(0x22);
  iVar4 = DAT_0301aeac;
  sVar1 = *param_1;
  *(short *)(DAT_0301aeac + 0x1b1) = sVar1;
  if (sVar1 == -1) {
    *(undefined2 *)(iVar4 + 0x1b1) = 1;
  }
  puVar3 = DAT_0301aeb4;
  psVar2 = DAT_0301aeb0;
  DAT_0301aeb0[0x79] = 99;
  *puVar3 = 0;
  FUN_02ffde94(psVar2,*(undefined2 *)(iVar4 + 0x1b1),3,0);
  if (*psVar2 != 0) {
    FUN_02ff2fa4(0x6e,1);
    FUN_02ff2fa4(0x7e,1);
    FUN_02ff3014(0xe,0);
    FUN_02ff3014(0xf,0);
    *DAT_0301aebc = 0xff;
    iVar4 = FUN_0301abb2(0x11a,0);
    if (iVar4 != 0) {
      *(undefined2 *)(DAT_0301aec0 + 4) = 4;
      FUN_03008eb4(0x130);
      return;
    }
    return;
  }
  return;
}


