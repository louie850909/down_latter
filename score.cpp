/*******************************************************************************
* タイトル:		スコアプログラム
* プログラム名:	score.cpp
* 作成者:			林劭羲
* 作成日:			2022/07/05
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "score.h"

/*******************************************************************************
* グローバル変数
*******************************************************************************/
SCORE g_Score;

/*******************************************************************************
 関数名:		InitScore
 引数:		なし
 戻り値:		なし
 説明:		スコアの初期化
*******************************************************************************/
void InitScore()
{
	g_Score.value = 0;
	g_Score.singleDigit		= { 74, 11, 1, 1, "０", false };
	g_Score.tenDigit		= { 72, 11, 1, 1, "０", false };
	g_Score.hundredDigit	= { 70, 11, 1, 1, "０", false };
	g_Score.kiloDigit		= { 68, 11, 1, 1, "０", false };
	g_Score.tenK_Digit		= { 66, 11, 1, 1, "０", false };
	g_Score.hundredK_Digit	= { 64, 11, 1, 1, "０", false };
}

/*******************************************************************************
 関数名:		UpdateScore
 引数:		なし
 戻り値:		なし
 説明:		スコアの更新
*******************************************************************************/
void UpdateScore()
{
	if (g_Score.value <= 999999)
	{
		int num = g_Score.value;
		g_Score.singleDigit.FullWidth		= Convert(num % 10);
		g_Score.singleDigit.use = true;
		num /= 10;
		g_Score.tenDigit.FullWidth			= Convert(num % 10);
		g_Score.tenDigit.use = true;
		num /= 10;
		g_Score.hundredDigit.FullWidth		= Convert(num % 10);
		g_Score.hundredDigit.use = true;
		num /= 10;
		g_Score.kiloDigit.FullWidth			= Convert(num % 10);
		g_Score.kiloDigit.use = true;
		num /= 10;
		g_Score.tenK_Digit.FullWidth		= Convert(num % 10);
		g_Score.tenK_Digit.use = true;
		num /= 10;
		g_Score.hundredK_Digit.FullWidth	= Convert(num % 10);
		g_Score.hundredK_Digit.use = true;

		g_Score.value += 1;
	}
}

/*******************************************************************************
 関数名:		DrawSpike
 引数:		なし
 戻り値:		なし
 説明:		スコアの描画
*******************************************************************************/
void DrawScore()
{
	if (g_Score.singleDigit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.singleDigit);
	}
	if (g_Score.tenDigit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.tenDigit);
	}
	if (g_Score.hundredDigit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.hundredDigit);
	}
	if (g_Score.kiloDigit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.kiloDigit);
	}
	if (g_Score.tenK_Digit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.tenK_Digit);
	}
	if (g_Score.hundredK_Digit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.hundredK_Digit);
	}
}

/*******************************************************************************
 関数名:		UninitSpike
 引数:		なし
 戻り値:		なし
 説明:		スコアの終了処理
*******************************************************************************/
void UninitScore()
{
	
}

/*******************************************************************************
 関数名:		AddScore
 引数:		足したい数字
 戻り値:		なし
 説明:		スコアを足す
*******************************************************************************/
void AddScore(int value)
{
	g_Score.value += value;
}

/*******************************************************************************
 関数名:		GetSpike
 引数:		なし
 戻り値:		スコアのアドレス
 説明:		スコアのアドレスを返す
*******************************************************************************/
SCORE* GetScore()
{
	return &g_Score;
}

/*******************************************************************************
 関数名:		Convert
 引数:		文字化したい数字
 戻り値:		文字列
 説明:		数字を文字列に変換する
*******************************************************************************/
const char* Convert(int value)
{
	switch (value)
	{
		case 0:
			return "０";
			break;
			
		case 1:
			return "１";
			break;
			
		case 2:
			return "２";
			break;

		case 3:
			return "３";
			break;
			
		case 4:
			return "４";
			break;
			
		case 5:
			return "５";
			break;
			
		case 6:
			return "６";
			break;
			
		case 7:
			return "７";
			break;
			
		case 8:
			return "８";
			break;
			
		case 9:
			return "９";
			break;
	default:
		break;
	}
}
