/*******************************************************************************
* タイトル:		ゲームイージーモードプログラム
* プログラム名:	gameMode_easy.cpp
* 作成者:			林劭羲
* 作成日:			2022/06/27
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "gameMode_easy.h"
#include "background.h"
#include "platform.h"
#include "player.h"
#include "spike.h"
#include "enemy.h"
#include "bullet.h"
#include "score.h"
#include "hp.h"

/*Game Overの時使用するための文字列*/
Textline g_eblank;
Textline g_eGameOver;
Textline g_eblank2;
Textline g_eContinue;
Textline g_eblank3;

/*******************************************************************************
 関数名:		InitGameModeEasy
 引数:		なし
 戻り値:		なし
 説明:		初期化
*******************************************************************************/
void InitGameModeEasy()
{
	InitBackground();
	InitScore();
	InitPlatform();
	InitSpike();
	InitEnemy();
	InitBullet();
	InitPlayer();
	InitHp();
	
	g_eblank		= { 2,11,"--------------------------------------------------------",false };
	g_eGameOver		= { 2,12,"|                        Game Over                     |",false };
	g_eblank2		= { 2,13,"|                                                      |",false };
	g_eContinue		= { 2,14,"|                Press ENTER to continue               |",false };
	g_eblank3		= { 2,15,"--------------------------------------------------------",false };
}

/*******************************************************************************
 関数名:		UpdateGameModeEasy
 引数:		なし
 戻り値:		なし
 説明:		更新
*******************************************************************************/
void UpdateGameModeEasy()
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
		g_eblank.use = true;
		g_eblank2.use = true;
		g_eblank3.use = true;
		g_eGameOver.use = true;
		g_eContinue.use = true;
		
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
 関数名:		DrawGameModeEasy
 引数:		なし
 戻り値:		なし
 説明:		描画
*******************************************************************************/
void DrawGameModeEasy()
{
	DrawBackground();
	DrawScore();
	DrawPlatform();
	DrawSpike();
	DrawEnemy();
	DrawBullet();
	DrawPlayer();
	DrawHp();

	if (g_eGameOver.use == true)
	{
		SetTextline(GetWindow(), g_eGameOver);
	}

	if (g_eContinue.use == true)
	{
		SetTextline(GetWindow(), g_eContinue);
	}
	
	if (g_eblank.use == true)
	{
		SetTextline(GetWindow(), g_eblank);
	}
	
	if (g_eblank2.use == true)
	{
		SetTextline(GetWindow(), g_eblank2);
	}

	if (g_eblank3.use == true)
	{
		SetTextline(GetWindow(), g_eblank3);
	}
	
	DrawWindow(GetWindow());
}

/*******************************************************************************
 関数名:		UninitGameModeEasy
 引数:		なし
 戻り値:		なし
 説明:		終了処理
*******************************************************************************/
void UninitGameModeEasy()
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
