#include "Utils.h"

void Utils::UpdateAnimation(float dT, float& runtime, float updtime, float& frame, float maxframe)
{

	
		runtime += dT;
		if (runtime >= updtime)
		{
			runtime = 0.0f;
			frame++;
			if (frame > maxframe)
			{
				frame = 0;
			}

		}

	
}
bool Utils::mainmenu = true;
