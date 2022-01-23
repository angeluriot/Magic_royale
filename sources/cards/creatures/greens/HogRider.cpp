#include "cards/creatures/greens/HogRider.hpp"

HogRider::HogRider(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

HogRider::~HogRider() {}

std::string HogRider::get_full_type() const
{
	return Creature::get_full_type() + " - Boar";
}

Card::Color HogRider::get_color() const
{
	return Color::Green;
}

std::string HogRider::get_name() const
{
	return "Hog Rider";
}

std::vector<Creature::Capacity> HogRider::get_capacities() const
{
	return
	{
		Capacity::Haste,
		Capacity::Unblockable
	};
}

std::string HogRider::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost HogRider::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::Green, 1 }
	};
}

int HogRider::get_full_power() const
{
	return 3;
}

int HogRider::get_full_toughness() const
{
	return 3;
}

Card* HogRider::clone() const
{
	return new HogRider(*this);
}
