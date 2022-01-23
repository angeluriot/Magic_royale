#include "cards/creatures/reds/Goblins.hpp"

Goblins::Goblins(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Goblins::~Goblins() {}

std::string Goblins::get_full_type() const
{
	return Creature::get_full_type() + " - Goblin";
}

Card::Color Goblins::get_color() const
{
	return Color::Red;
}

std::string Goblins::get_name() const
{
	return "Goblins";
}

std::vector<Creature::Capacity> Goblins::get_capacities() const
{
	return {};
}

std::string Goblins::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Goblins::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 },
		{ Color::Red, 1 }
	};
}

int Goblins::get_full_power() const
{
	return 2;
}

int Goblins::get_full_toughness() const
{
	return 2;
}

Card* Goblins::clone() const
{
	return new Goblins(*this);
}
