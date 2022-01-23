#include "cards/creatures/blacks/RoyalGhost.hpp"

RoyalGhost::RoyalGhost(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

RoyalGhost::~RoyalGhost() {}

std::string RoyalGhost::get_full_type() const
{
	return Creature::get_full_type() + " - Specter";
}

Card::Color RoyalGhost::get_color() const
{
	return Color::Black;
}

std::string RoyalGhost::get_name() const
{
	return "Royal Ghost";
}

std::vector<Creature::Capacity> RoyalGhost::get_capacities() const
{
	return
	{
		Capacity::FirstStrike
	};
}

std::string RoyalGhost::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost RoyalGhost::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Black, 1}
	};
}

int RoyalGhost::get_full_power() const
{
	return 3;
}

int RoyalGhost::get_full_toughness() const
{
	return 2;
}

Card* RoyalGhost::clone() const
{
	return new RoyalGhost(*this);
}
