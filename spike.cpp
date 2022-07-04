#include "spike.h"
#include "player.h"

FullwidthUnit g_spike[SPIKE_MAX];

void InitSpike()
{
	switch (GetState())					//難易度によって使用されたプラットフォーム数が違う
	{
	case GAME_MODE_HARD:				//全部を使用する
		for (int i = 0; i < SPIKE_MAX; i++)
		{
			g_spike[i].pos_x = (rand() % 49) + 2;
			g_spike[i].pos_y = i * 8 + 3;
			g_spike[i].height = 1;
			g_spike[i].width = 4;
			g_spike[i].FullWidth = "△";
			g_spike[i].use = true;
		}
		break;

	case GAME_MODE_NORMAL:				//二個を使用する
		for (int i = 0; i < SPIKE_MAX - 1; i++)
		{
			g_spike[i].pos_x = (rand() % 49) + 2;
			g_spike[i].pos_y = i * 8 + 3;
			g_spike[i].height = 1;
			g_spike[i].width = 4;
			g_spike[i].FullWidth = "△";
			g_spike[i].use = true;
		}

		for (int i = SPIKE_MAX - 1; i < SPIKE_MAX; i++)
		{
			g_spike[i].use = false;
		}
		break;

	case GAME_MODE_EASY:				//一個を使用する
		for (int i = 0; i < SPIKE_MAX - 2; i++)
		{
			g_spike[i].pos_x = (rand() % 49) + 2;
			g_spike[i].pos_y = i * 8 + 3;
			g_spike[i].height = 1;
			g_spike[i].width = 4;
			g_spike[i].FullWidth = "△";
			g_spike[i].use = true;
		}

		for (int i = SPIKE_MAX - 2; i < SPIKE_MAX; i++)
		{
			g_spike[i].use = false;
		}
		break;

	default:
		break;
	}
}

void UpdateSpike()
{
	PLAYER* p = GetPlayer();
	if (p[0].unit.use == true)
	{
		for (int i = 0; i < SPIKE_MAX; i++)
		{
			if (g_spike[i].use == true)
			{
				g_spike[i].pos_y -= 1;		//スパイクは画面の上に上がります

				if (g_spike[i].pos_y < 2)	//範囲外になった時、下に戻ります
				{
					g_spike[i].pos_x = (rand() % 46) + 5;
					g_spike[i].pos_y = 24;
				}
			}
		}
	}
}

void DrawSpike()
{
	for (int i = 0; i < SPIKE_MAX; i++)
	{
		if (g_spike[i].use == true)		//使用しているスパイクだけで描画する
		{
			SetFullwidthUnit(GetWindow(), g_spike[i]);
		}
	}
}

void UninitSpike()
{
	for (int i = 0; i < SPIKE_MAX; i++)
	{
		g_spike[i].use = false;
	}
}

FullwidthUnit* GetSpike()
{
	return &g_spike[0];
}
