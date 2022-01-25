#include "cards/spells/Poison.hpp"
#include "players/Player.hpp"

Poison::Poison(): Spell() {}

Poison::~Poison() {}

Card::Color Poison::get_color() const
{
	return Color::Red;
}

std::string Poison::get_name() const
{
	return "Poison";
}

std::string Poison::get_description() const
{
	return "Inflicts 2 damages and reduces power by 1 to all enemy creatures.";
}

Card::Cost Poison::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Red, 2 }
	};
}

void Poison::apply_effect()
{
	for (auto& creature : m_owner->get_opponent().creatures)
	{
		creature.modify_power(-1);
		creature.modify_toughness(-2);
	}
}

Card* Poison::clone() const
{
	return new Poison(*this);
}
