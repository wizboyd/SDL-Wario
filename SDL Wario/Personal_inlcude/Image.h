#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <tchar.h>
bool load_media(SDL_Surface* Keypresssurface[], SDL_Surface* gscreensurface);
bool load_media(SDL_Texture* Keypresssurface[], SDL_Texture* Texture, SDL_Renderer* renderer);
bool load_media();
void drawrectangle(int Xpos, int Ypos, int width, int height, int color, SDL_Renderer* renderer, bool fillin);
void setviewport(int Xpos, int Ypos, int width, int height, SDL_Renderer* renderer, SDL_Texture* texture);
SDL_Surface* LoadSurface(std::string path, SDL_Surface* surface);
SDL_Texture* loadtexture(std::string path, SDL_Renderer* renderer);// loads image as texture
