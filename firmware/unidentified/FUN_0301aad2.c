/**
 * FUN_0301aad2 @ 0x0301aad2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301aad2(void)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  undefined4 extraout_r1;
  bool bVar6;
  
  puVar2 = DAT_0301ace0;
  if (DAT_0301ace0[1] == '\x03') {
    *(undefined2 *)(DAT_0301ace0 + 4) = 3;
  }
  else {
    *(undefined2 *)(DAT_0301ace0 + 4) = 0;
  }
  puVar4 = DAT_0301acf4;
  iVar3 = DAT_0301ace4;
  *(undefined1 *)(DAT_0301acdc + 1) = 8;
  *(int *)(puVar2 + 0xc) = *(int *)(puVar2 + 0xc) + 1;
  bVar6 = (char)puVar4[2] != '\x01';
  cVar1 = '\x01';
  if (bVar6) {
    cVar1 = *(char *)(iVar3 + 0x1b7);
  }
  if ((!bVar6 || cVar1 == '\x01') && (*puVar4 == (uint)*(ushort *)(iVar3 + 0x1b1))) {
    FUN_0301af1c();
  }
  FUN_03009500(0x10,7);
  iVar5 = FUN_0301d4c4();
  if (iVar5 == 0) {
    bVar6 = (char)puVar4[2] != '\x01';
    cVar1 = '\x01';
    if (bVar6) {
      cVar1 = *(char *)(iVar3 + 0x1b7);
    }
    if ((!bVar6 || cVar1 == '\x01') && (*puVar4 == (uint)*(ushort *)(iVar3 + 0x1b1))) {
      thunk_FUN_0301da82(puVar4[1],1);
      *(uint *)(DAT_0301acf8 + 0x14) = puVar4[1];
      FUN_0301db2a();
      *(undefined1 *)(puVar4 + 2) = 0;
      *(undefined1 *)(iVar3 + 0x1b7) = 0;
    }
    iVar5 = FUN_0301afcc();
    if (iVar5 == 0) {
      FUN_0301abb2(0x119,0);
      FUN_03008160(0x23,&LAB_0301a8d8_1);
      FUN_02ff7be6(0x23);
      FUN_02ff7ae0(0x23);
      FUN_02ff196a(0,extraout_r1,*DAT_0301acfc,*DAT_0301acfc >> 0x1f,0);
      FUN_03001e04(*(undefined1 *)(iVar3 + 0x12));
      *(undefined4 *)(puVar2 + 0x10) = 0;
      *puVar2 = 0;
      FUN_03008eb4(0x128);
      *DAT_0301ace8 = 2;
      FUN_03008eb4(0x23);
      *DAT_0301acf0 = *DAT_0301acec;
      return 0;
    }
  }
  return 0xffffffff;
}


