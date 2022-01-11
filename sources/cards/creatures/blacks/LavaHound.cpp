#include "cards/creatures/blacks/LavaHound.hpp"

LavaHound::LavaHound(): Creature() {}

std::string LavaHound::get_full_type() const
{
	return Creature::get_full_type() + " - Demon";
}

Card::Color LavaHound::get_color() const
{
	return Color::Black;
}

std::string LavaHound::get_name() const
{
	return "Lava Hound";
}

std::vector<Creature::Capacity> LavaHound::get_capacities() const
{
	return
	{
		Capacity::Flying,
		Capacity::Reach,
		Capacity::Unblockable
	};
}

std::string LavaHound::get_description() const
{
	return "";
}

Card::Cost LavaHound::get_cost() const
{
	return
	{
		{ Color::Colorless, 4 },
		{ Color::Black, 3 }
	};
}

int LavaHound::get_full_power() const
{
	return 2;
}

int LavaHound::get_full_toughness() const
{
	return 7;
}
