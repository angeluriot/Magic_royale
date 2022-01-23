#include "cards/spells/Freeze.hpp"
#include "players/Player.hpp"

Freeze::Freeze(): Spell() {}

Freeze::~Freeze() {}

Card::Color Freeze::get_color() const
{
	return Color::Blue;
}

std::string Freeze::get_name() const
{
	return "Freeze";
}

std::string Freeze::get_description() const
{
	return "The opponent cannot block on this turn.";
}

Card::Cost Freeze::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Blue, 2 }
	};
}

void Freeze::apply_effect()
{
	m_owner->get_opponent().freeze();
}

Card* Freeze::clone() const
{
	return new Freeze(*this);
}
