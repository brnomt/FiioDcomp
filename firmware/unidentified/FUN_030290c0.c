/**
 * FUN_030290c0 @ 0x030290c0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030290c0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *unaff_r4;
  int unaff_r5;
  int unaff_r6;
  uint unaff_r9;
  uint unaff_r10;
  char cVar4;
  undefined8 uVar5;
  
  *unaff_r4 = DAT_0302948c;
  FUN_02ffb400(*unaff_r4,unaff_r4[3]);
  cVar4 = unaff_r9 <= *(uint *)(unaff_r5 + 0x12);
  if (((int)*(uint *)(unaff_r5 + 0x12) < (int)unaff_r9) &&
     (cVar4 = unaff_r10 <= (uint)unaff_r4[1], (int)unaff_r4[1] < (int)unaff_r10)) {
    unaff_r4[6] = *(undefined4 *)(unaff_r5 + 0x12);
    unaff_r4[7] = unaff_r4[1];
  }
  else {
    uVar1 = FUN_02ffb850(unaff_r4[1]);
    uVar2 = FUN_02ffb850();
    uVar1 = FUN_02ffb558(uVar2,uVar1);
    uVar2 = FUN_02ffb850(*(undefined4 *)(unaff_r5 + 0x12));
    uVar3 = FUN_02ffb850();
    uVar2 = FUN_02ffb558(uVar3,uVar2);
    FUN_02ffb9a8(uVar2,uVar1);
    if (cVar4 == '\0') {
      uVar1 = FUN_02ffb850(unaff_r4[1]);
      uVar2 = FUN_02ffb850();
      FUN_02ffb558(uVar2,uVar1);
    }
    else {
      uVar1 = FUN_02ffb850(*(undefined4 *)(unaff_r5 + 0x12));
      uVar2 = FUN_02ffb850();
      FUN_02ffb558(uVar2,uVar1);
    }
    uVar5 = FUN_02ffb936();
    *(undefined8 *)(unaff_r4 + 10) = uVar5;
    *(undefined8 *)(unaff_r4 + 0xc) = uVar5;
    uVar5 = FUN_02ffb862(*(undefined4 *)(unaff_r5 + 0x12));
    FUN_02ffb73e((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),unaff_r4[10],unaff_r4[0xb]);
    uVar1 = FUN_02ffb8f8();
    unaff_r4[6] = uVar1;
    uVar5 = FUN_02ffb862(unaff_r4[1]);
    FUN_02ffb73e((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),unaff_r4[0xc],unaff_r4[0xd]);
    uVar1 = FUN_02ffb8f8();
    unaff_r4[7] = uVar1;
  }
  if (unaff_r4[6] == 0) {
    unaff_r4[6] = 1;
  }
  if (unaff_r4[7] == 0) {
    unaff_r4[7] = 1;
  }
  unaff_r4[5] = unaff_r9 << 2;
  *(undefined4 *)(unaff_r6 + 4) = unaff_r4[6];
  *(undefined4 *)(unaff_r6 + 8) = unaff_r4[7];
  unaff_r4[4] = *(undefined4 *)(unaff_r6 + 0xc);
  unaff_r4[8] = (int)((uint)*(ushort *)(unaff_r5 + 0x12) << 0x10) / (int)unaff_r4[6] + 1;
  unaff_r4[9] = (int)((uint)*(ushort *)(unaff_r4 + 1) << 0x10) / (int)unaff_r4[7] + 1;
  unaff_r4[0xf] = 0;
  return 1;
}


