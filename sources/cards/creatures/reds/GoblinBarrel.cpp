#include "cards/creatures/reds/GoblinBarrel.hpp"

GoblinBarrel::GoblinBarrel(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

GoblinBarrel::~GoblinBarrel() {}

std::string GoblinBarrel::get_full_type() const
{
	return Creature::get_full_type() + " - Goblin";
}

Card::Color GoblinBarrel::get_color() const
{
	return Color::Red;
}

std::string GoblinBarrel::get_name() const
{
	return "Goblin Barrel";
}

std::vector<Creature::Capacity> GoblinBarrel::get_capacities() const
{
	return
	{
		Capacity::Haste,
		Capacity::Unblockable
	};
}

std::string GoblinBarrel::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost GoblinBarrel::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Red, 1 }
	};
}

int GoblinBarrel::get_full_power() const
{
	return 3;
}

int GoblinBarrel::get_full_toughness() const
{
	return 2;
}

Card* GoblinBarrel::clone() const
{
	return new GoblinBarrel(*this);
}
