#include "cards/creatures/greens/RoyalHogs.hpp"

RoyalHogs::RoyalHogs(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

RoyalHogs::~RoyalHogs() {}

std::string RoyalHogs::get_full_type() const
{
	return Creature::get_full_type() + " - Boar";
}

Card::Color RoyalHogs::get_color() const
{
	return Color::Green;
}

std::string RoyalHogs::get_name() const
{
	return "Royal Hogs";
}

std::vector<Creature::Capacity> RoyalHogs::get_capacities() const
{
	return
	{
		Capacity::Haste,
		Capacity::Unblockable
	};
}

std::string RoyalHogs::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost RoyalHogs::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::Green, 2 }
	};
}

int RoyalHogs::get_full_power() const
{
	return 4;
}

int RoyalHogs::get_full_toughness() const
{
	return 3;
}

Card* RoyalHogs::clone() const
{
	return new RoyalHogs(*this);
}
