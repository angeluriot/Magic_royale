#include "cards/creatures/blues/Witch.hpp"
#include "players/Player.hpp"
#include "cards/creatures/generateds/Skeleton.hpp"
#include "renderer/print.hpp"

Witch::Witch(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Witch::~Witch() {}

std::string Witch::get_full_type() const
{
	return Creature::get_full_type() + " - Wizard";
}

Card::Color Witch::get_color() const
{
	return Color::Blue;
}

std::string Witch::get_name() const
{
	return "Witch";
}

std::vector<Creature::Capacity> Witch::get_capacities() const
{
	return {};
}

std::string Witch::get_description() const
{
	return Creature::get_description() + "Spawns 1 Skeleton every turn.";
}

Card::Cost Witch::get_cost() const
{
	return
	{
		{ Color::Colorless, 4 },
		{ Color::Blue, 1}
	};
}

int Witch::get_full_power() const
{
	return 3;
}

int Witch::get_full_toughness() const
{
	return 4;
}

void Witch::special_ability()
{
	Creature::special_ability();

	std::cout << cyan << "[INFO] " << ::reset << "A " << italic << ::get_color(Skeleton().get_color()) <<
		Skeleton().get_name() << ::reset << " spawned." << End(2);

	m_owner->creatures.add(Skeleton());
	m_owner->creatures.back().set_owner(*m_owner);
}

Card* Witch::clone() const
{
	return new Witch(*this);
}
