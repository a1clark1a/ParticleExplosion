// SDL2_Project(Particles).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"

int main(int argc, char* argv[])
{
	ParticleExplosion::Screen screen;
	if (screen.Init() == false)
	{
		std::cout << "Error initialising SDL " << SDL_GetError() << std::endl;
	}

	//Gameloop
	while (true)
	{
		int elapsed = SDL_GetTicks();
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.001)) * 128);
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.003)) * 128);
	
		for (int y = 0; y < ParticleExplosion::Screen::SCREEN_HEIGHT; y++)
		{
			for (int x = 0; x < ParticleExplosion::Screen::SCREEN_WIDTH; x++)
			{
				screen.SetPixel(x, y, red, green, blue);
			}
		}

		screen.Update();

		if(screen.ProcessEvents() == false)
		{
			break;
		}
	}

	screen.Close();
    return 0;
}

