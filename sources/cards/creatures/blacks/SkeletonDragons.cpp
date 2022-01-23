#include "cards/creatures/blacks/SkeletonDragons.hpp"

SkeletonDragons::SkeletonDragons(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

SkeletonDragons::~SkeletonDragons() {}

std::string SkeletonDragons::get_full_type() const
{
	return Creature::get_full_type() + " - Dragon";
}

Card::Color SkeletonDragons::get_color() const
{
	return Color::Black;
}

std::string SkeletonDragons::get_name() const
{
	return "Skeleton Dragons";
}

std::vector<Creature::Capacity> SkeletonDragons::get_capacities() const
{
	return
	{
		Capacity::Flying,
		Capacity::Reach,
		Capacity::ZoneDamage
	};
}

std::string SkeletonDragons::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost SkeletonDragons::get_cost() const
{
	return
	{
		{ Color::Colorless, 2 },
		{ Color::Black, 2 }
	};
}

int SkeletonDragons::get_full_power() const
{
	return 3;
}

int SkeletonDragons::get_full_toughness() const
{
	return 3;
}

Card* SkeletonDragons::clone() const
{
	return new SkeletonDragons(*this);
}
