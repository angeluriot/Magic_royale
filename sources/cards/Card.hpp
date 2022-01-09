#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <map>

class Card
{
public:

	enum class Type
	{
		Creature,
		Land
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

	bool m_engaged;

public:

	Card();
	Card(const Card& other) = default;

	Card& operator=(const Card& other) = default;

	virtual Color get_color() const = 0;
	virtual Type get_type() const = 0;
	virtual std::string get_full_type() const = 0;
	virtual std::string get_name() const = 0;
	virtual std::string get_description() const = 0;
	virtual Cost get_cost() const = 0;
	virtual void engage();
	virtual void disengage();
	virtual bool is_engaged() const;
	virtual void reset();
	virtual void print() const;
};

#endif
