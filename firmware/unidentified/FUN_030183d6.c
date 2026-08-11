/**
 * FUN_030183d6 @ 0x030183d6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030183d6(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  longlong lVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 unaff_r4;
  uint uVar9;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined2 local_40 [8];
  undefined4 local_30;
  undefined4 local_2c;
  
  puVar4 = DAT_030184a8;
  local_4c = *(undefined4 *)(DAT_030184ac + 0x54);
  local_48 = *(undefined4 *)(DAT_030184ac + 0x58);
  uStack_44 = *(undefined4 *)(DAT_030184ac + 0x5c);
  uVar1 = *DAT_030184a8;
  uVar2 = DAT_030184a8[1];
  local_30 = FUN_02ffef2c(1);
  local_2c = FUN_02ffef08(2);
  *puVar4 = 0;
  puVar4[1] = 0;
  iVar6 = ui_refresh_and_redraw(0x26);
  if ((iVar6 != 0) || (iVar6 = func_0x030037c4(0xdd), iVar6 != 0)) {
    FUN_02fffc76(0x112,0);
    *puVar4 = 0xffff;
    func_0x030037a8(0xde);
  }
  iVar7 = func_0x030037c4(0xde);
  iVar5 = DAT_030184b4;
  iVar6 = DAT_030184b0;
  if (iVar7 == 1) {
    FUN_02fff4de(0x114,local_40);
    FUN_02fffc76(0x112,0);
    uVar8 = (uint)*(byte *)(iVar5 + 1);
    lVar3 = (longlong)iVar6 * (longlong)(int)(uVar8 - 1);
    iVar7 = (uVar8 - 1) * 0x156;
    if (uVar8 != 0) {
      FUN_02fffc76(0x113,(int)(short)(((short)(uVar8 - 1) +
                                      ((short)((ulonglong)lVar3 >> 0x20) - (short)(lVar3 >> 0x3f)) *
                                      -3) * 0x3a + 0x52),
                   (int)(short)(((short)(iVar7 >> 10) - (short)(iVar7 >> 0x1f)) * 0x4a + 0x13));
    }
    uVar8 = (uint)*(byte *)(iVar5 + 1);
    lVar3 = (longlong)iVar6 * (longlong)(int)(uVar8 - 1);
    iVar7 = (uVar8 - 1) * 0x156;
    if (uVar8 != 0) {
      FUN_02fffc76(0x41,(int)(short)(((short)(uVar8 - 1) +
                                     ((short)((ulonglong)lVar3 >> 0x20) - (short)(lVar3 >> 0x3f)) *
                                     -3) * 0x3a + 0x5e),
                   (int)(short)(((short)(iVar7 >> 10) - (short)(iVar7 >> 0x1f)) * 0x4a + 10));
    }
    uVar8 = 0;
    do {
      if (uVar8 + 1 == (uint)*(byte *)(iVar5 + 1)) {
        unaff_r4 = 0x120;
      }
      else {
        unaff_r4 = 0x114;
      }
      FUN_03018320(unaff_r4,*(undefined2 *)(DAT_0301895c + uVar8 * 2),local_40[0],
                   *(byte *)((int)&local_4c + uVar8 * 2) + 5,
                   *(byte *)((int)&local_4c + uVar8 * 2 + 1) + 5);
      uVar8 = uVar8 + 1 & 0xffff;
    } while (uVar8 < 6);
  }
  iVar7 = func_0x030037c4(0x1b3);
  if (iVar7 == 1) {
    uVar8 = *(byte *)(iVar5 + 1) - 1;
    uVar9 = uVar8 & 0xffff;
    if (*(byte *)(iVar5 + 1) != 0) {
      FUN_02fffc76(0x113,(int)(short)((((short)((ulonglong)((longlong)iVar6 * (longlong)(int)uVar8)
                                               >> 0x20) -
                                       (short)((longlong)iVar6 * (longlong)(int)uVar8 >> 0x3f)) * -3
                                      + (short)uVar8) * 0x3a + 0x52),
                   (int)(short)(((short)((int)(uVar8 * 0x156) >> 10) -
                                (short)((int)(uVar8 * 0x156) >> 0x1f)) * 0x4a + 0x13));
    }
    FUN_03018320(unaff_r4,*(undefined2 *)(DAT_0301895c + uVar9 * 2),local_40[0],
                 *(byte *)((int)&local_4c + uVar9 * 2) + 5,
                 *(byte *)((int)&local_4c + uVar9 * 2 + 1) + 5);
  }
  FUN_02ffef2c(local_30);
  puVar4[1] = uVar2;
  *puVar4 = uVar1;
  FUN_02ffef08(local_2c);
  return;
}


