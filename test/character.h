#pragma once
#include "raylib.h"
#include "raymath.h"
class character
{


private:
	

	


	float basespeed = 1200.5;

	const float winwid = 1920;
	const float winhei = 1080;
	float speed = 1200;
	int circenx = winwid / 2;
	int circeny = winhei / 2;
	int cirad = 25;

	float maxframe{ 4 };
	float runtime{ 0.0f };
	float frame{ 0 };
	float updtime{ 1.f / 4.f };
	int facing{ 0 };
	

	//int ball = circenx, circeny, cirad;

public:
	character()
	{

			
	}
	Rectangle charSource{ };
	Rectangle charDest{};
	Texture2D charText = LoadTexture("assets/down.png");

	Texture2D charWup = LoadTexture("assets/up.png");
	Texture2D charAleft = LoadTexture("assets/left.png");
	Texture2D charSdown = LoadTexture("assets/down.png");
	Texture2D charDright = LoadTexture("assets/right.png");
	//float runtime{};
	//void setScreenPos(int winwid, int winhei);
	///void getMovementInput();
	void Tick(float deltaTime);
	//int frame{};
	//float updtime{};
	void getMovementInput(Vector2& direction, float deltaTime);
	Vector2 characterPos{winwid / 2, winhei /2};
	//void undoMovement();
	Rectangle source{};
	Rectangle dest{};

	~character()
	{

	}



};