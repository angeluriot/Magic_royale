#include <iostream>
#include "Game.hpp"
#include "renderer/print.hpp"
#include "utils/utils.hpp"

int main()
{
	srand((unsigned int)time(NULL));
	clear_console();
	std::cout << yellow << bold <<
		"                     _                               _\n"
		"   /\\/\\   __ _  __ _(_) ___    _ __ ___  _   _  __ _| | ___\n"
		"  /    \\ / _` |/ _` | |/ __|  | '__/ _ \\| | | |/ _` | |/ _ \\\n"
		" / /\\/\\ \\ (_| | (_| | | (__   | | | (_) | |_| | (_| | |  __/\n"
		" \\/    \\/\\__,_|\\__, |_|\\___|  |_|  \\___/ \\__, |\\__,_|_|\\___|\n"
		"               |___/                     |___/\n" <<
		" ___________________________________________________________\n"
		"|___________________________________________________________|" << End(2);

	std::cout << End(1) << yellow << bold << "--=( Welcome to Magic Royale! )=--" << End(2);

	while (true)
	{
		std::cout << "What do you want to do?" << End(1);
		int res = choice({ "- Play -", "- Quit -" }, { green, red });

		// If player chooses "Play"
		if (res == 0)
		{
			Game::reset_game();
			Game::start();

			// Loop for choosing decks
			while (true)
			{
				try
				{
					Game::create_decks();
					break;
				}

				catch (const std::runtime_error& e)
				{
					std::cerr << e.what() << End(2);
				}
			}

			Game::play();
		}

		// If player chooses "Quit"
		else
		{
			quit_game();
			continue;
		}
	}

	return EXIT_SUCCESS;
}
