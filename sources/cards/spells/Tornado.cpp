#include "cards/spells/Tornado.hpp"
#include "players/Player.hpp"

Tornado::Tornado(): Spell() {}

Tornado::~Tornado() {}

Card::Color Tornado::get_color() const
{
	return Color::Green;
}

std::string Tornado::get_name() const
{
	return "Tornado";
}

std::string Tornado::get_description() const
{
	return "Inflicts 1 damage and reduces power by 1 to all enemy creatures.";
}

Card::Cost Tornado::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Green, 1 }
	};
}

void Tornado::apply_effect()
{
	for (auto& creature : m_owner->get_opponent().creatures)
	{
		creature.modify_power(-1);
		creature.modify_toughness(-1);
	}
}

Card* Tornado::clone() const
{
	return new Tornado(*this);
}
