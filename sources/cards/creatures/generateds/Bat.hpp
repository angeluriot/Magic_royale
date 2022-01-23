#ifndef BAT_HPP
#define BAT_HPP

#include "cards/Creature.hpp"

class Bat : public Creature
{
public:

	Bat();
	Bat(const Bat& other) = default;
	~Bat();

	Bat& operator=(const Bat& other) = default;

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
