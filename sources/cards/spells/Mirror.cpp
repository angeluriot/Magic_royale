#include "cards/spells/Mirror.hpp"
#include "players/Player.hpp"
#include "renderer/print.hpp"

Mirror::Mirror(): Spell() {}

Mirror::~Mirror() {}

Card::Color Mirror::get_color() const
{
	return Color::White;
}

std::string Mirror::get_name() const
{
	return "Mirror";
}

std::string Mirror::get_description() const
{
	return "Adds a copy of the last summoned creature in your hand.";
}

Card::Cost Mirror::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 },
		{ Color::White, 1 }
	};
}

void Mirror::apply_effect()
{
	if (m_owner->creatures.size() > 0)
	{
		Creature& creature = m_owner->creatures.back();

		std::cout << cyan << "[INFO] " << ::reset << italic << ::get_color(creature.get_color()) <<
			creature.get_name() << ::reset << " was added in your hand." << End(2);

		m_owner->hand.add(creature);
	}

	else
		std::cout << cyan << "[INFO] " << ::reset << "Nothing was added in your hand because you did not summon any creature." << End(2);
}

Card* Mirror::clone() const
{
	return new Mirror(*this);
}
