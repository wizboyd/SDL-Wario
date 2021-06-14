#include "Game.h"
#include <SDL_Checkh.h>
#include <AssetManager.h>
#include <Scene.h>
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

		renderer_global = {SDL_CreateRenderer(window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
			) };
		if (renderer_global == NULL)
		{
			WarioPrimark::raise();
		}

		WarioPrimark::check(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG));
		WarioPrimark::check(Mix_Init(MIX_INIT_OGG | MIX_INIT_MOD | MIX_INIT_MP3));
		WarioPrimark::check(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024));
		//load assets
		AssetManager* AM = AssetManager::get(renderer_global);
		//create scene
		Scene newScene( renderer_global);
		newScene.Init();
		
	}
}

