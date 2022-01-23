#ifndef GRAVEYARD_HPP
#define GRAVEYARD_HPP

#include "cards/Spell.hpp"

class Graveyard : public Spell
{
public:

	Graveyard();
	Graveyard(const Graveyard& other) = default;
	~Graveyard();

	Graveyard& operator=(const Graveyard& other) = default;

	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	void apply_effect() override;
	Card* clone() const override;
};

#endif
