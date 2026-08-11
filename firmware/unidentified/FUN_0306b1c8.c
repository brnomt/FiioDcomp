/**
 * FUN_0306b1c8 @ 0x0306b1c8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0306b1c8(uint param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  
  uVar1 = *(ushort *)(DAT_0306b584 + 6);
  if ((uVar1 & 0xc) == 0) {
    param_2 = 0x366;
  }
  else if ((uVar1 & 0xc) == 4 || (uVar1 & 0xc) == 8) {
    param_2 = 0x2f8;
  }
  else if ((~uVar1 & 0xc) == 0) {
    param_2 = 0x28a;
  }
  if (((uVar1 & 3) == 0) || ((uVar1 & 3) != 1)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 2;
  }
  return ((uint)((ulonglong)DAT_0306b588 * (ulonglong)param_1 >> 0x23) - param_2) / uVar2 & 0xff;
}


