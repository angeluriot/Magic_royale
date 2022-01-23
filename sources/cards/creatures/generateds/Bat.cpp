#include "cards/creatures/generateds/Bat.hpp"

Bat::Bat(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Bat::~Bat() {}

std::string Bat::get_full_type() const
{
	return Creature::get_full_type() + " - Bat";
}

Card::Color Bat::get_color() const
{
	return Color::Black;
}

std::string Bat::get_name() const
{
	return "Bat";
}

std::vector<Creature::Capacity> Bat::get_capacities() const
{
	return
	{
		Capacity::Flying,
		Capacity::Reach
	};
}

std::string Bat::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Bat::get_cost() const
{
	return {};
}

int Bat::get_full_power() const
{
	return 1;
}

int Bat::get_full_toughness() const
{
	return 1;
}

Card* Bat::clone() const
{
	return new Bat(*this);
}
