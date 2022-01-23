#include "cards/creatures/blacks/Bats.hpp"

Bats::Bats(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Bats::~Bats() {}

std::string Bats::get_full_type() const
{
	return Creature::get_full_type() + " - Bat";
}

Card::Color Bats::get_color() const
{
	return Color::Black;
}

std::string Bats::get_name() const
{
	return "Bats";
}

std::vector<Creature::Capacity> Bats::get_capacities() const
{
	return
	{
		Capacity::Flying,
		Capacity::Reach
	};
}

std::string Bats::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Bats::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 },
		{ Color::Black, 1 }
	};
}

int Bats::get_full_power() const
{
	return 3;
}

int Bats::get_full_toughness() const
{
	return 1;
}

Card* Bats::clone() const
{
	return new Bats(*this);
}
