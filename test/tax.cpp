#include "tax.h"

//assign a timer for spawn interval
//add a random vector2 to the enemy pos vector
//emplace_back(constructor(random vector2)
//for each loop for each tax tick



void tax::movethething(int perish)
{
	if (perish == 1)
	{
		Pos.y += inityvel;
	}
	else if (perish == 2)
	{
		Pos.y -= inityvel;
	}
	else if (perish == 3)
	{
		Pos.x += initxvel;
	}
	else if (perish == 4)
	{
		Pos.x -= initxvel;
	}
}

void tax::tick(float dT)
{
	/*float posX = GetRandomValue(0, Utils::winwid);
	float posY = GetRandomValue(0, Utils::winhei);*/
	Rectangle taxsource{0, 0, taxtex.width, taxtex.height };
	Rectangle taxdest{ Pos.x, Pos.y, taxtex.width, taxtex.height };
	if (!Utils::mainmenu)
	{
		DrawTexturePro(taxtex, taxsource, taxdest, Vector2{}, 0.f, WHITE);
	}
	movethething(spawnpointlocation);
	stupidtimergodieyouevilthing3thethreequal++;
	if (stupidtimergodieyouevilthing3thethreequal == expiretime)
	{
		//CloseWindow();
	}
	//CheckCollisionRecs(chardest, taxdest) 
	//{
	//	Character.damage();
	//}
}


