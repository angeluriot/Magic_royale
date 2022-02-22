#include "cards/creatures/blues/MotherWitch.hpp"
#include "players/Player.hpp"
#include "cards/creatures/generateds/Hog.hpp"
#include "renderer/print.hpp"

MotherWitch::MotherWitch(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

MotherWitch::~MotherWitch() {}

std::string MotherWitch::get_full_type() const
{
	return Creature::get_full_type() + " - Wizard";
}

Card::Color MotherWitch::get_color() const
{
	return Color::Blue;
}

std::string MotherWitch::get_name() const
{
	return "Mother Witch";
}

std::vector<Creature::Capacity> MotherWitch::get_capacities() const
{
	return {};
}

std::string MotherWitch::get_description() const
{
	return Creature::get_description() + "Turns creatures she kills into hogs.";
}

Card::Cost MotherWitch::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::Blue, 1}
	};
}

int MotherWitch::get_full_power() const
{
	return 2;
}

int MotherWitch::get_full_toughness() const
{
	return 4;
}

void MotherWitch::on_kill()
{
	Creature::on_kill();

	std::cout << cyan << "[INFO] " << ::reset << "A " << italic << ::get_color(Hog().get_color()) <<
		Hog().get_name() << ::reset << " spawned." << End(2);

	m_owner->creatures.add(Hog());
	m_owner->creatures.back().set_owner(*m_owner);
}

Card* MotherWitch::clone() const
{
	return new MotherWitch(*this);
}
