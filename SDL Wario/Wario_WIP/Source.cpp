#include <SDL.h>
#include <Game.h>

Game *game = nullptr;

int main(int argc, char* argv[]) {

	game = new Game();
	game->Initilize_game("Wario_Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, false);
	while (game->isrunning())
	{
		game->handleevents();
		//game->update();
		game->render();
	}
	game->Clean();
	return 0;
}

//whats the auto keyword?? suposedly I can put this keyword in front of a varible when INitilizing it to infer its type instead of explicitly stating its type...
//whats the using key word?? https://www.youtube.com/watch?v=YliqZh6s9ig
// whats a template??? https://www.youtube.com/watch?v=I-hZkUa9mIs&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=53