#ifndef CANNONCART_HPP
#define CANNONCART_HPP

#include "cards/Creature.hpp"

class CannonCart : public Creature
{
public:

	CannonCart();
	CannonCart(const CannonCart& other) = default;
	~CannonCart();

	CannonCart& operator=(const CannonCart& other) = default;

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
