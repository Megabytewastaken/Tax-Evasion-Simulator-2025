#include "Raylib.h"
#include "character.h"

int main()
{
	float runtime{};
	float updtime{1.f / 2.f};
	float frame{ 0 };
	float maxframe{ 1 };
	


	const int winwid = 1920;
	const int winhei = 1080;	
	character evader;

	bool mainmenu = true;

	//Make window + title
	InitWindow(winwid, winhei, "Enter to close the main menu!");

	Texture2D menutex = LoadTexture("assets/mainmenu.png");
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


		runtime += dT;
		if (runtime >= updtime)
		{
			runtime = 0.0f;
			frame++;
			if (frame > maxframe)
			{
				frame = 0;
			}
			//data.rec.x = frame * data.rec.width;
		}

		float frameHeight = menutex.height / (maxframe);
		Rectangle tsource{ 0.0f, (int)frame * frameHeight/2, (float)menutex.width, frameHeight};
		//x pos of texture y pos //width scale height scale
		Rectangle tdest{ 0, 0, (float)menutex.width, frameHeight};

		//Menu Logic
		if (IsKeyPressed(KEY_ENTER) && mainmenu)
		{
			mainmenu = false;
			SetWindowTitle("Tax Evasion Simulator 2025 (NO ADS)");
			HideCursor();
			//SetClipboardText("I HATE THE IRS!");
			//OpenURL("https://www.youtube.com/watch_popup?v=mt6O3US9IE4");
		}
		if (mainmenu)
		{
			DrawTexturePro(menutex, tsource, tdest, Vector2{}, 0.f, WHITE);
		}
		if (IsKeyPressed(KEY_F))
		{
			ToggleFullscreen();
		}

		EndDrawing();
	}
}
