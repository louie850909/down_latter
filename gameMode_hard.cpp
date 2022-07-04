/*******************************************************************************
* タイトル:		ゲームハードモードプログラム
* プログラム名:	gameMode_hard.cpp
* 作成者:			林劭羲
* 作成日:			2022/06/27
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "gameMode_hard.h"
#include "background.h"
#include "platform.h"
#include "player.h"
#include "spike.h"
#include "enemy.h"
#include "bullet.h"
#include "score.h"
#include "hp.h"

Textline g_hblank;
Textline g_hGameOver;
Textline g_hblank2;
Textline g_hContinue;
Textline g_hblank3;

/*******************************************************************************
 関数名:		InitGameModeHard
 引数:		なし
 戻り値:		なし
 説明:		初期化
*******************************************************************************/
void InitGameModeHard()
{
	InitBackground();
	InitScore();
	InitPlatform();
	InitSpike();
	InitEnemy();
	InitBullet();
	InitPlayer();
	InitHp();

	g_hblank = { 2,11,"--------------------------------------------------------",false };
	g_hGameOver = { 2,12,"|                        Game Over                     |",false };
	g_hblank2 = { 2,13,"|                                                      |",false };
	g_hContinue = { 2,14,"|                Press ENTER to continue               |",false };
	g_hblank3 = { 2,15,"--------------------------------------------------------",false };
}

/*******************************************************************************
 関数名:		UpdateGameModeHard
 引数:		なし
 戻り値:		なし
 説明:		更新
*******************************************************************************/
void UpdateGameModeHard()
{
	PLAYER* p = GetPlayer();
	if (p[0].unit.use == true)
	{
		UpdateBackground();
		UpdateScore();
		UpdatePlatform();
		UpdateSpike();
		UpdateEnemy();
		UpdatePlayer();
		UpdateBullet();
		UpdateHp();
	}
	else									// プレイヤーが消えるときGAMEOVER文字を出します
	{
		g_hblank.use = true;
		g_hblank2.use = true;
		g_hblank3.use = true;
		g_hGameOver.use = true;
		g_hContinue.use = true;

		if (_kbhit() == 0)					// Key入力がない？
		{									// Key入力がないからここでリターンする
			return;
		}

		int key = _getch();					// キー入力処理
		if ((key == 0) || (key == 224))		// 特殊Keyならもう１度取得する
		{
			key = _getch();
		}

		// 押されたkeyがEnterなら次のシーンへ
		if (key == 13)
		{
			SetState(GAME_RESULT);
		}
	}
}

/*******************************************************************************
 関数名:		DrawGameModeHard
 引数:		なし
 戻り値:		なし
 説明:		描画
*******************************************************************************/
void DrawGameModeHard()
{
	DrawBackground();
	DrawScore();
	DrawPlatform();
	DrawSpike();
	DrawEnemy();
	DrawBullet();
	DrawPlayer();
	DrawHp();

	if (g_hGameOver.use == true)
	{
		SetTextline(GetWindow(), g_hGameOver);
	}

	if (g_hContinue.use == true)
	{
		SetTextline(GetWindow(), g_hContinue);
	}

	if (g_hblank.use == true)
	{
		SetTextline(GetWindow(), g_hblank);
	}

	if (g_hblank2.use == true)
	{
		SetTextline(GetWindow(), g_hblank2);
	}

	if (g_hblank3.use == true)
	{
		SetTextline(GetWindow(), g_hblank3);
	}

	DrawWindow(GetWindow());
}

/*******************************************************************************
 関数名:		UninitGameModeHard
 引数:		なし
 戻り値:		なし
 説明:		終了処理
*******************************************************************************/
void UninitGameModeHard()
{
	UninitBackground();
	UninitScore();
	UninitPlatform();
	UninitSpike();
	UninitEnemy();
	UninitBullet();
	UninitPlayer();
	UninitHp();
}
