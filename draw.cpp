/*******************************************************************************
* タイトル:		描画プログラム
* プログラム名:	draw.cpp
* 作成者:			林劭羲
* 作成日:			2022/06/17
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "draw.h"

/*******************************************************************************
 関数名:		DrawWindow
 引数:		char *window
 戻り値:		なし
 説明:		window中の内容を画面に表示する
*******************************************************************************/
void DrawWindow(char *window)
{
	printf("%s\r", window);
}

/*******************************************************************************
 関数名:		SetHalfwidthUnit
 引数:		char *window, HalfwidthUnit obj
 戻り値:		なし
 説明:		半角objをwindowの中に導入する
*******************************************************************************/
void SetHalfwidthUnit(char *window, HalfwidthUnit obj)
{
	for (int y = 0; y < obj.height; y++)
	{
		for (int x = 0; x < obj.width; x++)
		{
			window[(obj.pos_y + y) * WINDOW_WIDTH + obj.pos_x + x] = obj.Halfwidth;
		}
	}
	
}

/*******************************************************************************
 関数名:		SetFullwidthUnit
 引数:		char *window, FullwidthUnit obj
 戻り値:		なし
 説明:		全角objをwindowの中に導入する
*******************************************************************************/
void SetFullwidthUnit(char *window, FullwidthUnit obj)
{
	for (int y = 0; y < obj.height; y++)
	{
		for(int x = 0; x < obj.width * 2; x++)
		{
			window[(obj.pos_y + y) * WINDOW_WIDTH + obj.pos_x + x] = obj.FullWidth[x % 2];
		}
		
	}
}

/*******************************************************************************
 関数名:		SetTextline
 引数:		char *window, Textline gametext
 戻り値:		なし
 説明:		文字列をwindowの中に導入する
*******************************************************************************/
void SetTextline (char* window, Textline gametext)
{
	int len = strlen(gametext.text);
	for (int i = 0; i < len; i++)
	{
		window[gametext.pos_y * WINDOW_WIDTH + gametext.pos_x + i] = gametext.text[i];
	}
}

/*******************************************************************************
 関数名:		ClearWindow
 引数:		char *window
 戻り値:		なし
 説明:		windowの中の内容を消す
*******************************************************************************/
void ClearWindow(char* window)
{
	for (int y = 0; y < WINDOW_HEIGHT; y++)
	{
		for (int x = 0; x < WINDOW_WIDTH; x++)
		{
			window[y * WINDOW_WIDTH + x] = ' ';
		}
	}
}
