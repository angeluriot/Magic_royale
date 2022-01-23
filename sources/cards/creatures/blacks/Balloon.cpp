#include "cards/creatures/blacks/Balloon.hpp"
#include "players/Player.hpp"
#include "renderer/print.hpp"

Balloon::Balloon(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Balloon::~Balloon() {}

std::string Balloon::get_full_type() const
{
	return Creature::get_full_type() + " - Skeleton";
}

Card::Color Balloon::get_color() const
{
	return Color::Black;
}

std::string Balloon::get_name() const
{
	return "Balloon";
}

std::vector<Creature::Capacity> Balloon::get_capacities() const
{
	return
	{
		Capacity::Flying,
		Capacity::Unblockable,
		Capacity::ZoneDamage
	};
}

std::string Balloon::get_description() const
{
	return Creature::get_description() + "Inflicts 1 damage to all enemy creatures on death.";
}

Card::Cost Balloon::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::Black, 2}
	};
}

int Balloon::get_full_power() const
{
	return 5;
}

int Balloon::get_full_toughness() const
{
	return 2;
}

void Balloon::die()
{
	Creature::die();

	std::cout << cyan << "[INFO] " << ::reset << italic << ::get_color(get_color()) << get_name() << ::reset <<
		" inflicted 1 damage to all enemy creatures." << End(2);

	for (auto& creature : m_owner->get_opponent().creatures)
		creature.modify_toughness(-1);
}

Card* Balloon::clone() const
{
	return new Balloon(*this);
}
