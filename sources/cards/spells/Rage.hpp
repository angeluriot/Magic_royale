#ifndef RAGE_HPP
#define RAGE_HPP

#include "cards/Spell.hpp"

class Rage : public Spell
{
public:

	Rage();
	Rage(const Rage& other) = default;
	~Rage();

	Rage& operator=(const Rage& other) = default;

	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	void apply_effect() override;
	Card* clone() const override;
};

#endif
