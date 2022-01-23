#ifndef ARROWS_HPP
#define ARROWS_HPP

#include "cards/Spell.hpp"

class Arrows : public Spell
{
public:

	Arrows();
	Arrows(const Arrows& other) = default;
	~Arrows();

	Arrows& operator=(const Arrows& other) = default;

	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	void apply_effect() override;
	Card* clone() const override;
};

#endif
