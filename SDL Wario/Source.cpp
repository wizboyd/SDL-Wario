#include <SDL.h>
#include <stdio.h>
#include <string>

enum KeyPresses
{
	ANY_KEY,
	UP_ARROW,
	DOWN_ARROW,
	LEFT_ARROW,
	RIGHT_ARROW,
	TOTAL
};

bool Quit = false;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Event e; //EVENT DECLARATION

SDL_Window* gwindow = NULL;//NA

SDL_Surface* gscreensurface = NULL;//NA

SDL_Surface* Mario = NULL;

SDL_Surface* Keypresssurface[TOTAL];

SDL_Surface* CurrentImageDispaly = NULL;

SDL_Surface* LoadSurface(std::string path){
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());

	if (loadedSurface == NULL)
	{
		printf("Could not load media %s! SDL ERROR: %s\n", path.c_str(), SDL_GetError());
	}
	return loadedSurface;
}

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

	Keypresssurface[ANY_KEY] = LoadSurface("Mario_staffordshire/test.bmp");
	if (Keypresssurface == NULL)
	{
		printf("failed to load the default Image SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	//====================
	Keypresssurface[UP_ARROW] = LoadSurface("Mario_staffordshire/UP.bmp");
	if (Keypresssurface == NULL)
	{
		printf("failed to load the up Image SDL Error: %s\n", SDL_GetError());
		success = false;
	}

	//=============================
	Keypresssurface[DOWN_ARROW] = LoadSurface("Mario_staffordshire/DOWN.bmp");
	if (Keypresssurface == NULL)
	{
		printf("failed to load the Down Image SDL Error: %s\n", SDL_GetError());
		success = false;
	}

	//===========================================
	Keypresssurface[LEFT_ARROW] = LoadSurface("Mario_staffordshire/LEFT.bmp");
	if (Keypresssurface == NULL)
	{
		printf("failed to load the left Image SDL Error: %s\n", SDL_GetError());
		success = false;
	}

	//========================================
	Keypresssurface[RIGHT_ARROW] = LoadSurface("Mario_staffordshire/Right.bmp");
	if (Keypresssurface == NULL)
	{
		printf("failed to load the Right Image SDL Error: %s\n", SDL_GetError());
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
			CurrentImageDispaly = Keypresssurface[ANY_KEY];
			while (!Quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						Quit = true;
					}
					else if(e.type == SDL_KEYDOWN)// virtual key code
					{
						switch (e.key.keysym.sym)
						{
						default:
							CurrentImageDispaly = Keypresssurface[ANY_KEY];
							break;

						case SDLK_UP:
							CurrentImageDispaly = Keypresssurface[UP_ARROW];
							break;

						case SDLK_DOWN:
							CurrentImageDispaly = Keypresssurface[DOWN_ARROW];
							break;

						case SDLK_RIGHT:
							CurrentImageDispaly = Keypresssurface[RIGHT_ARROW];
							break;

						case SDLK_LEFT:
							CurrentImageDispaly = Keypresssurface[LEFT_ARROW];
							break;
						}
					}
				}

				SDL_BlitSurface(CurrentImageDispaly, NULL, gscreensurface, NULL);

				SDL_UpdateWindowSurface(gwindow);
			}

		}
	}

	close();

	return 0;
}