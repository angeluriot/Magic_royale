#include "cards/creatures/greens/IceGolem.hpp"
#include "players/Player.hpp"
#include "renderer/print.hpp"

IceGolem::IceGolem(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

IceGolem::~IceGolem() {}

std::string IceGolem::get_full_type() const
{
	return Creature::get_full_type() + " - Golem";
}

Card::Color IceGolem::get_color() const
{
	return Color::Green;
}

std::string IceGolem::get_name() const
{
	return "Ice Golem";
}

std::vector<Creature::Capacity> IceGolem::get_capacities() const
{
	return
	{
		Capacity::Unblockable,
		Capacity::Freeze
	};
}

std::string IceGolem::get_description() const
{
	return Creature::get_description() + "Applies the effects of the Freeze capacity to all opponent creatures on death.";
}

Card::Cost IceGolem::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 },
		{ Color::Green, 1 }
	};
}

int IceGolem::get_full_power() const
{
	return 1;
}

int IceGolem::get_full_toughness() const
{
	return 3;
}

void IceGolem::die()
{
	Creature::die();

	std::cout << cyan << "[INFO] " << ::reset << bold << magenta << m_owner->get_opponent().get_name() <<
		::reset << "'s creatures will get the effects of the Freeze capacity in the next turn." << End(2);
	m_owner->get_opponent().freeze_capacity();
}

Card* IceGolem::clone() const
{
	return new IceGolem(*this);
}
