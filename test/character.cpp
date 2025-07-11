#include "character.h"





void character::getMovementInput(int& circenx, int& circeny)
{
		if (IsKeyDown(KEY_A) && circenx > 50)
		{
			circenx = circenx - speed;
		}
		if (IsKeyDown(KEY_S) && circeny < winhei - 50)
		{
			circeny = circeny + speed;
		}
		if (IsKeyDown(KEY_D) && circenx < winwid - 50)
		{
			circenx = circenx + speed;
		}
		if (IsKeyDown(KEY_W) && circeny > 50)
		{
			circeny = circeny - speed;
		}
		if (IsKeyDown(KEY_LEFT_SHIFT))
		{
			speed = basespeed * 2;
		}
		else
		{
			speed = basespeed;
		}
}
