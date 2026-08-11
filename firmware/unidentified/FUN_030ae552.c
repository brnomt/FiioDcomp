/**
 * FUN_030ae552 @ 0x030ae552
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030ae552(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  iVar1 = *DAT_030ae93c;
  iVar2 = 0x5000 - iVar1;
  bVar4 = iVar2 == param_1;
  iVar3 = iVar2 - param_1;
  if (iVar2 >= param_1) {
    bVar4 = param_1 == 0;
    iVar3 = param_1;
  }
  if (bVar4 || iVar3 < 0 != (iVar2 < param_1 && SBORROW4(iVar2,param_1))) {
    hifi_debug_printf_ovl(DAT_030ae940,param_1);
    return 0;
  }
  iVar3 = DAT_030ae944 + iVar1;
  *DAT_030ae93c = param_1 + (4U - param_1 & 3) + iVar1;
  return iVar3;
}


