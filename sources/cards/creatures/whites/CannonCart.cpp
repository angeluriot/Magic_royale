#include "cards/creatures/whites/CannonCart.hpp"
#include "players/Player.hpp"
#include "cards/creatures/generateds/Cannon.hpp"
#include "renderer/print.hpp"

CannonCart::CannonCart(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

CannonCart::~CannonCart() {}

std::string CannonCart::get_full_type() const
{
	return Creature::get_full_type() + " - Machine";
}

Card::Color CannonCart::get_color() const
{
	return Color::White;
}

std::string CannonCart::get_name() const
{
	return "Cannon Cart";
}

std::vector<Creature::Capacity> CannonCart::get_capacities() const
{
	return {};
}

std::string CannonCart::get_description() const
{
	return Creature::get_description() + "Spawns 1 Cannon on death.";
}

Card::Cost CannonCart::get_cost() const
{
	return
	{
		{ Color::Colorless, 4 },
		{ Color::White, 1}
	};
}

int CannonCart::get_full_power() const
{
	return 3;
}

int CannonCart::get_full_toughness() const
{
	return 4;
}

void CannonCart::die()
{
	Creature::die();

	std::cout << cyan << "[INFO] " << ::reset << "A " << italic << ::get_color(Cannon().get_color()) <<
		Cannon().get_name() << ::reset << " spawned." << End(2);

	m_owner->creatures.add(Cannon());
	m_owner->creatures.back().set_owner(*m_owner);
}

Card* CannonCart::clone() const
{
	return new CannonCart(*this);
}
