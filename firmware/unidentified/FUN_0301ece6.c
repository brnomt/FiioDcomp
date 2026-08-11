/**
 * FUN_0301ece6 @ 0x0301ece6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301ece6(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *unaff_r5;
  int unaff_r6;
  int unaff_r7;
  int unaff_r8;
  int unaff_r10;
  bool bVar7;
  
  *unaff_r5 = unaff_r8;
  if (unaff_r8 < 1) {
    unaff_r5[2] = unaff_r7;
  }
  else {
    uVar2 = unaff_r8 - 1;
    iVar6 = 0;
    if (uVar2 >> 0x10 != 0) {
      uVar2 = uVar2 >> 0x10;
      iVar6 = 0x10;
    }
    if ((uVar2 & 0xff00) != 0) {
      uVar2 = uVar2 >> 8;
      iVar6 = iVar6 + 8;
    }
    if ((uVar2 & 0xf0) != 0) {
      uVar2 = uVar2 >> 4;
      iVar6 = iVar6 + 4;
    }
    if ((uint)*(byte *)(DAT_0301f104 + uVar2) + iVar6 < 2) {
      iVar6 = 1;
    }
    else {
      uVar2 = unaff_r8 - 1;
      iVar6 = 0;
      if (uVar2 >> 0x10 != 0) {
        uVar2 = uVar2 >> 0x10;
        iVar6 = 0x10;
      }
      if ((uVar2 & 0xff00) != 0) {
        uVar2 = uVar2 >> 8;
        iVar6 = iVar6 + 8;
      }
      if ((uVar2 & 0xf0) != 0) {
        uVar2 = uVar2 >> 4;
        iVar6 = iVar6 + 4;
      }
      iVar6 = (uint)*(byte *)(DAT_0301f104 + uVar2) + iVar6;
    }
    unaff_r5[2] = iVar6;
  }
  bitreader_refill();
  iVar6 = bitreader_peek();
  bitreader_refill();
  if (iVar6 != 0) {
    bitreader_refill();
  }
  if (unaff_r5[3] == 2) {
    if (unaff_r6 != 1) {
      cVar1 = bitreader_peek();
      bitreader_refill();
      *(char *)(unaff_r5 + 0x24) = cVar1;
      if (cVar1 != '\0') {
        bitreader_refill();
        bitreader_refill();
        bitreader_refill();
        bitreader_refill();
        bitreader_refill();
        return 0xffffffff;
      }
    }
    bitreader_refill();
  }
  else {
    if (unaff_r5[3] == 0) {
      bitreader_refill();
      iVar3 = bitreader_peek();
      bitreader_refill();
      bitreader_refill();
      iVar4 = bitreader_peek();
      bitreader_refill();
      bitreader_refill();
      iVar6 = unaff_r5[0x19];
      bVar7 = iVar6 == iVar3;
      if (bVar7) {
        iVar6 = unaff_r5[0x1a];
      }
      if (!bVar7 || iVar6 != iVar4) {
        if (unaff_r5[0x18] != 0) {
          return 0xffffffff;
        }
        unaff_r10 = 1;
        unaff_r5[0x19] = iVar3;
        unaff_r5[0x1a] = iVar4;
      }
    }
    iVar6 = bitreader_peek();
    bitreader_refill();
    unaff_r5[0xb] = iVar6;
    if (iVar6 != 0) {
      *DAT_0301f108 = unaff_r7;
    }
    bitreader_peek();
    bitreader_refill();
    iVar3 = bitreader_peek();
    iVar6 = bitreader_refill();
    unaff_r5[0x11] = iVar3;
    if (iVar3 == 1 || iVar3 == 2) {
      if (iVar3 != 2) {
        bitreader_peek();
        bitreader_refill();
        bitreader_refill();
        bitreader_peek();
        bitreader_refill();
        bitreader_refill();
        bitreader_peek();
        bitreader_refill();
        bitreader_refill();
        bitreader_peek();
        bitreader_refill();
        bitreader_refill();
      }
      iVar6 = bitreader_peek();
      bitreader_refill();
      unaff_r5[0x12] = iVar6;
      iVar6 = bitreader_peek();
      bitreader_refill();
      unaff_r5[0x13] = iVar6;
      iVar6 = bitreader_peek();
      bitreader_refill();
      unaff_r5[0x14] = iVar6;
      iVar6 = unaff_r5[0x11];
      if (iVar6 != 2) {
        bitreader_peek();
        iVar6 = bitreader_refill();
      }
    }
    if (unaff_r6 != 1) {
      iVar6 = unaff_r5[3];
    }
    if (unaff_r6 != 1 && iVar6 != 0) {
      bitreader_refill();
    }
    iVar6 = bitreader_peek();
    bitreader_refill();
    if (iVar6 == 0) {
      unaff_r5[5] = 5;
    }
    else {
      iVar6 = bitreader_peek();
      bitreader_refill();
      unaff_r5[5] = iVar6;
      bitreader_refill();
    }
    if (unaff_r5[3] == 3) {
      bitreader_refill();
      bitreader_refill();
      bitreader_refill();
    }
    iVar6 = bitreader_peek();
    bitreader_refill();
    unaff_r5[6] = iVar6;
    if (iVar6 != 0) {
      *DAT_0301f108 = unaff_r7;
    }
    if (unaff_r6 == 1) {
      unaff_r5[8] = 0;
    }
    else {
      iVar6 = bitreader_peek();
      bitreader_refill();
      unaff_r5[8] = iVar6;
    }
    iVar6 = bitreader_peek();
    bitreader_refill();
    unaff_r5[10] = iVar6;
    if (iVar6 == 0) {
      *DAT_0301f108 = unaff_r7;
    }
    bitreader_refill();
    iVar6 = bitreader_peek();
    bitreader_refill();
    if (iVar6 != 0) {
      bitreader_refill();
    }
    if (unaff_r6 == 1) {
      unaff_r5[0x15] = 0;
      unaff_r5[0x16] = 0;
    }
    else {
      iVar6 = bitreader_peek();
      bitreader_refill();
      unaff_r5[0x15] = iVar6;
      if (iVar6 != 0) {
        bitreader_refill();
        bitreader_refill();
      }
      iVar6 = bitreader_peek();
      bitreader_refill();
      unaff_r5[0x16] = iVar6;
    }
    cVar1 = bitreader_peek();
    bitreader_refill();
    *(char *)(unaff_r5 + 0x24) = cVar1;
    if (cVar1 != '\0') {
      bitreader_refill();
      bitreader_refill();
      bitreader_refill();
      bitreader_refill();
      bitreader_refill();
      bitreader_refill();
      bitreader_refill();
      bitreader_refill();
      if (unaff_r5[3] == 1) {
        bitreader_refill();
        bitreader_refill();
        bitreader_refill();
        bitreader_refill();
        bitreader_refill();
        bitreader_refill();
      }
      return 0xffffffff;
    }
  }
  if (unaff_r10 == 0) {
    uVar5 = 0xfffffffe;
  }
  else {
    uVar5 = 0xfffffffd;
  }
  return uVar5;
}


