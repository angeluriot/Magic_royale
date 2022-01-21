#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <map>
#include <vector>
#include "utils/PtrList.hpp"

class Player;

class Card
{
public:

	enum class Type
	{
		Creature,
		Land,
		Spell
	};

	enum class Color
	{
		Colorless,
		White,
		Blue,
		Black,
		Red,
		Green
	};

	typedef std::map<Card::Color, int> Cost;

protected:

	Player* m_owner;
	bool m_engaged;

public:

	Card();
	Card(const Card& other) = default;
	virtual ~Card();

	Card& operator=(const Card& other) = default;

	virtual Color get_color() const = 0;
	virtual Type get_type() const = 0;
	virtual std::string get_full_type() const = 0;
	virtual std::string get_name() const = 0;
	virtual std::string get_description() const = 0;
	virtual Cost get_cost() const = 0;
	virtual void set_owner(Player& player);
	virtual void engage();
	virtual void disengage();
	virtual bool is_engaged() const;
	virtual void reset();
	virtual void print() const;
	virtual Card* clone() const = 0;

	static PtrList<Card> get_cards_from_string(const std::vector<std::string>& cards_string);
	static PtrList<Card> all_cards;
};

#endif
