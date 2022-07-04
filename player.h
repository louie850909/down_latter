#pragma once
#include "draw.h"
#include "main.h"

enum direction
{
	RIGHT,
	LEFT,
};

struct PLAYER
{
	FullwidthUnit unit;
	int hp;
	int direction;
	bool onGround;
};

void InitPlayer();
void UpdatePlayer();
void DrawPlayer();
void UninitPlayer();

PLAYER* GetPlayer();