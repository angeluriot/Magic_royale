#include "Game.hpp"
#include "renderer/Renderer.hpp"
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
	Renderer::clear();
	Renderer::print("                    _                               _\n"
		"  /\\/\\   __ _  __ _(_) ___    _ __ ___  _   _  __ _| | ___\n"
		" /    \\ / _` |/ _` | |/ __|  | '__/ _ \\| | | |/ _` | |/ _ \\\n"
		"/ /\\/\\ \\ (_| | (_| | | (__   | | | (_) | |_| | (_| | |  __/\n"
		"\\/    \\/\\__,_|\\__, |_|\\___|  |_|  \\___/ \\__, |\\__,_|_|\\___|\n"
		"              |___/                     |___/\n", Renderer::Color::Yellow, true);
	Renderer::new_lines(2);
	Renderer::print("---=([  Welcome to Magic Royale!  ])=---", Renderer::Color::Yellow, true);
	Renderer::new_lines();
}

void Game::create_decks()
{
	LavaHound lavaHound;
	Pekka pekka;
	IceWizard iceWizard;
	ElectroGiant electroGiant;
	Golem golem;
	RoyalGiant royalGiant;
	MegaKnight megaKnight;
	Forest forest1;
	Forest forest2;
	Island island1;
	Island island2;
	Plain plain1;
	Plain plain2;
	Swamp swamp1;
	Swamp swamp2;

	LavaHound lavaHound2;
	Pekka pekka2;
	IceWizard iceWizard2;
	ElectroGiant electroGiant2;
	Golem golem2;
	RoyalGiant royalGiant2;
	MegaKnight megaKnight2;
	Forest forest3;
	Forest forest4;
	Island island3;
	Island island4;
	Plain plain3;
	Plain plain4;
	Swamp swamp3;
	Swamp swamp4;

	PtrList<Card> deck;
	deck.add(lavaHound);
	deck.add(pekka);
	deck.add(iceWizard);
	deck.add(electroGiant);
	deck.add(golem);
	deck.add(royalGiant);
	deck.add(megaKnight);
	deck.add(forest1);
	deck.add(forest2);
	deck.add(island1);
	deck.add(island2);
	deck.add(plain1);
	deck.add(plain2);
	deck.add(swamp1);
	deck.add(swamp2);

	PtrList<Card> deck2;
	deck2.add(lavaHound2);
	deck2.add(pekka2);
	deck2.add(iceWizard2);
	deck2.add(electroGiant2);
	deck2.add(golem2);
	deck2.add(royalGiant2);
	deck2.add(megaKnight2);
	deck2.add(forest3);
	deck2.add(forest4);
	deck2.add(island3);
	deck2.add(island4);
	deck2.add(plain3);
	deck2.add(plain4);
	deck2.add(swamp3);
	deck2.add(swamp4);

	players[0].set_name("player_1");
	players[1].set_name("player_2");

	players[0].create_deck(deck);
	players[1].create_deck(deck2);
}

void Game::play()
{
	create_decks();

	players[0].begin_turn();

}
