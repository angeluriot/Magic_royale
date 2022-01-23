#include "cards/creatures/blacks/DarkPrince.hpp"

DarkPrince::DarkPrince(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

DarkPrince::~DarkPrince() {}

std::string DarkPrince::get_full_type() const
{
	return Creature::get_full_type() + " - Knight";
}

Card::Color DarkPrince::get_color() const
{
	return Color::Black;
}

std::string DarkPrince::get_name() const
{
	return "Dark Prince";
}

std::vector<Creature::Capacity> DarkPrince::get_capacities() const
{
	return
	{
		Capacity::Haste,
		Capacity::ZoneDamage,
		Capacity::Shield
	};
}

std::string DarkPrince::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost DarkPrince::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Black, 2 }
	};
}

int DarkPrince::get_full_power() const
{
	return 2;
}

int DarkPrince::get_full_toughness() const
{
	return 4;
}

Card* DarkPrince::clone() const
{
	return new DarkPrince(*this);
}
