#include "cards/creatures/greens/Golem.hpp"
#include "players/Player.hpp"
#include "cards/creatures/generateds/Golemites.hpp"

Golem::Golem(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Golem::~Golem() {}

std::string Golem::get_full_type() const
{
	return Creature::get_full_type() + " - Golem";
}

Card::Color Golem::get_color() const
{
	return Color::Green;
}

std::string Golem::get_name() const
{
	return "Golem";
}

std::vector<Creature::Capacity> Golem::get_capacities() const
{
	return
	{
		Capacity::Unblockable
	};
}

std::string Golem::get_description() const
{
	return Creature::get_description() + "Spawns 1 Golemites on death.";
}

Card::Cost Golem::get_cost() const
{
	return
	{
		{ Color::Colorless, 6 },
		{ Color::Green, 2 }
	};
}

int Golem::get_full_power() const
{
	return 2;
}

int Golem::get_full_toughness() const
{
	return 8;
}

void Golem::die()
{
	m_owner->creatures.add(Golemites());
	m_owner->creatures.back().set_owner(*m_owner);
}

Card* Golem::clone() const
{
	return new Golem(*this);
}
