/**
 * FUN_030641c2 @ 0x030641c2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030641c2(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  
  uVar3 = FUN_03021ffe(0);
  uVar4 = func_0x03021fea(0);
  iVar1 = DAT_03064474;
  *(undefined4 *)(DAT_03064474 + 0x20) = 0;
  FUN_03022242(1);
  FUN_03064098(*(undefined2 *)(iVar1 + 8));
  if (*(ushort *)(iVar1 + 8) < 2) {
    if (*(short *)(iVar1 + 10) == 0) {
      uVar5 = 0x480;
    }
    else {
      uVar5 = 0x3f4;
    }
    *(undefined4 *)(iVar1 + 0x1c) = uVar5;
    func_0x030245e8(3,0);
    FUN_030281e4(0,2,0,*(undefined4 *)(iVar1 + 0x18),0,0xf,0);
  }
  else {
    *(undefined4 *)(iVar1 + 0x1c) = 0xc00;
    func_0x030245e8(3,0);
    FUN_030281e4(0,2,0,*(undefined4 *)(iVar1 + 0x18),0,0x17,0);
  }
  FUN_030281b6(5);
  FUN_030281b6(4);
  iVar2 = DAT_03064488;
  piVar7 = (int *)(DAT_03064488 + -0x344);
  iVar6 = DAT_03064488 + 0x10;
  FUN_030323dc(5,uVar4,iVar6 + *piVar7 * 0x3000,*(undefined4 *)(iVar1 + 0x1c),DAT_03064488,0x306415b
              );
  FUN_030376b8(10);
  FUN_030323dc(4,iVar6 + (1 - *piVar7) * 0x3000,uVar3,*(undefined4 *)(iVar1 + 0x1c),iVar2 + -0x10,
               0x3064119);
  FUN_03022060(0,6);
  FUN_030222a2(0,6);
  if (*(ushort *)(iVar1 + 8) < 2) {
    ID3_Picture_Parser(0,0xf,0,1);
  }
  else {
    ID3_Picture_Parser(0,0x17,0,1);
  }
  uVar3 = *(undefined4 *)(iVar1 + 0x18);
  FUN_0303328e(uVar3);
  FUN_0303328a(2,uVar3);
  FUN_0303328a(0,uVar3);
  FUN_03033580();
  return;
}


