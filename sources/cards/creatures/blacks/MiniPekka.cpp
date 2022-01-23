#include "cards/creatures/blacks/MiniPekka.hpp"

MiniPekka::MiniPekka(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

MiniPekka::~MiniPekka() {}

std::string MiniPekka::get_full_type() const
{
	return Creature::get_full_type() + " - Demon";
}

Card::Color MiniPekka::get_color() const
{
	return Color::Black;
}

std::string MiniPekka::get_name() const
{
	return "Mini Pekka";
}

std::vector<Creature::Capacity> MiniPekka::get_capacities() const
{
	return {};
}

std::string MiniPekka::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost MiniPekka::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Black, 2 }
	};
}

int MiniPekka::get_full_power() const
{
	return 4;
}

int MiniPekka::get_full_toughness() const
{
	return 2;
}

Card* MiniPekka::clone() const
{
	return new MiniPekka(*this);
}
