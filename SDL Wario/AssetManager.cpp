
#include <AssetManager.h>
#include <iostream>
#include <filesystem>
#include <fstream>

AssetManager::AssetManager(SDL_Renderer* renderer, std::string resourcefolder) {
	WarioPrimark::check(TTF_Init());
	WarioPrimark::check(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG));
	AssetManager::renderer = renderer;
	int id_texture = 0;
	int id_music = 0;
	int id_music_chunks = 0;
	for (auto &file : std::filesystem::directory_iterator(resourcefolder))
	{
		//size_t i = file->path().string().rfind('.', file->path().string().length());
		if (file.path().extension() != ".png" && file.path().extension() != ".bmp" && file.path().extension() != ".jpg")
		{
			continue;
		}

		if (!checkifvalueexists(textures, getTexture(id_texture)))
		{
			LoadTexture(id_texture,file.path().string());
			id_texture++;
		}


	}

	//for (auto& file : std::filesystem::directory_iterator(resourcefolder))
	//{
	//	//size_t i = file->path().string().rfind('.', file->path().string().length());
	//	if (file.path().extension() != ".mp3")
	//	{
	//		continue;
	//	}

	//	if (!checkifvalueexists(Musics, getMusic(id_music)))
	//	{
	//		LoadMusic(id_music, file.path().string());
	//		id_music++;
	//	}


	//}

	//for (auto& file : std::filesystem::directory_iterator(resourcefolder))
	//{
	//	//size_t i = file->path().string().rfind('.', file->path().string().length());
	//	if (file.path().extension() != ".WAV")
	//	{
	//		continue;
	//	}

	//	if (!checkifvalueexists(Music_Chunks, getMusic_chunks(id_music_chunks)))
	//	{
	//		LoadMusic_chunk(id_music_chunks, file.path().string());
	//		id_music_chunks++;
	//	}


	//}


}

void AssetManager::LoadTexture(int id,std::string path) {
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

void AssetManager::LoadMusic(int id, std::string path) {
	if (Musics.count(id) <= 0) {
		Mix_Music* Music = Mix_LoadMUS(path.c_str());
		std::cout << Mix_GetError() << std::endl;
		if (Music)
		{
			Musics[id] = Music;
			std::cout << "Music [" << path << "] loaded!" << std::endl;
		}
		else
		{
			WarioPrimark::raise();
		}
	}
}

void AssetManager::LoadMusic_chunk(int id, std::string path) {
	if (Music_Chunks.count(id) <= 0) {
		Mix_Chunk* Music_chunk = Mix_LoadWAV(path.c_str());
		if (Music_chunk)
		{
			Music_Chunks[id] = Music_chunk;
			std::cout << "Music clip [" << path << "] loaded!" << std::endl;
		}
		else
		{
			WarioPrimark::raise();
		}
	}
}

//void AssetManager::createTiles(std::map<int, SDL_Texture*> texmap)
//{
//	WarioPrimark::Tile TileToAdd();//read map file and create tiles base on that
//}

template<typename T>
bool AssetManager::checkifvalueexists(std::map<int, T> map, T Tvalue)
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

void AssetManager::texture_store()
{
	for (auto const& x : textures)
	{
		switch (x.first)
		{
		default:
			break;
		case 1:
			break;
		}
	}
}

SDL_Texture* AssetManager::getTexture(int type) {
	return (textures.count(type) > 0) ? textures[type] : nullptr;
}

Mix_Chunk* AssetManager::getMusic_chunks(int id) {
	return(Music_Chunks.count(id) > 0) ? Music_Chunks[id]: nullptr;
}

Mix_Music* AssetManager::getMusic(int id) {
	return(Musics.count(id) > 0) ? Musics[id] : nullptr;
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
