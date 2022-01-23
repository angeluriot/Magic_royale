#ifndef CLONE_HPP
#define CLONE_HPP

#include "cards/Spell.hpp"

class Clone : public Spell
{
public:

	Clone();
	Clone(const Clone& other) = default;
	~Clone();

	Clone& operator=(const Clone& other) = default;

	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	void apply_effect() override;
	Card* clone() const override;
};

#endif
