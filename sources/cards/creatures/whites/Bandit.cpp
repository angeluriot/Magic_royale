#include "cards/creatures/whites/Bandit.hpp"

Bandit::Bandit(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Bandit::~Bandit() {}

std::string Bandit::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color Bandit::get_color() const
{
	return Color::White;
}

std::string Bandit::get_name() const
{
	return "Bandit";
}

std::vector<Creature::Capacity> Bandit::get_capacities() const
{
	return
	{
		Capacity::FirstStrike,
		Capacity::Haste
	};
}

std::string Bandit::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Bandit::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::White, 1 }
	};
}

int Bandit::get_full_power() const
{
	return 3;
}

int Bandit::get_full_toughness() const
{
	return 2;
}

Card* Bandit::clone() const
{
	return new Bandit(*this);
}
