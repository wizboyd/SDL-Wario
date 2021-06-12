#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>
#include <map>
#include <SDL_Checkh.h>
class AssetManager
{
public:
	//AssetManager();
	AssetManager(SDL_Renderer* renderer, std::string Imagefolder);
	~AssetManager() = default;

	SDL_Texture* getTexture(int type);
	void LoadTexture(int id, std::string path);
	bool checkifvalueexists(std::map<int, SDL_Texture*> map, SDL_Texture* Tvalue);

	void clean();

	//inline static AssetManager& get() {
	//	if (s_instance == nullptr)
	//	{
	//		s_instance = new AssetManager();
	//	}
	//	return s_instance;
	//}

private:
	static AssetManager* s_instance;
	std::map<int, SDL_Texture*> textures;
	std::map<int, SDL_
	SDL_Renderer* renderer;

};


