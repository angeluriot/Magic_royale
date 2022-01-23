#include "cards/creatures/blues/Sparky.hpp"

Sparky::Sparky(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Sparky::~Sparky() {}

std::string Sparky::get_full_type() const
{
	return Creature::get_full_type() + " - Machine";
}

Card::Color Sparky::get_color() const
{
	return Color::Blue;
}

std::string Sparky::get_name() const
{
	return "Sparky";
}

std::vector<Creature::Capacity> Sparky::get_capacities() const
{
	return
	{
		Capacity::ZoneDamage
	};
}

std::string Sparky::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Sparky::get_cost() const
{
	return
	{
		{ Color::Colorless, 5 },
		{ Color::Blue, 1 }
	};
}

int Sparky::get_full_power() const
{
	return 5;
}

int Sparky::get_full_toughness() const
{
	return 3;
}

Card* Sparky::clone() const
{
	return new Sparky(*this);
}
