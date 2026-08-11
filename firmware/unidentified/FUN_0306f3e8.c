/**
 * FUN_0306f3e8 @ 0x0306f3e8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0306f3e8(byte *param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  FUN_03070b92(param_2 + 0x1c,0xb);
  iVar4 = bitstream_getbits_be(param_2 + 0x1c,1);
  if (iVar4 == 0) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x4000;
  }
  iVar4 = bitstream_getbits_be(param_2 + 0x1c,1);
  if (iVar4 == 0) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x1000;
  }
  else if ((*(ushort *)(param_1 + 0x18) & 0x4000) != 0) {
    *(undefined2 *)(param_2 + 0x3c) = 0x101;
    return 0xffffffff;
  }
  cVar1 = bitstream_getbits_be(param_2 + 0x1c,2);
  uVar5 = (uint)(byte)(4U - cVar1);
  *param_1 = 4U - cVar1;
  if (uVar5 == 4) {
    *(undefined2 *)(param_2 + 0x3c) = 0x102;
    return 0xffffffff;
  }
  if ((*(uint *)(param_1 + 0x18) & 0x1000) == 0) {
    *DAT_0306f770 = uVar5 | 0x10;
  }
  else {
    if ((*(uint *)(param_1 + 0x18) & 0x4000) == 0) {
      uVar5 = uVar5 | 0x20;
    }
    else {
      uVar5 = uVar5 | 0x30;
    }
    *DAT_0306f770 = uVar5;
  }
  iVar4 = bitstream_getbits_be(param_2 + 0x1c,1);
  if (iVar4 == 0) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x10;
    uVar3 = FUN_03070b9a(*(undefined4 *)(param_2 + 0x1c),*(undefined4 *)(param_2 + 0x20),0x10,0xffff
                        );
    *(undefined2 *)(param_1 + 0x14) = uVar3;
  }
  iVar4 = bitstream_getbits_be(param_2 + 0x1c,4);
  if (iVar4 == 0xf) {
    *(undefined2 *)(param_2 + 0x3c) = 0x103;
    return 0xffffffff;
  }
  if ((*(ushort *)(param_1 + 0x18) & 0x1000) == 0) {
    uVar6 = *(undefined4 *)(DAT_0306f774 + (uint)*param_1 * 0x3c + iVar4 * 4 + -0x3c);
  }
  else {
    uVar6 = *(undefined4 *)(DAT_0306f774 + (uint)(*param_1 >> 1) * 0x3c + iVar4 * 4 + 0xb4);
  }
  *(undefined4 *)(param_1 + 0xc) = uVar6;
  iVar4 = bitstream_getbits_be(param_2 + 0x1c,2);
  if (iVar4 == 3) {
    *(undefined2 *)(param_2 + 0x3c) = 0x104;
    return 0xffffffff;
  }
  uVar5 = *(uint *)(DAT_0306f778 + iVar4 * 4);
  *(uint *)(param_1 + 0x10) = uVar5;
  if ((*(uint *)(param_1 + 0x18) & 0x1000) != 0) {
    *(uint *)(param_1 + 0x10) = uVar5 >> 1;
    if ((*(uint *)(param_1 + 0x18) & 0x4000) != 0) {
      *(uint *)(param_1 + 0x10) = uVar5 >> 2;
    }
  }
  iVar4 = bitstream_getbits_be(param_2 + 0x1c,1);
  if (iVar4 != 0) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x80;
  }
  iVar4 = bitstream_getbits_be(param_2 + 0x1c,1);
  if (iVar4 != 0) {
    *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 0x100;
  }
  cVar1 = bitstream_getbits_be(param_2 + 0x1c,2);
  param_1[1] = 3 - cVar1;
  uVar6 = bitstream_getbits_be(param_2 + 0x1c,2);
  *(undefined4 *)(param_1 + 4) = uVar6;
  iVar4 = bitstream_getbits_be(param_2 + 0x1c,1);
  if (iVar4 != 0) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x20;
  }
  iVar4 = bitstream_getbits_be(param_2 + 0x1c,1);
  if (iVar4 != 0) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x40;
  }
  bVar2 = bitstream_getbits_be(param_2 + 0x1c,2);
  param_1[8] = bVar2;
  if ((param_1[0x18] & 0x10) != 0) {
    uVar3 = bitstream_getbits_be(param_2 + 0x1c,0x10);
    *(undefined2 *)(param_1 + 0x16) = uVar3;
  }
  return 0;
}


