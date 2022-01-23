#include "cards/creatures/generateds/Skeleton.hpp"

Skeleton::Skeleton(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Skeleton::~Skeleton() {}

std::string Skeleton::get_full_type() const
{
	return Creature::get_full_type() + " - Skeleton";
}

Card::Color Skeleton::get_color() const
{
	return Color::Black;
}

std::string Skeleton::get_name() const
{
	return "Skeleton";
}

std::vector<Creature::Capacity> Skeleton::get_capacities() const
{
	return {};
}

std::string Skeleton::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Skeleton::get_cost() const
{
	return {};
}

int Skeleton::get_full_power() const
{
	return 1;
}

int Skeleton::get_full_toughness() const
{
	return 1;
}

Card* Skeleton::clone() const
{
	return new Skeleton(*this);
}
