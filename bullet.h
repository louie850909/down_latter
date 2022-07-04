#pragma once
#include "draw.h"
#include "main.h"
#include "player.h"

struct BULLET
{
	FullwidthUnit unit;
	int dir;
};

#define BULLET_MAX (10)

void InitBullet();
void UpdateBullet();
void DrawBullet();
void UninitBullet();

void SetBullet(PLAYER* player);
