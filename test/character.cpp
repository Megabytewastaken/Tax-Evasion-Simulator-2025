#include "character.h"

void character::setScreenPos(int winwid, int winhei)
{
}

void character::Tick(float dT)
{
	DrawCircle(circenx, circeny, cirad + 5, BLACK);
	DrawCircle(circenx, circeny, cirad, PINK);

	getMovementInput();
}
void character::getMovementInput()
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