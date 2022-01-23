#ifndef LIGHTNING_HPP
#define LIGHTNING_HPP

#include "cards/Spell.hpp"

class Lightning : public Spell
{
public:

	Lightning();
	Lightning(const Lightning& other) = default;
	~Lightning();

	Lightning& operator=(const Lightning& other) = default;

	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	void apply_effect() override;
	Card* clone() const override;
};

#endif
