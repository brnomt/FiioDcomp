/**
 * FUN_030038b0 @ 0x030038b0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030038b0(void)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  undefined2 local_40 [8];
  undefined4 local_30;
  undefined4 local_2c;
  
  puVar3 = DAT_03003ab8;
  uVar2 = *DAT_03003ab8;
  *DAT_03003ab8 = 0xffff;
  local_2c = FUN_02febd50(2);
  local_30 = FUN_02febd74(1);
  iVar5 = FUN_02ff0650(0x26);
  if (((iVar5 != 0) || (iVar5 = FUN_02ff060c(0x185), iVar5 != 0)) ||
     (iVar5 = FUN_02ff060c(0x2f), iVar5 != 0)) {
    FUN_02ff05f0(0x186);
    FUN_02ff05f0(0x21);
  }
  iVar6 = FUN_02ff060c(0x186);
  puVar4 = DAT_03003abc;
  iVar5 = DAT_03003a78;
  if (iVar6 != 0) {
    FUN_02fec622(0x7a);
    FUN_02fec116(1);
    FUN_02fec326(0x8c,local_40);
    *puVar3 = *DAT_03003ac0;
    FUN_02febe20(8,4,0x140,0x10,2,0x1c0);
    *puVar3 = 0xffff;
    bVar1 = *(byte *)(iVar5 + 5);
    uVar8 = 0;
    do {
      if (bVar1 <= uVar8) break;
      iVar6 = (int)(short)((short)uVar8 * 0x18 + 0x17);
      if (*(byte *)(iVar5 + 3) == uVar8) {
        *puVar3 = *DAT_03003ac0;
        FUN_02fecabe(0x85,4,iVar6);
      }
      else {
        *puVar3 = *puVar4;
      }
      FUN_02febe20(0x1c,iVar6 + 5U & 0xffff,local_40[0],0x10,0,
                   *(undefined2 *)(DAT_03003ac4 + uVar8 * 2));
      *puVar3 = *puVar4;
      uVar8 = uVar8 + 1 & 0xffff;
    } while (uVar8 < 2);
  }
  iVar6 = FUN_02ff060c(0x187);
  if (iVar6 != 0) {
    FUN_02fec326(0x8c,local_40);
    puVar4 = DAT_03003ac0;
    uVar8 = 0;
    do {
      iVar6 = (int)(short)((short)uVar8 * 0x18 + 0x17);
      *puVar3 = *DAT_03003abc;
      uVar7 = (uint)*(byte *)(iVar5 + 3);
      bVar9 = uVar7 != uVar8;
      if (bVar9) {
        uVar7 = (uint)*(byte *)(iVar5 + 4);
      }
      if (!bVar9 || uVar7 == uVar8) {
        if (*(byte *)(iVar5 + 4) == uVar8) {
          FUN_02fec65a(0x7a,0,0,iVar6,0x19);
        }
        if (*(byte *)(iVar5 + 3) == uVar8) {
          *puVar3 = *puVar4;
          FUN_02fecabe(0x85,4,iVar6);
        }
        FUN_02febe20(0x1c,iVar6 + 5U & 0xffff,local_40[0],0x10,0,
                     *(undefined2 *)(DAT_03003ac4 + uVar8 * 2));
      }
      uVar8 = uVar8 + 1 & 0xffff;
    } while (uVar8 < 2);
  }
  FUN_02fec116(0);
  iVar5 = FUN_02ff0650(1);
  if ((iVar5 != 0) && (iVar5 = FUN_02ff060c(0x3e), iVar5 == 1)) {
    FUN_02fecb14(*(byte *)(DAT_03003aac + 0x12) + 0xd2,0,0x50);
  }
  FUN_02febd74(local_30);
  *puVar3 = uVar2;
  FUN_02febd50(local_2c);
  return;
}


