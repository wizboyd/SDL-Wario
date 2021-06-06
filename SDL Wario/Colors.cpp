#include <Image.h>

Ltexure::Ltexure() {
	//Initialize
	mtexture = NULL;
	width = 0;
	height = 0;
	spriteclips[4] = {};
	animateclips[2] = {};
}
Ltexure::~Ltexure() {
	//deallocate
	free();
}

bool Ltexure::loadfromfile(std::string path, SDL_Renderer* rednerer) {
	free();

	SDL_Texture* finaltexture = NULL;

	SDL_Surface* surface = IMG_Load(path.c_str());

	if (surface == NULL)
	{
		printf("unable to load Image %s! SDL IMG Error: %s\n", path.c_str(), IMG_GetError());
		return false;
	}
	else
	{
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 0xFF, 0xFF));

		finaltexture = SDL_CreateTextureFromSurface(rednerer, surface);

		if (finaltexture == NULL) {
			printf("Unable to create texture from surface! SDL Error: %s", SDL_GetError());
		}
		else
		{
			width = surface->w;// just accessing the w property of the surface object.
			height = surface->h;
		}

		SDL_FreeSurface(surface);
		mtexture = finaltexture;
		
		bool test = mtexture != NULL;
		return mtexture != NULL;


	}

}

void Ltexure::free() {
	if (mtexture != NULL)
	{
		SDL_DestroyTexture(mtexture);
		mtexture = NULL;
		width = 0;
		height = 0;
	}
}

void Ltexure::render(int x, int y, SDL_Renderer* renderer, double angle /* = 0.0 */, SDL_Rect* clip /* = NULL */, SDL_Point* center /* = NULL */, SDL_RendererFlip flip) {
	SDL_Rect renderquad = { x,y,width,height };

	if (clip != NULL)
	{
		renderquad.w = clip->w;
		renderquad.h = clip->h;
	}
	SDL_RenderCopyEx(renderer, mtexture, clip, &renderquad, angle, center, flip);
	
}

bool Ltexure::loadfromrenderedtext(std::string texturetext, SDL_Color textColor, TTF_Font* gfont, SDL_Renderer* renderer) {
	free();

	SDL_Surface* textsurface = TTF_RenderText_Solid(gfont, texturetext.c_str(), textColor);
	if (textsurface == NULL)
	{
		printf("Unable to render text to surface! SDL_TTF Error: %s", TTF_GetError());
	}
	else
	{
		mtexture = SDL_CreateTextureFromSurface(renderer, textsurface);
		if (mtexture == NULL)
		{
			printf("unable to create texture from the rendered text! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			width = textsurface->w;
			height = textsurface->h;
		}

		SDL_FreeSurface(textsurface);

		return mtexture != NULL;
	}
}

void Ltexure::setcolor(Uint8 red, Uint8 green, Uint8 blue) {
	SDL_SetTextureColorMod(mtexture, red, green, blue);
}

void Ltexure::setalpha(Uint8 aplha) {
	SDL_SetTextureAlphaMod(mtexture, aplha);
}

void Ltexure::setblendmode(SDL_BlendMode blending) {
	SDL_SetTextureBlendMode(mtexture, blending);
}

int Ltexure::getwidth() { return width; }
int Ltexure::getheight() { return height;}

