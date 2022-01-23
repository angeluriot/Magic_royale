#ifndef BARBARIANBARREL_HPP
#define BARBARIANBARREL_HPP

#include "cards/Creature.hpp"

class BarbarianBarrel : public Creature
{
public:

	BarbarianBarrel();
	BarbarianBarrel(const BarbarianBarrel& other) = default;
	~BarbarianBarrel();

	BarbarianBarrel& operator=(const BarbarianBarrel& other) = default;

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
