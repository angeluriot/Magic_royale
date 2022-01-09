#include "cards/creatures/IceWizard.hpp"

IceWizard::IceWizard(): Creature(get_full_power(), get_full_toughness()) {}

std::string IceWizard::get_full_type() const
{
	return Creature::get_full_type() + " - Wizard";
}

Card::Color IceWizard::get_color() const
{
	return Color::Blue;
}

std::string IceWizard::get_name() const
{
	return "Ice Wizard";
}

std::string IceWizard::get_description() const
{
	return "";
}

Card::Cost IceWizard::get_cost() const
{
	return
	{
		{ Color::Colorless, 1 },
		{ Color::Blue, 1 }
	};
}

int IceWizard::get_full_power() const
{
	return 2;
}

int IceWizard::get_full_toughness() const
{
	return 2;
}
