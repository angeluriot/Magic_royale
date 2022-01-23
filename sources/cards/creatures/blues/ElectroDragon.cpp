#include "cards/creatures/blues/ElectroDragon.hpp"

ElectroDragon::ElectroDragon(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

ElectroDragon::~ElectroDragon() {}

std::string ElectroDragon::get_full_type() const
{
	return Creature::get_full_type() + " - Dragon";
}

Card::Color ElectroDragon::get_color() const
{
	return Color::Blue;
}

std::string ElectroDragon::get_name() const
{
	return "Electro Dragon";
}

std::vector<Creature::Capacity> ElectroDragon::get_capacities() const
{
	return
	{
		Capacity::Flying,
		Capacity::Reach,
		Capacity::Freeze
	};
}

std::string ElectroDragon::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost ElectroDragon::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::Blue, 2 }
	};
}

int ElectroDragon::get_full_power() const
{
	return 4;
}

int ElectroDragon::get_full_toughness() const
{
	return 3;
}

Card* ElectroDragon::clone() const
{
	return new ElectroDragon(*this);
}
