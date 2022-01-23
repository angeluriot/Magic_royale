#include "cards/creatures/blues/NightWitch.hpp"
#include "players/Player.hpp"
#include "cards/creatures/generateds/Bat.hpp"
#include "renderer/print.hpp"

NightWitch::NightWitch(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

NightWitch::~NightWitch() {}

std::string NightWitch::get_full_type() const
{
	return Creature::get_full_type() + " - Wizard";
}

Card::Color NightWitch::get_color() const
{
	return Color::Blue;
}

std::string NightWitch::get_name() const
{
	return "Night Witch";
}

std::vector<Creature::Capacity> NightWitch::get_capacities() const
{
	return {};
}

std::string NightWitch::get_description() const
{
	return Creature::get_description() + "Spawns 1 Bat every turn.";
}

Card::Cost NightWitch::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::Blue, 1 }
	};
}

int NightWitch::get_full_power() const
{
	return 3;
}

int NightWitch::get_full_toughness() const
{
	return 3;
}

void NightWitch::special_ability()
{
	Creature::special_ability();

	std::cout << cyan << "[INFO] " << ::reset << "A " << italic << ::get_color(Bat().get_color()) <<
		Bat().get_name() << ::reset << " spawned." << End(2);

	m_owner->creatures.add(Bat());
	m_owner->creatures.back().set_owner(*m_owner);
}

Card* NightWitch::clone() const
{
	return new NightWitch(*this);
}
