/**
 * FUN_03005b44 @ 0x03005b44
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03005b44(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  bool bVar6;
  
  iVar3 = DAT_03005e8c;
  bVar6 = SBORROW4(param_4,0xaa);
  iVar1 = param_4 - 0xaa;
  if ((int)param_4 < 0xaa) {
    bVar6 = SBORROW4(param_3,0x140);
    iVar1 = param_3 - 0x140;
  }
  if (iVar1 < 0 == bVar6) {
    return;
  }
  if ((int)param_4 < (int)param_2) {
    return;
  }
  do {
    FUN_02fef416(param_1 & 0xffff,param_2 & 0xffff,param_3 & 0xffff,param_4 & 0xffff);
    for (uVar5 = param_1; (int)uVar5 <= (int)param_3; uVar5 = uVar5 + 1) {
      cVar2 = *(char *)(iVar3 + 0x34f);
      if (cVar2 == '\0') {
        FUN_02fef364(0x632c);
      }
      else {
        if (cVar2 == '\x01') {
          uVar4 = 0x10a2;
        }
        else if (cVar2 == '\x02') {
          uVar4 = 0xfd55;
        }
        else if (cVar2 == '\x03') {
          uVar4 = 0x2b6f;
        }
        else {
          if (cVar2 != '\x04') goto LAB_03005bc2;
          uVar4 = 0xb2a0;
        }
        FUN_02fef364(uVar4);
      }
LAB_03005bc2:
    }
    param_2 = param_2 + 1;
    if ((int)param_4 < (int)param_2) {
      return;
    }
  } while( true );
}


