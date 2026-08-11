/**
 * FUN_0301be76 @ 0x0301be76
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301be76(byte *param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  FUN_0301c868(param_2 + 0x1c,0xb);
  iVar4 = bitstream_getbits_be_ovl_01c7(param_2 + 0x1c,1);
  if (iVar4 == 0) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x4000;
  }
  iVar4 = bitstream_getbits_be_ovl_01c7(param_2 + 0x1c,1);
  if (iVar4 == 0) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x1000;
  }
  else if ((*(ushort *)(param_1 + 0x18) & 0x4000) != 0) {
    *(undefined2 *)(param_2 + 0x3c) = 0x101;
    return 0xffffffff;
  }
  cVar1 = bitstream_getbits_be_ovl_01c7(param_2 + 0x1c,2);
  *param_1 = 4 - cVar1;
  if (*param_1 == 4) {
    *(undefined2 *)(param_2 + 0x3c) = 0x102;
    uVar5 = 0xffffffff;
  }
  else {
    iVar4 = bitstream_getbits_be_ovl_01c7(param_2 + 0x1c,1);
    if (iVar4 == 0) {
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x10;
      uVar3 = FUN_0301c870(*(undefined4 *)(param_2 + 0x1c),*(undefined4 *)(param_2 + 0x20),0x10,
                           0xffff);
      *(undefined2 *)(param_1 + 0x14) = uVar3;
    }
    iVar4 = bitstream_getbits_be_ovl_01c7(param_2 + 0x1c,4);
    if (iVar4 == 0xf) {
      *(undefined2 *)(param_2 + 0x3c) = 0x103;
      uVar5 = 0xffffffff;
    }
    else {
      if ((*(ushort *)(param_1 + 0x18) & 0x1000) == 0) {
        *(undefined4 *)(param_1 + 0xc) =
             *(undefined4 *)(*DAT_0301c228 + (*param_1 - 1) * 0x3c + iVar4 * 4);
      }
      else {
        *(undefined4 *)(param_1 + 0xc) =
             *(undefined4 *)(*DAT_0301c228 + (((int)(uint)*param_1 >> 1) + 3) * 0x3c + iVar4 * 4);
      }
      iVar4 = bitstream_getbits_be_ovl_01c7(param_2 + 0x1c,2);
      if (iVar4 == 3) {
        *(undefined2 *)(param_2 + 0x3c) = 0x104;
        uVar5 = 0xffffffff;
      }
      else {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(*DAT_0301c22c + iVar4 * 4);
        if (((*(ushort *)(param_1 + 0x18) & 0x1000) != 0) &&
           (*(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) >> 1,
           (*(ushort *)(param_1 + 0x18) & 0x4000) != 0)) {
          *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) >> 1;
        }
        iVar4 = bitstream_getbits_be_ovl_01c7(param_2 + 0x1c,1);
        if (iVar4 != 0) {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x80;
        }
        iVar4 = bitstream_getbits_be_ovl_01c7(param_2 + 0x1c,1);
        if (iVar4 != 0) {
          *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 0x100;
        }
        cVar1 = bitstream_getbits_be_ovl_01c7(param_2 + 0x1c,2);
        param_1[1] = 3 - cVar1;
        uVar5 = bitstream_getbits_be_ovl_01c7(param_2 + 0x1c,2);
        *(undefined4 *)(param_1 + 4) = uVar5;
        iVar4 = bitstream_getbits_be_ovl_01c7(param_2 + 0x1c,1);
        if (iVar4 != 0) {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x20;
        }
        iVar4 = bitstream_getbits_be_ovl_01c7(param_2 + 0x1c,1);
        if (iVar4 != 0) {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x40;
        }
        bVar2 = bitstream_getbits_be_ovl_01c7(param_2 + 0x1c,2);
        param_1[8] = bVar2;
        if ((param_1[0x18] & 0x10) != 0) {
          uVar3 = bitstream_getbits_be_ovl_01c7(param_2 + 0x1c,0x10);
          *(undefined2 *)(param_1 + 0x16) = uVar3;
        }
        uVar5 = 0;
      }
    }
  }
  return uVar5;
}


