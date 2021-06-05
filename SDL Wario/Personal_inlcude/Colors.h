#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
class Ltexure {
public:
	Ltexure();
	~Ltexure();
	SDL_Rect spriteclips[4];
	bool loadfromfile(std::string path, SDL_Renderer* rednerer);

	void free();

	void render(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip = NULL);
	void setcolor(Uint8 red, Uint8 green, Uint8 blue);
	void setalpha(Uint8 aplha);
	void setblendmode(SDL_BlendMode blending);
	int getwidth();
	int getheight();

private:

	SDL_Texture* mtexture;

	int width;
	int height;
};
