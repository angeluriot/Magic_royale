#include "cards/creatures/Barbarian.hpp"

Barbarian::Barbarian(): Creature(get_full_power(), get_full_toughness()) {}

std::string Barbarian::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color Barbarian::get_color() const
{
	return Color::White;
}

std::string Barbarian::get_name() const
{
	return "Barbarian";
}

std::string Barbarian::get_description() const
{
	return "";
}

Card::Cost Barbarian::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 },
		{ Color::White, 1 }
	};
}

int Barbarian::get_full_power() const
{
	return 2;
}

int Barbarian::get_full_toughness() const
{
	return 2;
}