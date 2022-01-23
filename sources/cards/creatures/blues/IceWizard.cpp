#include "cards/creatures/blues/IceWizard.hpp"
#include "players/Player.hpp"
#include "renderer/print.hpp"

IceWizard::IceWizard(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

IceWizard::~IceWizard() {}

std::string IceWizard::get_full_type() const
{
	return Creature::get_full_type() + " - Wizard";
}

Card::Color IceWizard::get_color() const
{
	return Color::Blue;
}

std::string IceWizard::get_name() const
{
	return "Ice Wizard";
}

std::vector<Creature::Capacity> IceWizard::get_capacities() const
{
	return
	{
		Capacity::Reach,
		Capacity::ZoneDamage,
		Capacity::Freeze
	};
}

std::string IceWizard::get_description() const
{
	return Creature::get_description() + "Inflicts the effects of Freeze capacity to all enemy creatures on spawn.";
}

Card::Cost IceWizard::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Blue, 1 }
	};
}

int IceWizard::get_full_power() const
{
	return 2;
}

int IceWizard::get_full_toughness() const
{
	return 3;
}

void IceWizard::spawn()
{
	Creature::spawn();

	std::cout << cyan << "[INFO] " << ::reset << italic << ::get_color(get_color()) << get_name() << ::reset <<
		" inflicted the effects of Freeze capacity to all enemy creatures." << End(2);

	for (auto& creature : m_owner->get_opponent().creatures)
		creature.modify_power(-1);
}

Card* IceWizard::clone() const
{
	return new IceWizard(*this);
}
