#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "cards/Creature.hpp"

class Barbarian : public Creature
{
public:

    Barbarian();
    Barbarian(const Barbarian& other) = default;

    Barbarian& operator=(const Barbarian& other) = default;

	std::string get_full_type() const override;
	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	int get_full_power() const override;
	int get_full_toughness() const override;
};

#endif