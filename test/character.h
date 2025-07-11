#pragma once
#include "raylib.h"
class character
{


private:
	int frame{};
	float runningTime{};
	float speed = 1;
	float basespeed = 12.5;
	const int winwid = 1920;
	const int winhei = 1080;


public:
	character()
	{


	}

	void setScreenPos(int winwid, int winhei);
	void getMovementInput(int& circenx, int& circeny);



	~character()
	{

	}
			


};

