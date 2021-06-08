#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <tchar.h>
#include <Colors.h>
#include <SDL_ttf.h>
#include <cmath>
#include <L_Mouse_Button.h>
#include <SDL_mixer.h>
bool load_media(SDL_Surface* Keypresssurface[], SDL_Surface* gscreensurface);
bool load_media(SDL_Texture* Keypresssurface[], SDL_Texture* Texture, SDL_Renderer* renderer);
bool load_media();
bool load_media(Mix_Music* &music, std::string path);
bool load_media(SDL_Renderer* renderer, Ltexure &texture, std::string path);
bool load_media(SDL_Renderer* renderer, TTF_Font* font, std::string path, int fontsize, Ltexure &texture);
void drawrectangle(int Xpos, int Ypos, int width, int height, int color, SDL_Renderer* renderer, bool fillin);
void setviewport(int Xpos, int Ypos, int width, int height, SDL_Renderer* renderer, SDL_Texture* texture);
SDL_Surface* LoadSurface(std::string path, SDL_Surface* surface);
SDL_Texture* loadtexture(std::string path, SDL_Renderer* renderer);// loads image as texture
