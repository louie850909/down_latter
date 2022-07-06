﻿/*******************************************************************************
* タイトル:		結果プログラム
* プログラム名:	result.h
* 作成者:			林劭羲
* 作成日:			2022/07/05
*******************************************************************************/
#pragma once

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"
#include "draw.h"

/*******************************************************************************
* 構造体定義
*******************************************************************************/
struct RANK
{
	char value;
	const char* line1;
	const char* line2;
	const char* line3;
	const char* line4;
	const char* line5;
};

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
void InitResult();
void UpdateResult();
void DrawResult();
void UninitResult();