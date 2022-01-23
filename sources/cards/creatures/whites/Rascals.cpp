#include "cards/creatures/whites/Rascals.hpp"

Rascals::Rascals(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Rascals::~Rascals() {}

std::string Rascals::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color Rascals::get_color() const
{
	return Color::White;
}

std::string Rascals::get_name() const
{
	return "Rascals";
}

std::vector<Creature::Capacity> Rascals::get_capacities() const
{
	return
	{
		Capacity::Reach
	};
}

std::string Rascals::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Rascals::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::White, 2}
	};
}

int Rascals::get_full_power() const
{
	return 3;
}

int Rascals::get_full_toughness() const
{
	return 4;
}

Card* Rascals::clone() const
{
	return new Rascals(*this);
}
