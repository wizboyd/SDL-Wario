#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdexcept>

[[noreturn]] inline void raise() {
	const char* error = SDL_GetError();
	throw std::runtime_error{ error }; // this will throw an error and stop the program
};

inline int check(const int code) {
	if (code < 0) {
		raise();
	}
	return code;
};

template <typename T>
inline T check_SDL_Component(T Component) {
	if (Component == NULL)
	{
		raise();
	}
	return Component;
};

