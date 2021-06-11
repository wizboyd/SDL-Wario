#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include<stdio.h>
#include <string>
#include <vector>
#include <TextureManager.h>
#include <GameObject.h>
#include <ObjectManager.h>
#include <iostream>



class Game
{
public:
	Game();
	~Game();

	bool Initilize_game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleevents();
	void update();
	void render();
	void Clean();
	bool isrunning();
	
	static SDL_Renderer* rendererer;
	static ObjectManager objManager;
	static TextureManager TexManager;
private:
	bool running;
	SDL_Window* window;
	
	

};

