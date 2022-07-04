#include "hp.h"
#include "player.h"

FullwidthUnit g_HP;
FullwidthUnit g_HP_blank;

void InitHp()
{
	g_HP		= { 60, 5, 10, 1, "Å°", true };
	g_HP_blank	= { 80, 5, 1, 1, "Å†", false };
}

void UpdateHp()
{
	PLAYER* player = GetPlayer();
	
	if (player[0].hp < 100)
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

void UninitHp()
{
	g_HP.use = false;
	g_HP_blank.use = false;
}
