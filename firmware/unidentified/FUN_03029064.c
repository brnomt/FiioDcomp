/**
 * FUN_03029064 @ 0x03029064
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03029064(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *unaff_r4;
  char cVar6;
  undefined8 uVar7;
  uint in_stack_00000038;
  
  iVar1 = *(int *)(param_3 + 0x16);
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  unaff_r4[1] = iVar1;
  uVar2 = FUN_02ffb850((int)*(short *)(param_3 + 0x1c));
  uVar2 = FUN_02ffb558(uVar2,0x41000000);
  unaff_r4[2] = uVar2;
  uVar2 = FUN_02ffb850(*(undefined4 *)(param_3 + 0x12));
  FUN_02ffb4ec(uVar2,unaff_r4[2]);
  uVar7 = FUN_02ffb936();
  FUN_02ffb5f0((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),DAT_03029484,DAT_03029488);
  uVar3 = FUN_02ffb8f8();
  unaff_r4[3] = uVar3 & 0xfffffffc;
  *unaff_r4 = DAT_0302948c;
  FUN_02ffb400(*unaff_r4,unaff_r4[3]);
  cVar6 = param_4 <= *(uint *)(param_3 + 0x12);
  if (((int)*(uint *)(param_3 + 0x12) < (int)param_4) &&
     (cVar6 = in_stack_00000038 <= (uint)unaff_r4[1], (int)unaff_r4[1] < (int)in_stack_00000038)) {
    unaff_r4[6] = *(undefined4 *)(param_3 + 0x12);
    unaff_r4[7] = unaff_r4[1];
  }
  else {
    uVar2 = FUN_02ffb850(unaff_r4[1]);
    uVar4 = FUN_02ffb850(in_stack_00000038);
    uVar2 = FUN_02ffb558(uVar4,uVar2);
    uVar4 = FUN_02ffb850(*(undefined4 *)(param_3 + 0x12));
    uVar5 = FUN_02ffb850(param_4);
    uVar4 = FUN_02ffb558(uVar5,uVar4);
    FUN_02ffb9a8(uVar4,uVar2);
    if (cVar6 == '\0') {
      uVar2 = FUN_02ffb850(unaff_r4[1]);
      uVar4 = FUN_02ffb850(in_stack_00000038);
      FUN_02ffb558(uVar4,uVar2);
    }
    else {
      uVar2 = FUN_02ffb850(*(undefined4 *)(param_3 + 0x12));
      uVar4 = FUN_02ffb850(param_4);
      FUN_02ffb558(uVar4,uVar2);
    }
    uVar7 = FUN_02ffb936();
    *(undefined8 *)(unaff_r4 + 10) = uVar7;
    *(undefined8 *)(unaff_r4 + 0xc) = uVar7;
    uVar7 = FUN_02ffb862(*(undefined4 *)(param_3 + 0x12));
    FUN_02ffb73e((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),unaff_r4[10],unaff_r4[0xb]);
    uVar2 = FUN_02ffb8f8();
    unaff_r4[6] = uVar2;
    uVar7 = FUN_02ffb862(unaff_r4[1]);
    FUN_02ffb73e((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),unaff_r4[0xc],unaff_r4[0xd]);
    uVar2 = FUN_02ffb8f8();
    unaff_r4[7] = uVar2;
  }
  if (unaff_r4[6] == 0) {
    unaff_r4[6] = 1;
  }
  if (unaff_r4[7] == 0) {
    unaff_r4[7] = 1;
  }
  unaff_r4[5] = param_4 << 2;
  *(undefined4 *)(param_2 + 4) = unaff_r4[6];
  *(undefined4 *)(param_2 + 8) = unaff_r4[7];
  unaff_r4[4] = *(undefined4 *)(param_2 + 0xc);
  unaff_r4[8] = (int)((uint)*(ushort *)(param_3 + 0x12) << 0x10) / (int)unaff_r4[6] + 1;
  unaff_r4[9] = (int)((uint)*(ushort *)(unaff_r4 + 1) << 0x10) / (int)unaff_r4[7] + 1;
  unaff_r4[0xf] = 0;
  return 1;
}


