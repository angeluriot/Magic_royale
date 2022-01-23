#include "cards/creatures/whites/Miner.hpp"

Miner::Miner(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Miner::~Miner() {}

std::string Miner::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color Miner::get_color() const
{
	return Color::White;
}

std::string Miner::get_name() const
{
	return "Miner";
}

std::vector<Creature::Capacity> Miner::get_capacities() const
{
	return
	{
		Capacity::Haste,
		Capacity::Unblockable
	};
}

std::string Miner::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Miner::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::White, 1 }
	};
}

int Miner::get_full_power() const
{
	return 2;
}

int Miner::get_full_toughness() const
{
	return 3;
}

Card* Miner::clone() const
{
	return new Miner(*this);
}
