
#include <stdio.h>
#include <Event.h>
#include <Image.h>

SDL_Surface* LoadSurface(std::string path) {
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());

	if (loadedSurface == NULL)
	{
		printf("Could not load media %s! SDL ERROR: %s\n", path.c_str(), SDL_GetError());
	}
	return loadedSurface;
}

bool load_media(SDL_Surface* Keypresssurface[]) {
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
