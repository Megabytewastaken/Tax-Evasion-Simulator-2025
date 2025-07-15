#pragma once
#include "Utils.h";

class tax
{


private:	
	int randscreenhei = GetRandomValue(0, GetScreenHeight());
	int randscreenwid = GetRandomValue(0, GetScreenWidth());
	vector<Vector2> projectileSpawn;
	vector<tax> taxes;




public:
	tax(Vector2 spawnPos)
	{
		SpawnPos = spawnPos;
	}

	Vector2 SpawnPos{};



	~tax()
	{

	}

};

