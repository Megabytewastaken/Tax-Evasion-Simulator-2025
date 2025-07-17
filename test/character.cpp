#include "character.h"
#include "Utils.h"



void character::Tick(float dT)
{
	

	//DrawCircle(circenx, circeny, cirad + 5, BLACK);
	//DrawCircle(circenx, circeny, cirad, PINK);
	Vector2 direction{};
	//cout << characterPos.x << " " << characterPos.y << endl;
	getMovementInput(characterPos,dT);
	
	
	switch (facing) {
	 case 1:
		charText = charSdown;
		break;
	case 2:
		charText = charAleft;
		break;
	case 3:
		charText = charDright;
		break;
	case 4:
		charText = charWup;
		break;
	default:
		charText = charSdown;
		break;
	}
	
	if (facing != 5)
	{
		Utils::UpdateAnimation(dT, runtime, updtime, frame, maxframe);
	}
	else
	{
		frame = 1;
	}
	 charSource = { frame * charWup.width / 4 , 0, (float)charWup.width / 4, (float)charWup.height };
	 charDest = { characterPos.x , characterPos.y , static_cast<float>(charWup.width / 4 * 0.5), static_cast<float>(charWup.height * 0.5) };
	 charBox = { characterPos.x + ((charDest.width / 2)*0.5f) , characterPos.y + ((charDest.height / 2)*0.5f) , static_cast<float>(charWup.width / 4 * 0.25), static_cast<float>(charWup.height * 0.25)};

	if (!Utils::mainmenu)
	{
		DrawTexturePro(charText, charSource, charDest, Vector2{}, 0.f, WHITE);
	}
	//DrawRectangleRec(charDest, RED);

}
void character::getMovementInput(Vector2& direction, float deltaTime)
{
	
	if (IsKeyDown(KEY_A) && characterPos.x > 7 || IsKeyDown(KEY_LEFT) && characterPos.x > 7)
	{
		direction.x -= speed * deltaTime;
		facing = 2;
	}
	else if (IsKeyDown(KEY_D) && characterPos.x < winwid - 180 || IsKeyDown(KEY_RIGHT) && characterPos.x < winwid - 180)
	{
		direction.x += speed * deltaTime;
		facing = 3;
	}
	else if (IsKeyDown(KEY_W) && characterPos.y > 7 || IsKeyDown(KEY_UP) && characterPos.y > 7)
	{
		direction.y -= speed * deltaTime;
		facing = 4;
	}
	else if (IsKeyDown(KEY_S) && characterPos.y < winhei - 210 || IsKeyDown(KEY_DOWN) && characterPos.y < winhei - 210)
	{
		direction.y += speed * deltaTime;
		facing = 1;
	}
	else
	{
		facing = 5;
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