#include "cards/creatures/blues/ElectroSpirit.hpp"

ElectroSpirit::ElectroSpirit(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

ElectroSpirit::~ElectroSpirit() {}

std::string ElectroSpirit::get_full_type() const
{
	return Creature::get_full_type() + " - Spirit";
}

Card::Color ElectroSpirit::get_color() const
{
	return Color::Blue;
}

std::string ElectroSpirit::get_name() const
{
	return "Electro Spirit";
}

std::vector<Creature::Capacity> ElectroSpirit::get_capacities() const
{
	return
	{
		Capacity::Freeze,
		Capacity::Kamikaze
	};
}

std::string ElectroSpirit::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost ElectroSpirit::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 }
	};
}

int ElectroSpirit::get_full_power() const
{
	return 2;
}

int ElectroSpirit::get_full_toughness() const
{
	return 1;
}

Card* ElectroSpirit::clone() const
{
	return new ElectroSpirit(*this);
}
