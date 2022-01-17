#include "cards/creatures/greens/RoyalGiant.hpp"

RoyalGiant::RoyalGiant(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

RoyalGiant::~RoyalGiant() {}

std::string RoyalGiant::get_full_type() const
{
	return Creature::get_full_type() + " - Giant";
}

Card::Color RoyalGiant::get_color() const
{
	return Color::Green;
}

std::string RoyalGiant::get_name() const
{
	return "Royal Giant";
}

std::vector<Creature::Capacity> RoyalGiant::get_capacities() const
{
	return
	{
		Capacity::Reach,
		Capacity::Unblockable
	};
}

std::string RoyalGiant::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost RoyalGiant::get_cost() const
{
	return
	{
		{ Color::Colorless, 4 },
		{ Color::Green, 2 }
	};
}

int RoyalGiant::get_full_power() const
{
	return 3;
}

int RoyalGiant::get_full_toughness() const
{
	return 5;
}

Card* RoyalGiant::clone() const
{
	return new RoyalGiant(*this);
}
