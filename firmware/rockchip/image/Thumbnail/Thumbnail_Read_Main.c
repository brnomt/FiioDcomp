/* ************************************************ */
/*	Thumbnail_Read.c								*/
/*	2015/5/11										*/
/*	by Yuki.KIshimoto								*/
/* ************************************************ */
/* ============================================================================================== */
/* 	ヘッダファイルのインクルード                                                   								                */
/* ============================================================================================== */
#include "..\ImageInclude\image_main.h"

#ifdef THUMB_DEC_INCLUDE

#pragma arm section code = "ImageContrlCode", rodata = "ImageContrlCode", rwdata = "ImageContrlData", zidata = "ImageContrlBss"

#include <stdio.h>
#include "Thumbnail_Read_IF.h"
#include "Thumbnail_Read_Task.h"

/* ============================================================================================== */
/* 	内部構造体定義：このモジュール内だけで使用する構造体の定義          					      */
/* ============================================================================================== */
/* 	[定義なし] */

/* ============================================================================================== */
/* 	内部マクロ定義：このモジュールだけで使用するマクロ定義                					      */
/* ============================================================================================== */


/* ============================================================================================== */
/* 	外部関数											                    					  */
/* ============================================================================================== */
void Thumbnail_Read_Main(void)											/* Exif 取得 メイン処理 */
{
	Thumbnail_Read_Task();
}

/* ---------------------------------------------------------------------------------------------- */
/* 	外部I/F関数                                                        							  */
/* ---------------------------------------------------------------------------------------------- */

void Thumbnail_IF_SetFileName(char *buf)
{
	Thumbnail_Task_SetFileName(&buf);
}

void Thumbnail_IF_SetFilePointer(FILE *fp)
{
	Thumbnail_Task_SetFilePointer(fp);
}

PIC_DATA *Thumbnail_IF_GetPictureData(void)
{
	PIC_DATA *ret_picdata;
	ret_picdata = Thumbnail_Task_GetPictureData();
	return ret_picdata;
}

long Thumbnail_IF_GetThumbnailOffset(void){
	long res = 0;

	res = Thumbnail_Task_GetThumbnailOffset();
	return res;
}
long Thumbnail_IF_GetThumbnailSize(void){
	long res = 0;

	res = Thumbnail_Task_GetThumbnailSize();

	return res;

}

int Thumbnail_IF_GetPictureType(void){
	int res = 0;

	res = Thumbnail_Task_GetPictureType();
	return res;
}

#endif


