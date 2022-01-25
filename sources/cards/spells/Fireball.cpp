#include "cards/spells/Fireball.hpp"
#include "players/Player.hpp"

Fireball::Fireball(): Spell() {}

Fireball::~Fireball() {}

Card::Color Fireball::get_color() const
{
	return Color::Red;
}

std::string Fireball::get_name() const
{
	return "Fireball";
}

std::string Fireball::get_description() const
{
	return "Inflicts 3 damages to all enemy creatures.";
}

Card::Cost Fireball::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Red, 2 }
	};
}

void Fireball::apply_effect()
{
	for (auto& creature : m_owner->get_opponent().creatures)
		creature.modify_toughness(-3);
}

Card* Fireball::clone() const
{
	return new Fireball(*this);
}
