#pragma once
#include <filesystem>
#include <string>
#include <vector>
#include <SDL.h>
#include <unordered_map>


class Texture {

public:
	Texture(SDL_Texture* texture, std::string path);
	Texture();
	~Texture();

	int getwidth();
	int getheight();
	SDL_Texture* gettexture();

	std::string TexturePath;
private:
	SDL_Texture* cTexture;
	int width, height;
};

class TextureManager
{
public:

	TextureManager();
	~TextureManager();
	//Loads All given textures from a directory
	std::unordered_map<std::string, Texture> LoadTextures(std::string path);

	void free(Texture texture);//maybe pass in as a reference so i could also set the pointer to NULL at the same time??

	void render(Texture TextureToRender);

	std::unordered_map <std::string, Texture> TMap;
	Texture GetTextureFromMap(std::string keypath);
	
private:

};


