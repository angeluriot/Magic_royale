#include "cards/creatures/blues/MegaMinion.hpp"

MegaMinion::MegaMinion(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

MegaMinion::~MegaMinion() {}

std::string MegaMinion::get_full_type() const
{
	return Creature::get_full_type() + " - Minion";
}

Card::Color MegaMinion::get_color() const
{
	return Color::Blue;
}

std::string MegaMinion::get_name() const
{
	return "Mega Minion";
}

std::vector<Creature::Capacity> MegaMinion::get_capacities() const
{
	return
	{
		Capacity::Flying,
		Capacity::Reach
	};
}

std::string MegaMinion::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost MegaMinion::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Blue, 1 }
	};
}

int MegaMinion::get_full_power() const
{
	return 2;
}

int MegaMinion::get_full_toughness() const
{
	return 3;
}

Card* MegaMinion::clone() const
{
	return new MegaMinion(*this);
}
