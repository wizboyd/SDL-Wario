#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
	SDL_Window* window = NULL;

	SDL_Surface* screensurf = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)//check out what a subsystem is??
	{
		printf("SDL COULD NOT BE INITIALIZED! SDL_ERROR: %s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow("WARIO Primark", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("window Could not be created! SDL_ERROR: %s\n", SDL_GetError());
		}
		else
		{
			screensurf = SDL_GetWindowSurface(window);

			SDL_FillRect(screensurf, NULL, SDL_MapRGB(screensurf->format, 0xFF, 0xFF, 0xFF));//whats -> mean

			SDL_UpdateWindowSurface(window);//need to update after rendering...

			SDL_Delay(2000);
		}
	}
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}