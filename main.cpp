#include <iostream>
#include "Application.h"

int main()
{
	try {
		Application game;
		game.run();
	} catch (std::exception& e)
	{
		std::cout << std::endl << "EXCEPTION: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}