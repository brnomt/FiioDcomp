/**
 * FUN_03085904 @ 0x03085904
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_03085904(uint *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  ushort uVar7;
  
  uVar5 = 0;
  uVar7 = 0;
  if (param_1 == (uint *)0x0) {
    return 2;
  }
  iVar2 = wma_input_cache_read
                    (param_1,param_1[1],*param_1 + param_1[0x45],
                     param_1[1] + (uint)CARRY4(*param_1,param_1[0x45]));
  if (iVar2 != 2) {
    return 3;
  }
  *(short *)(param_1 + 0x56) = (short)param_1[0x45];
  *(byte *)(param_1 + 0x57) = MasterStackPointer & 0x7f;
  *(byte *)((int)param_1 + 0x15d) = MasterStackPointer_1;
  cVar1 = *(char *)((int)param_1 + 0x12d);
  if (cVar1 == '\x01') {
    uVar3 = param_1[0x45] + 2;
    iVar2 = wma_input_cache_read
                      (param_1,param_1[1],*param_1 + uVar3,
                       (uint)(0xfffffffd < param_1[0x45]) + param_1[1] +
                       (uint)CARRY4(*param_1,uVar3));
    if (iVar2 != 1) {
      return 3;
    }
    uVar3 = (uint)MasterStackPointer;
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 == '\x03') {
        uVar3 = param_1[0x45] + 2;
        iVar2 = wma_input_cache_read
                          (param_1,param_1[1],*param_1 + uVar3,
                           (uint)(0xfffffffd < param_1[0x45]) + param_1[1] +
                           (uint)CARRY4(*param_1,uVar3));
        if (iVar2 != 4) {
          return 3;
        }
        param_1[0x58] =
             (uint)bRam00000002 * 0x10000 + (uint)MasterStackPointer_1 * 0x100 +
             (uint)MasterStackPointer + (uint)bRam00000003 * 0x1000000;
      }
      goto LAB_03085a08;
    }
    uVar3 = param_1[0x45] + 2;
    iVar2 = wma_input_cache_read
                      (param_1,param_1[1],*param_1 + uVar3,
                       param_1[1] +
                       (uint)(0xfffffffd < param_1[0x45]) + (uint)CARRY4(*param_1,uVar3));
    if (iVar2 != 2) {
      return 3;
    }
    uVar3 = (uint)_MasterStackPointer;
  }
  param_1[0x58] = uVar3;
LAB_03085a08:
  uVar3 = (uint)(byte)param_1[0x4b];
  uVar6 = uVar3 + 2;
  uVar4 = param_1[0x45] + uVar6;
  iVar2 = wma_input_cache_read
                    (param_1,param_1[1],*param_1 + uVar4,
                     (uint)CARRY4(param_1[0x45],uVar6) + param_1[1] + (uint)CARRY4(*param_1,uVar4));
  if (iVar2 != 1) {
    return 3;
  }
  *(byte *)(param_1 + 0x5b) = MasterStackPointer;
  param_1[0x5a] = 0xffffffff;
  if ((byte)param_1[0x5b] == 1) {
    uVar4 = param_1[0x58];
    param_1[0x58] = 0;
    param_1[0x59] = 0;
    param_1[0x5a] = uVar4;
    *(undefined1 *)((int)param_1 + 0x175) = 1;
    uVar4 = *param_1 + param_1[0x45];
    iVar2 = param_1[1] + (uint)CARRY4(*param_1,param_1[0x45]);
    iVar2 = wma_input_cache_read
                      (param_1,iVar2,uVar4 + uVar3 + 3,
                       (uint)(0xfffffffe < uVar6) + iVar2 + (uint)CARRY4(uVar4,uVar3 + 3));
    if (iVar2 != 1) {
      return 3;
    }
    param_1[0x5f] = (uint)MasterStackPointer;
    if (param_1[0x4a] != 0) {
      uVar4 = *param_1 + param_1[0x45];
      iVar2 = wma_input_cache_read
                        (param_1,uVar4,uVar4 + uVar3 + 4,
                         param_1[1] + (uint)CARRY4(*param_1,param_1[0x45]) +
                         (uint)(0xfffffffd < uVar6) + (uint)CARRY4(uVar4,uVar3 + 4));
      uVar7 = _MasterStackPointer;
      if (iVar2 != 2) {
        return 3;
      }
    }
  }
  else if (7 < (byte)param_1[0x5b]) {
    uVar4 = *param_1 + param_1[0x45];
    iVar2 = param_1[1] + (uint)CARRY4(*param_1,param_1[0x45]);
    iVar2 = wma_input_cache_read
                      (param_1,iVar2,uVar4 + uVar3 + 3,
                       (uint)(0xfffffffe < uVar6) + iVar2 + (uint)CARRY4(uVar4,uVar3 + 3));
    if (iVar2 != 8) {
      return 3;
    }
    param_1[0x59] =
         (uint)MasterStackPointer + (uint)bRam00000003 * 0x1000000 +
         (uint)bRam00000002 * 0x10000 + (uint)MasterStackPointer_1 * 0x100;
    param_1[0x5a] =
         (uint)bRam00000006 * 0x10000 + (uint)bRam00000005 * 0x100 +
         (uint)Reset + (uint)DAT_00000007 * 0x1000000;
    *(undefined1 *)((int)param_1 + 0x175) = 0;
  }
  uVar3 = (uint)(byte)param_1[0x4b] + (uint)(byte)param_1[0x5b] + 3;
  *(short *)((int)param_1 + 0x15a) = (short)uVar3;
  if (param_1[0x4a] == 0) {
    uVar4 = param_1[0x4d];
    if (uVar4 == 0) {
      uVar4 = param_1[5];
    }
    uVar5 = (((short)uVar4 - (short)param_1[0x45]) - (short)uVar3) - (short)param_1[0x51];
  }
  else {
    cVar1 = *(char *)((int)param_1 + 0x14e);
    if (cVar1 == '\x01') {
      uVar4 = param_1[0x45] + uVar3;
      iVar2 = wma_input_cache_read
                        (param_1,uVar4,uVar4 + *param_1,
                         (uint)CARRY4(param_1[0x45],uVar3) + param_1[1] +
                         (uint)CARRY4(uVar4,*param_1));
      if (iVar2 != 1) {
        return 3;
      }
      uVar5 = _MasterStackPointer & 0xff;
    }
    else if (cVar1 == '\x02') {
      uVar4 = param_1[0x45] + uVar3;
      iVar2 = wma_input_cache_read
                        (param_1,uVar4,uVar4 + *param_1,
                         (uint)CARRY4(param_1[0x45],uVar3) + param_1[1] +
                         (uint)CARRY4(uVar4,*param_1));
      uVar5 = _MasterStackPointer;
      if (iVar2 != 2) {
        return 3;
      }
    }
    else if (cVar1 == '\x03') {
      uVar4 = param_1[0x45] + uVar3;
      uVar3 = (uint)CARRY4(param_1[0x45],uVar3);
      iVar2 = wma_input_cache_read
                        (param_1,uVar3,uVar4 + *param_1,
                         uVar3 + param_1[1] + (uint)CARRY4(uVar4,*param_1));
      if (iVar2 != 4) {
        return 3;
      }
      uVar5 = (_MasterStackPointer & 0xff) + (_MasterStackPointer & 0xff00);
    }
  }
  if (uVar7 == 0) {
    uVar7 = uVar5;
  }
  *(ushort *)((int)param_1 + 0x16e) = uVar5;
  *(ushort *)((int)param_1 + 0x15a) =
       *(byte *)((int)param_1 + 0x14f) + uVar5 + *(short *)((int)param_1 + 0x15a);
  *(ushort *)((int)param_1 + 0x172) = uVar7;
  uVar3 = param_1[0x45] + (uint)*(ushort *)((int)param_1 + 0x15a);
  param_1[0x45] = uVar3;
  if ((uVar3 <= param_1[5]) && ((uVar3 != param_1[5] || (param_1[0x55] - 1 <= param_1[0x61])))) {
    return 0;
  }
  return 6;
}


