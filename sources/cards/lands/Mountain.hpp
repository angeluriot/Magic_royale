#ifndef MOUNTAIN_HPP
#define MOUNTAIN_HPP

#include "cards/Land.hpp"

class Mountain : public Land
{
public:

	Mountain();
	Mountain(const Mountain& other) = default;
	~Mountain();

	Mountain& operator=(const Mountain& other) = default;

	std::string get_full_type() const override;
	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Card* clone() const override;
};

#endif
