#include "cards/creatures/whites/MagicArcher.hpp"

MagicArcher::MagicArcher(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

MagicArcher::~MagicArcher() {}

std::string MagicArcher::get_full_type() const
{
	return Creature::get_full_type() + " - Elf";
}

Card::Color MagicArcher::get_color() const
{
	return Color::White;
}

std::string MagicArcher::get_name() const
{
	return "Magic Archer";
}

std::vector<Creature::Capacity> MagicArcher::get_capacities() const
{
	return
	{
		Capacity::Reach,
		Capacity::MultiHit
	};
}

std::string MagicArcher::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost MagicArcher::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::White, 1 }
	};
}

int MagicArcher::get_full_power() const
{
	return 3;
}

int MagicArcher::get_full_toughness() const
{
	return 3;
}

Card* MagicArcher::clone() const
{
	return new MagicArcher(*this);
}
