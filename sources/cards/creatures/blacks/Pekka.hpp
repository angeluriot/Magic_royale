#ifndef PEKKA_HPP
#define PEKKA_HPP

#include "cards/Creature.hpp"

class Pekka : public Creature
{
public:

	Pekka();
	Pekka(const Pekka& other) = default;
	~Pekka();

	Pekka& operator=(const Pekka& other) = default;

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
