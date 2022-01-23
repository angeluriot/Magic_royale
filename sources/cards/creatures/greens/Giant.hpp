#ifndef GIANT_HPP
#define GIANT_HPP

#include "cards/Creature.hpp"

class Giant : public Creature
{
public:

	Giant();
	Giant(const Giant& other) = default;
	~Giant();

	Giant& operator=(const Giant& other) = default;

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