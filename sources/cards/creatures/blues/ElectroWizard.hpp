#ifndef ELECTROWIZARD_HPP
#define ELECTROWIZARD_HPP

#include "cards/Creature.hpp"

class ElectroWizard : public Creature
{
public:

	ElectroWizard();
	ElectroWizard(const ElectroWizard& other) = default;
	~ElectroWizard();

	ElectroWizard& operator=(const ElectroWizard& other) = default;

	std::string get_full_type() const override;
	Color get_color() const override;
	std::string get_name() const override;
	std::vector<Capacity> get_capacities() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	int get_full_power() const override;
	int get_full_toughness() const override;
	void spawn() override;
	Card* clone() const override;
};

#endif
