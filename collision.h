/*******************************************************************************
* タイトル:		当たり判定プログラム
* プログラム名:	collision.h
* 作成者:			林劭羲
* 作成日:			2022/07/02
*******************************************************************************/
#pragma once

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <math.h>

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
bool CheckCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);