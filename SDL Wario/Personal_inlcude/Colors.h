#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
class Ltexure {
public:
	Ltexure();
	~Ltexure();

	bool loadfromfile(std::string path, SDL_Renderer* rednerer);

	void free();

	void render(int x, int y, SDL_Renderer* renderer);

	int getwidth();
	int getheight();

private:

	SDL_Texture* mtexture;

	int width;
	int height;
};
