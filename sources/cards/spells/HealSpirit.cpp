#include "cards/spells/HealSpirit.hpp"
#include "players/Player.hpp"

HealSpirit::HealSpirit(): Spell() {}

HealSpirit::~HealSpirit() {}

Card::Color HealSpirit::get_color() const
{
	return Color::White;
}

std::string HealSpirit::get_name() const
{
	return "Heal Spirit";
}

std::string HealSpirit::get_description() const
{
	return "Increases toughness by 1 for all allied creatures.";
}

Card::Cost HealSpirit::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 }
	};
}

void HealSpirit::apply_effect()
{
	for (auto& creature : m_owner->creatures)
		creature.modify_toughness(1);
}

Card* HealSpirit::clone() const
{
	return new HealSpirit(*this);
}
