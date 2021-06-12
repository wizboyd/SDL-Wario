#include <iostream>
#include <exception>
#include <SDL_main.h>
#include <Game.h>

 int main(int, char* []) {
	try
	{
		WarioPrimark::Game game;
		game.run();
		
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\n";
		return 1;
	}

	return 0;
}