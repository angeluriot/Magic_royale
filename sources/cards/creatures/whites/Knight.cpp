#include "cards/creatures/whites/Knight.hpp"

Knight::Knight(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Knight::~Knight() {}

std::string Knight::get_full_type() const
{
	return Creature::get_full_type() + " - Knight";
}

Card::Color Knight::get_color() const
{
	return Color::White;
}

std::string Knight::get_name() const
{
	return "Knight";
}

std::vector<Creature::Capacity> Knight::get_capacities() const
{
	return {};
}

std::string Knight::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Knight::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::White, 1 }
	};
}

int Knight::get_full_power() const
{
	return 2;
}

int Knight::get_full_toughness() const
{
	return 3;
}

Card* Knight::clone() const
{
	return new Knight(*this);
}
