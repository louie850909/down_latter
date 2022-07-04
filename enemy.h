#pragma once
#include "draw.h"
#include "main.h"

#define ENEMY_MAX (5)

void InitEnemy();
void UpdateEnemy();
void DrawEnemy();
void UninitEnemy();

FullwidthUnit* GetEnemy();