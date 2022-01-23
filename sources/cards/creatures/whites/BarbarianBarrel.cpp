#include "cards/creatures/whites/BarbarianBarrel.hpp"
#include "players/Player.hpp"
#include "renderer/print.hpp"

BarbarianBarrel::BarbarianBarrel(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

BarbarianBarrel::~BarbarianBarrel() {}

std::string BarbarianBarrel::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color BarbarianBarrel::get_color() const
{
	return Color::White;
}

std::string BarbarianBarrel::get_name() const
{
	return "Barbarian Barrel";
}

std::vector<Creature::Capacity> BarbarianBarrel::get_capacities() const
{
	return
	{
		Capacity::Haste
	};
}

std::string BarbarianBarrel::get_description() const
{
	return Creature::get_description() + "Inflicts 1 damage to all enemy creatures on spawn.";
}

Card::Cost BarbarianBarrel::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 },
		{ Color::White, 1 }
	};
}

int BarbarianBarrel::get_full_power() const
{
	return 2;
}

int BarbarianBarrel::get_full_toughness() const
{
	return 2;
}

void BarbarianBarrel::spawn()
{
	Creature::spawn();

	std::cout << cyan << "[INFO] " << ::reset << italic << ::get_color(get_color()) << get_name() << ::reset <<
		" inflicted 1 damage to all enemy creatures." << End(2);

	for (auto& creature : m_owner->get_opponent().creatures)
		creature.modify_toughness(-1);
}

Card* BarbarianBarrel::clone() const
{
	return new BarbarianBarrel(*this);
}
