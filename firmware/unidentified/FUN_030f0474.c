/**
 * FUN_030f0474 @ 0x030f0474
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030f0474(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_30 [8];
  byte local_28;
  uint local_27;
  int local_23;
  
  puVar1 = DAT_030f04e8;
  iVar3 = (*(code *)*DAT_030f04ec)(*DAT_030f04e8);
  puVar2 = DAT_030f04f0;
  (*(code *)*DAT_030f04f0)(iVar3 + -0x20,0,*puVar1);
  (*(code *)*DAT_030f04f4)(auStack_30,0x20,*puVar1);
  (*(code *)*puVar2)(*DAT_030f04fc,0,*DAT_030f04f8);
  iVar3 = FUN_030ee92e(auStack_30,s_APETAGEX_030f0500,8);
  if (((iVar3 == 0) && (((uint)local_28 | local_27 << 8) < 0x7d1)) &&
     (uVar4 = local_27 >> 0x18 | local_23 << 8, uVar4 - 0x20 < 0x1000001)) {
    return uVar4;
  }
  return 0;
}


