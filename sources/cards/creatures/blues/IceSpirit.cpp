#include "cards/creatures/blues/IceSpirit.hpp"

IceSpirit::IceSpirit(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

IceSpirit::~IceSpirit() {}

std::string IceSpirit::get_full_type() const
{
	return Creature::get_full_type() + " - Spirit";
}

Card::Color IceSpirit::get_color() const
{
	return Color::Blue;
}

std::string IceSpirit::get_name() const
{
	return "Ice Spirit";
}

std::vector<Creature::Capacity> IceSpirit::get_capacities() const
{
	return
	{
		Capacity::Freeze,
		Capacity::Kamikaze
	};
}

std::string IceSpirit::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost IceSpirit::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 }
	};
}

int IceSpirit::get_full_power() const
{
	return 1;
}

int IceSpirit::get_full_toughness() const
{
	return 2;
}

Card* IceSpirit::clone() const
{
	return new IceSpirit(*this);
}
