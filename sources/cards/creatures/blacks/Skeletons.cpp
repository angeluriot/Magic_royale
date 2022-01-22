#include "cards/creatures/blacks/Skeletons.hpp"

Skeletons::Skeletons(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Skeletons::~Skeletons() {}

std::string Skeletons::get_full_type() const
{
	return Creature::get_full_type() + " - Skeleton";
}

Card::Color Skeletons::get_color() const
{
	return Color::Black;
}

std::string Skeletons::get_name() const
{
	return "Skeletons";
}

std::vector<Creature::Capacity> Skeletons::get_capacities() const
{
	return {};
}

std::string Skeletons::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Skeletons::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 }
	};
}

int Skeletons::get_full_power() const
{
	return 2;
}

int Skeletons::get_full_toughness() const
{
	return 1;
}

Card* Skeletons::clone() const
{
	return new Skeletons(*this);
}
