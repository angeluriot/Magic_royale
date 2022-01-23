#ifndef FREEZE_HPP
#define FREEZE_HPP

#include "cards/Spell.hpp"

class Freeze : public Spell
{
public:

	Freeze();
	Freeze(const Freeze& other) = default;
	~Freeze();

	Freeze& operator=(const Freeze& other) = default;

	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	void apply_effect() override;
	Card* clone() const override;
};

#endif
