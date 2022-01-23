#include "cards/creatures/generateds/Barbarian.hpp"

Barbarian::Barbarian(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Barbarian::~Barbarian() {}

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

std::vector<Creature::Capacity> Barbarian::get_capacities() const
{
	return {};
}

std::string Barbarian::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Barbarian::get_cost() const
{
	return {};
}

int Barbarian::get_full_power() const
{
	return 2;
}

int Barbarian::get_full_toughness() const
{
	return 2;
}

Card* Barbarian::clone() const
{
	return new Barbarian(*this);
}
