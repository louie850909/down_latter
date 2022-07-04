/*******************************************************************************
* タイトル:		スパイクプログラム
* プログラム名:	spike.h
* 作成者:			林劭羲
* 作成日:			2022/07/02
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#pragma once
#include "draw.h"
#include "main.h"

/*******************************************************************************
* マクロ定義
*******************************************************************************/
#define SPIKE_MAX (3)

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
void InitSpike();
void UpdateSpike();
void DrawSpike();
void UninitSpike();

FullwidthUnit* GetSpike();
