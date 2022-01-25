#include "cards/spells/TheLog.hpp"
#include "players/Player.hpp"

TheLog::TheLog(): Spell() {}

TheLog::~TheLog() {}

Card::Color TheLog::get_color() const
{
	return Color::Green;
}

std::string TheLog::get_name() const
{
	return "The Log";
}

std::string TheLog::get_description() const
{
	return "Inflicts 2 damages to enemy creatures that do not have the Flying capacity.";
}

Card::Cost TheLog::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 },
		{ Color::Green, 1 }
	};
}

void TheLog::apply_effect()
{
	for (auto& creature : m_owner->get_opponent().creatures)
		if (!creature.has(Creature::Capacity::Flying))
			creature.modify_toughness(-2);
}

Card* TheLog::clone() const
{
	return new TheLog(*this);
}
