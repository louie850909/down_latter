/*******************************************************************************
* タイトル:		HPプログラム
* プログラム名:	hp.cpp
* 作成者:			林劭羲
* 作成日:			2022/07/03
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "hp.h"
#include "player.h"

/*******************************************************************************
* グローバル変数
*******************************************************************************/
FullwidthUnit g_HP;
FullwidthUnit g_HP_blank;

/*******************************************************************************
 関数名:		InitHp
 引数:		なし
 戻り値:		なし
 説明:		Hpの初期化
*******************************************************************************/
void InitHp()
{
	g_HP		= { 60, 5, 10, 1, "■", true };	// HPバー満たす部分
	g_HP_blank	= { 80, 5, 1, 1, "□", false };	// HPバー空く部分
}

/*******************************************************************************
 関数名:		UpdateHp
 引数:		なし
 戻り値:		なし
 説明:		Hpの更新
*******************************************************************************/
void UpdateHp()
{
	PLAYER* player = GetPlayer();
	
	if (player[0].hp < 100)				// ダメージ受けったあと実行する
	{
		g_HP_blank.use = true;
		
		int num = player[0].hp / 10;
		if (num < 0)
		{
			num = 0;
		}

		g_HP.width = num;
		g_HP_blank.width = 10 - num;
		g_HP_blank.pos_x = g_HP.pos_x + g_HP.width * 2;
	}
}

/*******************************************************************************
 関数名:		DrawHp
 引数:		なし
 戻り値:		なし
 説明:		Hpの描画
*******************************************************************************/
void DrawHp()
{
	if (g_HP.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_HP);
	}
	if (g_HP_blank.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_HP_blank);
	}
}

/*******************************************************************************
 関数名:		UninitHp
 引数:		なし
 戻り値:		なし
 説明:		Hpの終了処理
*******************************************************************************/
void UninitHp()
{
	g_HP.use = false;
	g_HP_blank.use = false;
}
