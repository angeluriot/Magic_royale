#ifndef FOREST_HPP
#define FOREST_HPP

#include "cards/Land.hpp"

class Forest : public Land
{
public:

	Forest();
	Forest(const Forest& other) = default;
	~Forest();

	Forest& operator=(const Forest& other) = default;

	std::string get_full_type() const override;
	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Card* clone() const override;
};

#endif
