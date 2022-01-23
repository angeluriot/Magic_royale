#include "cards/creatures/reds/GoblinGiant.hpp"
#include "players/Player.hpp"
#include "cards/creatures/reds/SpearGoblins.hpp"
#include "renderer/print.hpp"

GoblinGiant::GoblinGiant(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

GoblinGiant::~GoblinGiant() {}

std::string GoblinGiant::get_full_type() const
{
	return Creature::get_full_type() + " - Goblin";
}

Card::Color GoblinGiant::get_color() const
{
	return Color::Red;
}

std::string GoblinGiant::get_name() const
{
	return "Goblin Giant";
}

std::vector<Creature::Capacity> GoblinGiant::get_capacities() const
{
	return
	{
		Capacity::Reach,
		Capacity::Unblockable
	};
}

std::string GoblinGiant::get_description() const
{
	return Creature::get_description() + "Spawns 1 Spear Goblins on death";
}

Card::Cost GoblinGiant::get_cost() const
{
	return
	{
		{ Color::Colorless, 4 },
		{ Color::Red, 2 }
	};
}

int GoblinGiant::get_full_power() const
{
	return 3;
}

int GoblinGiant::get_full_toughness() const
{
	return 5;
}

void GoblinGiant::die()
{
	Creature::die();

	std::cout << cyan << "[INFO] " << ::reset << "A " << italic << ::get_color(SpearGoblins().get_color()) <<
		SpearGoblins().get_name() << ::reset << " spawned." << End(2);

	m_owner->creatures.add(SpearGoblins());
	m_owner->creatures.back().set_owner(*m_owner);
}

Card* GoblinGiant::clone() const
{
	return new GoblinGiant(*this);
}
