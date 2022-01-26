#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <map>
#include <vector>
#include "utils/PtrList.hpp"

class Player;

/**
 * @brief A class that represent a card.
 */
class Card
{
public:

	/**
	 * @brief An enum that represent the card type.
	 */
	enum class Type
	{
		Creature,	// Creature card.
		Land,		// Land card.
		Spell		// Spell card.
	};

	/**
	 * @brief An enum that represent the color of a card.
	 */
	enum class Color
	{
		Colorless,	// Not a specific color.
		White,		// White color.
		Blue,		// Blue color.
		Black,		// Black color.
		Red,		// Red color.
		Green		// Green color.
	};

	typedef std::map<Card::Color, int> Cost;

protected:

	Player* m_owner;	// The owner of the card.
	bool m_engaged;		// The engaged state of the card.

public:

	/**
	 * @brief Construct a new Card object.
	 */
	Card();

	/**
	 * @brief Construct a new Card object.
	 *
	 * @param other the card to copy
	 */
	Card(const Card& other) = default;

	/**
	 * @brief Destroy the Card object.
	 */
	virtual ~Card();

	/**
	 * @brief Operator =.
	 *
	 * @param other the card to copy
	 * @return a reference to the modified card
	 */
	Card& operator=(const Card& other) = default;

	/**
	 * @brief Give the color of the card.
	 *
	 * @return the color of the card
	 */
	virtual Color get_color() const = 0;

	/**
	 * @brief Give the type of the card.
	 *
	 * @return the type of the card
	 */
	virtual Type get_type() const = 0;

	/**
	 * @brief Give the full type of the card.
	 *
	 * @return the full type of the card
	 */
	virtual std::string get_full_type() const = 0;

	/**
	 * @brief Give the name of the card.
	 *
	 * @return the name of the card
	 */
	virtual std::string get_name() const = 0;

	/**
	 * @brief Give the description of the card.
	 *
	 * @return the description of the card
	 */
	virtual std::string get_description() const = 0;

	/**
	 * @brief Give the cost of the card.
	 *
	 * @return the cost of the card
	 */
	virtual Cost get_cost() const = 0;

	/**
	 * @brief Set the owner of the card.
	 *
	 * @param player the new owner of the card
	 */
	virtual void set_owner(Player& player);

	/**
	 * @brief Engage the card.
	 */
	virtual void engage();

	/**
	 * @brief Disengage the card.
	 */
	virtual void disengage();

	/**
	 * @brief Tell if the card is engaged.
	 *
	 * @return true if the card is engaged
	 */
	virtual bool is_engaged() const;

	/**
	 * @brief Reset the card.
	 */
	virtual void reset();

	/**
	 * @brief Print the card.
	 */
	virtual void print() const;

	/**
	 * @brief Clone the card.
	 *
	 * @return a pointer to the cloned card
	 */
	virtual Card* clone() const = 0;

	/**
	 * @brief Give the cards from the card names.
	 *
	 * @param cards_string the list of card names
	 * @return the list of cards
	 */
	static PtrList<Card> get_cards_from_string(const std::vector<std::string>& cards_string);

	/**
	 * @brief All the cards of the game.
	 */
	static PtrList<Card> all_cards;
};

#endif
