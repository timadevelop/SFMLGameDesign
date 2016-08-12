#include <iostream>
#include "Game.h"
int main()
{
	try {
		Game game;
		game.run();
	} catch (std::exception& e)
	{
		std::cout << std::endl << "EXCEPTION: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}