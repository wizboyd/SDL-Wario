#include "AssetManager.h"
#include <iostream>
#include <filesystem>
#include <fstream>
AssetManager* AssetManager::s_instance = nullptr;

AssetManager::AssetManager(SDL_Renderer* renderer, std::string Imagefolder) {
	WarioPrimark::check(TTF_Init());
	WarioPrimark::check(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG));
	AssetManager::renderer = renderer;
	int id = 0;
	for (auto &file : std::filesystem::directory_iterator(Imagefolder))
	{
		//size_t i = file->path().string().rfind('.', file->path().string().length());
		if (file.path().extension() != ".png" && file.path().extension() != ".bmp" && file.path().extension() != ".jpg")
		{
			std::cout << file.path().extension() << std::endl;
			continue;
		}

		if (!checkifvalueexists(textures, getTexture(id)))
		{
			LoadTexture(id, file.path().string());
			id++;
		}


	}
}

void AssetManager::LoadTexture(int id, std::string path) {
	if (textures.count(id) <= 0)
	{
		SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());
		if (texture)
		{
			textures[id] = texture;
			std::cout << "Texture: [" << path << "] loaded!" << std::endl;
		}
		else
		{
			WarioPrimark::raise();// this shoudl not run the game if a texture is missing
		
		}
	}
}

bool AssetManager::checkifvalueexists(std::map<int, SDL_Texture*> map, SDL_Texture* Tvalue)
{
	bool valueexists = false;
	for (auto const& [key, value] : map) {
		if (Tvalue == value)
		{
			valueexists = true;
			break;
		}
	}
	return valueexists;
}

void AssetManager::clean()
{
	for (auto it = textures.begin(); it != textures.end(); it++)
	{
		SDL_DestroyTexture(it->second);
		textures.erase(it);
	}

	textures.clear();

	std::cout << "Assets Cleared" << std::endl;
}

SDL_Texture* AssetManager::getTexture(int type) {
	return (textures.count(type) > 0) ? textures[type] : nullptr;
}

//SDL_Texture* AssetManager::getTexture(int type)
//{
//	try
//	{
//		SDL_Texture* tex = textures.at(type);
//		return tex;
//	}
//	catch (const std::exception&)
//	{
//		std::cout << "texture not part of map\n" << std::endl;
//		return nullptr;
//	}
//}
