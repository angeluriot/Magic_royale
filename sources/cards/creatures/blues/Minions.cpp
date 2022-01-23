#include "cards/creatures/blues/Minions.hpp"

Minions::Minions(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Minions::~Minions() {}

std::string Minions::get_full_type() const
{
	return Creature::get_full_type() + " - Minion";
}

Card::Color Minions::get_color() const
{
	return Color::Blue;
}

std::string Minions::get_name() const
{
	return "Minions";
}

std::vector<Creature::Capacity> Minions::get_capacities() const
{
	return
	{
		Capacity::Flying,
		Capacity::Reach
	};
}

std::string Minions::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Minions::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Blue, 1 }
	};
}

int Minions::get_full_power() const
{
	return 3;
}

int Minions::get_full_toughness() const
{
	return 2;
}

Card* Minions::clone() const
{
	return new Minions(*this);
}
