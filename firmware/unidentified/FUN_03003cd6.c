/**
 * FUN_03003cd6 @ 0x03003cd6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03003cd6(void)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  undefined2 local_40 [8];
  undefined4 local_30;
  undefined4 local_2c;
  
  puVar4 = DAT_03003ee0;
  puVar3 = DAT_03003edc;
  uVar2 = *DAT_03003edc;
  *DAT_03003edc = *DAT_03003ee0;
  local_2c = FUN_02fec1fc(2);
  local_30 = FUN_02fec220(1);
  iVar6 = FUN_02ff0afc(0x26);
  if (((iVar6 != 0) || (iVar6 = FUN_02ff0ab8(0x188), iVar6 != 0)) ||
     (iVar6 = FUN_02ff0ab8(0x2f), iVar6 != 0)) {
    FUN_02ff0a9c(0x189);
    FUN_02ff0a9c(0x21);
  }
  iVar6 = FUN_02ff0ab8(0x189);
  if (iVar6 != 0) {
    FUN_02fecace(0x7a);
    FUN_02fec5c2(1);
    *puVar3 = *DAT_03003ee4;
    FUN_02fec2cc(8,4,0x140,0x10,2,0x6b);
    *puVar3 = 0xffff;
    FUN_02fec7d2(0x8c,local_40);
    uVar8 = 0;
    bVar1 = *(byte *)(DAT_03003eac + 5);
    do {
      if (bVar1 <= uVar8) break;
      iVar6 = (int)(short)((short)uVar8 * 0x18 + 0x17);
      if (*(byte *)(DAT_03003eac + 3) == uVar8) {
        *puVar3 = *DAT_03003ee4;
        FUN_02fecf6a(0x85,4,iVar6);
      }
      else {
        *puVar3 = *puVar4;
        FUN_02fecb06(0x7a,0,0,iVar6,0x19);
      }
      FUN_02fec2cc(0x1c,iVar6 + 5U & 0xffff,local_40[0],0x10,0,
                   *(undefined2 *)(DAT_03003ee8 + uVar8 * 2));
      *puVar3 = *puVar4;
      uVar8 = uVar8 + 1 & 0xffff;
    } while (uVar8 < 3);
  }
  iVar6 = FUN_02ff0ab8(0x18a);
  if (iVar6 != 0) {
    FUN_02fec7d2(0x8c,local_40);
    iVar5 = DAT_03003ee8;
    iVar6 = DAT_03003eac;
    uVar8 = 0;
    do {
      iVar9 = (int)(short)((short)uVar8 * 0x18 + 0x17);
      uVar7 = (uint)*(byte *)(iVar6 + 3);
      bVar10 = uVar7 != uVar8;
      if (bVar10) {
        uVar7 = (uint)*(byte *)(iVar6 + 4);
      }
      if (!bVar10 || uVar7 == uVar8) {
        if (*(byte *)(iVar6 + 4) == uVar8) {
          *puVar3 = *puVar4;
          FUN_02fecb06(0x7a,0,0,iVar9,0x19);
        }
        if (*(byte *)(iVar6 + 3) == uVar8) {
          *puVar3 = *DAT_03003ee4;
          FUN_02fecf6a(0x85,4,iVar9);
        }
        *puVar3 = *puVar4;
        FUN_02fec2cc(0x1c,iVar9 + 5U & 0xffff,local_40[0],0x10,0,*(undefined2 *)(iVar5 + uVar8 * 2))
        ;
      }
      uVar8 = uVar8 + 1 & 0xffff;
    } while (uVar8 < 3);
  }
  FUN_02fec5c2(0);
  iVar6 = FUN_02ff0afc(1);
  if ((iVar6 != 0) && (iVar6 = FUN_02ff0ab8(0x3e), iVar6 == 1)) {
    FUN_02fecfc0(*(byte *)(DAT_03003ed0 + 0x12) + 0xd2,0,0x50);
  }
  FUN_02fec220(local_30);
  *puVar3 = uVar2;
  FUN_02fec1fc(local_2c);
  return;
}


