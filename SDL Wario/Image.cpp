
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

bool load_media(SDL_Texture* Keypresssurface[], SDL_Texture* Texture, SDL_Renderer* renderer) {
	bool success = true;

	Keypresssurface[ANY_KEY] = loadtexture("Mario_staffordshire/Mario.png", renderer);
	if (Keypresssurface == NULL)
	{
		printf("failed to load the default Image SDL Error: %s\n", IMG_GetError());
		success = false;
	}
	//====================
	Keypresssurface[UP_ARROW] = loadtexture("Mario_staffordshire/UP.bmp", renderer);
	if (Keypresssurface == NULL)
	{
		printf("failed to load the up Image SDL Error: %s\n", IMG_GetError());
		success = false;
	}

	//=============================
	Keypresssurface[DOWN_ARROW] = loadtexture("Mario_staffordshire/DOWN.bmp", renderer);
	if (Keypresssurface == NULL)
	{
		printf("failed to load the Down Image SDL Error: %s\n", IMG_GetError());
		success = false;
	}

	//===========================================
	Keypresssurface[LEFT_ARROW] = loadtexture("Mario_staffordshire/LEFT.bmp", renderer);
	if (Keypresssurface == NULL)
	{
		printf("failed to load the left Image SDL Error: %s\n", IMG_GetError());
		success = false;
	}

	//========================================
	Keypresssurface[RIGHT_ARROW] = loadtexture("Mario_staffordshire/Right.bmp", renderer);
	if (Keypresssurface == NULL)
	{
		printf("failed to load the Right Image SDL Error: %s\n", IMG_GetError());
		success = false;
	}

	return success;
}

bool load_media() {
	bool success = true;

	return success;
}

bool load_media(SDL_Renderer* renderer, Ltexure &texture, std::string path) {
	bool success = true;
	if (!texture.loadfromfile(path.c_str(), renderer))
	{
		printf("Failed to load image from file %s SDL_IMG error!: %s\n", path.c_str(), IMG_GetError());
		success = false;
	}
	else
	{
		texture.setblendmode(SDL_BLENDMODE_BLEND);
		texture.animateclips[0].x = 0;
		texture.animateclips[0].y = 0;
		texture.animateclips[0].w = 32;
		texture.animateclips[0].h = 30;

		texture.animateclips[1].x = 0;
		texture.animateclips[1].y = 32;
		texture.animateclips[1].w = 32;
		texture.animateclips[1].h = 32;
		/*int increment = 0;
		for (int i = 0; i < 4; i++)
		{
			texture.spriteclips[i].x = 0 + increment;
			texture.spriteclips[i].y = 0 + increment;
			texture.spriteclips[i].w = 100;
			texture.spriteclips[i].h = 100;
			increment += 100;

		}*/
	}
	return success;

}

bool load_media(SDL_Renderer* renderer, TTF_Font* font, std::string path, int fontsize, Ltexure &texture) {
	bool success = true;
	
	font = TTF_OpenFont(path.c_str(), fontsize);
	if (font == NULL)
	{
		printf("Failed to load font! SDL_TTF error: %s\n", TTF_GetError());
	}
	else
	{
		SDL_Color textColor = { 0,255,0, 255 };
		if (!texture.loadfromrenderedtext("Gamersrus", textColor,font,renderer))
		{
			printf("Failed to render text texture\n");
			success = false;
		}
	}
	return success;
}

void drawrectangle(int Xpos, int Ypos, int width, int height, int color, SDL_Renderer* renderer, bool fillin) {
	SDL_Rect fillrect = { Xpos,Ypos,width / 4,height / 4 };
	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
	if (fillin == true)
	{
		SDL_RenderFillRect(renderer, &fillrect);
	}
	else
	{
		SDL_RenderDrawRect(renderer, &fillrect);
	}
	
	SDL_RenderPresent(renderer);
}

void setviewport(int Xpos, int Ypos, int width, int height, SDL_Renderer* renderer, SDL_Texture* texture) {

	SDL_Rect Viewport = { Xpos, Ypos, width, height };
	SDL_RenderSetViewport(renderer, &Viewport);
	if (texture != NULL)
	{
		SDL_RenderCopy(renderer, texture, NULL, NULL);
	}

}

SDL_Texture* loadtexture(std::string path, SDL_Renderer* renderer) {
	//final texture
	SDL_Texture* newtexture = NULL;

	SDL_Surface* Loadedsurface = IMG_Load(path.c_str());
	if (Loadedsurface == NULL)
	{
		printf("Could not load Surface! SDL_Image error!: %s\n", IMG_GetError());
	}
	else
	{
		//create texture from surface
		newtexture = SDL_CreateTextureFromSurface(renderer, Loadedsurface);
		if (newtexture == NULL) {
			printf("Texture could not be created from %s SDL ERROR!: %s", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(Loadedsurface);
	}
	return newtexture;
}