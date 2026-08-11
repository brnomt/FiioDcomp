/**
 * FUN_0306e304 @ 0x0306e304
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0306e304(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  switch(param_1) {
  case 3:
    uVar3 = FUN_0306eacc();
    *param_2 = uVar3;
    return 1;
  case 4:
    uVar3 = FUN_0306eac0();
    *param_2 = uVar3;
    return 1;
  case 5:
    uVar3 = FUN_0306eac6();
    *param_2 = uVar3;
    return 1;
  case 6:
    uVar3 = FUN_0306ead2();
    *param_2 = uVar3;
    break;
  case 7:
    uVar1 = FUN_0306ead8();
    iVar2 = FUN_0306eac0();
    uVar3 = FUN_0306d274((int)((ulonglong)uVar1 * 1000),(int)((ulonglong)uVar1 * 1000 >> 0x20),iVar2
                         ,iVar2 >> 0x1f);
    goto LAB_0306e394;
  case 8:
    uVar3 = mp3_dec_internal(1);
    return uVar3;
  default:
    return 0;
  case 10:
    FUN_0306e97c(param_2,param_3);
    break;
  case 0xc:
    uVar3 = FUN_0306e990();
    return uVar3;
  case 0xe:
    FUN_0306eb64(param_2);
    break;
  case 0xf:
    FUN_0306eade();
    break;
  case 0x11:
    uVar3 = FUN_0306eabc();
LAB_0306e394:
    *param_2 = uVar3;
  }
  return 1;
}


