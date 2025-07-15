#include "character.h"
#include "Utils.h"



void character::Tick(float dT)
{
	

	//DrawCircle(circenx, circeny, cirad + 5, BLACK);
	//DrawCircle(circenx, circeny, cirad, PINK);
	Vector2 direction{};
	getMovementInput(characterPos,dT);
	Rectangle charSource{ (float)charWup.width / 4, 0, (float)charWup.width / 4, (float)charWup.height };
	Rectangle charDest{ characterPos.x, characterPos.y, (float)charWup.width / 4, (float)charWup.height };
	
	if (!Utils::mainmenu)
	{
		DrawTexturePro(charWup, charSource, charDest, Vector2{ (float)winwid / 2,(float)winhei / 2 }, 0.f, WHITE);
	}
	
	//WorldPosLastFrame = worldPos;
	
	//circenx += direction.x * speed * dT;  // Update X position
	//circeny += direction.y * speed * dT;
}
void character::getMovementInput(Vector2& direction, float deltaTime)
{
	
	if (IsKeyDown(KEY_A)) direction.x -= speed * deltaTime;
	if (IsKeyDown(KEY_D)) direction.x += speed * deltaTime;
	if (IsKeyDown(KEY_W)) direction.y -= speed * deltaTime;
	if (IsKeyDown(KEY_S)) direction.y += speed * deltaTime;

	
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