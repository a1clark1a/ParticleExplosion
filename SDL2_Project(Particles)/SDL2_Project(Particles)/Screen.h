#pragma once
#include <SDL.h>


namespace ParticleExplosion 
{
	class Screen
	{
	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;

		Screen();
		bool Init();
		bool ProcessEvents();
		void Close();
		void SetPixel(const int x, const int y, const Uint8 red, const Uint8 green, const Uint8 blue);
		void Update();
	

	private:
		SDL_Window * m_window;
		SDL_Renderer * m_renderer;
		SDL_Texture * m_texture;
		Uint32 * m_buffer;
	};
}