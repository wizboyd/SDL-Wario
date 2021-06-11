#pragma once
#include <TextureManager.h>
#include <SDL.h>
class Tile
{
public:

	Tile(Texture texture, int SrcX, int SrcY, int xpos, int ypos);
	~Tile();

private:
	Texture TileTexture;
	SDL_Rect srcRect, destrect;

};

