#include "cards/creatures/blacks/Bomber.hpp"

Bomber::Bomber(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Bomber::~Bomber() {}

std::string Bomber::get_full_type() const
{
	return Creature::get_full_type() + " - Skeleton";
}

Card::Color Bomber::get_color() const
{
	return Color::Black;
}

std::string Bomber::get_name() const
{
	return "Bomber";
}

std::vector<Creature::Capacity> Bomber::get_capacities() const
{
	return
	{
		Capacity::ZoneDamage
	};
}

std::string Bomber::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Bomber::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 },
		{ Color::Black, 1 }
	};
}

int Bomber::get_full_power() const
{
	return 3;
}

int Bomber::get_full_toughness() const
{
	return 1;
}

Card* Bomber::clone() const
{
	return new Bomber(*this);
}
