#include "cards/creatures/blues/Wizard.hpp"

Wizard::Wizard(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Wizard::~Wizard() {}

std::string Wizard::get_full_type() const
{
	return Creature::get_full_type() + " - Wizard";
}

Card::Color Wizard::get_color() const
{
	return Color::Blue;
}

std::string Wizard::get_name() const
{
	return "Wizard";
}

std::vector<Creature::Capacity> Wizard::get_capacities() const
{
	return
	{
		Capacity::Reach,
		Capacity::ZoneDamage
	};
}

std::string Wizard::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Wizard::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::Blue, 2 }
	};
}

int Wizard::get_full_power() const
{
	return 4;
}

int Wizard::get_full_toughness() const
{
	return 3;
}

Card* Wizard::clone() const
{
	return new Wizard(*this);
}
