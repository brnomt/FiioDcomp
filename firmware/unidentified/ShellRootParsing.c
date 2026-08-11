/**
 * ShellRootParsing @ 0x03022b10
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */

undefined4 ShellRootParsing(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_1d0 [8];
  int iStack_1c8;
  int aiStack_98 [32];
  
  puVar1 = DAT_03022af8;
  *(undefined4 *)(DAT_03022af8 + 4) = 0xffffffff;
  *(undefined4 *)(puVar1 + 8) = 0xffffffff;
  puVar2 = DAT_03022afc;
  *puVar1 = 0;
  puVar1[1] = 0;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  *(undefined2 *)puVar2 = 0xffe1;
  *(undefined2 *)((int)puVar2 + 2) = 0;
  FUN_02ff8972(puVar2 + 1,DAT_03022b00,4);
  *(undefined2 *)(puVar2 + 3) = 0x4d4d;
  *(undefined2 *)((int)puVar2 + 0xe) = 0x2a;
  puVar2[4] = 8;
  iVar3 = USBMSCHost_Read(0,0,(int)(char)puVar1[0x34]);
  if (iVar3 != 0) {
    return 0;
  }
  FUN_030221e4();
  FUN_02ff895c(aiStack_98,0x80);
  FUN_02ff895c(auStack_1d0,0x134);
  uVar4 = FUN_02ffce6c((int)(char)puVar1[0x34]);
  *(undefined4 *)(puVar1 + 0x2c) = uVar4;
  puVar1[1] = puVar1[0xc];
  iVar3 = FUN_030228aa(*(undefined4 *)(puVar1 + 0x34));
  if (iVar3 < 0) goto LAB_03022824;
  iVar5 = FUN_03022346(*(undefined4 *)(puVar1 + 0x34),puVar2[4],1,auStack_1d0);
  if (iVar5 != 0) {
    iVar7 = *(int *)(iVar5 + 0x138);
    iVar6 = 1;
    aiStack_98[0] = iVar5;
    if (iStack_1c8 != 0) {
      iVar5 = FUN_03022346(*(undefined4 *)(puVar1 + 0x34),iStack_1c8,3,auStack_1d0);
      if (iVar5 == 0) {
        iVar3 = -1;
      }
      else {
        iVar6 = 2;
        aiStack_98[1] = iVar5;
      }
    }
    if (iVar7 == 0) goto LAB_03022824;
    iVar5 = FUN_03022346(*(undefined4 *)(puVar1 + 0x34),iVar7,2,auStack_1d0);
    if (iVar5 != 0) {
      aiStack_98[iVar6] = iVar5;
      goto LAB_03022824;
    }
  }
  iVar3 = -1;
LAB_03022824:
  if (iVar3 < 0) {
    FUN_030221e4();
    return 0;
  }
  iVar3 = USBMSCHost_Read(0,0,(int)(char)puVar1[0x34]);
  if (iVar3 != 0) {
    return 0;
  }
  return 1;
}
