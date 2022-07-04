#pragma once
#include "main.h"
#include "draw.h"

struct SCORE
{
	int value;
	FullwidthUnit singleDigit;
	FullwidthUnit tenDigit;
	FullwidthUnit hundredDigit;
	FullwidthUnit kiloDigit;
	FullwidthUnit tenK_Digit;
	FullwidthUnit hundredK_Digit;
};

void InitScore();
void UpdateScore();
void DrawScore();
void UninitScore();

void AddScore(int value);
SCORE* GetScore();
const char* Convert(int value);