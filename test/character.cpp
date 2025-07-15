#include "character.h"



void character::Tick(float dT)
{
	//DrawCircle(circenx, circeny, cirad + 5, BLACK);
	//DrawCircle(circenx, circeny, cirad, PINK);
	Vector2 direction{};
	
	getMovementInput(direction);
	
	circenx += direction.x * speed * dT;  // Update X position
	circeny += direction.y * speed * dT;
}
void character::getMovementInput(Vector2& direction)
{
	if (IsKeyDown(KEY_A)) direction.x += 1.0;
	if (IsKeyDown(KEY_D)) direction.x -= 1.0;
	if (IsKeyDown(KEY_W)) direction.y += 1.0;
	if (IsKeyDown(KEY_S)) direction.y -= 1.0;

	/*if (IsKeyDown(KEY_A) && circenx > 75 || IsKeyDown(KEY_LEFT) && circenx > 75)
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
	}*/
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