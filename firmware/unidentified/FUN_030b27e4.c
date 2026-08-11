/**
 * FUN_030b27e4 @ 0x030b27e4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030b27e4(int *param_1,int *param_2,uint *param_3,int *param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int unaff_r4;
  undefined1 auStack_38 [24];
  
  if (param_1 != (int *)0x0) {
    unaff_r4 = *param_1;
  }
  if (param_1 == (int *)0x0 || unaff_r4 == 0) {
    return 0xfffffffe;
  }
  piVar1 = param_1;
  if (param_5 == 1) {
    piVar1 = *(int **)(unaff_r4 + 0x8f0);
  }
  iVar2 = unaff_r4;
  if (param_5 != 1 || piVar1 != (int *)0x1) {
    iVar2 = unaff_r4 + param_5 * 0x3a;
  }
  FUN_030b1524(auStack_38,*param_4 + 7 >> 3,*param_2);
  bitstream_getbits(auStack_38,*param_3);
  FUN_030b28b2(unaff_r4,auStack_38,param_5);
  if (*(char *)(iVar2 + 0x87d) == '\x02') {
    FWShellSn(unaff_r4,auStack_38,param_5);
  }
  else {
    FUN_030b3c3a();
  }
  iVar2 = FUN_030b16fc(auStack_38,*param_2,*param_3);
  *param_2 = *param_2 + ((int)(*param_3 + iVar2) >> 3);
  *param_3 = (uint)(byte)*param_3 + iVar2 & 7;
  *param_4 = *param_4 - iVar2;
  param_1[param_5 + 0xc] = 0;
  param_1[0x15] = param_1[0x15] | (uint)*(byte *)(param_5 * 0x65 + unaff_r4 + 0xc02);
  return 0;
}


