#include <DataTypes.h>


void WarioPrimark::map::loadmap(std::string path, int sizex, int sizey, std::map<int, SDL_Texture *> texturemap)
{
	char tile;
	std::fstream mapfile;
	mapfile.open(path);

	for (int y = 0; y < sizey; y++) {
		for (int x = 0; x < sizex; x++)
		{
			mapfile.get(tile);
			std::string s(1, tile);
			Tile addtomap(s, texturemap.at(atoi(&tile)));
			mapTiles.push_back(addtomap);
			mapfile.ignore();
		}
	}


	mapfile.close();
}




//WarioPrimark::Tile::Tile(int tiletype, std::map<int, SDL_Texture*> texturemap)
//{
//	sprite = texturemap.at(tiletype);
//}