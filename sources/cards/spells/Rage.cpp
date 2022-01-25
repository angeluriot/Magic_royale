#include "cards/spells/Rage.hpp"
#include "players/Player.hpp"

Rage::Rage(): Spell() {}

Rage::~Rage() {}

Card::Color Rage::get_color() const
{
	return Color::White;
}

std::string Rage::get_name() const
{
	return "Rage";
}

std::string Rage::get_description() const
{
	return "Increases power by 1 for all allied creatures.";
}

Card::Cost Rage::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 },
		{ Color::White, 1 }
	};
}

void Rage::apply_effect()
{
	for (auto& creature : m_owner->creatures)
		creature.modify_power(1);
}

Card* Rage::clone() const
{
	return new Rage(*this);
}
