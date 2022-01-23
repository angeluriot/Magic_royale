#include "cards/creatures/generateds/Cannon.hpp"

Cannon::Cannon(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Cannon::~Cannon() {}

std::string Cannon::get_full_type() const
{
	return Creature::get_full_type() + " - Machine";
}

Card::Color Cannon::get_color() const
{
	return Color::White;
}

std::string Cannon::get_name() const
{
	return "Cannon";
}

std::vector<Creature::Capacity> Cannon::get_capacities() const
{
	return {};
}

std::string Cannon::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Cannon::get_cost() const
{
	return {};
}

int Cannon::get_full_power() const
{
	return 2;
}

int Cannon::get_full_toughness() const
{
	return 3;
}

Card* Cannon::clone() const
{
	return new Cannon(*this);
}
