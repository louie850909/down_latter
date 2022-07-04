#pragma once
#include "main.h"
#include "draw.h"

struct RANK
{
	char value;
	const char* line1;
	const char* line2;
	const char* line3;
	const char* line4;
	const char* line5;
};

void InitResult();
void UpdateResult();
void DrawResult();
void UninitResult();