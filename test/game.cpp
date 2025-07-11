#include "Raylib.h"
#include "character.h"

struct AnimData
{
	Rectangle rec;
	Vector2 pos;
	int frame;
	float updateTime;
	float runningTime;
};

int main()
{
	const int winwid = 1920;
	const int winhei = 1080;
	
	bool mainmenu = true;

	InitWindow(winwid, winhei, "Evade Taxes.com (NO ADS)");


	Texture2D taxformtex = LoadTexture("assets/taxform_scaled_2x_pngcrushed.png");
	AnimData taxform{
		{0, 0, taxformtex.width, taxformtex.height},
		{winwid / 2 - taxformtex.width, winhei / 2 - taxformtex.height},
		0,
		0,
		0
	};

	character evader;
	
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		const int dT = GetFrameTime();

		BeginDrawing();
		//Draw Background:
		ClearBackground(BROWN);

		
		DrawRectangle(50, 50, winwid - 100, winhei - 100, BEIGE);

		DrawTextureRec(taxformtex, taxform.rec, taxform.pos, WHITE);


		//Circle
		evader.Tick(dT);

		//Movement
	

		if (IsKeyPressed(KEY_SPACE))
		{
			mainmenu = false;
		}
		if (mainmenu)
		{
			DrawRectangle(0, 0, winwid, winhei, BLACK);
		}


		EndDrawing();
	}
}