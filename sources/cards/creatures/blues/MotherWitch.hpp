#ifndef MOTHERWITCH_HPP
#define MOTHERWITCH_HPP

#include "cards/Creature.hpp"

class MotherWitch : public Creature
{
public:

	MotherWitch();
	MotherWitch(const MotherWitch& other) = default;
	~MotherWitch();

	MotherWitch& operator=(const MotherWitch& other) = default;

	std::string get_full_type() const override;
	Color get_color() const override;
	std::string get_name() const override;
	std::vector<Capacity> get_capacities() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	int get_full_power() const override;
	int get_full_toughness() const override;
	void on_kill() override;
	Card* clone() const override;
};

#endif
