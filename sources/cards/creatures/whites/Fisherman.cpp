#include "cards/creatures/whites/Fisherman.hpp"

Fisherman::Fisherman(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Fisherman::~Fisherman() {}

std::string Fisherman::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color Fisherman::get_color() const
{
	return Color::White;
}

std::string Fisherman::get_name() const
{
	return "Fisherman";
}

std::vector<Creature::Capacity> Fisherman::get_capacities() const
{
	return
	{
		Capacity::FirstStrike
	};
}

std::string Fisherman::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Fisherman::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::White, 1 }
	};
}

int Fisherman::get_full_power() const
{
	return 2;
}

int Fisherman::get_full_toughness() const
{
	return 3;
}

Card* Fisherman::clone() const
{
	return new Fisherman(*this);
}
