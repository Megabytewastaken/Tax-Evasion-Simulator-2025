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
	if (IsKeyDown(KEY_A) && circenx > 75 || IsKeyDown(KEY_LEFT) && circenx > 75)
	{
		circenx = circenx - speed;
	}
	if (IsKeyDown(KEY_S) && circeny < winhei - 75 || IsKeyDown(KEY_DOWN) && circeny < winhei - 75)
	{
		circeny = circeny + speed;
	}
	if (IsKeyDown(KEY_D) && circenx < winwid - 75 || IsKeyDown(KEY_RIGHT) && circenx < winwid - 75)
	{
		circenx = circenx + speed;
	}
	if (IsKeyDown(KEY_W) && circeny > 75 || IsKeyDown(KEY_UP) && circeny > 75)
	{
		circeny = circeny - speed;
	}
	if (IsKeyDown(KEY_LEFT_SHIFT))
	{
		speed = basespeed * 2;
	}
	else if (IsKeyDown(KEY_LEFT_CONTROL))
	{
		speed = basespeed / 2;
	}
	else
	{
		speed = basespeed;
	}
}