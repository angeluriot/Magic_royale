#include "cards/creatures/generateds/ElixirGolemites.hpp"
#include "players/Player.hpp"
#include "cards/creatures/generateds/SentientBlobs.hpp"
#include "renderer/print.hpp"

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
	return Creature::get_description() + "Spawns 1 Sentient Blobs on death. Sentient Blobs gives 2 Forest cards to the opponent on death.";
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
	Creature::die();

	std::cout << cyan << "[INFO] " << ::reset << "A " << italic << ::get_color(SentientBlobs().get_color()) <<
		SentientBlobs().get_name() << ::reset << " spawned." << End(2);

	m_owner->creatures.add(SentientBlobs());
	m_owner->creatures.back().set_owner(*m_owner);
}

Card* ElixirGolemites::clone() const
{
	return new ElixirGolemites(*this);
}
