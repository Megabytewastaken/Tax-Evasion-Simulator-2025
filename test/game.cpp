#include "character.h"
#include "menu.h"
#include "map.h"
#include "Utils.h"

int main()
{	const int winwid = 1920;
	const int winhei = 1080;	

	//Make window + title
	InitWindow(winwid, winhei, "Enter to close the main menu!");
	character evader;
	menu mainmenuu;
	map mape;
	
	Texture2D taxformtex = LoadTexture("assets/taxform_scaled_2x_pngcrushed.png");
	
	Texture2D gameBackground = LoadTexture("assets/gamearea.png");

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		const float dT = GetFrameTime();

		BeginDrawing();
		
		DrawTexture(gameBackground, 0,0 , WHITE);


		//Draw Background:
		ClearBackground(BROWN);
		//DrawRectangle(50, 50, winwid - 100, winhei - 100, BEIGE);

		//Draw Taxform
		//DrawTextureRec(taxformtex, taxform.rec, taxform.pos, WHITE);
		Rectangle source{ taxformtex.width, 0.0f, taxformtex.height};
		Rectangle dest{ 0, 0, (float)taxformtex.width, taxformtex.height};
		 
		//Circle
		
		mainmenuu.Tick(dT);
		evader.Tick(dT);
		
		


		EndDrawing();
	}
}
