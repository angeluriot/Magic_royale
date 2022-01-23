#ifndef MIRROR_HPP
#define MIRROR_HPP

#include "cards/Spell.hpp"

class Mirror : public Spell
{
public:

	Mirror();
	Mirror(const Mirror& other) = default;
	~Mirror();

	Mirror& operator=(const Mirror& other) = default;

	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	void apply_effect() override;
	Card* clone() const override;
};

#endif
