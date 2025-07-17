#pragma once
#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <vector>
using namespace std;
class Utils
{


public:
	static const int winwid = 1920;
	static const int winhei = 1080;
	static void UpdateAnimation(float dT, float& runtime, float updtime, float& frame, float maxframe);
	static bool mainmenu;
	static bool YOUSUCK;

};

