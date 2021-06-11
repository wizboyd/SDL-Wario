#pragma once
#include <SDL.h>
#include <TextureManager.h>
class GameObject
{
public:
	GameObject(Texture GameobjectTexture);
	~GameObject();

	void update();
	void render();

private:
	int xpos, ypos;

	Texture objtexture;
	SDL_Rect srcRect, destRect;

};

