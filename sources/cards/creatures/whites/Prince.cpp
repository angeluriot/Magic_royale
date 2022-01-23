#include "cards/creatures/whites/Prince.hpp"

Prince::Prince(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Prince::~Prince() {}

std::string Prince::get_full_type() const
{
	return Creature::get_full_type() + " - Knight";
}

Card::Color Prince::get_color() const
{
	return Color::White;
}

std::string Prince::get_name() const
{
	return "Prince";
}

std::vector<Creature::Capacity> Prince::get_capacities() const
{
	return
	{
		Capacity::FirstStrike,
		Capacity::Haste
	};
}

std::string Prince::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Prince::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::White, 2}
	};
}

int Prince::get_full_power() const
{
	return 4;
}

int Prince::get_full_toughness() const
{
	return 3;
}

Card* Prince::clone() const
{
	return new Prince(*this);
}
