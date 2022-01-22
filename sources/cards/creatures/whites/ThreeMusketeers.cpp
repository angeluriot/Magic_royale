#include "cards/creatures/whites/ThreeMusketeers.hpp"
#include "players/Player.hpp"

ThreeMusketeers::ThreeMusketeers(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

ThreeMusketeers::~ThreeMusketeers() {}

std::string ThreeMusketeers::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color ThreeMusketeers::get_color() const
{
	return Color::White;
}

std::string ThreeMusketeers::get_name() const
{
	return "Three Musketeers";
}

std::vector<Creature::Capacity> ThreeMusketeers::get_capacities() const
{
	return
	{
		Capacity::Reach
	};
}

std::string ThreeMusketeers::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost ThreeMusketeers::get_cost() const
{
	return
	{
		{ Color::Colorless, 6 },
		{ Color::White, 3 }
	};
}

int ThreeMusketeers::get_full_power() const
{
	return 6;
}

int ThreeMusketeers::get_full_toughness() const
{
	return 5;
}

Card* ThreeMusketeers::clone() const
{
	return new ThreeMusketeers(*this);
}
