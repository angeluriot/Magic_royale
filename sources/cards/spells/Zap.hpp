#ifndef ZAP_HPP
#define ZAP_HPP

#include "cards/Spell.hpp"

class Zap : public Spell
{
public:

	Zap();
	Zap(const Zap& other) = default;
	~Zap();

	Zap& operator=(const Zap& other) = default;

	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	void apply_effect() override;
	Card* clone() const override;
};

#endif
