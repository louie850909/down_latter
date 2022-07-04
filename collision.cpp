#include "collision.h"

bool CheckCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	int x1_left = x1;
	int x1_right = x1 + w1 * 2 - 1;
	int x1_top = y1;
	int x1_bottom = y1 + h1 - 1;
	int x2_left = x2;
	int x2_right = x2 + w2 * 2 - 1;
	int x2_top = y2;
	int x2_bottom = y2 + h2 - 1;
	
	if (x1_right < x2_left || x1_left > x2_right || abs(y2 - y1) > 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}
