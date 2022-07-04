#include "score.h"

SCORE g_Score;

void InitScore()
{
	g_Score.value = 0;
	g_Score.singleDigit		= { 74, 11, 1, 1, "‚O", false };
	g_Score.tenDigit		= { 72, 11, 1, 1, "‚O", false };
	g_Score.hundredDigit	= { 70, 11, 1, 1, "‚O", false };
	g_Score.kiloDigit		= { 68, 11, 1, 1, "‚O", false };
	g_Score.tenK_Digit		= { 66, 11, 1, 1, "‚O", false };
	g_Score.hundredK_Digit	= { 64, 11, 1, 1, "‚O", false };
}

void UpdateScore()
{
	if (g_Score.value <= 999999)
	{
		int num = g_Score.value;
		g_Score.singleDigit.FullWidth		= Convert(num % 10);
		g_Score.singleDigit.use = true;
		num /= 10;
		g_Score.tenDigit.FullWidth			= Convert(num % 10);
		g_Score.tenDigit.use = true;
		num /= 10;
		g_Score.hundredDigit.FullWidth		= Convert(num % 10);
		g_Score.hundredDigit.use = true;
		num /= 10;
		g_Score.kiloDigit.FullWidth			= Convert(num % 10);
		g_Score.kiloDigit.use = true;
		num /= 10;
		g_Score.tenK_Digit.FullWidth		= Convert(num % 10);
		g_Score.tenK_Digit.use = true;
		num /= 10;
		g_Score.hundredK_Digit.FullWidth	= Convert(num % 10);
		g_Score.hundredK_Digit.use = true;

		g_Score.value += 1;
	}
}

void DrawScore()
{
	if (g_Score.singleDigit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.singleDigit);
	}
	if (g_Score.tenDigit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.tenDigit);
	}
	if (g_Score.hundredDigit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.hundredDigit);
	}
	if (g_Score.kiloDigit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.kiloDigit);
	}
	if (g_Score.tenK_Digit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.tenK_Digit);
	}
	if (g_Score.hundredK_Digit.use == true)
	{
		SetFullwidthUnit(GetWindow(), g_Score.hundredK_Digit);
	}
}

void UninitScore()
{
	
}

void AddScore(int value)
{
	g_Score.value += value;
}

SCORE* GetScore()
{
	return &g_Score;
}

const char* Convert(int value)
{
	switch (value)
	{
		case 0:
			return "‚O";
			break;
			
		case 1:
			return "‚P";
			break;
			
		case 2:
			return "‚Q";
			break;

		case 3:
			return "‚R";
			break;
			
		case 4:
			return "‚S";
			break;
			
		case 5:
			return "‚T";
			break;
			
		case 6:
			return "‚U";
			break;
			
		case 7:
			return "‚V";
			break;
			
		case 8:
			return "‚W";
			break;
			
		case 9:
			return "‚X";
			break;
	default:
		break;
	}
}
