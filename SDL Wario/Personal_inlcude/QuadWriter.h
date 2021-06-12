pragma once
#include <DataTypes.h>
#include <SDL_render.h>

namespace WarioPrimark {
	class QuadWriter
	{
	public:
		QuadWriter(SDL_Renderer*, SDL_Texture*);
		~QuadWriter();

		void tilepos(Vector2D, Vector2D, double = 0.0);

	private:
		SDL_Renderer* renderer;
		SDL_Texture* texture;
	};
}
