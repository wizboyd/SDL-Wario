#include "Game.h"
#include <Entity.h>
#include <Transform.h>
#include <EntityManager.h>

SDL_Renderer* Game::rendererer = nullptr;
TextureManager Game::TexManager;
ObjectManager Game::objManager;


Game::Game() {
	running = true;
}

Game::~Game() {

}

bool Game::Initilize_game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL and subsystems could not be INITIALIZED! SDL_ERROR: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (fullscreen)
		{
			window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_FULLSCREEN);
		}
		window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("COULD NOT OPEN A WINDOW SDL_ERROR: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			rendererer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (rendererer == NULL)
			{
				printf("RENDERER COULD NOT BE CREATED FOR SOME REASON SDL_ERROR: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(rendererer, 0xFF, 0xFF, 0xFF, 0xFF);

				int IMG_FLAGS = IMG_INIT_PNG | IMG_INIT_JPG;
				if (!(IMG_Init(IMG_FLAGS) & IMG_FLAGS))
				{
					printf("COuld not load the required IMage support SDL_IMAGE_ERROR: %s\n", IMG_GetError());
					success = false;
				}
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_MIXER could not be INITILIZED SDL_MIXER_ERROR: %s", Mix_GetError());
					success = false;
				}
				EntityManager* manager = new EntityManager();
				Entity* entity = new Entity();
				manager->addEntity(entity);

				while (true)
				{
					manager->update();
					manager->draw();
				}

				std::cout << entity->getComponent<Transform>().position.x << std::endl;
				std::cout << entity->hascomponent<Transform>() << std::endl;

			}
		}
	}
	return success;
}

void Game::handleevents() {

}

void Game::render() {

}

void Game::Clean() {

}

void Game::update() {
	
}

bool Game::isrunning() {
	return running;
}