#include "cards/creatures/whites/FlyingMachine.hpp"

FlyingMachine::FlyingMachine(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

FlyingMachine::~FlyingMachine() {}

std::string FlyingMachine::get_full_type() const
{
	return Creature::get_full_type() + " - Machine";
}

Card::Color FlyingMachine::get_color() const
{
	return Color::White;
}

std::string FlyingMachine::get_name() const
{
	return "Flying Machine";
}

std::vector<Creature::Capacity> FlyingMachine::get_capacities() const
{
	return
	{
		Capacity::Flying,
		Capacity::Reach
	};
}

std::string FlyingMachine::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost FlyingMachine::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::White, 1 }
	};
}

int FlyingMachine::get_full_power() const
{
	return 2;
}

int FlyingMachine::get_full_toughness() const
{
	return 4;
}

Card* FlyingMachine::clone() const
{
	return new FlyingMachine(*this);
}
