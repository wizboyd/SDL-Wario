#include <Components.h>
#include <iostream>

void WarioPrimark::TilemapRenderer::DrawTileMap(map Map)
{
	SDL_RenderClear(mapRenderer);
	for (int i = 0; i < Map.mapTiles.size(); i++)
	{
		std::cout << Map.mapTiles.at(i).sprite << std::endl;
		SDL_RenderCopy(mapRenderer, Map.mapTiles.at(i).sprite, NULL, NULL); //will change soon
	}
	SDL_RenderPresent(mapRenderer);
}
