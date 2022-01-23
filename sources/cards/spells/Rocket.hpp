#ifndef ROCKET_HPP
#define ROCKET_HPP

#include "cards/Spell.hpp"

class Rocket : public Spell
{
public:

	Rocket();
	Rocket(const Rocket& other) = default;
	~Rocket();

	Rocket& operator=(const Rocket& other) = default;

	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	void apply_effect() override;
	Card* clone() const override;
};

#endif
