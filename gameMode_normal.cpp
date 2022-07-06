/*******************************************************************************
* タイトル:		ゲームノーマルモードプログラム
* プログラム名:	gameMode_normal.cpp
* 作成者:			林劭羲
* 作成日:			2022/07/04
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "gameMode_normal.h"
#include "background.h"
#include "platform.h"
#include "player.h"
#include "spike.h"
#include "enemy.h"
#include "bullet.h"
#include "score.h"
#include "hp.h"

/*Game Overの時使用するための文字列*/
Textline g_nblank;
Textline g_nGameOver;
Textline g_nblank2;
Textline g_nContinue;
Textline g_nblank3;

/*******************************************************************************
 関数名:		InitGameModeNormal
 引数:		なし
 戻り値:		なし
 説明:		初期化
*******************************************************************************/
void InitGameModeNormal()
{
	InitBackground();
	InitScore();
	InitPlatform();
	InitSpike();
	InitEnemy();
	InitBullet();
	InitPlayer();
	InitHp();

	g_nblank	= { 2,11,"--------------------------------------------------------",false };
	g_nGameOver = { 2,12,"|                        Game Over                     |",false };
	g_nblank2	= { 2,13,"|                                                      |",false };
	g_nContinue = { 2,14,"|                Press ENTER to continue               |",false };
	g_nblank3	= { 2,15,"--------------------------------------------------------",false };
}

/*******************************************************************************
 関数名:		UpdateGameModeNormal
 引数:		なし
 戻り値:		なし
 説明:		更新
*******************************************************************************/
void UpdateGameModeNormal()
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
		g_nblank.use = true;
		g_nblank2.use = true;
		g_nblank3.use = true;
		g_nGameOver.use = true;
		g_nContinue.use = true;

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
 関数名:		DrawGameModeNormal
 引数:		なし
 戻り値:		なし
 説明:		描画
*******************************************************************************/
void DrawGameModeNormal()
{
	DrawBackground();
	DrawScore();
	DrawPlatform();
	DrawSpike();
	DrawEnemy();
	DrawBullet();
	DrawPlayer();
	DrawHp();

	if (g_nGameOver.use == true)
	{
		SetTextline(GetWindow(), g_nGameOver);
	}

	if (g_nContinue.use == true)
	{
		SetTextline(GetWindow(), g_nContinue);
	}

	if (g_nblank.use == true)
	{
		SetTextline(GetWindow(), g_nblank);
	}

	if (g_nblank2.use == true)
	{
		SetTextline(GetWindow(), g_nblank2);
	}

	if (g_nblank3.use == true)
	{
		SetTextline(GetWindow(), g_nblank3);
	}

	DrawWindow(GetWindow());
}

/*******************************************************************************
 関数名:		UninitGameModeNormal
 引数:		なし
 戻り値:		なし
 説明:		終了処理
*******************************************************************************/
void UninitGameModeNormal()
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
