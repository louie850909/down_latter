#include "bullet.h"
#include "enemy.h"
#include "collision.h"
#include "score.h"

BULLET g_Bullet[BULLET_MAX];

void InitBullet()
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		g_Bullet[i].unit.use = false;
	}
}

void UpdateBullet()
{
	PLAYER* player = GetPlayer();
	FullwidthUnit* enemy = GetEnemy();
	
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (g_Bullet[i].unit.use == true)
		{
			//移動処理
			if (g_Bullet[i].dir == RIGHT)		// プレイヤーが右に向こうとき、弾は右に移動する
			{
				g_Bullet[i].unit.pos_x += 2;
			}
			else
			{
				g_Bullet[i].unit.pos_x -= 2;	// プレイヤーが左に向こうとき、弾は左に移動する
			}
			g_Bullet[i].unit.pos_y -= 1;
			
			//画面外チェック
			if (g_Bullet[i].unit.pos_x < 2 || g_Bullet[i].unit.pos_x > 56 || g_Bullet[i].unit.pos_y < 2)
			{
				g_Bullet[i].unit.use = false;
			}

			//敵との当たり判定
			for (int j = 0; j < ENEMY_MAX; j++)
			{
				if (enemy[j].use == true)
				{
					if (CheckCollision(g_Bullet[i].unit.pos_x, g_Bullet[i].unit.pos_y, g_Bullet[i].unit.width, g_Bullet[i].unit.height,
						enemy[j].pos_x, enemy[j].pos_y, enemy[j].width, enemy[j].height) == true)
					{
						enemy[j].use = false;
						g_Bullet[i].unit.use = false;
						AddScore(100);
					}
				}
			}
		}
	}
}

void DrawBullet()
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (g_Bullet[i].unit.use == true)
		{
			SetFullwidthUnit(GetWindow(), g_Bullet[i].unit);
		}
	}
}

void UninitBullet()
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		g_Bullet[i].unit.use = false;
	}
}

void SetBullet(PLAYER* player)
{
 	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (g_Bullet[i].unit.use == false)
		{
			if (player[0].direction == LEFT)
			{
				g_Bullet[i].dir = LEFT;
				g_Bullet[i].unit.pos_x = player[0].unit.pos_x - g_Bullet[i].unit.width;
				g_Bullet[i].unit.pos_y = player[0].unit.pos_y + 1;
				g_Bullet[i].unit.FullWidth = "〇";
				g_Bullet[i].unit.height = 1;
				g_Bullet[i].unit.width = 1;
				g_Bullet[i].unit.use = true;
				return;
			}
			else
			{
				g_Bullet[i].dir = RIGHT;
				g_Bullet[i].unit.pos_x = player[0].unit.pos_x - g_Bullet[i].unit.width;
				g_Bullet[i].unit.pos_y = player[0].unit.pos_y + 1;
				g_Bullet[i].unit.FullWidth = "〇";
				g_Bullet[i].unit.height = 1;
				g_Bullet[i].unit.width = 1;
				g_Bullet[i].unit.use = true;
				return;
			}
		}
	}
}
