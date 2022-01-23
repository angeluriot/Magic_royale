#include "cards/creatures/reds/GoblinGang.hpp"
#include "players/Player.hpp"
#include "renderer/print.hpp"

GoblinGang::GoblinGang(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

GoblinGang::~GoblinGang() {}

std::string GoblinGang::get_full_type() const
{
	return Creature::get_full_type() + " - Goblin";
}

Card::Color GoblinGang::get_color() const
{
	return Color::Red;
}

std::string GoblinGang::get_name() const
{
	return "Goblin Gang";
}

std::vector<Creature::Capacity> GoblinGang::get_capacities() const
{
	return
	{
		Capacity::Reach
	};
}

std::string GoblinGang::get_description() const
{
	return Creature::get_description() + "Adds 1 power to all Goblin type allies while alive.";
}

Card::Cost GoblinGang::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Red, 1 }
	};
}

int GoblinGang::get_full_power() const
{
	return 3;
}

int GoblinGang::get_full_toughness() const
{
	return 2;
}

void GoblinGang::spawn()
{
	Creature::spawn();

	std::cout << cyan << "[INFO] " << ::reset << italic << ::get_color(get_color()) << get_name() << ::reset <<
		" addded 1 power to all Goblin type allies." << End(2);

	for (auto& creature : m_owner->creatures)
		if (creature.get_full_type() == "Creature - Goblin")
			creature.modify_power(1);
}

void GoblinGang::special_ability()
{
	Creature::special_ability();

	std::cout << cyan << "[INFO] " << ::reset << italic << ::get_color(get_color()) << get_name() << ::reset <<
		" addded 1 power to all Goblin type allies." << End(2);

	for (auto& creature : m_owner->creatures)
		if (creature.get_full_type() == "Creature - Goblin")
			creature.modify_power(1);
}

Card* GoblinGang::clone() const
{
	return new GoblinGang(*this);
}
