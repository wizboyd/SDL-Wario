#include "GameObject.h"
#include <ObjectManager.h>
#include <Game.h>


GameObject::GameObject(Texture GameobjectTexture)
	:objtexture(GameobjectTexture)
{

	
}

GameObject::~GameObject()
{

}

void GameObject::update() {
	xpos = 0;
	ypos = 0;

	srcRect.h = 32;
	srcRect.h = 32;
	srcRect.h = 0;
	srcRect.h = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void GameObject::render() {

	SDL_RenderCopy(Game::rendererer, objtexture.gettexture(), &srcRect, &destRect);

}