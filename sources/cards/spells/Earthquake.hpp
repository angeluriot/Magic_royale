#ifndef EARTHQUAKE_HPP
#define EARTHQUAKE_HPP

#include "cards/Spell.hpp"

class Earthquake : public Spell
{
public:

	Earthquake();
	Earthquake(const Earthquake& other) = default;
	~Earthquake();

	Earthquake& operator=(const Earthquake& other) = default;

	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	void apply_effect() override;
	Card* clone() const override;
};

#endif
