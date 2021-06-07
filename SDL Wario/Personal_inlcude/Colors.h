#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
class Ltexure {
public:
	Ltexure();
	~Ltexure();
	SDL_Rect spriteclips[4];
	bool loadfromfile(std::string path, SDL_Renderer* rednerer);
	const int WALKING_ANIMATION_FRAMES = 2;
	SDL_Rect animateclips[2];

	void free();

	void render(int x, int y, SDL_Renderer* renderer,double angle = 0.0, SDL_Rect* clip = NULL, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void setcolor(Uint8 red, Uint8 green, Uint8 blue);
	void setalpha(Uint8 aplha);
	void setblendmode(SDL_BlendMode blending);

	#if defined(SDL_TTF_MAJOR_VERSION)
	bool loadfromrenderedtext(std::string texturetext, SDL_Color textColor, TTF_Font* gfont, SDL_Renderer* renderer);
	#endif
	int getwidth();
	int getheight();

private:

	SDL_Texture* mtexture;

	int width;
	int height;
};
