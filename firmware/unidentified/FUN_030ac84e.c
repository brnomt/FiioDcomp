/**
 * FUN_030ac84e @ 0x030ac84e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined8 FUN_030ac84e(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined8 uVar4;
  
  bVar1 = param_2 < 0;
  if (bVar1) {
    bVar2 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar2 - param_2;
  }
  bVar2 = param_4 < 0;
  if (bVar2) {
    bVar3 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar3 - param_4;
  }
  uVar4 = FUN_030ac7ec(param_1,param_2,param_3,param_4);
  if (bVar1 != bVar2) {
    uVar4 = CONCAT44(-(uint)((int)uVar4 != 0) - (int)((ulonglong)uVar4 >> 0x20),-(int)uVar4);
  }
  return uVar4;
}


