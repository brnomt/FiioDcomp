/**
 * FUN_0301c870 @ 0x0301c870
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0301c870(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  uint uStack_1c;
  
  uStack_28 = param_1;
  uStack_24 = param_2;
  uStack_20 = param_3;
  uStack_1c = param_4;
  for (; 0x1f < param_3; param_3 = param_3 - 0x20) {
    uVar1 = bitstream_getbits_be_ovl_01c7(&uStack_28,0x20);
    uVar2 = (uint)*(ushort *)(*DAT_0301c974 + ((param_4 >> 8 ^ uVar1 >> 0x18) & 0xff) * 2) ^
            param_4 << 8;
    uVar2 = (uint)*(ushort *)(*DAT_0301c974 + ((uVar2 >> 8 ^ uVar1 >> 0x10) & 0xff) * 2) ^
            uVar2 << 8;
    uVar2 = (uint)*(ushort *)(*DAT_0301c974 + ((uVar2 ^ uVar1) >> 8 & 0xff) * 2) ^ uVar2 << 8;
    param_4 = (uint)*(ushort *)(*DAT_0301c974 + ((uVar1 ^ uVar2 >> 8) & 0xff) * 2) ^ uVar2 << 8;
  }
  uVar1 = param_3 >> 3;
  if (uVar1 != 0) {
    if (uVar1 != 1) {
      if (uVar1 != 2) {
        if (uVar1 != 3) goto LAB_0301c964;
        uVar1 = bitstream_getbits_be_ovl_01c7(&uStack_28,8);
        param_4 = (uint)*(ushort *)(*DAT_0301c974 + ((uVar1 ^ param_4 >> 8) & 0xff) * 2) ^
                  param_4 << 8;
      }
      uVar1 = bitstream_getbits_be_ovl_01c7(&uStack_28,8);
      param_4 = (uint)*(ushort *)(*DAT_0301c974 + ((uVar1 ^ param_4 >> 8) & 0xff) * 2) ^
                param_4 << 8;
    }
    uVar1 = bitstream_getbits_be_ovl_01c7(&uStack_28,8);
    param_4 = (uint)*(ushort *)(*DAT_0301c974 + ((uVar1 ^ param_4 >> 8) & 0xff) * 2) ^ param_4 << 8;
    param_3 = param_3 & 7;
  }
LAB_0301c964:
  while (bVar3 = param_3 != 0, param_3 = param_3 - 1, bVar3) {
    uVar2 = bitstream_getbits_be_ovl_01c7(&uStack_28,1);
    uVar1 = param_4 >> 0xf;
    param_4 = param_4 << 1;
    if (((uVar2 ^ uVar1) & 1) != 0) {
      param_4 = param_4 ^ 0x8005;
    }
  }
  return param_4 & 0xffff;
}


