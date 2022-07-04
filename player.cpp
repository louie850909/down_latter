#include "player.h"
#include "platform.h"
#include "collision.h"
#include "spike.h"
#include "bullet.h"

PLAYER g_Player;

void InitPlayer()
{
	FullwidthUnit p = { 20, 4, 1,1, "¶", true };
	g_Player = { p, 100, RIGHT, false };
}

void UpdatePlayer()
{
	FullwidthUnit* platform = GetPlatform();
	FullwidthUnit* spike = GetSpike();
	
	if (g_Player.unit.use == true)
	{	
		if (g_Player.onGround == true)
		{
			g_Player.unit.pos_y -= 1;
		}
		else
		{
			g_Player.unit.pos_y += 1;
		}

		if (g_Player.unit.pos_y < 3)			// 天井との衝突判定
		{
			g_Player.unit.pos_y = 3;
			
			switch (GetState())
			{
			case GAME_MODE_EASY:
				g_Player.hp -= 10;
				break;

			case GAME_MODE_NORMAL:
				g_Player.hp -= 20;
				break;

			case GAME_MODE_HARD:
				g_Player.hp -= 100;
				break;
				
			default:
				break;
			}
		}
		
		for (int i = 0; i < PLATFORM_MAX; i++)	// プラットフォームとの衝突判定
		{
			if (platform[i].use == true)
			{
				if (CheckCollision(g_Player.unit.pos_x, g_Player.unit.pos_y, g_Player.unit.width, g_Player.unit.height, platform[i].pos_x, platform[i].pos_y, platform[i].width, platform[i].height) == true)
				{
					g_Player.onGround = true;
					g_Player.unit.pos_y = platform[i].pos_y - g_Player.unit.height;
					break;
				}
				else
				{
					g_Player.onGround = false;
				}
			}
		}

		for (int i = 0; i < SPIKE_MAX; i++)	// スパイクとの衝突判定
		{
			if (spike[i].use == true)
			{
				if (CheckCollision(g_Player.unit.pos_x, g_Player.unit.pos_y, g_Player.unit.width, g_Player.unit.height, spike[i].pos_x, spike[i].pos_y, spike[i].width, spike[i].height) == true)
				{
					g_Player.onGround = true;
					g_Player.unit.pos_y = spike[i].pos_y - g_Player.unit.height;
					
					switch (GetState())
					{
					case GAME_MODE_EASY:
						g_Player.hp -= 10;
						break;

					case GAME_MODE_NORMAL:
						g_Player.hp -= 20;
						break;

					case GAME_MODE_HARD:
						g_Player.hp -= 100;
						break;

					default:
						break;
					}
					
					break;
				}
				else
				{
					g_Player.onGround = false;
				}
			}
		}

		if (g_Player.unit.pos_y > 24 || g_Player.hp <= 0)		// プレイヤーが画面外に出たら消す
		{
			g_Player.unit.use = false;
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
		case 'a':
		case 0x4b:	// ←
			g_Player.unit.pos_x -= 2;
			g_Player.direction = LEFT;
			
			if (g_Player.unit.pos_x <= 1)
			{
				g_Player.unit.pos_x = 2;
			}
			if (g_Player.unit.pos_x >= 58)
			{
				g_Player.unit.pos_x = 56;
			}
			
			break;

		case 'd':
		case 0x4d:	// →
			g_Player.unit.pos_x += 2;
			g_Player.direction = RIGHT;

			if (g_Player.unit.pos_x <= 1)
			{
				g_Player.unit.pos_x = 2;
			}
			if (g_Player.unit.pos_x >= 58)
			{
				g_Player.unit.pos_x = 56;
			}
			
			break;

		case ' ':
			SetBullet(GetPlayer());
			break;
			
		default:
			break;
		}
	}
}

void DrawPlayer()
{
	if (g_Player.unit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Player.unit);
	}
}

void UninitPlayer()
{
	g_Player.unit.use = false;
}

PLAYER* GetPlayer()
{
	return &g_Player;
}
