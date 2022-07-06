/*******************************************************************************
* タイトル:		エネミープログラム
* プログラム名:	enemy.cpp
* 作成者:			林劭羲
* 作成日:			2022/07/03
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "enemy.h"
#include "player.h"
#include "collision.h"

/*******************************************************************************
* グローバル変数
*******************************************************************************/
FullwidthUnit g_Enemy[ENEMY_MAX];

/*******************************************************************************
 関数名:		InitEnemy
 引数:		なし
 戻り値:		なし
 説明:		敵の初期化
*******************************************************************************/
void InitEnemy()
{
	switch (GetState())							// ゲームモードによって敵の数が違う
	{
	case GAME_MODE_EASY:						// 簡単モード 敵の数：0
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			g_Enemy[i].use = false;
		}
		break;
		
	case GAME_MODE_NORMAL:						// 普通モード 敵の数：3
		for (int i = 0; i < ENEMY_MAX - 2; i++)
		{
			g_Enemy[i].pos_x		= (rand() % 55) + 2;
			g_Enemy[i].pos_y		= (rand() % 23) + 2;
			g_Enemy[i].height		= 1;
			g_Enemy[i].width		= 1;
			g_Enemy[i].FullWidth	= "∝";
			g_Enemy[i].use			= true;
		}

		for(int i= ENEMY_MAX - 2; i < ENEMY_MAX; i++)
		{
			g_Enemy[i].use = false;
		}
		break;
		
	case GAME_MODE_HARD:						// 困難モード 敵の数：5
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			g_Enemy[i].pos_x		= (rand() % 55) + 2;
			g_Enemy[i].pos_y		= (rand() % 23) + 2;
			g_Enemy[i].height		= 1;
			g_Enemy[i].width		= 1;
			g_Enemy[i].FullWidth	= "∝";
			g_Enemy[i].use			= true;
		}
		break;
		
	default:
		break;
	}
}

/*******************************************************************************
 関数名:		UpdateEnemy
 引数:		なし
 戻り値:		なし
 説明:		敵の更新
*******************************************************************************/
void UpdateEnemy()
{
	PLAYER* p = GetPlayer();
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (g_Enemy[i].use)
		{
			// プレイヤーが近くにいると追跡する
			if ((abs(g_Enemy[i].pos_x - p[0].unit.pos_x) < 30) && (abs(g_Enemy[i].pos_y - p[0].unit.pos_y) < 13))
			{
				int vec_x = p[0].unit.pos_x - g_Enemy[i].pos_x;
				int vec_y = p[0].unit.pos_y - g_Enemy[i].pos_y;
				int move_x = vec_x / 5;
				int move_y = vec_y / 5;

				if (rand() % 2)
				{
					g_Enemy[i].pos_x += move_x;
					g_Enemy[i].pos_y += move_y;
				}
			}
			// 普段はランダムで移動する
			else
			{
				g_Enemy[i].pos_x += rand() % 3 - 1;
				g_Enemy[i].pos_y += rand() % 3 - 1;

				if (g_Enemy[i].pos_x <= 1)
				{
					g_Enemy[i].pos_x = 2;
				}

				if (g_Enemy[i].pos_x >= 57)
				{
					g_Enemy[i].pos_x = 56;
				}

				if (g_Enemy[i].pos_y <= 1)
				{
					g_Enemy[i].pos_y = 2;
				}

				if (g_Enemy[i].pos_y >= 23)
				{
					g_Enemy[i].pos_y = 22;
				}
			}

			if(CheckCollision(g_Enemy[i].pos_x, g_Enemy[i].pos_y, g_Enemy[i].width, g_Enemy[i].height, p[0].unit.pos_x, p[0].unit.pos_y, p[0].unit.width, p[0].unit.height) == true)
			{
				switch (GetState())
				{
				case GAME_MODE_EASY:
					p[0].hp -= 10;
					break;
					
				case GAME_MODE_NORMAL:
					p[0].hp -= 20;
					break;
					
				case GAME_MODE_HARD:
					p[0].hp -= 100;
					break;

				default:
					break;
				}
			}
		}
	}
}

/*******************************************************************************
 関数名:		DrawEnemy
 引数:		なし
 戻り値:		なし
 説明:		敵の描画
*******************************************************************************/
void DrawEnemy()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (g_Enemy[i].use)
		{
			SetFullwidthUnit(GetWindow(), g_Enemy[i]);
		}
	}
}

/*******************************************************************************
 関数名:		UninitEnemy
 引数:		なし
 戻り値:		なし
 説明:		敵の終了処理
*******************************************************************************/
void UninitEnemy()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		g_Enemy[i].use = false;
	}
}

/*******************************************************************************
 関数名:		GetEnemy
 引数:		なし
 戻り値:		敵のアドレス
 説明:		敵のアドレスを返す
*******************************************************************************/
FullwidthUnit* GetEnemy()
{
	return &g_Enemy[0];
}
