#include "cards/creatures/blacks/MegaKnight.hpp"
#include "players/Player.hpp"
#include "renderer/print.hpp"

MegaKnight::MegaKnight(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

MegaKnight::~MegaKnight() {}

std::string MegaKnight::get_full_type() const
{
	return Creature::get_full_type() + " - Knight";
}

Card::Color MegaKnight::get_color() const
{
	return Color::Black;
}

std::string MegaKnight::get_name() const
{
	return "Mega Knight";
}

std::vector<Creature::Capacity> MegaKnight::get_capacities() const
{
	return
	{
		Capacity::ZoneDamage,
		Capacity::FirstStrike
	};
}

std::string MegaKnight::get_description() const
{
	return Creature::get_description() + "Inflicts 2 damages to all enemy creatures on spawn.";
}

Card::Cost MegaKnight::get_cost() const
{
	return
	{
		{ Color::Colorless, 5 },
		{ Color::Black, 2 }
	};
}

int MegaKnight::get_full_power() const
{
	return 3;
}

int MegaKnight::get_full_toughness() const
{
	return 6;
}

void MegaKnight::spawn()
{
	Creature::spawn();

	std::cout << cyan << "[INFO] " << ::reset << italic << ::get_color(get_color()) << get_name() << ::reset <<
		" inflicted 2 damages to all enemy creatures." << End(2);

	for (auto& creature : m_owner->get_opponent().creatures)
		creature.modify_toughness(-2);
}

Card* MegaKnight::clone() const
{
	return new MegaKnight(*this);
}
