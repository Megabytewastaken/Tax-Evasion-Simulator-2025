#include "character.h"
#include "menu.h"
#include "map.h"
#include "Utils.h"
#include "tax.h"



int main()
{	
	int cash = 0;
	int stupidtimergodieyouevilthing{0};
	
	int stupidtimergodieyouevilthing2thesequal = 0;

	//Make window + title
	InitWindow(Utils::winwid, Utils::winhei, "Enter to close the main menu!");
	character evader;
	menu mainmenuu;
	map mape;
	
	//Texture2D taxformtex = LoadTexture("assets/taxform_scaled_2x_pngcrushed.png");
	
	Texture2D gameBackground = LoadTexture("assets/gamearea.png");

	vector<tax> taxes{};

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
		/*Rectangle source{ taxformtex.width, 0.0f, taxformtex.height};
		Rectangle dest{ 0, 0, (float)taxformtex.width, taxformtex.height};*/
		 
		//Circle
		
		mainmenuu.Tick(dT);
		evader.Tick(dT);
		//DrawRectangleRec(evader.charDest, PINK);
		if (!Utils::mainmenu)
		{
			DrawText(TextFormat("$$$ Saved: %i", cash, "K %i"), 10, 10, 102, DARKGREEN);
			DrawText(TextFormat("$$$ Saved: %i", cash, "K %i"), 15, 15, 100, GREEN);
			stupidtimergodieyouevilthing++;
		}
		if (stupidtimergodieyouevilthing == 12)
		{
			cash = cash + 1;
			stupidtimergodieyouevilthing = 0;
		}	
		
		stupidtimergodieyouevilthing2thesequal++;

		


		if (stupidtimergodieyouevilthing2thesequal == 10)
		{
			
				int randspawnpointlocation = GetRandomValue(1, 4);

				if (randspawnpointlocation == 1)
				{
					float posX = GetRandomValue(0, Utils::winwid);
					float posY = 0;
					taxes.emplace_back(Vector2{ posX, posY }, randspawnpointlocation);

				}
				else if (randspawnpointlocation == 2)
				{
					float posX = GetRandomValue(0, Utils::winwid);
					float posY = Utils::winhei;
					taxes.emplace_back(Vector2{ posX, posY }, randspawnpointlocation);
				}
				else if (randspawnpointlocation == 3)
				{
					float posY = GetRandomValue(0, Utils::winhei);
					float posX = 0;
					taxes.emplace_back(Vector2{ posX, posY }, randspawnpointlocation);
				}
				else if (randspawnpointlocation == 4)
				{
					float posX = GetRandomValue(0, Utils::winhei) - 50;
					float posY = Utils::winwid;
					taxes.emplace_back(Vector2{ posX, posY }, randspawnpointlocation);
				}
			
			stupidtimergodieyouevilthing2thesequal = 0;
		}
		for (auto& tax : taxes) 
		{
			tax.tick(dT, evader.charBox, cash);
		}

		if (cash < -100)
		{
			SetClipboardText("I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! I HATE THE IRS! ");

			OpenURL("https://www.irs.gov/payments");
			break;
		}
		if (cash > 35)
		{	
			OpenURL("https://www.youtube.com/watch_popup?v=mt6O3US9IE4");
			WaitTime(5);
			OpenURL("https://www.youtube.com/watch?v=fXNYEex2uh4");
			WaitTime(5);
			OpenURL("https://www.globalcitizensolutions.com/how-to-avoid-paying-taxes-legally/");
			break;
		}
		if (cash > 1000)
		{
			
		}
		
		
		EndDrawing();
	}


		CloseWindow();
	
	UnloadTexture(evader.charText);
		/*for (auto& tax : taxes)
		{
			UnloadTexture();
		}*/

}	
