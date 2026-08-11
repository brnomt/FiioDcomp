/**
 * FUN_03029b44 @ 0x03029b44
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03029b44(void)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  
  switch(*DAT_03029f00) {
  case 0:
    if ((*(uint *)(*(int *)(DAT_03029f04 + 0xc) + 0xc) < 0x1f401) &&
       (*(uint *)(*(int *)(DAT_03029f04 + 0xc) + 8) < 0xac45)) {
      FUN_0300c558(5);
      return;
    }
    FUN_0300c558(6);
    return;
  case 1:
    break;
  case 2:
    if ((*(uint *)(*(int *)(DAT_03029f04 + 0xc) + 0xc) < 0x1f401) &&
       (*(uint *)(*(int *)(DAT_03029f04 + 0xc) + 8) < 0xac45)) {
      FUN_0300c558(0xb);
      return;
    }
    FUN_0300c558(10);
    return;
  case 3:
    FUN_0300c558(9);
    return;
  case 4:
    iVar2 = *(int *)(DAT_03029f04 + 0xc);
    uVar1 = *(uint *)(iVar2 + 0xc);
    bVar3 = uVar1 == DAT_03029f08;
    if (uVar1 <= DAT_03029f08) {
      bVar3 = *(int *)(iVar2 + 0x10) == 1;
    }
    if (!bVar3) {
      bVar3 = uVar1 - 0xd2f1 == DAT_03029f0c;
      if (uVar1 - 0xd2f1 <= DAT_03029f0c) {
        bVar3 = *(int *)(iVar2 + 0x10) == 2;
      }
      if (!bVar3) {
        if ((DAT_03029f10 + uVar1 < DAT_03029f14) && (*(int *)(iVar2 + 0x10) == 2)) {
          FUN_0300c558(0xf);
          return;
        }
        bVar3 = uVar1 - 0x3e800 == DAT_03029f18;
        if (uVar1 - 0x3e800 <= DAT_03029f18) {
          bVar3 = *(int *)(iVar2 + 0x10) == 2;
        }
        if (bVar3) {
          FUN_0300c558(0x10);
          return;
        }
        bVar4 = DAT_03029f1c <= uVar1;
        bVar3 = uVar1 == DAT_03029f1c;
        if (!bVar4 || bVar3) {
          bVar4 = 1 < *(uint *)(iVar2 + 0x10);
          bVar3 = *(uint *)(iVar2 + 0x10) == 2;
        }
        if (!bVar3) {
          bVar4 = 53999 < uVar1;
          bVar3 = uVar1 == 54000;
        }
        if (!bVar4 || bVar3) {
          FUN_0300c558(0x11);
          return;
        }
        goto switchD_03029b4e_caseD_5;
      }
    }
    FUN_0300c558(0xe);
    return;
  case 5:
switchD_03029b4e_caseD_5:
    FUN_0300c558(0x12);
    return;
  case 6:
    FUN_0300c558(0x13);
    return;
  case 7:
    FUN_0300c558(0x14);
    return;
  case 8:
    FUN_0300c558(0x15);
    return;
  case 9:
    FUN_0300c558(0x16);
    return;
  default:
    return;
  }
  uVar1 = *(uint *)(*(int *)(DAT_03029f04 + 0xc) + 0xc);
  if (uVar1 < 0x1f400) {
    iVar2 = *(int *)(*(int *)(DAT_03029f04 + 0xc) + 8);
    if (iVar2 == 32000) {
      uVar1 = uVar1 - 22000;
    }
    else {
      if (iVar2 != 0xac44) goto LAB_03029ba6;
      uVar1 = uVar1 - 48000;
    }
    if (999 < uVar1) {
LAB_03029ba6:
      FUN_0300c558(7);
      return;
    }
  }
  FUN_0300c558(8);
  return;
}


