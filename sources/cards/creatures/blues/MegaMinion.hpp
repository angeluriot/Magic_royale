#ifndef MEGAMINION_HPP
#define MEGAMINION_HPP

#include "cards/Creature.hpp"

class MegaMinion : public Creature
{
public:

	MegaMinion();
	MegaMinion(const MegaMinion& other) = default;
	~MegaMinion();

	MegaMinion& operator=(const MegaMinion& other) = default;

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