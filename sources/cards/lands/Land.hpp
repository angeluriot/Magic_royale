#ifndef LAND_HPP
#define LAND_HPP

#include "cards/Card.hpp"
#include <string>

class Land : public Card
{
public:

	enum class Type : int
	{
		Plain = 0,
		Island = 1,
		Swamp = 2,
		Mountain = 3,
		Forest = 4,
		Neutral = 5
	};

protected:

    Type m_land_type;

public:

    Land(std::string name, Type land_type);
    ~Land();

};

#endif
