#ifndef GAME_HPP
#define GAME_HPP

#include <array>
#include "players/Player.hpp"

class Game
{
private:

	static std::array<Player, 2> m_players;

public:

	static void start();
	static void create_decks();
	static void play();
};

#endif
