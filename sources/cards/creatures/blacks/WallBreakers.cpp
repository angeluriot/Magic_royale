#include "cards/creatures/blacks/WallBreakers.hpp"

WallBreakers::WallBreakers(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

WallBreakers::~WallBreakers() {}

std::string WallBreakers::get_full_type() const
{
	return Creature::get_full_type() + " - Skeleton";
}

Card::Color WallBreakers::get_color() const
{
	return Color::Black;
}

std::string WallBreakers::get_name() const
{
	return "Wall Breakers";
}

std::vector<Creature::Capacity> WallBreakers::get_capacities() const
{
	return
	{
		Capacity::Unblockable,
		Capacity::Kamikaze
	};
}

std::string WallBreakers::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost WallBreakers::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 },
		{ Color::Black, 1 }
	};
}

int WallBreakers::get_full_power() const
{
	return 5;
}

int WallBreakers::get_full_toughness() const
{
	return 2;
}

Card* WallBreakers::clone() const
{
	return new WallBreakers(*this);
}
