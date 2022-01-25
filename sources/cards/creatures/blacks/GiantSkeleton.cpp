#include "cards/creatures/blacks/GiantSkeleton.hpp"
#include "players/Player.hpp"
#include "renderer/print.hpp"

GiantSkeleton::GiantSkeleton(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

GiantSkeleton::~GiantSkeleton() {}

std::string GiantSkeleton::get_full_type() const
{
	return Creature::get_full_type() + " - Skeleton";
}

Card::Color GiantSkeleton::get_color() const
{
	return Color::Black;
}

std::string GiantSkeleton::get_name() const
{
	return "Giant Skeleton";
}

std::vector<Creature::Capacity> GiantSkeleton::get_capacities() const
{
	return {};
}

std::string GiantSkeleton::get_description() const
{
	return Creature::get_description() + "Inflicts 3 damages to all enemy creatures on death.";
}

Card::Cost GiantSkeleton::get_cost() const
{
	return
	{
		{ Color::Colorless, 4 },
		{ Color::Black, 2 }
	};
}

int GiantSkeleton::get_full_power() const
{
	return 2;
}

int GiantSkeleton::get_full_toughness() const
{
	return 6;
}

void GiantSkeleton::die()
{
	Creature::die();

	std::cout << cyan << "[INFO] " << ::reset << italic << ::get_color(get_color()) << get_name() << ::reset <<
		" inflicted 3 damages to all enemy creatures." << End(2);

	for (auto& creature : m_owner->get_opponent().creatures)
		creature.modify_toughness(-3);
}

Card* GiantSkeleton::clone() const
{
	return new GiantSkeleton(*this);
}
