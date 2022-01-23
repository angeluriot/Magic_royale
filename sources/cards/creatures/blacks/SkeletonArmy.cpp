#include "cards/creatures/blacks/SkeletonArmy.hpp"

SkeletonArmy::SkeletonArmy(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

SkeletonArmy::~SkeletonArmy() {}

std::string SkeletonArmy::get_full_type() const
{
	return Creature::get_full_type() + " - Skeleton";
}

Card::Color SkeletonArmy::get_color() const
{
	return Color::Black;
}

std::string SkeletonArmy::get_name() const
{
	return "Skeleton Army";
}

std::vector<Creature::Capacity> SkeletonArmy::get_capacities() const
{
	return
	{
		Capacity::MultiHit
	};
}

std::string SkeletonArmy::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost SkeletonArmy::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Black, 1 }
	};
}

int SkeletonArmy::get_full_power() const
{
	return 4;
}

int SkeletonArmy::get_full_toughness() const
{
	return 1;
}

Card* SkeletonArmy::clone() const
{
	return new SkeletonArmy(*this);
}
