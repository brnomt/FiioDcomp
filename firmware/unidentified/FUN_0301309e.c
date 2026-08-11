/**
 * FUN_0301309e @ 0x0301309e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301309e(uint param_1)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int unaff_r4;
  short unaff_r5;
  int unaff_r6;
  uint unaff_r7;
  int unaff_r8;
  uint unaff_r10;
  bool bVar7;
  uint in_stack_00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  uint in_stack_00000014;
  undefined2 uStack00000018;
  short sStack0000001a;
  short sStack0000001c;
  short sStack0000001e;
  ushort in_stack_00000020;
  undefined4 in_stack_00000024;
  short in_stack_00000034;
  undefined2 uStack00000040;
  short sStack00000042;
  short sStack00000044;
  short sStack00000046;
  undefined4 in_stack_00000048;
  undefined4 in_stack_0000004c;
  undefined4 in_stack_00000050;
  undefined4 in_stack_00000054;
  int in_stack_00000058;
  int in_stack_0000005c;
  undefined4 in_stack_00000060;
  
  do {
    FUN_02ffd462(param_1);
    while( true ) {
      uVar4 = FUN_02ffb856(unaff_r4 + 0x70);
      if (in_stack_00000020 < uVar4) {
        *(int *)(DAT_03013278 + 0x10) = unaff_r4 + 0x70;
        puVar1 = DAT_0301326c;
        *DAT_0301326c = *DAT_03013268;
        puVar1[1] = 0xbdf7;
        uStack00000040 = uStack00000018;
        sStack00000042 = sStack0000001a + 5;
        sStack00000044 = sStack0000001c;
        sStack00000046 = sStack0000001a + 0x14;
        FUN_02ffc458(&stack0x00000040,_uStack00000018,0x100005,0x8c);
        DAT_0301326c[1] = *DAT_0301327c;
        MediaLib_GetTotalFiles(0x154);
      }
      else {
        *DAT_0301326c = *DAT_03013268;
        MediaLib_GetTotalFiles_c(0x154);
      }
      while( true ) {
        iVar3 = DAT_03013274;
        uVar4 = (uint)*(byte *)(unaff_r4 + 0x4e);
        bVar7 = uVar4 == 5;
        if (5 < uVar4) {
          uVar4 = 5;
        }
        if (bVar7) {
          uVar4 = 1;
        }
        if ((unaff_r10 == *(ushort *)(DAT_03013274 + 0x1ee)) &&
           (iVar2 = MediaLib_GetTotalFiles_d(0x1dc), iVar2 == 0)) {
          if (*(short *)(DAT_03013278 + 0xc) == 0) {
            iVar2 = (int)(short)((short)(unaff_r8 << 3) + 0x1c + in_stack_00000024._2_2_);
            iVar6 = (int)(short)(in_stack_00000034 + unaff_r5);
            iVar3 = uVar4 + 0x74;
          }
          else {
            iVar6 = 5;
            iVar2 = (int)(short)((short)unaff_r8 * 8 + 0x18);
            if (*(short *)(iVar3 + 0x1ee) == 1) {
              iVar3 = 0x130;
            }
            else {
              iVar3 = 0x12e;
            }
          }
        }
        else if (*(short *)(DAT_03013278 + 0xc) == 0) {
          iVar2 = (int)(short)((short)(unaff_r8 << 3) + 0x1c + in_stack_00000024._2_2_);
          iVar6 = (int)(short)(in_stack_00000034 + unaff_r5);
          iVar3 = uVar4 + 0x6e;
        }
        else if (unaff_r7 == 1) {
          iVar6 = 5;
          iVar3 = 0x12f;
          iVar2 = in_stack_0000005c;
        }
        else {
          iVar6 = 5;
          iVar3 = 0x12d;
          iVar2 = (int)(short)((short)(unaff_r8 << 3) + 0x18);
        }
        FUN_02ffd462(iVar3,iVar6,iVar2);
        sStack0000001e = sStack0000001a;
        _uStack00000018 = CONCAT22(sStack0000001a + 5,uStack00000018);
        sStack0000001e = sStack0000001e + 0x14;
        uVar5 = FUN_02ffc718(1);
        FUN_02ffbbc8(&stack0x00000018,&stack0x00000018,unaff_r4 + 0x70,0);
        FUN_02ffc718(uVar5);
        unaff_r7 = unaff_r7 + 1 & 0xffff;
        unaff_r4 = *(int *)(unaff_r4 + 4);
        if ((in_stack_00000058 <= (int)unaff_r7) || (in_stack_00000008 <= unaff_r7)) {
          MediaLib_GetTotalFiles(0x153);
          MediaLib_GetTotalFiles_b(0x21);
          iVar3 = MediaLib_GetTotalFiles_d(0x154);
          if ((iVar3 != 0) &&
             (iVar3 = MediaLib_GetTotalFiles_d(0x1dc), puVar1 = DAT_0301326c, iVar3 == 0)) {
            *DAT_0301326c = *DAT_03013268;
            puVar1[1] = 0xbdf7;
            FUN_02ffc330(*(undefined4 *)(DAT_03013278 + 0x10));
            MediaLib_GetTotalFiles(0x3e);
          }
          FUN_02ffc718(in_stack_00000048);
          puVar1 = DAT_0301326c;
          DAT_0301326c[1] = (short)in_stack_00000050;
          *puVar1 = (short)in_stack_00000054;
          FUN_02ffc6f4(in_stack_0000004c);
          return;
        }
        unaff_r10 = unaff_r7 - unaff_r6;
        unaff_r8 = unaff_r10 * 3;
        sStack0000001e = (short)unaff_r10 * 0x18;
        _uStack00000018 = CONCAT22(sStack0000001e + 0x17,(short)in_stack_00000060);
        sStack0000001c = (short)in_stack_00000060 + in_stack_00000020;
        sStack0000001e = sStack0000001e + 0x2f;
        if ((unaff_r10 == *(ushort *)(DAT_03013274 + 0x1ee)) &&
           (iVar3 = MediaLib_GetTotalFiles_d(0x1dc), iVar3 == 0)) break;
        *DAT_0301326c = *DAT_03013270;
      }
      if (*(short *)(DAT_03013274 + 0x1ee) == 0) break;
      uVar5 = in_stack_0000000c;
      if (*(short *)(DAT_03013274 + 0x1ee) != 5) {
        uVar5 = in_stack_00000010;
      }
      FUN_02ffd462(uVar5);
    }
    param_1 = in_stack_00000014 & 0xffff;
  } while( true );
}


