/**
 * FUN_0301bca8 @ 0x0301bca8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301bca8(int param_1,int param_2,uint param_3,uint param_4)

{
  *DAT_0301bd5c = 1;
  *DAT_0301bd8c = 1;
  *DAT_0301bd74 = 0;
  *DAT_0301bd60 = param_3;
  *DAT_0301bd78 = param_4;
  *DAT_0301bd58 = param_1;
  *DAT_0301bd84 = param_2;
  *DAT_0301bd7c = *(uint *)(param_1 + 0x3c + param_3 * 4);
  *DAT_0301bd68 = (uint)(*(char *)(param_1 + 1) != '\0');
  if (*DAT_0301bd74 < *DAT_0301bd78) {
    *DAT_0301bd80 = *DAT_0301bd60 | (0xf - *DAT_0301bd7c) * 2;
    FUN_02ff5d5a(DAT_0301bd88,*DAT_0301bd84 + *DAT_0301bd74 * 0x80,0x80);
    *DAT_0301bd7c = (byte)*DAT_0301bd7c + 1 & 0xf;
    *DAT_0301bd74 = *DAT_0301bd74 + 1;
  }
  else {
    *(uint *)(*DAT_0301bd58 + 0x3c + *DAT_0301bd60 * 4) = *DAT_0301bd7c;
    *DAT_0301bd8c = 0;
  }
  return;
}


