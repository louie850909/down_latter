/*******************************************************************************
* タイトル:		描画プログラム
* プログラム名:	draw.h
* 作成者:			林劭羲
* 作成日:			2022/06/17
*******************************************************************************/
#pragma once

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <stdio.h>
#include <string.h>

/*******************************************************************************
* マクロ定義
*******************************************************************************/
#define WINDOW_WIDTH (80)
#define WINDOW_HEIGHT (25)
/*******************************************************************************
* 構造体定義
*******************************************************************************/
struct HalfwidthUnit
{
	int pos_x;
	int pos_y;
	int width;
	int height;
	char Halfwidth;
	bool use;
};

struct FullwidthUnit
{
	int pos_x;
	int pos_y;
	int width;
	int height;
	const char* FullWidth;
	bool use;
};

struct Textline
{
	int pos_x;
	int pos_y;
	const char* text;
	bool use;
};

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
void DrawWindow(char* window);
void SetHalfwidthUnit(char* window, HalfwidthUnit gameobj);
void SetFullwidthUnit(char* window, FullwidthUnit gameobj);
void SetTextline(char* window, Textline gametext);
void ClearWindow(char* window);


