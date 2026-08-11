/**
 * FUN_0300cd58 @ 0x0300cd58
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300cd58(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  ushort uVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  char local_218;
  char local_217;
  char local_216;
  
  FUN_02feb5d6(&local_218,0x200,(int)*DAT_0300ce8c);
  puVar1 = DAT_0300ce90;
  *DAT_0300ce90 = 2;
  iVar6 = FUN_0300cb04(&local_218,0x200);
  puVar3 = DAT_0300ce98;
  puVar2 = DAT_0300ce94;
  if (iVar6 == 1) {
    *puVar1 = 3;
    *puVar2 = 0;
    *puVar3 = 0;
    puVar3[8] = 0;
  }
  else if (local_218 == -1) {
    if (local_217 == -2) {
      *puVar1 = 1;
      *puVar3 = 2;
      puVar3[8] = 2;
    }
  }
  else {
    bVar7 = local_218 == -0x11;
    if (bVar7) {
      local_218 = local_217;
    }
    bVar8 = bVar7 && local_218 == -0x45;
    if (bVar7 && local_218 == -0x45) {
      bVar8 = local_216 == -0x41;
    }
    if (bVar8) {
      *puVar1 = 3;
      *puVar2 = 3;
      *puVar3 = 3;
      puVar3[8] = 3;
    }
  }
  uVar4 = DAT_0300ce9c;
  puVar3[1] = *puVar3;
  uVar5 = 0;
  puVar1[3] = uVar4;
  do {
    *(undefined2 *)puVar1[3] = 0;
    FUN_0300c65a();
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0xc);
  puVar1[3] = uVar4;
  return;
}


