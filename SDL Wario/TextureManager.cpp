#include <Game.h>

namespace fs = std::filesystem;
static int Total_Number_Of_Textures;

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{

}

std::unordered_map<std::string, Texture> TextureManager::LoadTextures(std::string path) {
	std::unordered_map<std::string, Texture> TMap;
	for (auto &entry : fs::directory_iterator(path.c_str()))
	{
		try
		{

			SDL_Surface* surface = IMG_Load(entry.path().string().c_str());
			SDL_Texture* passedtexture = SDL_CreateTextureFromSurface(Game::rendererer,surface);
			if (passedtexture == NULL)
			{
				throw 505;
			}
			SDL_FreeSurface(surface);
			surface = nullptr;
			Texture file(passedtexture, "");
			if (file.gettexture() == NULL)
			{
				throw 505;
			}
			printf("Loaded File %s\n", entry.path().string().c_str());
			Total_Number_Of_Textures++;
			TMap[entry.path().filename().string().c_str()] = file;
			
		}
		catch (...)
		{
			printf("%s was not a suitable file format for IMG loading\n", entry.path().string().c_str());
			continue;
		}


	}
	return TMap;
}


Texture TextureManager::GetTextureFromMap(std::string keypath)
{
	Texture toreturn;
	try
	{
		
		toreturn = TMap.at(keypath);
		return toreturn;
	}
	catch (...)
	{
		printf("Could not find texture");
		return toreturn;
	}
	
}

Texture::Texture(SDL_Texture* texture, std::string path)
	:TexturePath(path), cTexture(texture)
{
	width = 0;
	height = 0;
}

Texture::Texture()
{

}

Texture::~Texture()
{

}

int Texture::getwidth()
{
	return width;
}

int Texture::getheight()
{
	return height;
}

SDL_Texture* Texture::gettexture()
{
	return cTexture;
}
