#ifndef LAVAPUPS_HPP
#define LAVAPUPS_HPP

#include "cards/Creature.hpp"

class LavaPups : public Creature
{
public:

	LavaPups();
	LavaPups(const LavaPups& other) = default;

	LavaPups& operator=(const LavaPups& other) = default;

	std::string get_full_type() const override;
	Color get_color() const override;
	std::string get_name() const override;
	std::vector<Capacity> get_capacities() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	int get_full_power() const override;
	int get_full_toughness() const override;
};

#endif