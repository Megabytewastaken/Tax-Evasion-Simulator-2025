#pragma once
#include "Utils.h";

class tax
{


private:	

	vector<Vector2> projectileSpawn;
	vector<tax> taxes;
	Texture2D taxtex = LoadTexture("assets/taxform.png");



public:
	Vector2 Pos{};
	float initxvel{1};
	float inityvel{1};
	float dmg{100};
	float expiretime{60};
	int spawnpointlocation{ GetRandomValue(1, 4) };
	int stupidtimergodieyouevilthing3thethreequal = 0;
	
	tax(Vector2 SpawnPos, int spawnLocation)
	{
		Pos.x = SpawnPos.x;
		Pos.y = SpawnPos.y;
		spawnpointlocation = spawnLocation;
	}

	void movethething(int perish);

	void tick(float dT);

	~tax()
	{
		
	}

};

