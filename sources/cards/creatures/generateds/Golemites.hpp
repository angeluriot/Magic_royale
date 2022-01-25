#ifndef GOLEMITES_HPP
#define GOLEMITES_HPP

#include "cards/Creature.hpp"

class Golemites : public Creature
{
public:

	Golemites();
	Golemites(const Golemites& other) = default;
	~Golemites();

	Golemites& operator=(const Golemites& other) = default;

	std::string get_full_type() const override;
	Color get_color() const override;
	std::string get_name() const override;
	std::vector<Capacity> get_capacities() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	int get_full_power() const override;
	int get_full_toughness() const override;
	void die() override;
	Card* clone() const override;
};

#endif
