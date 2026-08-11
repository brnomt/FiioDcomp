/**
 * FUN_030a25d0 @ 0x030a25d0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030a25d0(undefined4 *param_1,short *param_2,short *param_3)

{
  int iVar1;
  uint uVar2;
  short *psVar3;
  short *psVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = FUN_030a247c(param_2,param_2,32000,param_1[2]);
  FUN_030a2920(*param_1,param_2,param_3);
  uVar5 = param_1[2];
  if (0 < (int)uVar5) {
    psVar3 = param_2 + -1;
    if ((uVar5 & 1) != 0) {
      *param_2 = (short)((int)*param_2 + ((1 << (uVar2 & 0xff)) >> 1) >> (uVar2 & 0xff));
      psVar3 = param_2;
    }
    iVar6 = (int)uVar5 >> 1;
    if (iVar6 != 0) {
      psVar4 = psVar3;
      do {
        iVar1 = (1 << (uVar2 & 0xff)) >> 1;
        psVar3[1] = (short)(psVar4[1] + iVar1 >> (uVar2 & 0xff));
        psVar4 = psVar4 + 2;
        psVar3 = psVar3 + 2;
        *psVar3 = (short)(*psVar4 + iVar1 >> (uVar2 & 0xff));
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  uVar5 = param_1[2];
  if (0 < (int)uVar5) {
    psVar3 = param_3 + -1;
    if ((uVar5 & 1) != 0) {
      *param_3 = (short)((int)*param_3 + ((1 << (uVar2 & 0xff)) >> 1) >> (uVar2 & 0xff));
      psVar3 = param_3;
    }
    iVar6 = (int)uVar5 >> 1;
    if (iVar6 == 0) {
      return;
    }
    psVar4 = psVar3;
    do {
      iVar1 = (1 << (uVar2 & 0xff)) >> 1;
      psVar4[1] = (short)(psVar3[1] + iVar1 >> (uVar2 & 0xff));
      psVar3 = psVar3 + 2;
      psVar4 = psVar4 + 2;
      *psVar4 = (short)(*psVar3 + iVar1 >> (uVar2 & 0xff));
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    return;
  }
  return;
}


