#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
bool load_media(SDL_Surface* Keypresssurface[], SDL_Surface* gscreensurface);
bool load_media(SDL_Texture* Keypresssurface[], SDL_Texture* Texture, SDL_Renderer* renderer);
SDL_Surface* LoadSurface(std::string path, SDL_Surface* surface);
SDL_Texture* loadtexture(std::string path, SDL_Renderer* renderer);// loads image as texture
