#include "cards/spells/Earthquake.hpp"
#include "players/Player.hpp"

Earthquake::Earthquake(): Spell() {}

Earthquake::~Earthquake() {}

Card::Color Earthquake::get_color() const
{
	return Color::Green;
}

std::string Earthquake::get_name() const
{
	return "Earthquake";
}

std::string Earthquake::get_description() const
{
	return "Inflicts 3 damages to enemy creatures that do not have the Flying capacity.";
}

Card::Cost Earthquake::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Green, 1 }
	};
}

void Earthquake::apply_effect()
{
	for (auto& creature : m_owner->get_opponent().creatures)
		if (!creature.has(Creature::Capacity::Flying))
			creature.modify_toughness(-3);
}

Card* Earthquake::clone() const
{
	return new Earthquake(*this);
}
