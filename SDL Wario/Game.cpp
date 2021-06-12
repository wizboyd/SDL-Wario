#include "Game.h"
#include <SDL_Checkh.h>
#include <AssetManager.h>
namespace WarioPrimark {

	Game::Game()
	{
		WarioPrimark::check(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO));//will check if SDL can INTITILize if not will terminate program;
	}

	Game::~Game() {
		SDL_Quit();
	}

void Game::run(){
		SDL_Window* window{SDL_CreateWindow(//creates a window and sets it to the varible window
		"Wario Primark",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			800,600,
			SDL_WINDOW_SHOWN
		) };
		if (window == NULL)
		{
			WarioPrimark::raise();
		}

		SDL_Renderer* renderer{SDL_CreateRenderer(window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
			) };
		if (renderer == NULL)
		{
			WarioPrimark::raise();
		}
		//load assets
		AssetManager assetmanager(renderer, "Mario_staffordshire");
	}
}

