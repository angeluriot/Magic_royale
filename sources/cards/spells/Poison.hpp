#ifndef POISON_HPP
#define POISON_HPP

#include "cards/Spell.hpp"

class Poison : public Spell
{
public:

	Poison();
	Poison(const Poison& other) = default;
	~Poison();

	Poison& operator=(const Poison& other) = default;

	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	void apply_effect() override;
	Card* clone() const override;
};

#endif
