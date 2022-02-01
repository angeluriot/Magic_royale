#include "cards/creatures/whites/BattleHealer.hpp"
#include "players/Player.hpp"
#include "renderer/print.hpp"

BattleHealer::BattleHealer(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

BattleHealer::~BattleHealer() {}

std::string BattleHealer::get_full_type() const
{
	return Creature::get_full_type() + " - Angel";
}

Card::Color BattleHealer::get_color() const
{
	return Color::White;
}

std::string BattleHealer::get_name() const
{
	return "Battle Healer";
}

std::vector<Creature::Capacity> BattleHealer::get_capacities() const
{
	return
	{
		Capacity::Flying,
		Capacity::Reach
	};
}

std::string BattleHealer::get_description() const
{
	return Creature::get_description() + "Adds 1 toughness to all allied creatures while alive.";
}

Card::Cost BattleHealer::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::White, 2 }
	};
}

int BattleHealer::get_full_power() const
{
	return 1;
}

int BattleHealer::get_full_toughness() const
{
	return 3;
}

void BattleHealer::spawn()
{
	Creature::spawn();

	std::cout << cyan << "[INFO] " << ::reset << italic << ::get_color(get_color()) << get_name() << ::reset <<
		" added 1 toughness to all allied creatures." << End(2);

	for (auto& creature : m_owner->creatures)
		creature.modify_toughness(1);
}

void BattleHealer::special_ability()
{
	Creature::special_ability();

	std::cout << cyan << "[INFO] " << ::reset << italic << ::get_color(get_color()) << get_name() << ::reset <<
		" added 1 toughness to all allied creatures." << End(2);

	for (auto& creature : m_owner->creatures)
		creature.modify_toughness(1);
}

Card* BattleHealer::clone() const
{
	return new BattleHealer(*this);
}
