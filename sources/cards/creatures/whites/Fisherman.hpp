#ifndef FISHERMAN_HPP
#define FISHERMAN_HPP

#include "cards/Creature.hpp"

class Fisherman : public Creature
{
public:

	Fisherman();
	Fisherman(const Fisherman& other) = default;
	~Fisherman();

	Fisherman& operator=(const Fisherman& other) = default;

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