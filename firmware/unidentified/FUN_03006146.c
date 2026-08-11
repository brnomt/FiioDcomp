/**
 * FUN_03006146 @ 0x03006146
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03006146(uint param_1,int param_2,uint param_3,byte param_4)

{
  longlong lVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  uint uVar7;
  undefined2 unaff_r4;
  int unaff_r5;
  undefined2 unaff_r6;
  undefined2 unaff_r7;
  int unaff_r8;
  int in_r12;
  undefined2 unaff_lr;
  char in_CY;
  undefined2 in_stack_00000088;
  undefined2 uStack0000008a;
  undefined2 in_stack_0000008c;
  undefined2 uStack0000008e;
  
  *(undefined2 *)(unaff_r5 + (uint)param_4 * 2) = unaff_r4;
  uVar7 = param_4 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar7 * 2) = 0x74;
  uVar7 = uVar7 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar7 * 2) = unaff_r7;
  uVar7 = uVar7 + 1 & 0xff;
  if (in_CY == '\0') {
    uVar3 = uVar7 + 1 & 0xff;
    *(undefined2 *)(unaff_r5 + uVar7 * 2) = unaff_lr;
    *(undefined2 *)(unaff_r5 + uVar3 * 2) = 0x53;
    uVar7 = uVar3 + 1 & 0xff;
    *(undefined2 *)(unaff_r5 + uVar7 * 2) = unaff_lr;
    FUN_02fef2b2(0x13c,0x127,0x67);
    goto LAB_030062bc;
  }
  uVar3 = param_1 / 1000;
  if (999 < param_1) {
    lVar1 = (longlong)unaff_r8 * (longlong)(int)(uVar3 / 1000);
    *(short *)(unaff_r5 + uVar7 * 2) =
         (short)(uVar3 / 1000) + ((short)(int)(lVar1 >> 0x22) - (short)(lVar1 >> 0x3f)) * -10 + 0x30
    ;
    uVar7 = uVar7 + 1 & 0xff;
  }
  if (99 < param_1) {
    iVar4 = (int)((ulonglong)((longlong)DAT_03006338 * (longlong)(int)uVar3) >> 0x20);
    iVar4 = (iVar4 >> 5) - (iVar4 >> 0x1f);
    lVar1 = (longlong)unaff_r8 * (longlong)iVar4;
    *(short *)(unaff_r5 + uVar7 * 2) =
         (short)iVar4 + ((short)(int)(lVar1 >> 0x22) - (short)(lVar1 >> 0x3f)) * -10 + 0x30;
    uVar7 = uVar7 + 1 & 0xff;
  }
  iVar4 = (int)((ulonglong)((longlong)unaff_r8 * (longlong)(int)uVar3) >> 0x20);
  iVar4 = (iVar4 >> 2) - (iVar4 >> 0x1f);
  lVar1 = (longlong)unaff_r8 * (longlong)iVar4;
  sVar2 = (short)iVar4;
  *(short *)(unaff_r5 + uVar7 * 2) =
       sVar2 + ((short)(int)(lVar1 >> 0x22) - (short)(lVar1 >> 0x3f)) * -10 + 0x30;
  uVar7 = uVar7 + 1 & 0xff;
  *(short *)(unaff_r5 + uVar7 * 2) = (short)uVar3 + sVar2 * -10 + 0x30;
  uVar7 = uVar7 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar7 * 2) = 0x6b;
  uVar7 = uVar7 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar7 * 2) = unaff_r6;
  uVar7 = uVar7 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar7 * 2) = 0x70;
  uVar7 = uVar7 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar7 * 2) = 0x73;
  if ((in_r12 == 3 || in_r12 == 5) || (in_r12 == 6 || in_r12 == 7)) {
    if (param_3 < 0x18) {
      if (DAT_03006340 <= param_2) goto LAB_0300629e;
      if (param_2 < 0xac44) goto LAB_0300628c;
      uVar5 = 0x13a;
    }
    else {
      if (param_2 < 0xac44) goto LAB_0300628c;
LAB_0300629e:
      uVar5 = 0x13b;
    }
  }
  else {
LAB_0300628c:
    uVar5 = 0x147;
  }
  FUN_02fef2b2(uVar5,0x127,0x67);
LAB_030062bc:
  uVar3 = uVar7 + 1 & 0xff;
  uVar7 = uVar3 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar3 * 2) = 0;
  *(undefined2 *)(unaff_r5 + uVar7 * 2) = 0;
  uVar7 = uVar7 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar7 * 2) = 0;
  *(undefined2 *)(unaff_r5 + (uVar7 + 1 & 0xff) * 2) = 0;
  in_stack_00000088 = 0xa3;
  uStack0000008a = 0x7d;
  in_stack_0000008c = 0x140;
  uStack0000008e = 0x8c;
  FUN_02fee544(1);
  if (*(char *)(DAT_03006344 + 0x34f) == '\x04') {
    uVar6 = 0xe162;
  }
  else {
    uVar6 = 0x44de;
  }
  *DAT_03006348 = uVar6;
  FUN_02feda18(&stack0x00000088);
  FUN_02fee544(2);
  return;
}


