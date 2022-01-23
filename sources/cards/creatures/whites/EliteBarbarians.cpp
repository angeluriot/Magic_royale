#include "cards/creatures/whites/EliteBarbarians.hpp"

EliteBarbarians::EliteBarbarians(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

EliteBarbarians::~EliteBarbarians() {}

std::string EliteBarbarians::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color EliteBarbarians::get_color() const
{
	return Color::White;
}

std::string EliteBarbarians::get_name() const
{
	return "Elite Barbarians";
}

std::vector<Creature::Capacity> EliteBarbarians::get_capacities() const
{
	return {};
}

std::string EliteBarbarians::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost EliteBarbarians::get_cost() const
{
	return
	{
		{ Color::Colorless, 4 },
		{ Color::White, 2 }
	};
}

int EliteBarbarians::get_full_power() const
{
	return 4;
}

int EliteBarbarians::get_full_toughness() const
{
	return 4;
}

Card* EliteBarbarians::clone() const
{
	return new EliteBarbarians(*this);
}
