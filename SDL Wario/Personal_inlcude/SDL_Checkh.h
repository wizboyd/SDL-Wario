#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdexcept>

namespace WarioPrimark {

	[[ noreturn ]] inline void raise() {
		const char* error = SDL_GetError();
		throw std::runtime_error{ error };
	}

	inline int check(const int code) {
		if (code < 0)
		{
			raise();
		};
		return code;
	}

}
