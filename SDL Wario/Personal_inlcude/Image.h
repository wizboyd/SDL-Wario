#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
bool load_media(SDL_Surface* Keypresssurface[], SDL_Surface* gscreensurface);
SDL_Surface* LoadSurface(std::string path, SDL_Surface* surface);
