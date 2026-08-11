/**
 * FUN_030c2790 @ 0x030c2790
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c2790(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  iVar2 = 0;
  uVar4 = param_1[1];
  for (uVar5 = uVar4; uVar5 != 0; uVar5 = uVar5 >> 1) {
    iVar2 = iVar2 + 1;
  }
  uVar7 = *param_1;
  uVar5 = (int)uVar4 >> ((int)((iVar2 + -1) * (uVar7 - 1)) / (int)uVar7 & 0xffU);
  while( true ) {
    uVar3 = 1;
    uVar6 = 1;
    if (0 < (int)uVar7) {
      if ((uVar7 & 1) != 0) {
        uVar6 = uVar5 + 1;
        uVar3 = uVar5;
      }
      iVar2 = (int)uVar7 >> 1;
      if (iVar2 != 0) {
        do {
          uVar3 = uVar5 * uVar5 * uVar3;
          uVar6 = uVar6 * (uVar5 + 1) * (uVar5 + 1);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
    bVar8 = SBORROW4(uVar4,uVar3);
    iVar2 = uVar4 - uVar3;
    uVar1 = uVar3;
    if ((int)uVar3 <= (int)uVar4) {
      bVar8 = SBORROW4(uVar6,uVar4);
      iVar2 = uVar6 - uVar4;
      uVar1 = uVar6;
    }
    if (uVar4 != uVar1 && iVar2 < 0 == bVar8) break;
    if ((int)uVar4 < (int)uVar3) {
      uVar5 = uVar5 - 1;
    }
    else {
      uVar5 = uVar5 + 1;
    }
  }
  return;
}


