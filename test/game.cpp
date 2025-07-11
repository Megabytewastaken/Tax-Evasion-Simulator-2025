#include "Raylib.h"

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
	int circenx = winwid / 2;
	int circeny = winhei / 2;
	int cirad = 25;
	float speed = 1;
	float basespeed = 12.5;

	InitWindow(winwid, winhei, "Evade Taxes.com (NO ADS)");


	Texture2D taxformtex = LoadTexture("assets/taxform_scaled_2x_pngcrushed.png");
	AnimData taxform{
		{0, 0, taxformtex.width, taxformtex.height},
		{winwid / 2 - taxformtex.width, winhei / 2 - taxformtex.height},
		0,
		0,
		0
	};

	
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
		DrawCircle(circenx, circeny, cirad + 5, BLACK);
		DrawCircle(circenx, circeny, cirad, PINK);

		//Movement
		if (IsKeyDown(KEY_A) && circenx >  50)
		{
			circenx = circenx - speed;
		}
		if (IsKeyDown(KEY_S) && circeny < winhei - 50)
		{
			circeny = circeny + speed;
		}
		if (IsKeyDown(KEY_D) && circenx < winwid - 50)
		{
			circenx = circenx + speed;
		}
		if (IsKeyDown(KEY_W) && circeny > 50)
		{
			circeny = circeny - speed;
		}
		if (IsKeyDown(KEY_LEFT_SHIFT))
		{
			speed = basespeed * 2;
		}
		else
		{
			speed = basespeed;
		}

		EndDrawing();
	}
}