#include "stdafx.h"
#include "Screen.h"
#include <iostream>

namespace ParticleExplosion 
{
	Screen::Screen()
		:m_window(NULL),
		m_renderer(NULL),
		m_texture(NULL),
		m_buffer(NULL)
	{

	}


	bool Screen::Init()
	{

		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			std::cout << SDL_GetError() << std::endl;
			return false;
		}

		m_window = SDL_CreateWindow("ParticleExplosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);


		if (m_window == NULL)
		{
			std::cout << SDL_GetError() << std::endl;
			SDL_Quit();
			return false;
		}

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);


		if (m_renderer == NULL)
		{
			std::cout << SDL_GetError() << std::endl;
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		if (m_texture == NULL)
		{
			std::cout << SDL_GetError() << std::endl;
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		m_buffer = new Uint32[SCREEN_HEIGHT * SCREEN_WIDTH];

		memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

		return true;
	}

	void Screen::SetPixel(const int x, const int y, const Uint8 red, const Uint8 green, const Uint8 blue)
	{
		Uint32 color = 0;

		color += red;
		color <<= 8;
		color += green;
		color <<= 8;
		color += blue;
		color <<= 8;
		color += 0xFF;

		m_buffer[(y * SCREEN_WIDTH) + x] = color;
	}

	bool Screen::ProcessEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				return false;
			}
		}
		return true;
	}

	void Screen::Close()
	{
		delete[] m_buffer;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texture);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

	

	void Screen::Update()
	{
		SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);
	}
}