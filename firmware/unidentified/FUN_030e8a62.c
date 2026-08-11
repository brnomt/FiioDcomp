/**
 * FUN_030e8a62 @ 0x030e8a62
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e8a62(int param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_030e8af8;
  uVar2 = *DAT_030e8af8;
  *DAT_030e8af8 =
       uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18;
  uVar2 = puVar1[1];
  puVar1[1] = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
  uVar2 = puVar1[2];
  puVar1[2] = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
  uVar2 = puVar1[3];
  puVar1[3] = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
  *(ushort *)((int)puVar1 + 0x16) =
       *(ushort *)((int)puVar1 + 0x16) >> 8 | *(ushort *)((int)puVar1 + 0x16) << 8;
  uVar2 = puVar1[6];
  puVar1[6] = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
  uVar2 = puVar1[7];
  puVar1[7] = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
  uVar2 = puVar1[8];
  puVar1[8] = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
  hifi_debug_printf_sync_ovl_0e45(DAT_030e8afc,puVar1[6]);
  hifi_debug_printf_sync_ovl_0e45(DAT_030e8b00,puVar1[3]);
  hifi_debug_printf_sync_ovl_0e45(DAT_030e8b04,puVar1[7]);
  hifi_debug_printf_sync_ovl_0e45(DAT_030e8b08,puVar1[8]);
  hifi_debug_printf_sync_ovl_0e45(DAT_030e8b0c,*(undefined1 *)((int)puVar1 + 0x11));
  hifi_debug_printf_sync_ovl_0e45(DAT_030e8b10,*(undefined1 *)((int)puVar1 + 0x15));
  hifi_debug_printf_sync_ovl_0e45(DAT_030e8b14,*(undefined2 *)((int)puVar1 + 0x16));
  hifi_debug_printf_sync_ovl_0e45(DAT_030e8b18,*(undefined1 *)((int)puVar1 + 0x12));
  hifi_debug_printf_sync_ovl_0e45(DAT_030e8b8c,*(undefined1 *)((int)puVar1 + 0x13));
  hifi_debug_printf_sync_ovl_0e45(DAT_030e8b90,(char)puVar1[5]);
  uVar2 = puVar1[3];
  *(uint *)(param_1 + 0x34) = uVar2;
  *(undefined1 *)(param_1 + 0x38) = *(undefined1 *)((int)puVar1 + 0x11);
  *(undefined1 *)(param_1 + 0x39) = *(undefined1 *)((int)puVar1 + 0x12);
  *(undefined1 *)(param_1 + 0x3a) = *(undefined1 *)((int)puVar1 + 0x13);
  *(char *)(param_1 + 0x3b) = (char)puVar1[5];
  *(uint *)(param_1 + 0x10) = (uint)*(byte *)((int)puVar1 + 0x15);
  *(uint *)(param_1 + 0x14) = puVar1[7];
  *(uint *)(param_1 + 0x18) = puVar1[8];
  if (uVar2 == 0 || 0x1fffffff < uVar2) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


