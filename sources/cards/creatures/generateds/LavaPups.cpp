#include "cards/creatures/generateds/LavaPups.hpp"

LavaPups::LavaPups(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

LavaPups::~LavaPups() {}

std::string LavaPups::get_full_type() const
{
	return Creature::get_full_type() + " - Lava Monster";
}

Card::Color LavaPups::get_color() const
{
	return Color::Red;
}

std::string LavaPups::get_name() const
{
	return "Lava Pups";
}

std::vector<Creature::Capacity> LavaPups::get_capacities() const
{
	return
	{
		Capacity::Flying,
		Capacity::Reach
	};
}

std::string LavaPups::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost LavaPups::get_cost() const
{
	return {};
}

int LavaPups::get_full_power() const
{
	return 3;
}

int LavaPups::get_full_toughness() const
{
	return 1;
}

Card* LavaPups::clone() const
{
	return new LavaPups(*this);
}
