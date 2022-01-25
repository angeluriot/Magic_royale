#include "cards/spells/Zap.hpp"
#include "players/Player.hpp"

Zap::Zap(): Spell() {}

Zap::~Zap() {}

Card::Color Zap::get_color() const
{
	return Color::Blue;
}

std::string Zap::get_name() const
{
	return "Zap";
}

std::string Zap::get_description() const
{
	return "Inflicts 1 damage to all enemy creatures.";
}

Card::Cost Zap::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 },
		{ Color::Blue, 1 }
	};
}

void Zap::apply_effect()
{
	for (auto& creature : m_owner->get_opponent().creatures)
		creature.modify_toughness(-1);
}

Card* Zap::clone() const
{
	return new Zap(*this);
}
