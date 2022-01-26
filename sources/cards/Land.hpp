#ifndef LAND_HPP
#define LAND_HPP

#include "cards/Card.hpp"
#include <string>

/**
 * @brief A class that represent a land.
 */
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
	virtual void print() const;
};

#endif
