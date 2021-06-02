#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* gwindow = NULL;//NA

SDL_Surface* gscreensurface = NULL;//NA

SDL_Surface* Mario = NULL;

bool init() {
	//INIT FLag
	bool success = true;

	//INIT SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)//check out what a subsystem is??
	{
		printf("SDL COULD NOT BE INITIALIZED! SDL_ERROR: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gwindow = SDL_CreateWindow("WARIO Primark", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gwindow == NULL)
		{
			printf("window Could not be created! SDL_ERROR: %s\n", SDL_GetError());
		}
		else
		{
			gscreensurface = SDL_GetWindowSurface(gwindow);
		}
	}
	return success;
}

bool load_media() {
	bool success = true;

	Mario = SDL_LoadBMP("Mario_staffordshire/test.bmp");
	if (Mario == NULL)
	{
		printf("COuld not load Image! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

void close()
{
	SDL_FreeSurface(Mario);
	Mario = NULL;

	SDL_DestroyWindow(gwindow);
	gwindow = NULL;

	SDL_Quit();
}


int main(int argc, char* args[]) {

	if (!init())
	{
		printf("Failed to Initialize!\n");
	}
	else
	{
		if (!load_media())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			SDL_BlitSurface(Mario, NULL, gscreensurface, NULL);

			SDL_UpdateWindowSurface(gwindow);

			SDL_Delay(2000);
		}
	}

	close();

	return 0;
}