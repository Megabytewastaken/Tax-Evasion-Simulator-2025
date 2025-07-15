#pragma once
#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <vector>
using namespace std;
class Utils
{


public:
	
	bool mainmenu = true;
	static void UpdateAnimation(float dT, float& runtime, float updtime, float& frame, float maxframe);
	

};

