#ifndef GAME_HPP
#define GAME_HPP

#include <array>
#include "players/Player.hpp"

class Game
{
public:

	static std::array<Player, 2> players;	// Players.
	static const int deck_size;				// The number of cards in a deck.
	static int turn;						// The current turn.

	/**
	 * @brief Resets the game.
	 */
	static void reset_game();

	/**
	 * @brief Starts the game.
	 */
	static void start();

	/**
	 * @brief Creates the decks.
	 */
	static void create_decks();

	/**
	 * @brief The main game loop.
	 */
	static void play();
};

#endif
