#include "cards/spells/Clone.hpp"
#include "players/Player.hpp"

Clone::Clone(): Spell() {}

Clone::~Clone() {}

Card::Color Clone::get_color() const
{
	return Color::Blue;
}

std::string Clone::get_name() const
{
	return "Clone";
}

std::string Clone::get_description() const
{
	return "Duplicates all your creatures but with 1 toughness.";
}

Card::Cost Clone::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::Blue, 1 }
	};
}

void Clone::apply_effect()
{
	std::vector<Creature*> creatures;

	for (auto& creature : m_owner->creatures)
		creatures.push_back(&creature);

	for (auto& creature : creatures)
	{
		m_owner->creatures.add(*creature);
		m_owner->creatures.back().set_clone();
	}
}

Card* Clone::clone() const
{
	return new Clone(*this);
}
