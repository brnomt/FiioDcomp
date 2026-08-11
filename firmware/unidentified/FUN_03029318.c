/**
 * FUN_03029318 @ 0x03029318
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03029318(uint param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *unaff_r4;
  uint uVar6;
  uint uVar7;
  int unaff_r6;
  undefined4 *unaff_r8;
  int unaff_r9;
  int unaff_r11;
  undefined4 uStack00000000;
  undefined4 uStack00000004;
  undefined4 uStack00000008;
  int in_stack_00000014;
  int in_stack_00000018;
  uint uStack00000020;
  uint uStack00000024;
  uint uStack00000028;
  undefined4 in_stack_0000002c;
  undefined4 in_stack_00000030;
  undefined4 in_stack_00000034;
  undefined4 in_stack_00000038;
  undefined4 in_stack_00000044;
  
code_r0x03029318:
  uStack00000024 = (uint)*(byte *)(*unaff_r4 + (unaff_r4[0xe] >> 0x10) * 4 + 1);
  uStack00000028 = (uint)*(byte *)(*unaff_r4 + (unaff_r4[0xe] >> 0x10) * 4);
  uStack00000020 = param_1;
  do {
    uStack00000000 = in_stack_00000030;
    uStack00000004 = in_stack_00000034;
    uStack00000008 = in_stack_00000038;
    uVar1 = (**(code **)(unaff_r9 + 8))
                      (uStack00000020,uStack00000024,uStack00000028,in_stack_0000002c);
    *(undefined2 *)(in_stack_00000018 + unaff_r11 * 2 + in_stack_00000014 * 2) = uVar1;
    unaff_r4[0xe] = unaff_r4[0xe] + unaff_r4[8];
    unaff_r11 = unaff_r11 + 1;
    if (unaff_r4[6] <= unaff_r11) {
      unaff_r4[0xf] = unaff_r4[0xf] + unaff_r4[9];
      *(uint *)(unaff_r6 + 0x58) =
           unaff_r4[3] *
           (((unaff_r4[0xf] >> 0x10) - ((uint)(unaff_r4[0xf] - unaff_r4[9]) >> 0x10)) + -1);
      uVar4 = FUN_02ffb850(*(undefined4 *)(unaff_r6 + 0x12));
      FUN_02ffb4ec(uVar4,unaff_r4[2]);
      iVar5 = FUN_02ffb8d0();
      *(int *)(unaff_r6 + 0x58) = (unaff_r4[3] - iVar5) + *(int *)(unaff_r6 + 0x58);
      if (*(int *)(unaff_r6 + 0x16) < 1) {
        (**(code **)(unaff_r9 + 4))
                  (*unaff_r8,(unaff_r4[0xf] >> 0x10) * unaff_r4[3] + *(int *)(unaff_r6 + 10),0);
      }
      else {
        (**(code **)(unaff_r9 + 4))
                  (*unaff_r8,
                   (unaff_r4[1] - (unaff_r4[0xf] >> 0x10)) * unaff_r4[3] + *(int *)(unaff_r6 + 10),0
                  );
      }
      return 1;
    }
    switch(in_stack_00000044) {
    case 0:
      iVar2 = unaff_r4[0xe];
      iVar5 = iVar2 >> 0x10;
      uStack00000008 = FUN_02ffb850(iVar5);
      FUN_02ffb4ec(uStack00000008,unaff_r4[2]);
      iVar3 = FUN_02ffb89e();
      uVar6 = (uint)*(byte *)(*unaff_r4 + iVar3);
      switch(iVar5 + ((int)(iVar5 + ((uint)(iVar2 >> 0x1f) >> 0x1d)) >> 3) * -8 & 0xff) {
      case 0:
        uVar6 = (uint)(*(byte *)(*unaff_r4 + iVar3) >> 7);
        break;
      case 1:
        uVar6 = (uVar6 & 0x7f) >> 6;
        break;
      case 2:
        uVar6 = (uVar6 & 0x3f) >> 5;
        break;
      case 3:
        uVar6 = (uVar6 & 0x1f) >> 4;
        break;
      case 4:
        uVar6 = (uVar6 & 0xf) >> 3;
        break;
      case 5:
        uVar6 = (uVar6 & 7) >> 2;
        break;
      case 6:
        uVar6 = (uVar6 & 3) >> 1;
        break;
      case 7:
        uVar6 = uVar6 & 1;
      }
      uStack00000020 = (uint)*(byte *)(*(int *)(unaff_r6 + 0x38) + uVar6 * 4 + 2);
      uStack00000024 = (uint)*(byte *)(*(int *)(unaff_r6 + 0x38) + uVar6 * 4 + 1);
      uStack00000028 = (uint)*(byte *)(*(int *)(unaff_r6 + 0x38) + uVar6 * 4);
      break;
    case 1:
      iVar5 = unaff_r4[0xe] >> 0x10;
      uVar6 = iVar5 + (iVar5 - (unaff_r4[0xe] >> 0x1f) >> 1) * -2 & 0xff;
      uStack00000008 = FUN_02ffb850();
      FUN_02ffb4ec(uStack00000008,unaff_r4[2]);
      iVar5 = FUN_02ffb89e();
      uVar7 = (uint)*(byte *)(*unaff_r4 + iVar5);
      if (uVar6 == 0) {
        uVar7 = (uint)(*(byte *)(*unaff_r4 + iVar5) >> 4);
      }
      else if (uVar6 == 1) {
        uVar7 = uVar7 & 0xf;
      }
      uStack00000020 = (uint)*(byte *)(*(int *)(unaff_r6 + 0x38) + uVar7 * 4 + 2);
      uStack00000024 = (uint)*(byte *)(*(int *)(unaff_r6 + 0x38) + uVar7 * 4 + 1);
      uStack00000028 = (uint)*(byte *)(*(int *)(unaff_r6 + 0x38) + uVar7 * 4);
      break;
    case 2:
      uVar6 = (uint)*(byte *)(*unaff_r4 + (unaff_r4[0xe] >> 0x10));
      uStack00000020 = (uint)*(byte *)(*(int *)(unaff_r6 + 0x38) + uVar6 * 4 + 2);
      uStack00000024 = (uint)*(byte *)(*(int *)(unaff_r6 + 0x38) + uVar6 * 4 + 1);
      uStack00000028 = (uint)*(byte *)(*(int *)(unaff_r6 + 0x38) + uVar6 * 4);
      break;
    case 3:
      uVar6 = (uint)*(ushort *)(*unaff_r4 + (unaff_r4[0xe] >> 0x10) * 2);
      uStack00000020 = (int)(uVar6 & 0x7c00) >> 7;
      uStack00000024 = (int)(uVar6 & 0x3e0) >> 2;
      uStack00000028 = (uVar6 & 0x1f) << 3;
      break;
    case 4:
      uStack00000020 = (uint)*(byte *)(*unaff_r4 + (unaff_r4[0xe] >> 0x10) * 3 + 2);
      uStack00000024 = (uint)*(byte *)(*unaff_r4 + (unaff_r4[0xe] >> 0x10) * 3 + 1);
      uStack00000028 = (uint)*(byte *)(*unaff_r4 + (unaff_r4[0xe] >> 0x10) * 3);
    default:
      break;
    case 5:
      goto switchD_0302929a_caseD_5;
    case 8:
      uVar6 = (uint)*(ushort *)(*unaff_r4 + (unaff_r4[0xe] >> 0x10) * 2);
      uStack00000020 = (int)(uVar6 & 0xf800) >> 8;
      uStack00000024 = (int)(uVar6 & 0x7e0) >> 3;
      uStack00000028 = (uVar6 & 0x1f) << 3;
      break;
    case 9:
      uStack00000020 = (uint)*(byte *)(*unaff_r4 + (unaff_r4[0xe] >> 0x10) * 4 + 3);
      uStack00000024 = (uint)*(byte *)(*unaff_r4 + (unaff_r4[0xe] >> 0x10) * 4 + 2);
      uStack00000028 = (uint)*(byte *)(*unaff_r4 + (unaff_r4[0xe] >> 0x10) * 4 + 1);
    }
  } while( true );
switchD_0302929a_caseD_5:
  param_1 = (uint)*(byte *)(*unaff_r4 + (unaff_r4[0xe] >> 0x10) * 4 + 2);
  goto code_r0x03029318;
}


