#pragma once
#include <Game.h>
class GameObject
{
public:
	GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~GameObject() = default;

	void update();
	void render();

private:
	int xpos;
	int ypos;

	SDL_Texture* objtexture;
	SDL_Rect srcrect, destrect;
	SDL_Renderer* renderer;
};

