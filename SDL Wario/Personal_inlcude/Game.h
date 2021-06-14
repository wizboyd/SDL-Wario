#pragma once
#include <SDL.h>
static SDL_Renderer* renderer_global;
namespace WarioPrimark {
	class Game
	{
	public:
		Game();
		~Game();
		//static SDL_Renderer* renderer_global;

		void run();
	};
}

