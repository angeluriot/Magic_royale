#include "cards/creatures/reds/FireSpirit.hpp"

FireSpirit::FireSpirit(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

FireSpirit::~FireSpirit() {}

std::string FireSpirit::get_full_type() const
{
	return Creature::get_full_type() + " - Spirit";
}

Card::Color FireSpirit::get_color() const
{
	return Color::Red;
}

std::string FireSpirit::get_name() const
{
	return "Fire Spirit";
}

std::vector<Creature::Capacity> FireSpirit::get_capacities() const
{
	return
	{
		Capacity::ZoneDamage,
		Capacity::Kamikaze
	};
}

std::string FireSpirit::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost FireSpirit::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 }
	};
}

int FireSpirit::get_full_power() const
{
	return 2;
}

int FireSpirit::get_full_toughness() const
{
	return 1;
}

Card* FireSpirit::clone() const
{
	return new FireSpirit(*this);
}
