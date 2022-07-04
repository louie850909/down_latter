/*******************************************************************************
* タイトル:		チュートリアルプログラム
* プログラム名:	tutorial.cpp
* 作成者:			林劭羲
* 作成日:			2022/06/25
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "tutorial.h"

/*******************************************************************************
* グローバル変数
*******************************************************************************/
FullwidthUnit tu_player;
FullwidthUnit tu_enemy;
FullwidthUnit tu_spike;
FullwidthUnit tu_platform;
//FullwidthUnit tu_bounceplat; todo
FullwidthUnit tu_arrow;

Textline tu_title;
FullwidthUnit tu_divider;

Textline tu_player_explain;
Textline tu_enemy_explain;
Textline tu_spike_explain;
Textline tu_platform_explain;
//Textline tu_bounceplat_explain; todo
FullwidthUnit tu_divider2;

Textline tu_select_difficulty;

Textline tu_easy_explain;
Textline tu_normal_explain;
Textline tu_hard_explain;

Textline tu_difficulty_easy;
Textline tu_difficulty_normal;
Textline tu_difficulty_hard;

/*******************************************************************************
 関数名:		InitTutorial
 引数:		なし
 戻り値:		なし
 説明:		初期化
*******************************************************************************/
void InitTutorial()
{
	tu_title				= { 33,1,"チュートリアル", true };
	tu_divider				= { 0, 2, 40, 1, "―", true };
	
	tu_player				= { 12, 3, 1, 1, "¶", true };
	tu_enemy				= { 12, 4, 1, 1, "∝", true };
	tu_spike				= { 12, 5, 1, 1, "△", true };
	tu_platform				= { 12, 6, 1, 1, "■", true };
	//tu_bounceplat			= { 12, 7, 1, 1, "〒", true }; todo

	tu_player_explain		= { 14, 3, "：プレイヤーです、方向キーで左右を制御する、スペースで攻撃", true };
	tu_enemy_explain		= { 14, 4, "：敵です、触られたらHPが減る", true };
	tu_spike_explain		= { 14, 5, "：スパイクです、触られたらHPが減る", true };
	tu_platform_explain		= { 14, 6, "：プラットフォームです", true };
	//tu_bounceplat_explain	= { 14, 7, "：バウンドプラットフォームです、触られたら上に上がる", true }; todo
	tu_divider2				= { 0, 8, 40, 1, "―", true };

	tu_select_difficulty	= { 29, 11, "難易度を選択してください", true };

	tu_easy_explain			= { 7, 14, "プラットフォームの数が多い、敵がない、スパイクによるダメージが少ない", false };
	tu_normal_explain		= { 6, 14, "プラットフォームの数や敵の数が少ない、敵やスパイクによるダメージが多い", false };
	tu_hard_explain			= { 1, 14, "プラットフォームの数が激少なめ、敵の数が多い、敵やスパイクによるダメージが即死", false };

	tu_arrow				= { 34, 21, 1, 1, "→", true };
	tu_difficulty_easy		= { 36, 21, "イージー", true };
	tu_difficulty_normal	= { 36, 22, "ノーマル", true };
	tu_difficulty_hard		= { 36, 23, "ハード", true };
}

/*******************************************************************************
 関数名:		UpdateTutorial
 引数:		なし
 戻り値:		なし
 説明:		更新
*******************************************************************************/
void UpdateTutorial()
{	
	if (tu_arrow.pos_y == 21)
	{
		tu_easy_explain.use = true;
		tu_normal_explain.use = false;
		tu_hard_explain.use = false;
	}
	else if (tu_arrow.pos_y == 22)
	{
		tu_easy_explain.use = false;
		tu_normal_explain.use = true;
		tu_hard_explain.use = false;
	}
	else if (tu_arrow.pos_y == 23)
	{
		tu_easy_explain.use = false;
		tu_normal_explain.use = false;
		tu_hard_explain.use = true;
	}
	
	if (_kbhit() == 0)					// Key入力がない？
	{									// Key入力がないからここでリターンする
		return;
	}


	int key = _getch();					// キー入力処理
	if ((key == 0) || (key == 224))		// 特殊Keyならもう１度取得する
	{
		key = _getch();
	}

	// 押されたkeyの方向へ移動させる
	switch (key)
	{
	case 'w':
	case 0x48:	// ↑
		tu_arrow.pos_y = ((tu_arrow.pos_y - 1) % 3) + 21;
		break;

	case 's':
	case 0x50:	// ↓
		tu_arrow.pos_y = ((tu_arrow.pos_y + 1) % 3) + 21;
		break;

	default:
		break;
	}

	// 押されたkeyがEnterなら次のシーンへ
	if ((key == 13) && (tu_arrow.pos_y == 21))
	{
		SetState(GAME_MODE_EASY);
	}
	else if ((key == 13) && (tu_arrow.pos_y == 22))
	{
		SetState(GAME_MODE_NORMAL);
	}
	else if ((key == 13) && (tu_arrow.pos_y == 23))
	{
		SetState(GAME_MODE_HARD);
	}
}

/*******************************************************************************
 関数名:		DrawTutorail
 引数:		なし
 戻り値:		なし
 説明:		描画
*******************************************************************************/
void DrawTutorial()
{
	SetTextline(GetWindow(), tu_title);
	SetFullwidthUnit(GetWindow(), tu_divider);

	SetFullwidthUnit(GetWindow(), tu_player);
	SetFullwidthUnit(GetWindow(), tu_enemy);
	SetFullwidthUnit(GetWindow(), tu_spike);
	SetFullwidthUnit(GetWindow(), tu_platform);
	//SetFullwidthUnit(GetWindow(), tu_bounceplat); todo

	SetTextline(GetWindow(), tu_player_explain);
	SetTextline(GetWindow(), tu_enemy_explain);
	SetTextline(GetWindow(), tu_spike_explain);
	SetTextline(GetWindow(), tu_platform_explain);
	//SetTextline(GetWindow(), tu_bounceplat_explain); todo
	SetFullwidthUnit(GetWindow(), tu_divider2);

	SetTextline(GetWindow(), tu_select_difficulty);

	if (tu_easy_explain.use == true)
	{
		SetTextline(GetWindow(), tu_easy_explain);
	}
	else if (tu_normal_explain.use == true)
	{
		SetTextline(GetWindow(), tu_normal_explain);
	}
	else if (tu_hard_explain.use == true)
	{
		SetTextline(GetWindow(), tu_hard_explain);
	}

	SetFullwidthUnit(GetWindow(), tu_arrow);
	SetTextline(GetWindow(), tu_difficulty_easy);
	SetTextline(GetWindow(), tu_difficulty_normal);
	SetTextline(GetWindow(), tu_difficulty_hard);

	DrawWindow(GetWindow());
}

/*******************************************************************************
 関数名:		UninitTutorial
 引数:		なし
 戻り値:		なし
 説明:		終了処理
*******************************************************************************/
void UninitTutorial()
{
	ClearWindow(GetWindow());
}
