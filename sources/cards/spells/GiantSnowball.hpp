#ifndef GIANTSNOWBALL_HPP
#define GIANTSNOWBALL_HPP

#include "cards/Spell.hpp"

class GiantSnowball : public Spell
{
public:

	GiantSnowball();
	GiantSnowball(const GiantSnowball& other) = default;
	~GiantSnowball();

	GiantSnowball& operator=(const GiantSnowball& other) = default;

	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	void apply_effect() override;
	Card* clone() const override;
};

#endif
