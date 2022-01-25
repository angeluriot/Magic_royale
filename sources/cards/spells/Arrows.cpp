#include "cards/spells/Arrows.hpp"
#include "players/Player.hpp"

Arrows::Arrows(): Spell() {}

Arrows::~Arrows() {}

Card::Color Arrows::get_color() const
{
	return Color::White;
}

std::string Arrows::get_name() const
{
	return "Arrows";
}

std::string Arrows::get_description() const
{
	return "Inflicts 2 damages to all enemy creatures.";
}

Card::Cost Arrows::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::White, 1 }
	};
}

void Arrows::apply_effect()
{
	for (auto& creature : m_owner->get_opponent().creatures)
		creature.modify_toughness(-2);
}

Card* Arrows::clone() const
{
	return new Arrows(*this);
}
