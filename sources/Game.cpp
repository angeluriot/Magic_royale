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
		std::cout << yellow << "Player " << i + 1 << reset << ", what is your name?" << End(2);
		std::string name;
		getline(std::cin, name);
		std::cout << End(2);
		players[i].set_name(name);
	}
}

void Game::create_decks()
{
	PtrList<Card> deck_1;

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
	deck_1.add(LavaHound());
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
	while (true)
	{
		players[0].begin_turn();
		players[1].begin_turn();
	}
}
