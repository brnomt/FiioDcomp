/**
 * FUN_03011158 @ 0x03011158
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


char FUN_03011158(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined8 uVar4;
  
  cVar2 = '\0';
  FUN_02feccb4(*(undefined4 *)(DAT_030114c8 + 0x28),*(undefined4 *)(DAT_030114c8 + 0x2c),param_1,
               param_2);
  uVar4 = CONCAT44(extraout_r3,extraout_r2);
  bVar3 = 0;
  do {
    uVar4 = FUN_02feccb4((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),10,0);
    uVar1 = (uint)((ulonglong)uVar4 >> 0x20);
    if (uVar1 == 0 && ((int)uVar4 != 0) <= uVar1) {
      return cVar2;
    }
    cVar2 = cVar2 + '\x01';
    bVar3 = bVar3 + 1;
  } while (bVar3 < 0x10);
  return cVar2;
}


