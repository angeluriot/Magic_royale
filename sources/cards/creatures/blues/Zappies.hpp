#ifndef ZAPPIES_HPP
#define ZAPPIES_HPP

#include "cards/Creature.hpp"

class Zappies : public Creature
{
public:

	Zappies();
	Zappies(const Zappies& other) = default;
	~Zappies();

	Zappies& operator=(const Zappies& other) = default;

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