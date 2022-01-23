#ifndef NIGHTWITCH_HPP
#define NIGHTWITCH_HPP

#include "cards/Creature.hpp"

class NightWitch : public Creature
{
public:

	NightWitch();
	NightWitch(const NightWitch& other) = default;
	~NightWitch();

	NightWitch& operator=(const NightWitch& other) = default;

	std::string get_full_type() const override;
	Color get_color() const override;
	std::string get_name() const override;
	std::vector<Capacity> get_capacities() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	int get_full_power() const override;
	int get_full_toughness() const override;
	void special_ability() override;
	Card* clone() const override;
};

#endif
