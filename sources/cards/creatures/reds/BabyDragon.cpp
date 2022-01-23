#include "cards/creatures/reds/BabyDragon.hpp"

BabyDragon::BabyDragon(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

BabyDragon::~BabyDragon() {}

std::string BabyDragon::get_full_type() const
{
	return Creature::get_full_type() + " - Dragon";
}

Card::Color BabyDragon::get_color() const
{
	return Color::Red;
}

std::string BabyDragon::get_name() const
{
	return "Baby Dragon";
}

std::vector<Creature::Capacity> BabyDragon::get_capacities() const
{
	return
	{
		Capacity::Flying,
		Capacity::Reach,
		Capacity::ZoneDamage
	};
}

std::string BabyDragon::get_description() const
{
	return Creature::get_description() + "";
}

Card::Cost BabyDragon::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::Red, 1 }
	};
}

int BabyDragon::get_full_power() const
{
	return 2;
}

int BabyDragon::get_full_toughness() const
{
	return 4;
}

Card* BabyDragon::clone() const
{
	return new BabyDragon(*this);
}
