#ifndef MEGAKNIGHT_HPP
#define MEGAKNIGHT_HPP

#include "cards/Creature.hpp"

class MegaKnight : public Creature
{
public:

	MegaKnight();
	MegaKnight(const MegaKnight& other) = default;
	~MegaKnight();

	MegaKnight& operator=(const MegaKnight& other) = default;

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
