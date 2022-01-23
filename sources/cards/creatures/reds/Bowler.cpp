#include "cards/creatures/reds/Bowler.hpp"

Bowler::Bowler(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Bowler::~Bowler() {}

std::string Bowler::get_full_type() const
{
	return Creature::get_full_type() + " - Goblin";
}

Card::Color Bowler::get_color() const
{
	return Color::Red;
}

std::string Bowler::get_name() const
{
	return "Bowler";
}

std::vector<Creature::Capacity> Bowler::get_capacities() const
{
	return
	{
		Capacity::ZoneDamage,
		Capacity::MultiHit
	};
}

std::string Bowler::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Bowler::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::Red, 2 }
	};
}

int Bowler::get_full_power() const
{
	return 3;
}

int Bowler::get_full_toughness() const
{
	return 4;
}

Card* Bowler::clone() const
{
	return new Bowler(*this);
}
