/**
 * FUN_030f8722 @ 0x030f8722
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030f8722(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar2 = param_2 - 1;
  uVar3 = *(undefined8 *)(param_1 + uVar2 * 2);
  while (uVar1 = (undefined4)((ulonglong)uVar3 >> 0x20), (uVar2 & 0xfffffff9) != 0) {
    uVar3 = softfloat_dmul_a((int)uVar3,uVar1,param_3,param_4);
    uVar2 = uVar2 - 1;
    uVar3 = softfloat_dadd_a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_1[uVar2 * 2],
                             (param_1 + uVar2 * 2)[1]);
  }
  if (uVar2 != 2) {
    if (uVar2 != 4) {
      if (uVar2 != 6) {
        return;
      }
      uVar3 = softfloat_dmul_a((int)uVar3,uVar1,param_3,param_4);
      uVar3 = softfloat_dadd_a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_1[10],param_1[0xb]);
      uVar3 = softfloat_dmul_a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_3,param_4);
      uVar3 = softfloat_dadd_a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_1[8],param_1[9]);
    }
    uVar3 = softfloat_dmul_a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_3,param_4);
    uVar3 = softfloat_dadd_a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_1[6],param_1[7]);
    uVar3 = softfloat_dmul_a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_3,param_4);
    uVar3 = softfloat_dadd_a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_1[4],param_1[5]);
  }
  uVar3 = softfloat_dmul_a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_3,param_4);
  uVar3 = softfloat_dadd_a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_1[2],param_1[3]);
  uVar3 = softfloat_dmul_a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_3,param_4);
  softfloat_dadd_a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),*param_1,param_1[1]);
  return;
}


