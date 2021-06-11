#include "Tile.h"

Tile::Tile(Texture texture, int SrcX, int SrcY, int xpos, int ypos)
	:TileTexture(texture)
{

	srcRect.x = SrcX;
	srcRect.y = SrcY;

	srcRect.w = srcRect.h = 32;

	destrect.x = xpos;
	destrect.y = ypos;
	destrect.w = destrect.h = 32;
}