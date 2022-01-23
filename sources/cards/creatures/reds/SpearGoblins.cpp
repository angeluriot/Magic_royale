#include "cards/creatures/reds/SpearGoblins.hpp"

SpearGoblins::SpearGoblins(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

SpearGoblins::~SpearGoblins() {}

std::string SpearGoblins::get_full_type() const
{
	return Creature::get_full_type() + " - Goblin";
}

Card::Color SpearGoblins::get_color() const
{
	return Color::Red;
}

std::string SpearGoblins::get_name() const
{
	return "Spear Goblins";
}

std::vector<Creature::Capacity> SpearGoblins::get_capacities() const
{
	return
	{
		Capacity::Reach
	};
}

std::string SpearGoblins::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost SpearGoblins::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 },
		{ Color::Red, 1 }
	};
}

int SpearGoblins::get_full_power() const
{
	return 2;
}

int SpearGoblins::get_full_toughness() const
{
	return 2;
}

Card* SpearGoblins::clone() const
{
	return new SpearGoblins(*this);
}
