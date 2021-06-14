#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
class Game
{
public:
	Game() = default;
	~Game() = default;

	void INIT(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleevents();
	void update();
	void render();
	void clean();
	bool getrunning() { return isrunning; }


	const int FPS = 60;
	const int FrameDelay = 1000 / FPS;
	uint32_t framestart;
	int frametime;
private:
	bool isrunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* playetexture;
};

