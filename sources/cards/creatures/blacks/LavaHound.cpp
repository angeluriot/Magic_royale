#include "cards/creatures/blacks/LavaHound.hpp"
#include "players/Player.hpp"
#include "cards/creatures/generateds/LavaPups.hpp"

LavaHound::LavaHound(): Creature() {}

LavaHound::~LavaHound() {}

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
		{ Color::Colorless, 1 },
		{ Color::Black, 1 }
	};
}

int LavaHound::get_full_power() const
{
	return 10;
}

int LavaHound::get_full_toughness() const
{
	return 7;
}

void LavaHound::die()
{
	m_owner->add_creature(LavaPups());
}

Card* LavaHound::clone() const
{
	return new LavaHound(*this);
}
