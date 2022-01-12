#include "cards/creatures/generateds/Golemites.hpp"

Golemites::Golemites(): Creature() {}

std::string Golemites::get_full_type() const
{
	return Creature::get_full_type() + " - Golem";
}

Card::Color Golemites::get_color() const
{
	return Color::Green;
}

std::string Golemites::get_name() const
{
	return "Golemites";
}

std::vector<Creature::Capacity> Golemites::get_capacities() const
{
	return
	{
		Capacity::Unblockable
	};
}

std::string Golemites::get_description() const
{
	return "";
}

Card::Cost Golemites::get_cost() const
{
	return {};
}

int Golemites::get_full_power() const
{
	return 1;
}

int Golemites::get_full_toughness() const
{
	return 3;
}
