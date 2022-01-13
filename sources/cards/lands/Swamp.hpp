#ifndef SWAMP_HPP
#define SWAMP_HPP

#include "cards/Land.hpp"

class Swamp : public Land
{
public:

	Swamp();
	Swamp(const Swamp& other) = default;
	~Swamp();

	Swamp& operator=(const Swamp& other) = default;

	std::string get_full_type() const override;
	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Card* clone() const override;
};

#endif
