#ifndef ICEWIZARD_HPP
#define ICEWIZARD_HPP

#include "cards/Creature.hpp"

class IceWizard : public Creature
{
public:

	IceWizard();
	IceWizard(const IceWizard& other) = default;

	IceWizard& operator=(const IceWizard& other) = default;

	std::string get_full_type() const override;
	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	int get_full_power() const override;
	int get_full_toughness() const override;
};

#endif
