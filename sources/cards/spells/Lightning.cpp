#include "cards/spells/Lightning.hpp"
#include "players/Player.hpp"

Lightning::Lightning(): Spell() {}

Lightning::~Lightning() {}

Card::Color Lightning::get_color() const
{
	return Color::Blue;
}

std::string Lightning::get_name() const
{
	return "Lightning";
}

std::string Lightning::get_description() const
{
	return "Inflicts 4 damages to all enemy creatures.";
}

Card::Cost Lightning::get_cost() const
{
	return
	{
		{ Color::Colorless, 4 },
		{ Color::Blue, 2 }
	};
}

void Lightning::apply_effect()
{
	for (auto& creature : m_owner->get_opponent().creatures)
		creature.modify_toughness(-4);
}

Card* Lightning::clone() const
{
	return new Lightning(*this);
}
