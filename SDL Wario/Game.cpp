#include "Game.h"
#include <Utilty.h>
#include <TextureManager.h>
#include <GameObject.h>

GameObject* Player;

void Game::INIT(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	isrunning = true;
	int flag = 0;
	if (fullscreen)
	{
		flag = SDL_WINDOW_FULLSCREEN;
	}
	check(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO));

	window = check_SDL_Component(SDL_CreateWindow(title, xpos, ypos, width, height, flag));
	renderer = check_SDL_Component(SDL_CreateRenderer(window, -1, 0));
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	Player = new GameObject("Mario_staffordshire/Luigi.png", renderer, 0, 0);
}

void Game::handleevents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	default:
		break;
	case SDL_QUIT:
		isrunning = false;
		break;

	}
}

void Game::update()
{
	Player->update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	Player->render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
