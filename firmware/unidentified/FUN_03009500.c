/**
 * FUN_03009500 @ 0x03009500
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03009500(short param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 unaff_r6;
  char *unaff_r8;
  int unaff_r11;
  
  FUN_03009156(0,(int)param_1,2);
  *unaff_r8 = '\x02';
  FUN_02ff73f6(0x21);
  *(undefined2 *)(unaff_r11 + 4) = unaff_r6;
  FUN_02ff4124();
  puVar3 = DAT_03009744;
  if (*unaff_r8 == '\0') {
    uVar1 = *DAT_03009744;
    uVar2 = DAT_03009744[1];
    uVar4 = FUN_02ff2b38(1);
    uVar5 = FUN_02ff2b14(2);
    *puVar3 = 0xffff;
    puVar3[1] = 0xffff;
    iVar6 = FUN_02ff73d0(0x32);
    if (iVar6 != 0) {
      FUN_02ff73b4(0x95);
    }
    iVar6 = FUN_02ff73d0(0x95);
    if (((iVar6 == 1) || (iVar6 = FUN_02ff73d0(0x26), iVar6 == 1)) ||
       (iVar6 = FUN_02ff73d0(0x2f), iVar6 != 0)) {
      FUN_02ff33e6(0x7a);
      *puVar3 = *DAT_03009748;
      FUN_02ff2be4(0,3,0x140,0x10);
      *puVar3 = 0xffff;
      FUN_02ff73b4(0x21);
      FUN_02ff73b4(0x96);
      FUN_02ff73b4(0x9b);
      FUN_02ff73b4(0x1a9);
      FUN_02ff2eda(1);
    }
    FUN_02ff2eda(0);
    FUN_03009156(0,0);
    FUN_02ff2b38(uVar4);
    puVar3[1] = uVar2;
    *puVar3 = uVar1;
    FUN_02ff2b14(uVar5);
    return;
  }
  return;
}


