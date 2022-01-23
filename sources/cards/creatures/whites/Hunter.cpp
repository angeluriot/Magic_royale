#include "cards/creatures/whites/Hunter.hpp"

Hunter::Hunter(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Hunter::~Hunter() {}

std::string Hunter::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color Hunter::get_color() const
{
	return Color::White;
}

std::string Hunter::get_name() const
{
	return "Hunter";
}

std::vector<Creature::Capacity> Hunter::get_capacities() const
{
	return
	{
		Capacity::Reach,
		Capacity::ZoneDamage,
		Capacity::MultiHit
	};
}

std::string Hunter::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Hunter::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::White, 2 }
	};
}

int Hunter::get_full_power() const
{
	return 3;
}

int Hunter::get_full_toughness() const
{
	return 3;
}

Card* Hunter::clone() const
{
	return new Hunter(*this);
}
