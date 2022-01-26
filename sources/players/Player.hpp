#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <map>
#include <stdlib.h>
#include <time.h>
#include "utils/PtrList.hpp"
#include "cards/Land.hpp"
#include "cards/Creature.hpp"

/**
 * @brief A class that represent a player.
 */
class Player
{
public:

	typedef std::map<Card::Color, int> Resources;

private:

	std::string m_name;				// The player name.
	int m_health;					// The player health.
	bool m_alive;					// The player alive state.
	bool m_freezed;					// Will be freezed on the next turn.
	bool m_freeze_capacity;			// The creatures will be freezed on the next turn.
	bool m_rage;					// The creatures will get rage on the next turn.

public:

	PtrList<Card> deck;				// The deck of the player.
	PtrList<Card> library;			// The library of the player.
	PtrList<Card> hand;				// The hand of the player.
	PtrList<Land> lands;			// The lands of the player.
	PtrList<Creature> creatures;	// The creatures of the player.
	PtrList<Card> graveyard;		// The graveyard of the player.

	/**
	 * @brief Construct a new Player object.
	 */
	Player();

	/**
	 * @brief Reset the player.
	 */
	void reset_player();

	/**
	 * @brief Tell if the player is alive.
	 *
	 * @return true if the player is alive
	 */
	bool is_alive();

	/**
	 * @brief Tell if the player can attack.
	 *
	 * @return true if the player can attack
	 */
	bool can_attack();

	/**
	 * @brief Freeze the player.
	 */
	void freeze();

	/**
	 * @brief Freeze the player's creatures.
	 */
	void freeze_capacity();

	/**
	 * @brief Give rage to the player's creatures.
	 */
	void rage();

	/**
	 * @brief Give the name of the player.
	 *
	 * @return the name of the player
	 */
	std::string get_name() const;

	/**
	 * @brief Set the name of the player.
	 *
	 * @param name the new name
	 */
	void set_name(const std::string& name);

	/**
	 * @brief Give the health of the player.
	 *
	 * @return the health of the player
	 */
	int get_health() const;

	/**
	 * @brief Set the health of the player.
	 *
	 * @param health the new health
	 */
	void set_health(int health);

	/**
	 * @brief Reduce the health of the player.
	 *
	 * @param amount the damages
	 */
	void reduce_health(int amount);

	/**
	 * @brief Give the land resources of the player.
	 *
	 * @return the land resources of the player
	 */
	Resources get_resources();

	/**
	 * @brief Remove a target from the creatures.
	 *
	 * @param target the target to remove
	 */
	void remove_target(const Creature& target);

	/**
	 * @brief Create the player deck.
	 *
	 * @param deck the deck to give to the player
	 */
	void create_deck(const PtrList<Card>& deck);

	/**
	 * @brief Play a card.
	 *
	 * @param card the card to play
	 */
	void play_card(const Card& card);

	/**
	 * @brief Tell if a card is playable.
	 *
	 * @param card the card to check
	 * @return true if the card is playable
	 */
	bool is_card_playable(const Card& card);

	/**
	 * @brief Engage the lands to play a card.
	 *
	 * @param card the card to play
	 * @return true if the card is playable
	 */
	bool engage_lands(const Card& card);

	/**
	 * @brief Print the board.
	 */
	void show_board();

	/**
	 * @brief Print the creatures.
	 */
	void show_creatures();

	/**
	 * @brief Clear flags and reset cards.
	 */
	void clear_before_turn();

	/**
	 * @brief Start the turn of the player.
	 */
	void begin_turn();

	/**
	 * @brief Draw a card.
	 */
	void draw_card();

	/**
	 * @brief Disengage the cards.
	 */
	void disengage_cards();

	/**
	 * @brief The main phase of the game.
	 */
	void main_phase();

	/**
	 * @brief The combat phase of the game.
	 */
	void combat_phase();

	/**
	 * @brief The end phase of the game.
	 */
	void block();

	/**
	 * @brief The secondary phase of the game.
	 */
	void secondary_phase();

	/**
	 * @brief End the turn of the player.
	 */
	void end_turn();

	/**
	 * @brief Get the opponent player.
	 *
	 * @return a reference to the opponent player
	 */
	Player& get_opponent() const;

	/**
	 * @brief Reset the creatures.
	 */
	void reset_creatures();

	/**
	 * @brief Call die() on all death creatures.
	 */
	void check_creatures_death();
};

#endif
