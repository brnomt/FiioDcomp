/**
 * FUN_0301afcc @ 0x0301afcc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301afcc(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_03009500(0xf,7);
  FUN_02ff7be6(0xe);
  FUN_02ff7a9c(0xe,0xe0);
  FUN_03008160(0xe,&DAT_0301af97);
  FUN_02ff7ae0(0xe);
  thunk_FUN_0301b1a4();
  FUN_02ff7be6(0x11);
  FUN_03008160(0x11,DAT_0301b170);
  FUN_02ff7ae0(0x11);
  FUN_0301d03e();
  iVar2 = FUN_0301b20c(8,0);
  if (iVar2 != 0) {
    FUN_02ff3014(3,0);
    FUN_02ff6c10(0,2,0,8000);
    FUN_02ff1f52(0,0xf,0,1);
    iVar2 = DAT_0301b174;
    FUN_03001cba(*(undefined4 *)(DAT_0301b174 + 0x14));
    FUN_03001cb6(0,*(undefined4 *)(iVar2 + 0x14));
    puVar1 = DAT_0301b164;
    DAT_0301b164[1] = 0x480;
    FUN_0301b270(puVar1);
    FUN_03000e08(2,*puVar1,DAT_0301b168,puVar1[1]);
    FUN_02ff0cce(0,4);
    return 0;
  }
  return 0xffffffff;
}


