#include "cards/creatures/whites/Archers.hpp"

Archers::Archers(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Archers::~Archers() {}

std::string Archers::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color Archers::get_color() const
{
	return Color::White;
}

std::string Archers::get_name() const
{
	return "Archers";
}

std::vector<Creature::Capacity> Archers::get_capacities() const
{
	return
	{
		Capacity::Reach
	};
}

std::string Archers::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Archers::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::White, 1 }
	};
}

int Archers::get_full_power() const
{
	return 3;
}

int Archers::get_full_toughness() const
{
	return 2;
}

Card* Archers::clone() const
{
	return new Archers(*this);
}
