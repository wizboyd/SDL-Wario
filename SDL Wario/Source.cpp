#include <Image.h>
#include <stdio.h>
#include <Event.h>


bool Quit = false;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Event e; //EVENT DECLARATION

SDL_Window* gwindow = NULL;//NA

SDL_Surface* gscreensurface = NULL;//NA

//SDL_Surface* Mario = NULL;

SDL_Surface* Keypresssurface[TOTAL];

SDL_Surface* CurrentImageDispaly = NULL;


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
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL Image could not be INITIALIZED! SDL_ERROR: %s\n", IMG_GetError());
				success = false;
			}
			else
			{
				gscreensurface = SDL_GetWindowSurface(gwindow);
			}
			
		}
	}
	return success;
}



void close()
{
	//SDL_FreeSurface(Mario);
	//Mario = NULL;

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
		if (!load_media(Keypresssurface, gscreensurface))
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
						else if (e.type == SDL_KEYDOWN)// virtual key code
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

					SDL_Rect stretchrect;

					stretchrect.x = 0;
					stretchrect.y = 0;
					stretchrect.w = SCREEN_WIDTH;
					stretchrect.h = SCREEN_HEIGHT;

					SDL_BlitScaled(CurrentImageDispaly, NULL, gscreensurface, &stretchrect);

					SDL_UpdateWindowSurface(gwindow);
				}

		}
	}

	close();

	return 0;
}