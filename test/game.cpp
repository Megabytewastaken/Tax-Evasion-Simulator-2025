#include "character.h"
#include "menu.h"
#include "map.h"
#include "Utils.h"

int main()
{	const int winwid = 1920;
	const int winhei = 1080;	
	int cash = 0;
	int stupidtimergodieyouevilthing{0};

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

		//Draw Taxform
		//DrawTextureRec(taxformtex, taxform.rec, taxform.pos, WHITE);
	
		 
		//Circle
		
		mainmenuu.Tick(dT);
		evader.Tick(dT);
		
		if (!Utils::mainmenu)
		{
			DrawText(TextFormat("$$$ Saved: %i", cash), 10, 10, 102, DARKGREEN);
			DrawText(TextFormat("$$$ Saved: %i", cash), 15, 15, 100, GREEN);
			stupidtimergodieyouevilthing++;
		}
		if (stupidtimergodieyouevilthing == 12)
		{
			cash = cash + 1;
			stupidtimergodieyouevilthing = 0;
		}
		//DrawRectangle(0, 0, winwid - 75, winhei - 75, PINK);
		EndDrawing();
	}
}
