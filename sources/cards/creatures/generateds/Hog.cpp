#include "cards/creatures/generateds/Hog.hpp"

Hog::Hog(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Hog::~Hog() {}

std::string Hog::get_full_type() const
{
	return Creature::get_full_type() + " - Boar";
}

Card::Color Hog::get_color() const
{
	return Color::Green;
}

std::string Hog::get_name() const
{
	return "Hog";
}

std::vector<Creature::Capacity> Hog::get_capacities() const
{
	return
	{
		Capacity::Haste,
		Capacity::Unblockable
	};
}

std::string Hog::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Hog::get_cost() const
{
	return {};
}

int Hog::get_full_power() const
{
	return 2;
}

int Hog::get_full_toughness() const
{
	return 2;
}

Card* Hog::clone() const
{
	return new Hog(*this);
}
