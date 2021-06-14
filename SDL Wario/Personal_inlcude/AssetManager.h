#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>
#include <map>
#include <SDL_Checkh.h>
#include <vector>
#include <utility>
#include <DataTypes.h>
class AssetManager
{
public:
	//AssetManager();

	~AssetManager() = default;
	static AssetManager* get(SDL_Renderer* rend) {
		if (s_instance == NULL)
		{
			s_instance = new AssetManager(rend, "Mario_staffordshire");
		}
		return s_instance;
	}
	 std::map<int, SDL_Texture*> textures;
	 std::map<WarioPrimark::BlockTypes, std::pair<std::string, SDL_Texture*>> texture_storage;

	 void texture_store();

	SDL_Texture* getTexture(int type);
	void LoadTexture(int id, std::string path);

	Mix_Chunk* getMusic_chunks(int id);
	Mix_Music* getMusic(int id);
	
	void LoadMusic(int id, std::string path);
	void LoadMusic_chunk(int id, std::string path);

	//void createTiles(std::map<int, SDL_Texture*> texmap);

	template<typename T>
	bool checkifvalueexists(std::map<int, T> map, T Tvalue);

	void clean();

	/*inline static AssetManager* get() {
		if (s_instance == nullptr)
		{
			s_instance = new AssetManager(renderer, "Mario_staffordshire");
		}
		return s_instance;
	}*/
	SDL_Renderer* renderer;
private:
	static AssetManager* s_instance;
	std::map<int, Mix_Music*> Musics;
	std::map<int, Mix_Chunk*> Music_Chunks;
	AssetManager(SDL_Renderer* renderer, std::string resourcefolder);

};


