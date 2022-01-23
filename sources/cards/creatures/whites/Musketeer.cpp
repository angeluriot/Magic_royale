#include "cards/creatures/whites/Musketeer.hpp"

Musketeer::Musketeer(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Musketeer::~Musketeer() {}

std::string Musketeer::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color Musketeer::get_color() const
{
	return Color::White;
}

std::string Musketeer::get_name() const
{
	return "Musketeer";
}

std::vector<Creature::Capacity> Musketeer::get_capacities() const
{
	return
	{
		Capacity::Reach
	};
}

std::string Musketeer::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Musketeer::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::White, 2 }
	};
}

int Musketeer::get_full_power() const
{
	return 3;
}

int Musketeer::get_full_toughness() const
{
	return 3;
}

Card* Musketeer::clone() const
{
	return new Musketeer(*this);
}
