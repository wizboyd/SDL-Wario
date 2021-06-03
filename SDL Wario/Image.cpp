
#include <stdio.h>
#include <Event.h>
#include <Image.h>


SDL_Surface* LoadSurface(std::string path, SDL_Surface* gscreensurface) {
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	SDL_Surface* optimizedsurface = NULL;
	if (loadedSurface == NULL)
	{
		printf("Could not load media %s! SDL ERROR: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		optimizedsurface = SDL_ConvertSurface(loadedSurface, gscreensurface->format, 0);
		if (optimizedsurface == NULL)
		{
			printf("Unable to optimize image %s! SDL ERROR: %s\n", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}
	loadedSurface = NULL;
	return optimizedsurface;
}

bool load_media(SDL_Surface* Keypresssurface[], SDL_Surface* surface) {
	bool success = true;

	Keypresssurface[ANY_KEY] = LoadSurface("Mario_staffordshire/Mario.png", surface);
	if (Keypresssurface == NULL)
	{
		printf("failed to load the default Image SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	//====================
	Keypresssurface[UP_ARROW] = LoadSurface("Mario_staffordshire/UP.bmp", surface);
	if (Keypresssurface == NULL)
	{
		printf("failed to load the up Image SDL Error: %s\n", SDL_GetError());
		success = false;
	}

	//=============================
	Keypresssurface[DOWN_ARROW] = LoadSurface("Mario_staffordshire/DOWN.bmp", surface);
	if (Keypresssurface == NULL)
	{
		printf("failed to load the Down Image SDL Error: %s\n", SDL_GetError());
		success = false;
	}

	//===========================================
	Keypresssurface[LEFT_ARROW] = LoadSurface("Mario_staffordshire/LEFT.bmp", surface);
	if (Keypresssurface == NULL)
	{
		printf("failed to load the left Image SDL Error: %s\n", SDL_GetError());
		success = false;
	}

	//========================================
	Keypresssurface[RIGHT_ARROW] = LoadSurface("Mario_staffordshire/Right.bmp", surface);
	if (Keypresssurface == NULL)
	{
		printf("failed to load the Right Image SDL Error: %s\n", SDL_GetError());
		success = false;
	}

	return success;
}
