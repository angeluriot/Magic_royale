#include "cards/creatures/greens/Golem.hpp"

Golem::Golem(): Creature(get_full_power(), get_full_toughness()) {}

std::string Golem::get_full_type() const
{
	return Creature::get_full_type() + " - Golem";
}

Card::Color Golem::get_color() const
{
	return Color::Green;
}

std::string Golem::get_name() const
{
	return "Golem";
}

std::string Golem::get_description() const
{
	return "";
}

Card::Cost Golem::get_cost() const
{
	return
	{
		{ Color::Colorless, 6 },
		{ Color::Green, 2 }
	};
}

int Golem::get_full_power() const
{
	return 2;
}

int Golem::get_full_toughness() const
{
	return 8;
}
