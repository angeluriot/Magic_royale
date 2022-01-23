#ifndef WIZARD_HPP
#define WIZARD_HPP

#include "cards/Creature.hpp"

class Wizard : public Creature
{
public:

	Wizard();
	Wizard(const Wizard& other) = default;
	~Wizard();

	Wizard& operator=(const Wizard& other) = default;

	std::string get_full_type() const override;
	Color get_color() const override;
	std::string get_name() const override;
	std::vector<Capacity> get_capacities() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	int get_full_power() const override;
	int get_full_toughness() const override;
	Card* clone() const override;
};

#endif