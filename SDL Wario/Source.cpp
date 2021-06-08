#include <Image.h>
#include <stdio.h>
#include <Event.h>
#include <iostream>
using namespace std;


bool Quit = false;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
int frame = 0;
double degrees = 0;

// sound
Mix_Music* underworldM = NULL;
Mix_Music* NESMUsic = NULL;
//=================


Ltexure spritesheet;
SDL_Event e; //EVENT DECLARATION

SDL_Texture* gTexture = NULL;

SDL_Renderer* grenderer = NULL;

SDL_Window* gwindow = NULL;//NA

TTF_Font* gfont = NULL;

//scene textures
Ltexure Ftexture;
Ltexure Backtexture;
Ltexure written;
Lbuttonsprite L;
L_Mouse_Button Mbuttons[BUTTON_SPRITE_TOTAL];

SDL_RendererFlip fliptype = SDL_FLIP_NONE;
//SDL_Surface* Mario = NULL;

SDL_Surface* Keypresssurface[TOTAL];
SDL_Texture* TexturepressSurface[TOTAL];

SDL_Texture* CurrentImageDispaly = NULL;


bool init() {

	//INIT FLag
	bool success = true;

	//INIT SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)//check out what a subsystem is??
	{
		printf("SDL COULD NOT BE INITIALIZED! SDL_ERROR: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gwindow = SDL_CreateWindow("WARIO Primark", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gwindow == NULL)
		{
			printf("window Could not be created! SDL_ERROR: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//create renderer
			grenderer = SDL_CreateRenderer(gwindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (grenderer == NULL)
			{
				printf("Renderer Could not be created! SDL Error %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(grenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL Image could not be INITIALIZED! SDL_ERROR: %s\n", IMG_GetError());
					success = false;
				}

				if (TTF_Init() == -1)
				{
					printf("SDL_TTF could not be Initialized! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,2048) < 0)
				{
					printf("SDL_MIXER could not be INITIALIZED SDL_MIXER ERROR: %s\n", Mix_GetError());
					success = false;
				}
				

			}
			
			
		}
	}
	return success;
}



void close()
{
	//SDL_FreeSurface(Mario);
	//Mario = NULL;

	Backtexture.free();
	Ftexture.free();
	written.free();

	Mix_FreeMusic(NESMUsic);
	Mix_FreeMusic(underworldM);
	NESMUsic = NULL;
	underworldM = NULL;

	SDL_DestroyTexture(gTexture);
	gTexture = NULL;
	gfont = NULL;

	SDL_DestroyWindow(gwindow);
	gwindow = NULL;
	SDL_DestroyRenderer(grenderer);
	grenderer = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}


int main(int argc, char* args[]) {

	if (!init())
	{
		printf("Failed to Initialize!\n");
	}
	else
	{
		if (!load_media(grenderer, Backtexture, "Mario_staffordshire/NES - Mario Bros - General Sprites.png"))
		{
			printf("Failed to load media!\n");
		}
		else if (!load_media(grenderer, Ftexture, "Mario_staffordshire/NPC1.png")) {
			printf("Failed to load media!\n");
		}
		else if (!load_media(grenderer, spritesheet, "Mario_staffordshire/NPC2.png"))
		{
			printf("Failed to load media!\n");
		}
		else if (!load_media(grenderer,gfont,"Mario_staffordshire/Pacifico.ttf",28, written))
		{
			printf("Failed to load media\n");
		}
		else if (!load_media(NESMUsic, "Mario_staffordshire/Mario.mp3"))
		{
			printf("Failed to load media\n");
		}
		else if(!load_media(underworldM, "Mario_staffordshire/MarioUnderworld.mp3"))
		{
			printf("Failed to load media\n");
		}
		else {
			CurrentImageDispaly = TexturepressSurface[ANY_KEY];
			//drawrectangle(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1, grenderer, false);
			int frame = 0;
			while (!Quit)
			{
				
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						Quit = true;
					}
					else if(e.type == SDL_KEYDOWN)
					{
						Mix_Music* currentplaying = NULL;
						switch (e.key.keysym.sym)
						{
						default:
							break;

						case  SDLK_1:
							Mix_PlayMusic( NESMUsic, 0);
							currentplaying = NESMUsic;
							break;
						case SDLK_2:
							Mix_PlayMusic(underworldM, 0);
							currentplaying = underworldM;
							break;
						case  SDLK_3:
							if (Mix_PlayingMusic() == 0)
							{
								Mix_PlayMusic(currentplaying, 0);
							}
							
							else
							{
								if (Mix_PausedMusic() == 1)
								{
									Mix_ResumeMusic();
								}
								else
								{
									Mix_PauseMusic();
								}
								
							}
							break;
						case SDLK_0:
							Mix_HaltMusic();
						}
					}

					for (int i = 0; i < BUTTON_SPRITE_TOTAL; i++)
					{
						Mbuttons[i].handleevent(&e);
					}
				}
				for (int i = 0; i < BUTTON_SPRITE_TOTAL; i++)
				{
					Mbuttons[i].render(Backtexture, grenderer);
					cout << to_string(Mbuttons[i].mCurrentSprite) << endl;
				}

				SDL_RenderPresent(grenderer);
			}

		}
	}

	close();

	return 0;
}