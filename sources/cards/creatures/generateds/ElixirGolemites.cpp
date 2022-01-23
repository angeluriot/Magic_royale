#include "cards/creatures/generateds/ElixirGolemites.hpp"
#include "players/Player.hpp"
#include "cards/creatures/generateds/SentientBlobs.hpp"

ElixirGolemites::ElixirGolemites(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

ElixirGolemites::~ElixirGolemites() {}

std::string ElixirGolemites::get_full_type() const
{
	return Creature::get_full_type() + " - Golem";
}

Card::Color ElixirGolemites::get_color() const
{
	return Color::Green;
}

std::string ElixirGolemites::get_name() const
{
	return "Elixir Golemites";
}

std::vector<Creature::Capacity> ElixirGolemites::get_capacities() const
{
	return
	{
		Capacity::Unblockable
	};
}

std::string ElixirGolemites::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost ElixirGolemites::get_cost() const
{
	return {};
}

int ElixirGolemites::get_full_power() const
{
	return 1;
}

int ElixirGolemites::get_full_toughness() const
{
	return 3;
}

void ElixirGolemites::die()
{
	m_owner->creatures.add(SentientBlobs());
	m_owner->creatures.back().set_owner(*m_owner);
}

Card* ElixirGolemites::clone() const
{
	return new ElixirGolemites(*this);
}
