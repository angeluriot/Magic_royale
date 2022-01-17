#include "cards/creatures/blacks/Pekka.hpp"

Pekka::Pekka(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Pekka::~Pekka() {}

std::string Pekka::get_full_type() const
{
	return Creature::get_full_type() + " - Demon";
}

Card::Color Pekka::get_color() const
{
	return Color::Black;
}

std::string Pekka::get_name() const
{
	return "Pekka";
}

std::vector<Creature::Capacity> Pekka::get_capacities() const
{
	return {};
}

std::string Pekka::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost Pekka::get_cost() const
{
	return
	{
		{ Color::Colorless, 5 },
		{ Color::Black, 2 }
	};
}

int Pekka::get_full_power() const
{
	return 4;
}

int Pekka::get_full_toughness() const
{
	return 5;
}

Card* Pekka::clone() const
{
	return new Pekka(*this);
}
