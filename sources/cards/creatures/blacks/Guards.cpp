#include "cards/creatures/blacks/Guards.hpp"

Guards::Guards(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Guards::~Guards() {}

std::string Guards::get_full_type() const
{
	return Creature::get_full_type() + " - Skeleton";
}

Card::Color Guards::get_color() const
{
	return Color::Black;
}

std::string Guards::get_name() const
{
	return "Guards";
}

std::vector<Creature::Capacity> Guards::get_capacities() const
{
	return
	{
		Capacity::Shield
	};
}

std::string Guards::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Guards::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Black, 1 }
	};
}

int Guards::get_full_power() const
{
	return 2;
}

int Guards::get_full_toughness() const
{
	return 3;
}

Card* Guards::clone() const
{
	return new Guards(*this);
}
