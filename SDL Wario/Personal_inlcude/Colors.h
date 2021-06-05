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

	int getwidth();
	int getheight();

private:

	SDL_Texture* mtexture;

	int width;
	int height;
};
