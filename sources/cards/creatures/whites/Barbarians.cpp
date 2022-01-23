#include "cards/creatures/whites/Barbarians.hpp"

Barbarians::Barbarians(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Barbarians::~Barbarians() {}

std::string Barbarians::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color Barbarians::get_color() const
{
	return Color::White;
}

std::string Barbarians::get_name() const
{
	return "Barbarians";
}

std::vector<Creature::Capacity> Barbarians::get_capacities() const
{
	return {};
}

std::string Barbarians::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Barbarians::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::White, 2 }
	};
}

int Barbarians::get_full_power() const
{
	return 4;
}

int Barbarians::get_full_toughness() const
{
	return 3;
}

Card* Barbarians::clone() const
{
	return new Barbarians(*this);
}
