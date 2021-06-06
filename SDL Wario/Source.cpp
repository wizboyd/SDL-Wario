#include <Image.h>
#include <stdio.h>
#include <Event.h>
#include <iostream>


bool Quit = false;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
int frame = 0;
double degrees = 0;


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

SDL_RendererFlip fliptype = SDL_FLIP_NONE;
//SDL_Surface* Mario = NULL;

SDL_Surface* Keypresssurface[TOTAL];
SDL_Texture* TexturepressSurface[TOTAL];

SDL_Texture* CurrentImageDispaly = NULL;


bool init() {

	//INIT FLag
	bool success = true;

	//INIT SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)//check out what a subsystem is??
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
		else {
			CurrentImageDispaly = TexturepressSurface[ANY_KEY];
			//drawrectangle(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1, grenderer, false);
			while (!Quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						Quit = true;
					}
					else if (e.type == SDL_KEYDOWN)// virtual key code
					{
						switch (e.key.keysym.sym)
						{
						default:
							CurrentImageDispaly = TexturepressSurface[ANY_KEY];
							break;

						case SDLK_UP:
							CurrentImageDispaly = TexturepressSurface[UP_ARROW];
							degrees -= 60;
							break;

						case SDLK_DOWN:
							CurrentImageDispaly = TexturepressSurface[DOWN_ARROW];
							degrees += 60;
							break;

						case SDLK_RIGHT:
							CurrentImageDispaly = TexturepressSurface[RIGHT_ARROW];
							fliptype = SDL_FLIP_HORIZONTAL;
							break;

						case SDLK_LEFT:
							CurrentImageDispaly = TexturepressSurface[LEFT_ARROW];
							fliptype = SDL_FLIP_VERTICAL;
							break;
						}
					}
				}

				/*SDL_Rect stretchrect;

				stretchrect.x = 0;
				stretchrect.y = 0;
				stretchrect.w = SCREEN_WIDTH;
				stretchrect.h = SCREEN_HEIGHT;

				SDL_RenderClear(grenderer);

				SDL_RenderCopy(grenderer, CurrentImageDispaly, NULL, NULL);

				SDL_RenderPresent(grenderer);*/
				SDL_SetRenderDrawColor(grenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(grenderer);

				SDL_Rect* currentclip = &spritesheet.animateclips[frame / 8];
				int test = frame / 8;
				int test2 = sizeof(spritesheet.animateclips);
				spritesheet.render((SCREEN_WIDTH - currentclip->w) / 2, (SCREEN_HEIGHT - currentclip->h) / 2, grenderer, degrees, currentclip, NULL, fliptype);

				written.render(50, 50, grenderer, NULL, NULL, NULL, fliptype);

				/*Backtexture.setcolor(red, green, blue);
				Backtexture.setalpha(alpha);
				Backtexture.render(0, 0, grenderer, &Backtexture.spriteclips[0]);
				Backtexture.render(SCREEN_WIDTH - Backtexture.spriteclips[1].w, 0, grenderer, &Backtexture.spriteclips[1]);
				Backtexture.render(0,SCREEN_HEIGHT - Backtexture.spriteclips[2].h, grenderer, &Backtexture.spriteclips[2]);
				Backtexture.render(SCREEN_WIDTH - Backtexture.spriteclips[3].w, SCREEN_HEIGHT - Backtexture.spriteclips[3].y, grenderer, &Backtexture.spriteclips[3]);*/
				SDL_RenderPresent(grenderer);
				frame++;
				if ((frame / 8) >= sizeof(spritesheet.animateclips)/sizeof(spritesheet.animateclips[0]))
				{
					frame = 0;
				}
			}

		}
	}

	close();

	return 0;
}