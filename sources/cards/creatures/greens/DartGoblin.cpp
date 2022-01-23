#include "cards/creatures/greens/DartGoblin.hpp"

DartGoblin::DartGoblin(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

DartGoblin::~DartGoblin() {}

std::string DartGoblin::get_full_type() const
{
	return Creature::get_full_type() + " - Goblin";
}

Card::Color DartGoblin::get_color() const
{
	return Color::Green;
}

std::string DartGoblin::get_name() const
{
	return "Dart Goblin";
}

std::vector<Creature::Capacity> DartGoblin::get_capacities() const
{
	return
	{
		Capacity::Reach
	};
}

std::string DartGoblin::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost DartGoblin::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Green, 1 }
	};
}

int DartGoblin::get_full_power() const
{
	return 3;
}

int DartGoblin::get_full_toughness() const
{
	return 2;
}

Card* DartGoblin::clone() const
{
	return new DartGoblin(*this);
}
