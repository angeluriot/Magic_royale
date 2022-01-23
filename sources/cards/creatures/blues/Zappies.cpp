#include "cards/creatures/blues/Zappies.hpp"

Zappies::Zappies(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Zappies::~Zappies() {}

std::string Zappies::get_full_type() const
{
	return Creature::get_full_type() + " - Machine";
}

Card::Color Zappies::get_color() const
{
	return Color::Blue;
}

std::string Zappies::get_name() const
{
	return "Zappies";
}

std::vector<Creature::Capacity> Zappies::get_capacities() const
{
	return
	{
		Capacity::Reach,
		Capacity::Freeze
	};
}

std::string Zappies::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Zappies::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::Blue, 1 }
	};
}

int Zappies::get_full_power() const
{
	return 3;
}

int Zappies::get_full_toughness() const
{
	return 3;
}

Card* Zappies::clone() const
{
	return new Zappies(*this);
}
