#pragma once
#include "raylib.h"
class character
{


private:

	

	float basespeed = 12.5;
	const int winwid = 1920;
	const int winhei = 1080;
	float speed = 1;
	int circenx = winwid / 2;
	int circeny = winhei / 2;
	int cirad = 25;

	float maxframe{ 1 };
	float runtime{ 0.0f };
	float frame{ 0 };
	float updtime{ 1.f / 2.f };
	Texture2D downwalktex = LoadTexture("assets/forward.png");

	//int ball = circenx, circeny, cirad;

public:
	character()
	{


	}

	float runtime{};
	void setScreenPos(int winwid, int winhei);
	void getMovementInput();
	void Tick(float deltaTime);
	int frame{};
	float updtime{};

	~character()
	{

	}



};