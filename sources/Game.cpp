#include "Game.hpp"
#include "renderer/print.hpp"

std::array<Player, 2> Game::players;
int Game::turn = 0;

void Game::start()
{
	for (int i = 0; i < 2; i++)
	{
		std::cout << yellow << "Player " << i + 1 << reset << ", what is your name?" << End(2);
		std::string name;
		getline(std::cin, name);
		std::cout << End(2);
		players[i].set_name(name);
	}
}

void Game::create_decks()
{
	
}

void Game::play()
{
	
}
