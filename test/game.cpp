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

AnimData updanimdata(AnimData data, float dT, int maxframe, int startframe)
{
	data.runningTime += dT;
	if (data.runningTime >= data.updateTime)
	{
		data.runningTime = 0.0f;
		data.frame++;
		if (data.frame > maxframe)
		{
			data.frame = startframe;
		}
		data.rec.x = data.frame * data.rec.width;
	}
	return data;
}

int main()
{
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
		{0, 0, mtex.width, mtex.height},
		{0, 0},
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

		//Draw Taxform
		DrawTextureRec(taxformtex, taxform.rec, taxform.pos, WHITE);

		//Circle
		evader.Tick(dT);

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
		}
		if (IsKeyPressed(KEY_F))
		{
			ToggleFullscreen();
		}

			EndDrawing();
		}
	}