/**
 * FUN_030021e4 @ 0x030021e4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030021e4(void)

{
  ushort uVar1;
  short sVar2;
  ushort *puVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined2 local_50 [8];
  undefined1 auStack_40 [16];
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  
  puVar3 = DAT_030025d8;
  local_80 = *DAT_030025d4;
  uStack_7c = DAT_030025d4[1];
  uStack_78 = DAT_030025d4[2];
  uStack_74 = DAT_030025d4[3];
  local_70 = DAT_030025d4[4];
  uStack_6c = DAT_030025d4[5];
  uStack_68 = DAT_030025d4[6];
  uStack_64 = DAT_030025d4[7];
  local_60 = DAT_030025d4[8];
  uStack_5c = DAT_030025d4[9];
  local_58 = DAT_030025d4[10];
  uStack_54 = DAT_030025d4[0xb];
  local_28 = (uint)*DAT_030025d8;
  uVar1 = DAT_030025d8[1];
  local_30 = FUN_02feb810(1);
  local_2c = FUN_02feb7ec(2);
  *puVar3 = *DAT_030025dc;
  puVar3[1] = *DAT_030025e0;
  FUN_02fec0be(0x7a);
  FUN_02fec0f6(0x7a,0,0,0x17,0x8f);
  FUN_02febdc2(0x8c,local_50);
  FUN_02febdc2(0x9e,auStack_40);
  uVar6 = 0;
  do {
    sVar2 = (short)uVar6;
    uVar4 = (uint)*DAT_030025e4;
    if ((uVar4 != 5 && uVar4 != 4) && (uVar4 != 3 && uVar4 != 2)) {
      uVar4 = 1;
    }
    if (uVar6 == uVar4) {
      if (uVar6 == 0) {
        FUN_02fec55a(0x86,4,0x17);
      }
      else {
        if (uVar6 == 5) {
          uVar5 = 0x88;
        }
        else {
          uVar5 = 0x85;
        }
        FUN_02fec55a(uVar5,4,(int)(short)(sVar2 * 0x18 + 0x17));
      }
      FUN_02fec55a(*(short *)((int)&local_80 + uVar6 * 6) + 9,5,(int)(short)(sVar2 * 0x18 + 0x18));
      *puVar3 = *DAT_030025e8;
    }
    else {
      FUN_02fec55a(*(undefined2 *)((int)&local_80 + uVar6 * 6),5,(int)(short)(sVar2 * 0x18 + 0x18));
      *puVar3 = *DAT_030025dc;
    }
    FUN_02feb8bc(0x1c,uVar6 * 0x18 + 0x1c & 0xffff,local_50[0],0x10,0,
                 *(undefined2 *)((int)&local_80 + uVar6 * 6 + 2));
    uVar6 = uVar6 + 1 & 0xffff;
  } while (uVar6 < 6);
  FUN_02feb810(local_30);
  puVar3[1] = uVar1;
  *puVar3 = (ushort)local_28;
  FUN_02feb7ec(local_2c);
  return;
}


