#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include "cards/Spell.hpp"

class Fireball : public Spell
{
public:

	Fireball();
	Fireball(const Fireball& other) = default;
	~Fireball();

	Fireball& operator=(const Fireball& other) = default;

	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	void apply_effect() override;
	Card* clone() const override;
};

#endif
