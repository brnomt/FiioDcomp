/**
 * FUN_030060e4 @ 0x030060e4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030060e4(uint param_1,int param_2,uint param_3,int param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int unaff_r5;
  int unaff_r8;
  int in_r12;
  undefined2 unaff_lr;
  undefined2 in_stack_00000088;
  undefined2 uStack0000008a;
  undefined2 in_stack_0000008c;
  undefined2 uStack0000008e;
  
  uVar8 = DAT_0300633c;
  uVar2 = (ulonglong)DAT_0300633c;
  *(undefined2 *)(unaff_r5 + param_4 * 2) = 0x7c;
  uVar9 = (uint)(uVar2 * param_3 >> 0x23);
  uVar7 = param_4 + 1U & 0xff;
  sVar3 = (short)uVar9;
  if (9 < param_3) {
    *(short *)(unaff_r5 + uVar7 * 2) =
         sVar3 + (short)(uint)((ulonglong)uVar8 * (ulonglong)uVar9 >> 0x23) * -10 + 0x30;
    uVar7 = uVar7 + 1 & 0xff;
  }
  *(short *)(unaff_r5 + uVar7 * 2) = (short)param_3 + sVar3 * -10 + 0x30;
  uVar8 = uVar7 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar8 * 2) = 0x62;
  uVar8 = uVar8 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar8 * 2) = 0x69;
  uVar8 = uVar8 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar8 * 2) = 0x74;
  uVar8 = uVar8 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar8 * 2) = 0x7c;
  uVar8 = uVar8 + 1 & 0xff;
  if (9 >= param_3) {
    uVar7 = uVar8 + 1 & 0xff;
    *(undefined2 *)(unaff_r5 + uVar8 * 2) = unaff_lr;
    *(undefined2 *)(unaff_r5 + uVar7 * 2) = 0x53;
    uVar8 = uVar7 + 1 & 0xff;
    *(undefined2 *)(unaff_r5 + uVar8 * 2) = unaff_lr;
    FUN_02fef2b2(0x13c,0x127,0x67);
    goto LAB_030062bc;
  }
  uVar7 = param_1 / 1000;
  if (999 < param_1) {
    lVar1 = (longlong)unaff_r8 * (longlong)(int)(uVar7 / 1000);
    *(short *)(unaff_r5 + uVar8 * 2) =
         (short)(uVar7 / 1000) + ((short)(int)(lVar1 >> 0x22) - (short)(lVar1 >> 0x3f)) * -10 + 0x30
    ;
    uVar8 = uVar8 + 1 & 0xff;
  }
  if (99 < param_1) {
    iVar4 = (int)((ulonglong)((longlong)DAT_03006338 * (longlong)(int)uVar7) >> 0x20);
    iVar4 = (iVar4 >> 5) - (iVar4 >> 0x1f);
    lVar1 = (longlong)unaff_r8 * (longlong)iVar4;
    *(short *)(unaff_r5 + uVar8 * 2) =
         (short)iVar4 + ((short)(int)(lVar1 >> 0x22) - (short)(lVar1 >> 0x3f)) * -10 + 0x30;
    uVar8 = uVar8 + 1 & 0xff;
  }
  iVar4 = (int)((ulonglong)((longlong)unaff_r8 * (longlong)(int)uVar7) >> 0x20);
  iVar4 = (iVar4 >> 2) - (iVar4 >> 0x1f);
  lVar1 = (longlong)unaff_r8 * (longlong)iVar4;
  sVar3 = (short)iVar4;
  *(short *)(unaff_r5 + uVar8 * 2) =
       sVar3 + ((short)(int)(lVar1 >> 0x22) - (short)(lVar1 >> 0x3f)) * -10 + 0x30;
  uVar8 = uVar8 + 1 & 0xff;
  *(short *)(unaff_r5 + uVar8 * 2) = (short)uVar7 + sVar3 * -10 + 0x30;
  uVar8 = uVar8 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar8 * 2) = 0x6b;
  uVar8 = uVar8 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar8 * 2) = 0x62;
  uVar8 = uVar8 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar8 * 2) = 0x70;
  uVar8 = uVar8 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar8 * 2) = 0x73;
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
  uVar7 = uVar8 + 1 & 0xff;
  uVar8 = uVar7 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar7 * 2) = 0;
  *(undefined2 *)(unaff_r5 + uVar8 * 2) = 0;
  uVar8 = uVar8 + 1 & 0xff;
  *(undefined2 *)(unaff_r5 + uVar8 * 2) = 0;
  *(undefined2 *)(unaff_r5 + (uVar8 + 1 & 0xff) * 2) = 0;
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


