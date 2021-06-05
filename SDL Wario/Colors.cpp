#include <Image.h>

Ltexure::Ltexure() {
	//Initialize
	mtexture = NULL;
	width = 0;
	height = 0;
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

void Ltexure::render(int x, int y, SDL_Renderer* renderer) {
	SDL_Rect renderquad = { x,y,width,height };
	SDL_RenderCopy(renderer, mtexture, NULL, &renderquad);
}

int Ltexure::getwidth() { return width; }
int Ltexure::getheight() { return height;}

