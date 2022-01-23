#include "cards/creatures/whites/RoyalRecruits.hpp"

RoyalRecruits::RoyalRecruits(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

RoyalRecruits::~RoyalRecruits() {}

std::string RoyalRecruits::get_full_type() const
{
	return Creature::get_full_type() + " - Human";
}

Card::Color RoyalRecruits::get_color() const
{
	return Color::White;
}

std::string RoyalRecruits::get_name() const
{
	return "Royal Recruits";
}

std::vector<Creature::Capacity> RoyalRecruits::get_capacities() const
{
	return {};
}

std::string RoyalRecruits::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost RoyalRecruits::get_cost() const
{
	return
	{
		{ Color::Colorless, 4 },
		{ Color::White, 3 }
	};
}

int RoyalRecruits::get_full_power() const
{
	return 5;
}

int RoyalRecruits::get_full_toughness() const
{
	return 14;
}

Card* RoyalRecruits::clone() const
{
	return new RoyalRecruits(*this);
}
