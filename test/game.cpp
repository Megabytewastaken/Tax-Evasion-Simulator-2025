#include "Raylib.h"
#include "character.h"


int main()
{
	float runtime{};
	



	const int winwid = 1920;
	const int winhei = 1080;	
	character evader;

	bool mainmenu = true;

	//Make window + title
	InitWindow(winwid, winhei, "Space to close the main menu!");


	Texture2D taxformtex = LoadTexture("assets/taxform_scaled_2x_pngcrushed.png");
	AnimData taxform{
		{0, 0, taxformtex.width, taxformtex.height},
		{winwid / 4 - taxformtex.width, winhei / 4 - taxformtex.height},
		0,
		0,
		0
	};
	Texture2D mtex = LoadTexture("assets/mainmenu.png");
	AnimData menutex{
		{0, 0, mtex.width, mtex.height/2},
		{0, 0},
		0,
		1.0f / 2.0f,
		0.0f
	};


	Rectangle source{mtex.width, 0.0f, mtex.height / 2.0f };
	//x pos of texture y pos //width scale height scale
	Rectangle dest{0, 0, (float)texture.width, mtex.height /2};

	updanimdata(menutex, dT, 1, 0);


	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		const int dT = GetFrameTime();

		BeginDrawing();

		//Draw Background:
		ClearBackground(BROWN);
		DrawRectangle(50, 50, winwid - 100, winhei - 100, BEIGE);

		//Draw Taxform
		DrawTextureRec(taxformtex, taxform.rec, taxform.pos, WHITE);

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

		//Menu Logic
		if (IsKeyPressed(KEY_SPACE) && mainmenu)
		{
			mainmenu = false;
			SetWindowTitle("Tax Evasion Simulator 2025 (NO ADS)");
			HideCursor();
			SetClipboardText("I HATE THE IRS!");
			//OpenURL("https://www.youtube.com/watch_popup?v=mt6O3US9IE4");
		}
		if (mainmenu)
		{
			DrawTextureRec(mtex, menutex.rec, menutex.pos, WHITE);
			updanimdata(menutex, dT, 1, 0);

		}
		if (IsKeyPressed(KEY_F))
		{
			ToggleFullscreen();
		}

		EndDrawing();
	}
	}
}