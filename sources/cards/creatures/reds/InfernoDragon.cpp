#include "cards/creatures/reds/InfernoDragon.hpp"

InfernoDragon::InfernoDragon(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

InfernoDragon::~InfernoDragon() {}

std::string InfernoDragon::get_full_type() const
{
	return Creature::get_full_type() + " - Dragon";
}

Card::Color InfernoDragon::get_color() const
{
	return Color::Red;
}

std::string InfernoDragon::get_name() const
{
	return "Inferno Dragon";
}

std::vector<Creature::Capacity> InfernoDragon::get_capacities() const
{
	return
	{
		Capacity::Flying,
		Capacity::Reach
	};
}

std::string InfernoDragon::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost InfernoDragon::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Red, 2 }
	};
}

int InfernoDragon::get_full_power() const
{
	return 4;
}

int InfernoDragon::get_full_toughness() const
{
	return 2;
}

Card* InfernoDragon::clone() const
{
	return new InfernoDragon(*this);
}
