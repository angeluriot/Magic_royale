#include "Game.hpp"
#include "renderer/print.hpp"
#include "utils/PtrList.hpp"
#include "cards/creatures/blacks/LavaHound.hpp"
#include "cards/creatures/blacks/Pekka.hpp"
#include "cards/creatures/blues/IceWizard.hpp"
#include "cards/creatures/greens/ElectroGiant.hpp"
#include "cards/creatures/greens/Golem.hpp"
#include "cards/creatures/greens/RoyalGiant.hpp"
#include "cards/creatures/whites/MegaKnight.hpp"
#include "cards/lands/Forest.hpp"
#include "cards/lands/Island.hpp"
#include "cards/lands/Plain.hpp"
#include "cards/lands/Swamp.hpp"

Player player_1;
Player player_2;
std::array<Player, 2> Game::players = { player_1, player_2 };
int Game::turn = 0;

void Game::start()
{
	for (int i = 0; i < 2; i++)
	{
		std::string name = input(std::string(bold.data()) + std::string(yellow.data()) + "Player " +
			std::to_string(i + 1) + std::string(reset.data()) + " name: ");

		players[i].set_name(name == "" ? "Player " + std::to_string(i + 1) : name);
	}

	if (players[0].get_name() == players[1].get_name())
		players[1].set_name(players[1].get_name() + " (2)");

	std::cout << End(1);
}

void Game::create_decks()
{
	PtrList<Card> deck_1;

	deck_1.add(LavaHound());
	deck_1.add(Pekka());
	deck_1.add(IceWizard());
	deck_1.add(ElectroGiant());
	deck_1.add(Golem());
	deck_1.add(RoyalGiant());
	deck_1.add(MegaKnight());
	deck_1.add(Forest());
	deck_1.add(Forest());
	deck_1.add(Island());
	deck_1.add(Island());
	deck_1.add(Plain());
	deck_1.add(Plain());
	deck_1.add(Swamp());
	deck_1.add(Swamp());

	PtrList<Card> deck_2 = deck_1;

	players[0].set_name("player_1");
	players[1].set_name("player_2");

	players[0].create_deck(deck_1);
	players[1].create_deck(deck_2);
}

void Game::play()
{
	players[0].begin_turn();
}
