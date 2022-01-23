#include "cards/creatures/blues/MinionHorde.hpp"

MinionHorde::MinionHorde(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

MinionHorde::~MinionHorde() {}

std::string MinionHorde::get_full_type() const
{
	return Creature::get_full_type() + " - Minion";
}

Card::Color MinionHorde::get_color() const
{
	return Color::Blue;
}

std::string MinionHorde::get_name() const
{
	return "Minion Horde";
}

std::vector<Creature::Capacity> MinionHorde::get_capacities() const
{
	return
	{
		Capacity::Flying,
		Capacity::Reach
	};
}

std::string MinionHorde::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost MinionHorde::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::Blue, 2}
	};
}

int MinionHorde::get_full_power() const
{
	return 5;
}

int MinionHorde::get_full_toughness() const
{
	return 2;
}

Card* MinionHorde::clone() const
{
	return new MinionHorde(*this);
}
