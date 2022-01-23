#include "cards/creatures/greens/RamRider.hpp"

RamRider::RamRider(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

RamRider::~RamRider() {}

std::string RamRider::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color RamRider::get_color() const
{
	return Color::Green;
}

std::string RamRider::get_name() const
{
	return "Ram Rider";
}

std::vector<Creature::Capacity> RamRider::get_capacities() const
{
	return
	{
		Capacity::MultiHit,
		Capacity::Freeze,
		Capacity::Haste
	};
}

std::string RamRider::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost RamRider::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::Green, 2}
	};
}

int RamRider::get_full_power() const
{
	return 3;
}

int RamRider::get_full_toughness() const
{
	return 4;
}

Card* RamRider::clone() const
{
	return new RamRider(*this);
}
