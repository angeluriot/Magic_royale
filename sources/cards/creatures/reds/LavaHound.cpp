#include "cards/creatures/reds/LavaHound.hpp"
#include "players/Player.hpp"
#include "cards/creatures/generateds/LavaPups.hpp"

LavaHound::LavaHound(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

LavaHound::~LavaHound() {}

std::string LavaHound::get_full_type() const
{
	return Creature::get_full_type() + " - Demon";
}

Card::Color LavaHound::get_color() const
{
	return Color::Red;
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
	return Creature::get_description() + "";
}

Card::Cost LavaHound::get_cost() const
{
	return
	{
		{ Color::Colorless, 5 },
		{ Color::Red, 2 }
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

void LavaHound::die()
{
	m_owner->creatures.add(LavaPups());
	m_owner->creatures.back().set_owner(*m_owner);
}

Card* LavaHound::clone() const
{
	return new LavaHound(*this);
}
