#ifndef HEALSPIRIT_HPP
#define HEALSPIRIT_HPP

#include "cards/Spell.hpp"

class HealSpirit : public Spell
{
public:

	HealSpirit();
	HealSpirit(const HealSpirit& other) = default;
	~HealSpirit();

	HealSpirit& operator=(const HealSpirit& other) = default;

	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	void apply_effect() override;
	Card* clone() const override;
};

#endif
