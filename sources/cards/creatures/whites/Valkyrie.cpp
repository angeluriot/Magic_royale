#include "cards/creatures/whites/Valkyrie.hpp"

Valkyrie::Valkyrie(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Valkyrie::~Valkyrie() {}

std::string Valkyrie::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color Valkyrie::get_color() const
{
	return Color::White;
}

std::string Valkyrie::get_name() const
{
	return "Valkyrie";
}

std::vector<Creature::Capacity> Valkyrie::get_capacities() const
{
	return
	{
		Capacity::ZoneDamage
	};
}

std::string Valkyrie::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Valkyrie::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::White, 2 }
	};
}

int Valkyrie::get_full_power() const
{
	return 2;
}

int Valkyrie::get_full_toughness() const
{
	return 4;
}

Card* Valkyrie::clone() const
{
	return new Valkyrie(*this);
}
