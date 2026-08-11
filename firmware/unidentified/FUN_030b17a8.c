/**
 * FUN_030b17a8 @ 0x030b17a8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030b17a8(undefined1 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = bitstream_getbits(param_2,4);
  *param_1 = uVar1;
  uVar1 = bitstream_getbits(param_2,2);
  param_1[1] = uVar1;
  uVar1 = bitstream_getbits(param_2,4);
  param_1[2] = uVar1;
  uVar1 = bitstream_getbits(param_2,4);
  param_1[3] = uVar1;
  uVar1 = bitstream_getbits(param_2,4);
  param_1[4] = uVar1;
  uVar1 = bitstream_getbits(param_2,4);
  param_1[5] = uVar1;
  uVar1 = bitstream_getbits(param_2,2);
  param_1[6] = uVar1;
  uVar1 = bitstream_getbits(param_2,3);
  param_1[7] = uVar1;
  uVar1 = bitstream_getbits(param_2,4);
  param_1[8] = uVar1;
  bVar2 = bitstream_getbits(param_2,1);
  param_1[9] = bVar2 << 4;
  if ((bVar2 & 0xf) != 0) {
    bVar2 = bitstream_getbits(param_2,4);
    param_1[9] = bVar2 | param_1[9];
  }
  bVar2 = bitstream_getbits(param_2,1);
  param_1[10] = bVar2 << 4;
  if ((bVar2 & 0xf) != 0) {
    bVar2 = bitstream_getbits(param_2,4);
    param_1[10] = bVar2 | param_1[10];
  }
  bVar2 = bitstream_getbits(param_2,1);
  param_1[0xb] = bVar2 << 4;
  if ((bVar2 & 0xf) != 0) {
    cVar3 = bitstream_getbits(param_2,2);
    param_1[0xb] = param_1[0xb] | cVar3 << 1;
    bVar2 = bitstream_getbits(param_2,1);
    param_1[0xb] = bVar2 | param_1[0xb];
  }
  iVar4 = 0;
  if (param_1[3] != '\0') {
    do {
      cVar3 = bitstream_getbits(param_2,1);
      param_1[iVar4 + 0xc] = cVar3 << 4;
      bVar2 = bitstream_getbits(param_2,4);
      iVar5 = iVar4 + 1;
      param_1[iVar4 + 0xc] = bVar2 | param_1[iVar4 + 0xc];
      iVar4 = iVar5;
    } while (iVar5 < (int)(uint)(byte)param_1[3]);
  }
  iVar4 = 0;
  if (param_1[4] != '\0') {
    do {
      cVar3 = bitstream_getbits(param_2,1);
      param_1[iVar4 + 0x1b] = cVar3 << 4;
      bVar2 = bitstream_getbits(param_2,4);
      iVar5 = iVar4 + 1;
      param_1[iVar4 + 0x1b] = bVar2 | param_1[iVar4 + 0x1b];
      iVar4 = iVar5;
    } while (iVar5 < (int)(uint)(byte)param_1[4]);
  }
  iVar4 = 0;
  if (param_1[5] != '\0') {
    do {
      cVar3 = bitstream_getbits(param_2,1);
      param_1[iVar4 + 0x2a] = cVar3 << 4;
      bVar2 = bitstream_getbits(param_2,4);
      iVar5 = iVar4 + 1;
      param_1[iVar4 + 0x2a] = bVar2 | param_1[iVar4 + 0x2a];
      iVar4 = iVar5;
    } while (iVar5 < (int)(uint)(byte)param_1[5]);
  }
  iVar4 = 0;
  if (param_1[6] != '\0') {
    do {
      uVar1 = bitstream_getbits(param_2,4);
      iVar5 = iVar4 + 1;
      param_1[iVar4 + 0x39] = uVar1;
      iVar4 = iVar5;
    } while (iVar5 < (int)(uint)(byte)param_1[6]);
  }
  iVar4 = 0;
  if (param_1[7] != '\0') {
    do {
      uVar1 = bitstream_getbits(param_2,4);
      iVar5 = iVar4 + 1;
      param_1[iVar4 + 0x3c] = uVar1;
      iVar4 = iVar5;
    } while (iVar5 < (int)(uint)(byte)param_1[7]);
  }
  iVar4 = 0;
  if (param_1[8] != '\0') {
    do {
      cVar3 = bitstream_getbits(param_2,1);
      param_1[iVar4 + 0x43] = cVar3 << 4;
      bVar2 = bitstream_getbits(param_2,4);
      iVar5 = iVar4 + 1;
      param_1[iVar4 + 0x43] = bVar2 | param_1[iVar4 + 0x43];
      iVar4 = iVar5;
    } while (iVar5 < (int)(uint)(byte)param_1[8]);
  }
  FUN_030b1718(param_2);
  for (iVar4 = bitstream_getbits(param_2,8); iVar4 != 0; iVar4 = iVar4 + -1) {
    bitstream_getbits(param_2,8);
  }
  return 0;
}


