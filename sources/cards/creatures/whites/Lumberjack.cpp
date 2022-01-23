#include "cards/creatures/whites/Lumberjack.hpp"
#include "players/Player.hpp"
#include "renderer/print.hpp"

Lumberjack::Lumberjack(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

Lumberjack::~Lumberjack() {}

std::string Lumberjack::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color Lumberjack::get_color() const
{
	return Color::White;
}

std::string Lumberjack::get_name() const
{
	return "Lumberjack";
}

std::vector<Creature::Capacity> Lumberjack::get_capacities() const
{
	return {};
}

std::string Lumberjack::get_description() const
{
	return Creature::get_description() + "Casts a Rage spell 1 turn after his death.";
}

Card::Cost Lumberjack::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::White, 1 }
	};
}

int Lumberjack::get_full_power() const
{
	return 4;
}

int Lumberjack::get_full_toughness() const
{
	return 2;
}

void Lumberjack::die()
{
	Creature::die();

	std::cout << cyan << "[INFO] " << ::reset << bold << magenta << m_owner->get_name() << ::reset << " will get rage in the next turn." << End(2);
	m_owner->rage();
}

Card* Lumberjack::clone() const
{
	return new Lumberjack(*this);
}
