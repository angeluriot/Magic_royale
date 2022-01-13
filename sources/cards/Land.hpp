#ifndef LAND_HPP
#define LAND_HPP

#include "cards/Card.hpp"
#include <string>

class Land : public Card
{
public:

	Land();
	Land(const Land& other) = default;
	virtual ~Land();

	Land& operator=(const Land& other) = default;

	virtual Type get_type() const override;
	virtual std::string get_full_type() const override;
	virtual Cost get_cost() const override;
};

#endif
