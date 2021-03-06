// SDL2_Project(Particles).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"


using namespace ParticleExplosion;

int main(int argc, char* argv[])
{
	srand(time(NULL));

	Screen screen;
	if (screen.Init() == false)
	{
		std::cout << "Error initialising SDL " << SDL_GetError() << std::endl;
	}

	Swarm swarm;

	//Gameloop
	while (true)
	{
		int elapsed = SDL_GetTicks();

		swarm.Update(elapsed);

		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.001)) * 128);
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.003)) * 128);

		const Particle * const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH/ 2 + Screen::SCREEN_HEIGHT / 2;

			screen.SetPixel(x, y,red, green, blue);
		}

		screen.BoxBlur();
		screen.Update();

		if(screen.ProcessEvents() == false)
		{
			break;
		}
	}

	screen.Close();
    return 0;
}

