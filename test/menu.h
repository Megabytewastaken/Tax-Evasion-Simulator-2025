#pragma once
#include "raylib.h"
#include "raymath.h"
class menu
{

private:
	
	






public:
	menu()
	{


	}
	Texture2D men = LoadTexture("assets/mainmenu.png");
	float maxframe{ 1 };
	float runtime{0.0f};
	void setScreenPos(int winwid, int winhei);
	void getMenuInput();
	void Tick(float deltaTime);
	float frame{0};
	float updtime{1.f / 2.f};
	Rectangle tsource{};
	Rectangle tdest{};
	bool mainmenu = true;

	

	~menu()
	{

	}
};

