#include "cards/spells/GiantSnowball.hpp"
#include "players/Player.hpp"

GiantSnowball::GiantSnowball(): Spell() {}

GiantSnowball::~GiantSnowball() {}

Card::Color GiantSnowball::get_color() const
{
	return Color::Blue;
}

std::string GiantSnowball::get_name() const
{
	return "Giant Snowball";
}

std::string GiantSnowball::get_description() const
{
	return "Reduces power by 1 for all enemy creatures.";
}

Card::Cost GiantSnowball::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 },
		{ Color::Blue, 1 }
	};
}

void GiantSnowball::apply_effect()
{
	for (auto& creature : m_owner->get_opponent().creatures)
		creature.modify_power(-1);
}

Card* GiantSnowball::clone() const
{
	return new GiantSnowball(*this);
}
