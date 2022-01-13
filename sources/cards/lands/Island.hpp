#ifndef ISLAND_HPP
#define ISLAND_HPP

#include "cards/Land.hpp"

class Island : public Land
{
public:

	Island();
	Island(const Island& other) = default;
	~Island();

	Island& operator=(const Island& other) = default;

	std::string get_full_type() const override;
	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Card* clone() const override;
};

#endif
