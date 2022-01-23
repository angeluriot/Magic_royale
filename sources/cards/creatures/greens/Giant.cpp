#include "cards/creatures/greens/Giant.hpp"

Giant::Giant(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Giant::~Giant() {}

std::string Giant::get_full_type() const
{
	return Creature::get_full_type() + " - Giant";
}

Card::Color Giant::get_color() const
{
	return Color::Green;
}

std::string Giant::get_name() const
{
	return "Giant";
}

std::vector<Creature::Capacity> Giant::get_capacities() const
{
	return
	{
		Capacity::Unblockable
	};
}

std::string Giant::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Giant::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::Green, 2 }
	};
}

int Giant::get_full_power() const
{
	return 2;
}

int Giant::get_full_toughness() const
{
	return 5;
}

Card* Giant::clone() const
{
	return new Giant(*this);
}
