#include "cards/creatures/blues/ElectroWizard.hpp"
#include "players/Player.hpp"
#include "renderer/print.hpp"

ElectroWizard::ElectroWizard(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

ElectroWizard::~ElectroWizard() {}

std::string ElectroWizard::get_full_type() const
{
	return Creature::get_full_type() + " - Wizard";
}

Card::Color ElectroWizard::get_color() const
{
	return Color::Blue;
}

std::string ElectroWizard::get_name() const
{
	return "Electro Wizard";
}

std::vector<Creature::Capacity> ElectroWizard::get_capacities() const
{
	return
	{
		Capacity::Reach,
		Capacity::MultiHit,
		Capacity::Freeze
	};
}

std::string ElectroWizard::get_description() const
{
	return Creature::get_description() + "Inflicts 1 damage to all enemy creatures on spawn.";
}

Card::Cost ElectroWizard::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Blue, 2 }
	};
}

int ElectroWizard::get_full_power() const
{
	return 3;
}

int ElectroWizard::get_full_toughness() const
{
	return 3;
}

void ElectroWizard::spawn()
{
	Creature::spawn();

	std::cout << cyan << "[INFO] " << ::reset << italic << ::get_color(get_color()) << get_name() << ::reset <<
		" inflicted 1 damage to all enemy creatures." << End(2);

	for (auto& creature : m_owner->get_opponent().creatures)
		creature.modify_toughness(-1);
}

Card* ElectroWizard::clone() const
{
	return new ElectroWizard(*this);
}
