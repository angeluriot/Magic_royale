#include "Game.hpp"
#include "renderer/print.hpp"
#include "utils/PtrList.hpp"
#include "utils/utils.hpp"
#include "utils/files.hpp"
#include <filesystem>

std::array<Player, 2> Game::players = { Player(), Player() };
const int Game::deck_size = 30;
int Game::turn = 0;

void Game::reset_game()
{
	players[0].reset_player();
	players[1].reset_player();
}

void Game::start()
{
	for (int i = 0; i < 2; i++)
	{
		std::string name = input(to_str(bold) + to_str(magenta) + "Player " + to_str(i + 1) + to_str(reset) + " name:");
		name = remove_spaces(name);
		players[i].set_name(name == "" ? "Player " + to_str(i + 1) : name); // If the player did not choose a name, they will be named Player 1 or Player 2
	}

	// If both players choose the same name, player 2 will have a "(2)" next to their name
	if (players[0].get_name() == players[1].get_name())
		players[1].set_name(players[1].get_name() + " (2)");

	std::cout << End(1);
}

void Game::create_decks()
{
	if (!std::filesystem::exists("decks"))
		throw_error("No decks directory.");

	auto files = get_decks_name();
	std::vector<std::string> additional = { "- Refresh -", "- Quit -" };

	if (files.size() == 0)
		throw_error("No decks found.");

	for (auto& player : players)
	{
		std::cout << magenta << bold << player.get_name() << reset << ", which deck do you want to use?" << End(1);
		int res = choice(files, additional);

		// If player chooses "Refresh"
		if (res == (int)files.size())
		{
			create_decks();
			return;
		}

		// If player chooses "Quit"
		else if (res == (int)files.size() + 1)
		{
			quit_game();
			create_decks();
			return;
		}

		// If player chooses a deck
		else
		{
			auto cards = Card::get_cards_from_string(get_cards_from_deck(files[res]));
			player.create_deck(cards);
		}
	}
}

void Game::play()
{
	while (true)
	{
		std::cout << End(1) << yellow << bold << "--=( Turn " + to_str(++Game::turn) + " )=--" << End(2);

		for (auto& player : players)
		{
			if (player.is_alive())
			{
				if (player.get_opponent().is_alive())
					player.begin_turn();

				else
				{
					std::cout << magenta << bold << player.get_opponent().get_name() << reset << " has lost!" << End(1);
					std::cout << magenta << bold << player.get_name() << reset << " wins this game!" << End(2);
					return; // Stops the game if opponent loses
				}
			}

			else
			{
				std::cout << magenta << bold << player.get_name() << reset << " has lost!" << End(1);
				std::cout << magenta << bold << player.get_opponent().get_name() << reset << " wins this game!" << End(2);
				return; // Stops the game if active player loses
			}
		}
	}
}
