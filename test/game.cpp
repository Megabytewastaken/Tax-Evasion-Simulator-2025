#include "Raylib.h"
#include "character.h"
#include "menu.h"




int main()
{
	


	const int winwid = 1920;
	const int winhei = 1080;	
	
	bool mainmenu = true;

	//Make window + title
	InitWindow(winwid, winhei, "Enter to close the main menu!");
	character evader;
	menu mainmenuu;
	
	Texture2D taxformtex = LoadTexture("assets/taxform_scaled_2x_pngcrushed.png");
	

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		const float dT = GetFrameTime();

		BeginDrawing();
		


		//Draw Background:
		ClearBackground(BROWN);
		DrawRectangle(50, 50, winwid - 100, winhei - 100, BEIGE);

		//Draw Taxform
		//DrawTextureRec(taxformtex, taxform.rec, taxform.pos, WHITE);
		Rectangle source{ taxformtex.width, 0.0f, taxformtex.height};
		Rectangle dest{ 0, 0, (float)taxformtex.width, taxformtex.height};

		//Circle
		evader.Tick(dT);
		mainmenuu.Tick(dT);

		
		


		EndDrawing();
	}
}
