#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <map>

namespace WarioPrimark {

	// const int ValueFromTEXMAP(std::map<std::string, SDL_Texture*> texmap, std::string picturepath) {
	//	for (const auto& p : texmap)
	//	{
	//		if (p.first == picturepath)
	//		{
	//			int pathnumber = atoi(p.first.c_str());
	//			return pathnumber;//converts path to number ??
	//		}
	//	}
	//	return 0;
	//}

	enum BlockTypes {
		None,
		BRICK
	};

	class Vector2D {
	public:
		float X, Y;

		Vector2D(float x = 0, float y = 0) : X(x), Y(y) {};

		inline void Ones() {
			X = 1.0f;
			Y = 1.0f;
		}

		inline void Zero() {
			X = 0.0f;
			Y = 0.0f;
		}
	};

	class Tile
	{
	public:
		Tile(std::string tiletype, SDL_Texture* tex)
			:sprite(tex) {};
		~Tile() = default;

		SDL_Texture* sprite;
	private:
		SDL_Color Tint;
	};

	class map
	{
	public:
		map() = default;
		~map() = default;

		void loadmap(std::string path, int sizex, int sizey, std::map<int, SDL_Texture*> texturemap);
		//const int ValueFromTEXMAP(std::map<std::string, SDL_Texture*> texmap, std::string picturepath);
		BlockTypes btypes;
		std::vector<Tile> mapTiles;
	
	private:

	};

}
