#include "menu.h"
#include "raylib.h"
#include "Utils.h"
;

void menu::setScreenPos(int winwid, int winhei)
{
};
void menu::Tick(float dT)
{
    float frameHeight = men.height / (maxframe);
    tsource = { 0.0f, (int)frame* frameHeight / 2, (float)men.width, frameHeight };
    //x pos of texture y pos //width scale height scale
    tdest = { 0, 0, (float)men.width, frameHeight };
    Utils::UpdateAnimation(dT,runtime, updtime, frame, maxframe);
	getMenuInput();
    
}

void menu::getMenuInput()
{
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
        DrawTexturePro(men, tsource, tdest, Vector2{}, 0.f, WHITE);
    }

    if (IsKeyPressed(KEY_F))
    {
        ToggleFullscreen();
    }
}