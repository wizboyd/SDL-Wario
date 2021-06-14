#include <GameObject.h>
#include <TextureManager.h>

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{
	renderer = ren;
	objtexture = TextureManager::LoadTexture(texturesheet, ren);
	xpos = x;
	ypos = y;
}

void GameObject::update()
{

	xpos++;
	ypos++;
	srcrect.h = 32;
	srcrect.w = 32;
	srcrect.x = 0;
	srcrect.y = 0;

	destrect.x = xpos;
	destrect.y = ypos;
	destrect.w = 32;
	destrect.h = 32;
}

void GameObject::render()
{
	SDL_RenderCopy(renderer, objtexture, &srcrect, &destrect);
}

