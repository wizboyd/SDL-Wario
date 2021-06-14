#include <iostream>
#include <Utilty.h>
#include <Game.h>

Game *game = nullptr;

int main(int argc, char* argv[]) {
	try
	{
		game = new Game();
		game->INIT("wario Primark", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
		while (game->getrunning())
		{
			game->framestart = SDL_GetTicks();
			game->handleevents();
			game->update();
			game->render();
			game->frametime = SDL_GetTicks() - game->framestart;

			if (game->FrameDelay > game->frametime)
			{
				SDL_Delay(game->FrameDelay - game->frametime);
			}
		}

		game->clean();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
		return 1;
	}

	return 0;
}