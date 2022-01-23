#ifndef TORNADO_HPP
#define TORNADO_HPP

#include "cards/Spell.hpp"

class Tornado : public Spell
{
public:

	Tornado();
	Tornado(const Tornado& other) = default;
	~Tornado();

	Tornado& operator=(const Tornado& other) = default;

	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	void apply_effect() override;
	Card* clone() const override;
};

#endif
