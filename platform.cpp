/*******************************************************************************
* タイトル:		プラットフォームプログラム
* プログラム名:	platform.cpp
* 作成者:			林劭羲
* 作成日:			2022/06/27
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "platform.h"
#include "player.h"

/*******************************************************************************
* グローバル変数
*******************************************************************************/
FullwidthUnit g_platform[PLATFORM_MAX];

/*******************************************************************************
 関数名:		InitPlatform
 引数:		なし
 戻り値:		なし
 説明:		プラットフォーム初期化
*******************************************************************************/
void InitPlatform()
{
	switch (GetState())					//難易度によって使用されたプラットフォーム数が違う
	{
	case GAME_MODE_EASY:				//全部を使用する
		for (int i = 0; i < PLATFORM_MAX; i++)
		{
			g_platform[i].pos_x		= (rand() % 49) + 2;
			g_platform[i].pos_y		= i * 4 + 2;
			g_platform[i].height	= 1;
			g_platform[i].width		= 4;
			g_platform[i].FullWidth	= "■";
			g_platform[i].use		= true;
		}
		break;
		
	case GAME_MODE_NORMAL:				//四個を使用する
		for (int i = 0; i < PLATFORM_MAX - 2; i++)
		{
			g_platform[i].pos_x		= (rand() % 49) + 2;
			g_platform[i].pos_y		= i * 4 + 2;
			g_platform[i].height	= 1;
			g_platform[i].width		= 4;
			g_platform[i].FullWidth	= "■";
			g_platform[i].use		= true;
		}

		for (int i = PLATFORM_MAX - 2; i < PLATFORM_MAX; i++)
		{
			g_platform[i].use		= false;
		}
		break;

	case GAME_MODE_HARD:				//三個を使用する
		for (int i = 0; i < PLATFORM_MAX - 3; i++)
		{
			g_platform[i].pos_x		= (rand() % 49) + 2;
			g_platform[i].pos_y		= i * 4 + 2;
			g_platform[i].height	= 1;
			g_platform[i].width		= 4;
			g_platform[i].FullWidth	= "■";
			g_platform[i].use		= true;
		}

		for (int i = PLATFORM_MAX - 3; i < PLATFORM_MAX; i++)
		{
			g_platform[i].use		= false;
		}
		break;
		
	default:
		break;
	}
}

/*******************************************************************************
 関数名:		UpdatePlatform
 引数:		なし
 戻り値:		なし
 説明:		プラットフォーム更新
*******************************************************************************/
void UpdatePlatform()
{
	PLAYER* p = GetPlayer();
	if (p[0].unit.use == true)
	{
		for (int i = 0; i < PLATFORM_MAX; i++)
		{
			if (g_platform[i].use == true)
			{
				g_platform[i].pos_y -= 1;		//プラットフォームは画面の上に上がります

				if (g_platform[i].pos_y < 2)	//範囲外になった時、下に戻ります
				{
					g_platform[i].pos_x = (rand() % 46) + 5;
					g_platform[i].pos_y = 24;
				}
			}
		}
	}
}

/*******************************************************************************
 関数名:		DrawPlatform
 引数:		なし
 戻り値:		なし
 説明:		プラットフォーム描画
*******************************************************************************/
void DrawPlatform()
{
	for (int i = 0; i < PLATFORM_MAX; i++)
	{
		if (g_platform[i].use == true)		//使用しているプラットフォームだけで描画する
		{
			SetFullwidthUnit(GetWindow(), g_platform[i]);
		}
	}
}

/*******************************************************************************
 関数名:		UninitPlatform
 引数:		なし
 戻り値:		なし
 説明:		プラットフォーム終了処理
*******************************************************************************/
void UninitPlatform()
{
	for (int i = 0; i < PLATFORM_MAX; i++)
	{
		g_platform[i].use = false;
	}
}

/*******************************************************************************
 関数名:		GetPlatform
 引数:		なし
 戻り値:		プラットフォームのアドレス
 説明:		プラットフォームのアドレスを返す
*******************************************************************************/
FullwidthUnit* GetPlatform()
{
	return &g_platform[0];
}
