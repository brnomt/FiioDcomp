/**
 * FUN_0308847c @ 0x0308847c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0308847c(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uStack_20;
  uint uStack_1c;
  
  if (param_1 == 0) {
    return 3;
  }
  if (param_3 != 0) {
    if (*(char *)(param_1 + 0x94) != '\0') {
      *(undefined4 *)(param_1 + 100) = 0;
      *(undefined4 *)(param_1 + 0x68) = 0;
      *(undefined2 *)(param_1 + 0x74) = 0;
      *(undefined2 *)(param_1 + 0x98) = 0;
      *(short *)(param_1 + 0x96) = (short)param_3;
      *(undefined1 *)(param_1 + 0x95) = 1;
      if (0xf < param_3) {
        puVar2 = (uint *)((7 - (param_3 & 7)) + param_2);
        uStack_20 = (*puVar2 & 0xffffff | (uint)*(byte *)((int)puVar2 + 3) << 0x18) ^
                    *(uint *)(param_1 + 0x9c);
        uStack_1c = (puVar2[1] & 0xffffff | (uint)*(byte *)((int)puVar2 + 7) << 0x18) ^
                    *(uint *)(param_1 + 0xa0);
        FUN_030840d6(param_1 + 0x78,&uStack_20,param_1 + 0x1b0,0);
        *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) ^ *(uint *)(param_1 + 0xa4);
        *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) ^ *(uint *)(param_1 + 0xa8);
        iVar4 = 0;
        iVar3 = param_1 + 0xac;
        sVar5 = 0;
        do {
          *(char *)(iVar3 + iVar4) = (char)iVar4;
          sVar5 = sVar5 + 2;
          *(char *)(iVar3 + iVar4 + 1) = (char)(iVar4 + 1);
          iVar4 = iVar4 + 2;
        } while (sVar5 < 0x100);
        uVar6 = 0;
        *(undefined1 *)(param_1 + 0x1ac) = 0;
        *(undefined1 *)(param_1 + 0x1ad) = 0;
        uVar7 = 0;
        iVar4 = 0;
        iVar8 = 0x100;
        do {
          bVar1 = *(byte *)(iVar3 + iVar4);
          uVar6 = uVar6 + bVar1 + (uint)*(byte *)(param_1 + 0x78 + uVar7) & 0xff;
          *(undefined1 *)(iVar3 + iVar4) = *(undefined1 *)(iVar3 + uVar6);
          *(byte *)(iVar3 + uVar6) = bVar1;
          uVar7 = (uVar7 + 1) % 8;
          iVar4 = iVar4 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      return 0;
    }
    return 3;
  }
  return 1;
}


