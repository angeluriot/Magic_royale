#include "cards/creatures/reds/Firecracker.hpp"

Firecracker::Firecracker(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Firecracker::~Firecracker() {}

std::string Firecracker::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color Firecracker::get_color() const
{
	return Color::Red;
}

std::string Firecracker::get_name() const
{
	return "Firecracker";
}

std::vector<Creature::Capacity> Firecracker::get_capacities() const
{
	return
	{
		Capacity::Reach,
		Capacity::MultiHit,
		Capacity::ZoneDamage
	};
}

std::string Firecracker::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Firecracker::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Red, 1}
	};
}

int Firecracker::get_full_power() const
{
	return 3;
}

int Firecracker::get_full_toughness() const
{
	return 2;
}

Card* Firecracker::clone() const
{
	return new Firecracker(*this);
}
