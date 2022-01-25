#include "cards/creatures/whites/Executioner.hpp"

Executioner::Executioner(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Executioner::~Executioner() {}

std::string Executioner::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color Executioner::get_color() const
{
	return Color::White;
}

std::string Executioner::get_name() const
{
	return "Executioner";
}

std::vector<Creature::Capacity> Executioner::get_capacities() const
{
	return
	{
		Capacity::MultiHit,
		Capacity::Reach
	};
}

std::string Executioner::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Executioner::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::White, 2}
	};
}

int Executioner::get_full_power() const
{
	return 3;
}

int Executioner::get_full_toughness() const
{
	return 4;
}

Card* Executioner::clone() const
{
	return new Executioner(*this);
}
