#ifndef GOBLINS_HPP
#define GOBLINS_HPP

#include "cards/Creature.hpp"

class Goblins : public Creature
{
public:

	Goblins();
	Goblins(const Goblins& other) = default;
	~Goblins();

	Goblins& operator=(const Goblins& other) = default;

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