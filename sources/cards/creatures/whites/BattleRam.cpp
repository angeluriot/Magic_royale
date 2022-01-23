#include "cards/creatures/whites/BattleRam.hpp"
#include "players/Player.hpp"
#include "cards/creatures/generateds/Barbarian.hpp"
#include "renderer/print.hpp"

BattleRam::BattleRam(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

BattleRam::~BattleRam() {}

std::string BattleRam::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color BattleRam::get_color() const
{
	return Color::White;
}

std::string BattleRam::get_name() const
{
	return "Battle Ram";
}

std::vector<Creature::Capacity> BattleRam::get_capacities() const
{
	return
	{
		Capacity::Haste,
		Capacity::Unblockable,
		Capacity::Kamikaze
	};
}

std::string BattleRam::get_description() const
{
	return Creature::get_description() + "Spawns 1 Barbarian on death.";
}

Card::Cost BattleRam::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::White, 1 }
	};
}

int BattleRam::get_full_power() const
{
	return 3;
}

int BattleRam::get_full_toughness() const
{
	return 1;
}

void BattleRam::die()
{
	Creature::die();

	std::cout << cyan << "[INFO] " << ::reset << "A " << italic << ::get_color(Barbarian().get_color()) <<
		Barbarian().get_name() << ::reset << " spawned." << End(2);

	m_owner->creatures.add(Barbarian());
	m_owner->creatures.back().set_owner(*m_owner);
}

Card* BattleRam::clone() const
{
	return new BattleRam(*this);
}
