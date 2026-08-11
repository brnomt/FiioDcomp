/**
 * FUN_030853d0 @ 0x030853d0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint FUN_030853d0(int param_1,undefined4 *param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  while (*(char *)(param_1 + 0xf0) != '\x06') {
    uVar2 = FUN_03084c3c(param_1);
    if (uVar2 != 0) {
      return uVar2;
    }
  }
  cVar1 = *(char *)(param_1 + 0x1b0);
  if (cVar1 != '\0') {
    if (cVar1 == '\x01') {
      local_30 = 0;
      uVar3 = 0;
      local_2c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      local_1c = 0;
      uVar2 = FUN_0308502e(param_1,&local_30,&local_2c,&local_28);
      if (uVar2 != DAT_03085520) {
        if ((int)uVar2 < 0) {
          *(undefined1 *)(param_1 + 0xf0) = 7;
          return uVar2 & 0xff;
        }
        if (uVar2 == 3) {
          uVar3 = 1;
        }
      }
      uVar2 = FUN_03086254(*(undefined4 *)(param_1 + 0x1ac),local_30,local_2c,uVar3);
    }
    else {
      if (cVar1 != '\x02') {
        return 0;
      }
      uVar2 = FUN_03086942(*(undefined4 *)(param_1 + 0x1ac),param_2,param_1 + 0x1b0,0);
    }
    if ((int)uVar2 < 0) {
      *(undefined1 *)(param_1 + 0xf0) = 7;
      return 1;
    }
    bVar4 = uVar2 != 5;
    if (bVar4) {
      uVar2 = (uint)*(byte *)(param_1 + 0x1b0);
    }
    if (bVar4 && uVar2 != 0) {
      return 0;
    }
  }
  return 6;
}


