#include "cards/creatures/whites/Princess.hpp"

Princess::Princess(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Princess::~Princess() {}

std::string Princess::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color Princess::get_color() const
{
	return Color::White;
}

std::string Princess::get_name() const
{
	return "Princess";
}

std::vector<Creature::Capacity> Princess::get_capacities() const
{
	return
	{
		Capacity::Reach,
		Capacity::ZoneDamage
	};
}

std::string Princess::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Princess::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::White, 1 }
	};
}

int Princess::get_full_power() const
{
	return 3;
}

int Princess::get_full_toughness() const
{
	return 2;
}

Card* Princess::clone() const
{
	return new Princess(*this);
}
