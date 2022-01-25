#include "cards/creatures/generateds/Golemites.hpp"
#include "players/Player.hpp"
#include "renderer/print.hpp"

Golemites::Golemites(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Golemites::~Golemites() {}

std::string Golemites::get_full_type() const
{
	return Creature::get_full_type() + " - Golem";
}

Card::Color Golemites::get_color() const
{
	return Color::Green;
}

std::string Golemites::get_name() const
{
	return "Golemites";
}

std::vector<Creature::Capacity> Golemites::get_capacities() const
{
	return
	{
		Capacity::Unblockable
	};
}

std::string Golemites::get_description() const
{
	return Creature::get_description() + "Inflicts 1 damage to all enemy creatures on death.";
}

Card::Cost Golemites::get_cost() const
{
	return {};
}

int Golemites::get_full_power() const
{
	return 1;
}

int Golemites::get_full_toughness() const
{
	return 3;
}

void Golemites::die()
{
	Creature::die();

	std::cout << cyan << "[INFO] " << ::reset << italic << ::get_color(get_color()) << get_name() << ::reset <<
		" inflicted 1 damage to all enemy creatures." << End(2);

	for (auto& creature : m_owner->get_opponent().creatures)
		creature.modify_toughness(-1);
}

Card* Golemites::clone() const
{
	return new Golemites(*this);
}
